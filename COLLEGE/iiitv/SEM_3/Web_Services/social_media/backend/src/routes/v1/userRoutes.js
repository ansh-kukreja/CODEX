const express = require('express');
const router = express.Router();
const mockNoSqlDb = require('../../data/mockNoSqlDb');
const { staticStories } = require('../../data/staticData');
const { AppError } = require('../../middleware/errorHandler');
const { publicCache } = require('../../middleware/cacheControl');

/**
 * GET /api/v1/users
 * Returns list of users
 * Returns 200 OK
 */
router.get('/', publicCache, async (req, res) => {
  const users = await mockNoSqlDb.collection('users').find();
  return res.status(200).sendNegotiated({
    count: users.length,
    data: users
  }, 'usersList');
});

/**
 * GET /api/v1/users/:id
 * Retrieves specific user profile by ID or username
 * Returns 200 OK or 404 Not Found
 */
router.get('/:id', publicCache, async (req, res, next) => {
  const { id } = req.params;
  let user = await mockNoSqlDb.collection('users').findById(id);

  if (!user) {
    user = await mockNoSqlDb.collection('users').findOne({ username: id });
  }

  if (!user) {
    return next(new AppError(`User with identifier "${id}" does not exist.`, 404, 'USER_NOT_FOUND'));
  }

  return res.status(200).sendNegotiated(user, 'userProfile');
});

/**
 * GET /api/v1/users/:id/posts
 * Retrieves all posts authored by a user
 * Returns 200 OK or 404 Not Found
 */
router.get('/:id/posts', publicCache, async (req, res, next) => {
  const { id } = req.params;
  let user = await mockNoSqlDb.collection('users').findById(id);
  if (!user) {
    user = await mockNoSqlDb.collection('users').findOne({ username: id });
  }

  if (!user) {
    return next(new AppError(`User with identifier "${id}" does not exist.`, 404, 'USER_NOT_FOUND'));
  }

  const posts = await mockNoSqlDb.collection('posts').find();
  const userPosts = posts.filter(p => p.userId === user.id || p.author.username === user.username);

  return res.status(200).sendNegotiated({
    userId: user.id,
    username: user.username,
    count: userPosts.length,
    data: userPosts
  }, 'userPosts');
});

module.exports = router;
