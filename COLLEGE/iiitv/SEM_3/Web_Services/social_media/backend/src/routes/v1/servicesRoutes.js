const express = require('express');
const router = express.Router();
const { callSoapWeatherService } = require('../../services/soapService');
const { externalServiceBreaker } = require('../../services/circuitBreaker');
const { retryWithBackoff } = require('../../services/outboundClient');
const mockSqlDb = require('../../data/mockSqlDb');
const mockNoSqlDb = require('../../data/mockNoSqlDb');
const { strictRateLimiter } = require('../../middleware/rateLimiter');
const { AppError } = require('../../middleware/errorHandler');

/**
 * GET /api/v1/services/soap-call
 * Reads WSDL and executes a real SOAP XML request
 */
router.get('/soap-call', async (req, res, next) => {
  try {
    const city = req.query.city || 'Boston';
    const soapResult = await callSoapWeatherService(city);
    return res.status(200).sendNegotiated(soapResult, 'soapExecutionResult');
  } catch (err) {
    return next(new AppError(`SOAP execution failed: ${err.message}`, 500, 'SOAP_EXECUTION_ERROR', err.stack));
  }
});

/**
 * GET /api/v1/services/circuit-breaker
 * Executes through Circuit Breaker and returns state
 */
router.get('/circuit-breaker', async (req, res, next) => {
  try {
    const shouldFail = req.query.fail === 'true';

    const execution = await externalServiceBreaker.execute(
      async () => {
        if (shouldFail) {
          throw new Error('Simulated downstream third-party service timeout or outage');
        }
        return {
          service: 'Downstream Event Sync',
          status: 'healthy',
          payload: { syncedAt: new Date().toISOString() }
        };
      },
      async (error) => {
        return {
          service: 'Downstream Event Sync',
          status: 'fallback_active',
          fallbackMessage: 'Degraded mode: serving cached event data while circuit is active.',
          errorReason: error.message
        };
      }
    );

    return res.status(execution.circuitBreakerState === 'OPEN' ? 503 : 200).sendNegotiated({
      ...execution,
      metrics: externalServiceBreaker.getStatus()
    }, 'circuitBreakerStatus');
  } catch (err) {
    return next(new AppError(err.message, 503, 'CIRCUIT_BREAKER_BLOCKED', externalServiceBreaker.getStatus()));
  }
});

/**
 * POST /api/v1/services/circuit-breaker/reset
 */
router.post('/circuit-breaker/reset', (req, res) => {
  externalServiceBreaker.reset();
  return res.status(200).sendNegotiated({
    message: 'Circuit breaker successfully reset to CLOSED state.',
    status: externalServiceBreaker.getStatus()
  }, 'circuitBreakerReset');
});

/**
 * GET /api/v1/services/retry-demo
 * Demonstrates exponential backoff and jitter
 */
router.get('/retry-demo', async (req, res) => {
  let attemptCounter = 0;
  const failTimes = parseInt(req.query.failTimes, 10) || 2; // will succeed on 3rd try

  const result = await retryWithBackoff(async (attempt) => {
    attemptCounter++;
    if (attempt <= failTimes) {
      throw new Error(`Transient network glitch on attempt ${attempt}`);
    }
    return {
      message: `Outbound operation succeeded after ${attempt} attempts with exponential backoff!`,
      timestamp: new Date().toISOString()
    };
  }, { maxRetries: 4, baseDelayMs: 150 });

  return res.status(200).sendNegotiated(result, 'retryResult');
});

/**
 * POST /api/v1/services/sql-query
 * Parameterized SQL query execution over static data
 */
router.post('/sql-query', async (req, res, next) => {
  const { sql, params } = req.body;
  const querySql = sql || 'SELECT * FROM posts WHERE userId = ?';
  const queryParams = params || ['usr_alan'];

  try {
    const result = await mockSqlDb.query(querySql, queryParams);
    return res.status(200).sendNegotiated(result, 'sqlQueryResult');
  } catch (err) {
    return next(new AppError(err.message, 400, 'SQL_EXECUTION_ERROR'));
  }
});

/**
 * POST /api/v1/services/nosql-query
 * Document query over in-memory NoSQL collections
 */
router.post('/nosql-query', async (req, res) => {
  const { collection, filter } = req.body;
  const colName = collection || 'posts';
  const queryFilter = filter || {};

  const docs = await mockNoSqlDb.collection(colName).find(queryFilter);
  return res.status(200).sendNegotiated({
    collection: colName,
    filter: queryFilter,
    count: docs.length,
    documents: docs
  }, 'nosqlQueryResult');
});

/**
 * GET /api/v1/services/rate-limit-test
 * Uses strict rate limiter to easily demonstrate 429 Too Many Requests
 */
router.get('/rate-limit-test', strictRateLimiter, (req, res) => {
  return res.status(200).sendNegotiated({
    message: 'Rate limit request successful! Notice X-RateLimit headers.',
    remaining: res.getHeader('X-RateLimit-Remaining'),
    limit: res.getHeader('X-RateLimit-Limit')
  }, 'rateLimitTest');
});

/**
 * GET /api/v1/services/status-codes/:code
 * Allows direct verification of distinct status codes
 */
router.get('/status-codes/:code', (req, res, next) => {
  const code = parseInt(req.params.code, 10);
  switch (code) {
    case 200:
      return res.status(200).sendNegotiated({ statusCode: 200, message: '200 OK: Standard successful response' });
    case 201:
      return res.status(201).sendNegotiated({ statusCode: 201, message: '201 Created: New resource successfully instantiated' });
    case 204:
      return res.status(204).end();
    case 304:
      res.removeHeader('Content-Type');
      return res.status(304).end();
    case 400:
      return next(new AppError('400 Bad Request: Malformed query or client parameters.', 400, 'BAD_REQUEST'));
    case 401:
      return next(new AppError('401 Unauthorized: Authentication credentials required.', 401, 'UNAUTHORIZED'));
    case 403:
      return next(new AppError('403 Forbidden: Insufficient permissions for operation.', 403, 'FORBIDDEN'));
    case 404:
      return next(new AppError('404 Not Found: The requested resource does not exist.', 404, 'NOT_FOUND'));
    case 409:
      return next(new AppError('409 Conflict: Target state conflict or duplicate resource exists.', 409, 'CONFLICT'));
    case 422:
      return next(new AppError('422 Unprocessable Entity: Payload failed semantic schema validation.', 422, 'UNPROCESSABLE_ENTITY'));
    case 429:
      return next(new AppError('429 Too Many Requests: Rate limit exceeded.', 429, 'RATE_LIMIT_EXCEEDED'));
    case 503:
      return next(new AppError('503 Service Unavailable: Downstream circuit breaker open.', 503, 'SERVICE_UNAVAILABLE'));
    default:
      return res.status(200).sendNegotiated({ statusCode: code, message: `Status code ${code} handled.` });
  }
});

module.exports = router;
