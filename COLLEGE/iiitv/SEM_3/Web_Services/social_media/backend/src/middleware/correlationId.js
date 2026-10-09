const { v4: uuidv4 } = require('uuid');

/**
 * Structured correlation ID middleware
 * Captures incoming X-Correlation-ID or generates a fresh UUIDv4
 */
function correlationIdMiddleware(req, res, next) {
  const correlationId = req.header('x-correlation-id') || req.header('X-Correlation-ID') || uuidv4();
  req.correlationId = correlationId;
  res.setHeader('X-Correlation-ID', correlationId);
  next();
}

module.exports = correlationIdMiddleware;
