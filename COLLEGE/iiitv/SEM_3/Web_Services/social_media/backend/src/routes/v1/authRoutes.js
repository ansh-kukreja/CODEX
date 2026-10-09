const express = require('express');
const router = express.Router();
const { staticUsers } = require('../../data/staticData');
const { generateToken, authenticateJWT } = require('../../middleware/auth');
const { validateSchema } = require('../../middleware/validateSchema');
const { authLoginSchema } = require('../../schemas/authSchemas');
const { AppError } = require('../../middleware/errorHandler');

/**
 * POST /api/v1/auth/login
 * Authenticates user credentials and returns JWT token
 * Returns 200 OK or 401 Unauthorized
 */
router.post('/login', validateSchema(authLoginSchema), (req, res, next) => {
  const { username, password } = req.body;

  // In this static demonstration, check against static users
  // Password accepted for static users is 'password123' or any non-empty >= 4 chars for Melanie
  const user = staticUsers.find(u => u.username.toLowerCase() === username.toLowerCase());

  if (!user) {
    return next(new AppError('Invalid username or password credentials.', 401, 'INVALID_CREDENTIALS'));
  }

  // Example demonstration check: reject if password is wrong
  if (password !== 'password123' && password !== 'melanie123') {
    return next(new AppError('Invalid username or password credentials. Hint: use password123', 401, 'INVALID_CREDENTIALS'));
  }

  const token = generateToken(user);

  return res.status(200).sendNegotiated({
    message: 'Authentication successful',
    token,
    user: {
      id: user.id,
      username: user.username,
      name: user.name,
      avatar: user.avatar,
      role: user.role
    }
  }, 'authResponse');
});

/**
 * GET /api/v1/auth/me
 * Retrieves current authenticated user profile
 * Returns 200 OK or 401 Unauthorized
 */
router.get('/me', authenticateJWT, (req, res) => {
  return res.status(200).sendNegotiated({
    user: req.user
  }, 'userProfile');
});

module.exports = router;
