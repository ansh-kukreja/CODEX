/**
 * Structured JSON Logger with correlation ID
 * Outputs machine-parseable JSON logs adhering to 12-factor logging principles
 */
function structuredLogger(req, res, next) {
  const startTime = Date.now();

  res.on('finish', () => {
    const durationMs = Date.now() - startTime;
    const logEntry = {
      timestamp: new Date().toISOString(),
      correlationId: req.correlationId || 'unknown',
      method: req.method,
      url: req.originalUrl || req.url,
      statusCode: res.statusCode,
      durationMs,
      userAgent: req.get('user-agent') || 'none',
      ip: req.ip || req.connection.remoteAddress
    };

    if (process.env.NODE_ENV !== 'test') {
      console.log(JSON.stringify(logEntry));
    }
  });

  next();
}

module.exports = structuredLogger;
