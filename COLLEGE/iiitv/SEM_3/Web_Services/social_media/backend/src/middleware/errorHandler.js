/**
 * Custom application error class for structured REST errors
 */
class AppError extends Error {
  constructor(message, statusCode = 500, code = 'INTERNAL_SERVER_ERROR', details = null) {
    super(message);
    this.statusCode = statusCode;
    this.code = code;
    this.details = details;
    Error.captureStackTrace(this, this.constructor);
  }
}

/**
 * 404 Route Not Found handler
 */
function notFoundHandler(req, res, next) {
  res.status(404).json({
    error: {
      code: 'ROUTE_NOT_FOUND',
      message: `Cannot ${req.method} ${req.originalUrl || req.url}`,
      details: null,
      timestamp: new Date().toISOString(),
      correlationId: req.correlationId || 'unknown'
    }
  });
}

/**
 * Central Express error handling middleware
 * Enforces one consistent error body across the entire application
 */
function centralErrorHandler(err, req, res, next) {
  const statusCode = err.statusCode || 500;
  const errorCode = err.code || (statusCode === 500 ? 'INTERNAL_SERVER_ERROR' : 'BAD_REQUEST');

  const errorResponse = {
    error: {
      code: errorCode,
      message: err.message || 'An unexpected error occurred.',
      details: err.details || null,
      timestamp: new Date().toISOString(),
      correlationId: req.correlationId || 'unknown'
    }
  };

  if (process.env.NODE_ENV !== 'production' && statusCode === 500) {
    errorResponse.error.stack = err.stack;
  }

  res.status(statusCode).json(errorResponse);
}

module.exports = {
  AppError,
  notFoundHandler,
  centralErrorHandler
};
