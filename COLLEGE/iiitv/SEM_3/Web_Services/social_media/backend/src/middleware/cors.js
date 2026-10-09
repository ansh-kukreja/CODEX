const cors = require('cors');
const config = require('../config/env');

/**
 * Deliberate CORS configuration middleware
 * Explicitly whitelists allowed origins, methods, headers, and exposed response headers
 */
const deliberateCors = cors({
  origin: function (origin, callback) {
    // Allow non-browser requests (e.g. curl, postman, server-to-server) or listed origins
    if (!origin || config.corsOrigins.includes(origin) || origin.startsWith('http://localhost:')) {
      return callback(null, true);
    }
    return callback(new Error(`Origin ${origin} not allowed by deliberate CORS policy`));
  },
  methods: ['GET', 'POST', 'PUT', 'PATCH', 'DELETE', 'OPTIONS', 'HEAD'],
  allowedHeaders: [
    'Content-Type',
    'Authorization',
    'Idempotency-Key',
    'If-None-Match',
    'X-Correlation-ID',
    'Accept',
    'X-Requested-With'
  ],
  exposedHeaders: [
    'ETag',
    'X-RateLimit-Limit',
    'X-RateLimit-Remaining',
    'X-RateLimit-Reset',
    'X-Correlation-ID',
    'Idempotent-Replay',
    'X-Idempotency-Key',
    'Retry-After',
    'Cache-Control'
  ],
  credentials: true,
  maxAge: 86400, // 24 hours preflight cache
  optionsSuccessStatus: 204
});

module.exports = deliberateCors;
