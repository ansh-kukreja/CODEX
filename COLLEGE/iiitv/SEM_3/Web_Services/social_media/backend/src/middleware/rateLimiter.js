const config = require('../config/env');

// In-memory sliding window rate limiter
const requestCounts = new Map();

/**
 * Factory for rate limiting middleware
 * @param {Object} options
 * @param {number} options.windowMs - Sliding window time in ms
 * @param {number} options.max - Max requests allowed in the window
 */
function createRateLimiter(options = {}) {
  const windowMs = options.windowMs || config.rateLimitWindowMs;
  const max = options.max || config.rateLimitMaxRequests;

  return function rateLimiterMiddleware(req, res, next) {
    const key = req.ip || req.connection.remoteAddress || 'global_client';
    const now = Date.now();

    let record = requestCounts.get(key);
    if (!record || now - record.startTime > windowMs) {
      record = {
        count: 0,
        startTime: now,
        resetTime: Math.ceil((now + windowMs) / 1000)
      };
      requestCounts.set(key, record);
    }

    record.count += 1;
    const remaining = Math.max(0, max - record.count);
    const resetSeconds = record.resetTime;

    // Set standard rate-limiting headers
    res.setHeader('X-RateLimit-Limit', max);
    res.setHeader('X-RateLimit-Remaining', remaining);
    res.setHeader('X-RateLimit-Reset', resetSeconds);

    if (record.count > max) {
      const retryAfterSeconds = Math.max(1, resetSeconds - Math.ceil(now / 1000));
      res.setHeader('Retry-After', retryAfterSeconds);

      return res.status(429).json({
        error: {
          code: 'RATE_LIMIT_EXCEEDED',
          message: 'Too many requests. Please slow down and try again later.',
          details: {
            limit: max,
            windowMs,
            retryAfterSeconds
          },
          timestamp: new Date().toISOString(),
          correlationId: req.correlationId || 'unknown'
        }
      });
    }

    next();
  };
}

module.exports = {
  globalRateLimiter: createRateLimiter({ windowMs: 60000, max: 120 }),
  strictRateLimiter: createRateLimiter({ windowMs: 15000, max: 3 }), // For easy 429 testing in demo
  createRateLimiter
};
