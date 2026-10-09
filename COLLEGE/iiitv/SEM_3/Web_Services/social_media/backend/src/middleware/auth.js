const jwt = require('jsonwebtoken');
const config = require('../config/env');
const { staticUsers } = require('../data/staticData');

/**
 * Generates a signed JWT token for a user
 */
function generateToken(user) {
  return jwt.sign(
    {
      userId: user.id,
      username: user.username,
      role: user.role || 'user'
    },
    config.jwtSecret,
    { expiresIn: '7d' }
  );
}

/**
 * JWT Authentication middleware
 * Validates 'Authorization: Bearer <token>' header
 */
function authenticateJWT(req, res, next) {
  const authHeader = req.header('authorization') || req.header('Authorization');

  if (!authHeader || !authHeader.startsWith('Bearer ')) {
    return res.status(401).json({
      error: {
        code: 'UNAUTHORIZED',
        message: 'Access denied. Bearer token missing in Authorization header.',
        timestamp: new Date().toISOString(),
        correlationId: req.correlationId || 'unknown'
      }
    });
  }

  const token = authHeader.substring(7).trim();

  try {
    const decoded = jwt.verify(token, config.jwtSecret);
    const user = staticUsers.find(u => u.id === decoded.userId);

    if (!user) {
      return res.status(401).json({
        error: {
          code: 'USER_NOT_FOUND',
          message: 'The token subject is no longer active.',
          timestamp: new Date().toISOString(),
          correlationId: req.correlationId || 'unknown'
        }
      });
    }

    req.user = user;
    req.jwtPayload = decoded;
    next();
  } catch (err) {
    return res.status(401).json({
      error: {
        code: 'INVALID_TOKEN',
        message: 'Provided JWT token is invalid or has expired.',
        details: err.message,
        timestamp: new Date().toISOString(),
        correlationId: req.correlationId || 'unknown'
      }
    });
  }
}

/**
 * Optional authentication middleware: attaches user if token present, proceeds otherwise
 */
function optionalAuth(req, res, next) {
  const authHeader = req.header('authorization') || req.header('Authorization');
  if (authHeader && authHeader.startsWith('Bearer ')) {
    const token = authHeader.substring(7).trim();
    try {
      const decoded = jwt.verify(token, config.jwtSecret);
      const user = staticUsers.find(u => u.id === decoded.userId);
      if (user) req.user = user;
    } catch {
      // Ignore token errors for optional auth
    }
  }
  next();
}

/**
 * Authorization role-guard middleware
 */
function requireRole(...allowedRoles) {
  return function roleMiddleware(req, res, next) {
    if (!req.user || !allowedRoles.includes(req.user.role)) {
      return res.status(403).json({
        error: {
          code: 'FORBIDDEN',
          message: 'You do not have sufficient permissions to access this resource.',
          details: { requiredRoles: allowedRoles, currentRole: req.user?.role || 'guest' },
          timestamp: new Date().toISOString(),
          correlationId: req.correlationId || 'unknown'
        }
      });
    }
    next();
  };
}

module.exports = {
  generateToken,
  authenticateJWT,
  optionalAuth,
  requireRole
};
