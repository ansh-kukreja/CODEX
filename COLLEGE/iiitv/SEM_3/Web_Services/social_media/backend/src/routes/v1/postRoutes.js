const express = require('express');
const router = express.Router();
const mockNoSqlDb = require('../../data/mockNoSqlDb');
const { validateSchema } = require('../../middleware/validateSchema');
const { postCreateSchema, postUpdateSchema } = require('../../schemas/postSchemas');
const { commentCreateSchema } = require('../../schemas/commentSchemas');
const { optionalAuth, authenticateJWT } = require('../../middleware/auth');
const { AppError } = require('../../middleware/errorHandler');
const { publicCache } = require('../../middleware/cacheControl');

/**
 * GET /api/v1/posts
 * Cursor pagination with next link, content negotiation, and cache control
 * Returns 200 OK or 400 Bad Request
 */
router.get('/', publicCache, async (req, res, next) => {
  const limit = parseInt(req.query.limit, 10) || 5;
  const cursor = req.query.cursor;
  const tag = req.query.tag;
  const search = req.query.search;

  if (limit <= 0 || limit > 50 || isNaN(limit)) {
    return next(new AppError('Query parameter "limit" must be a positive integer between 1 and 50.', 400, 'INVALID_LIMIT'));
  }

  let posts = await mockNoSqlDb.collection('posts').find();

  // Optional tag filter
  if (tag) {
    posts = posts.filter(p => p.tags && p.tags.map(t => t.toLowerCase()).includes(tag.toLowerCase()));
  }

  // Optional search query
  if (search) {
    const s = search.toLowerCase();
    posts = posts.filter(p =>
      p.caption.toLowerCase().includes(s) ||
      (p.location && p.location.toLowerCase().includes(s)) ||
      p.author.name.toLowerCase().includes(s)
    );
  }

  // Cursor pagination logic (cursor is post id)
  let startIndex = 0;
  if (cursor) {
    const foundIndex = posts.findIndex(p => p.id === cursor);
    if (foundIndex === -1) {
      return next(new AppError(`Cursor "${cursor}" not found in current dataset.`, 400, 'INVALID_CURSOR'));
    }
    startIndex = foundIndex + 1;
  }

  const paginatedItems = posts.slice(startIndex, startIndex + limit);
  const nextItem = posts[startIndex + limit];
  const nextCursor = nextItem ? nextItem.id : null;
  const hasMore = Boolean(nextCursor);

  // Construct RFC-compliant navigation links
  const baseUrl = `${req.protocol}://${req.get('host')}/api/v1/posts`;
  const links = {
    self: `${baseUrl}?limit=${limit}${cursor ? `&cursor=${cursor}` : ''}${tag ? `&tag=${tag}` : ''}`
  };

  if (hasMore) {
    links.next = `${baseUrl}?limit=${limit}&cursor=${nextCursor}${tag ? `&tag=${tag}` : ''}`;
  }

  return res.status(200).sendNegotiated({
    data: paginatedItems,
    pagination: {
      limit,
      cursor: cursor || null,
      nextCursor,
      hasMore,
      count: paginatedItems.length,
      total: posts.length
    },
    links
  }, 'postsFeed');
});

/**
 * POST /api/v1/posts
 * Creates a new post with Ajv validation and Idempotency-Key support
 * Returns 201 Created or 422 Unprocessable Entity
 */
router.post('/', optionalAuth, validateSchema(postCreateSchema), async (req, res, next) => {
  const { caption, imageUrl, location, eventTime, capacity, timeRemaining, tags } = req.body;
  const currentUser = req.user || {
    id: 'usr_melanie',
    username: 'melanie_v',
    name: 'Melanie Vance',
    avatar: 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=300&h=300&fit=crop&crop=face',
    verified: true
  };

  const newPost = {
    id: `post_${Date.now()}`,
    userId: currentUser.id,
    author: {
      id: currentUser.id,
      username: currentUser.username,
      name: currentUser.name,
      avatar: currentUser.avatar,
      verified: currentUser.verified || false
    },
    caption,
    imageUrl,
    location: location || 'Boston, MA',
    eventTime: eventTime || 'Just now',
    capacity: capacity || 'Open',
    timeRemaining: timeRemaining || 'Active',
    likesCount: 0,
    commentsCount: 0,
    isLiked: false,
    isSaved: false,
    tags: tags || ['namogram'],
    createdAt: new Date().toISOString(),
    updatedAt: new Date().toISOString()
  };

  const result = await mockNoSqlDb.collection('posts').insertOne(newPost);

  // Set Location header as per REST standards
  res.setHeader('Location', `/api/v1/posts/${newPost.id}`);
  return res.status(201).sendNegotiated(result.document, 'post');
});

/**
 * GET /api/v1/posts/:id
 * Retrieves a single post by ID
 * Returns 200 OK or 404 Not Found
 */
router.get('/:id', publicCache, async (req, res, next) => {
  const post = await mockNoSqlDb.collection('posts').findById(req.params.id);

  if (!post) {
    return next(new AppError(`Post with id "${req.params.id}" was not found.`, 404, 'POST_NOT_FOUND'));
  }

  const comments = await mockNoSqlDb.collection('comments').find({ postId: post.id });

  return res.status(200).sendNegotiated({
    ...post,
    comments
  }, 'postDetail');
});

/**
 * PUT /api/v1/posts/:id
 * Full replacement/update of post
 * Returns 200 OK or 404 Not Found
 */
router.put('/:id', optionalAuth, validateSchema(postCreateSchema), async (req, res, next) => {
  const post = await mockNoSqlDb.collection('posts').findById(req.params.id);

  if (!post) {
    return next(new AppError(`Post with id "${req.params.id}" was not found for update.`, 404, 'POST_NOT_FOUND'));
  }

  const { caption, imageUrl, location, eventTime, capacity, timeRemaining, tags } = req.body;
  const updated = {
    ...post,
    caption,
    imageUrl,
    location: location || post.location,
    eventTime: eventTime || post.eventTime,
    capacity: capacity || post.capacity,
    timeRemaining: timeRemaining || post.timeRemaining,
    tags: tags || post.tags,
    updatedAt: new Date().toISOString()
  };

  await mockNoSqlDb.collection('posts').updateOne({ id: post.id }, updated);

  return res.status(200).sendNegotiated(updated, 'post');
});

/**
 * PATCH /api/v1/posts/:id
 * Partial update of post
 * Returns 200 OK, 404 Not Found, or 422 Unprocessable Entity
 */
router.patch('/:id', optionalAuth, validateSchema(postUpdateSchema), async (req, res, next) => {
  const post = await mockNoSqlDb.collection('posts').findById(req.params.id);

  if (!post) {
    return next(new AppError(`Post with id "${req.params.id}" was not found for patch.`, 404, 'POST_NOT_FOUND'));
  }

  const result = await mockNoSqlDb.collection('posts').updateOne({ id: post.id }, req.body);

  return res.status(200).sendNegotiated(result.document, 'post');
});

/**
 * DELETE /api/v1/posts/:id
 * Deletes a post
 * Returns 204 No Content or 404 Not Found
 */
router.delete('/:id', optionalAuth, async (req, res, next) => {
  const post = await mockNoSqlDb.collection('posts').findById(req.params.id);

  if (!post) {
    return next(new AppError(`Post with id "${req.params.id}" does not exist.`, 404, 'POST_NOT_FOUND'));
  }

  await mockNoSqlDb.collection('posts').deleteOne({ id: post.id });

  return res.status(204).end();
});

/**
 * GET /api/v1/posts/:id/comments
 * Retrieves all comments for a post
 * Returns 200 OK or 404 Not Found
 */
router.get('/:id/comments', publicCache, async (req, res, next) => {
  const post = await mockNoSqlDb.collection('posts').findById(req.params.id);

  if (!post) {
    return next(new AppError(`Post with id "${req.params.id}" does not exist.`, 404, 'POST_NOT_FOUND'));
  }

  const comments = await mockNoSqlDb.collection('comments').find({ postId: post.id });

  return res.status(200).sendNegotiated({
    postId: post.id,
    count: comments.length,
    comments
  }, 'postComments');
});

/**
 * POST /api/v1/posts/:id/comments
 * Adds a new comment to a post with Ajv validation
 * Returns 201 Created or 404 Not Found
 */
router.post('/:id/comments', optionalAuth, validateSchema(commentCreateSchema), async (req, res, next) => {
  const post = await mockNoSqlDb.collection('posts').findById(req.params.id);

  if (!post) {
    return next(new AppError(`Post with id "${req.params.id}" was not found to comment.`, 404, 'POST_NOT_FOUND'));
  }

  const currentUser = req.user || {
    id: 'usr_melanie',
    username: 'melanie_v',
    avatar: 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=300&h=300&fit=crop&crop=face'
  };

  const newComment = {
    id: `cmt_${Date.now()}`,
    postId: post.id,
    userId: currentUser.id,
    username: currentUser.username,
    avatar: currentUser.avatar,
    content: req.body.content,
    createdAt: new Date().toISOString()
  };

  await mockNoSqlDb.collection('comments').insertOne(newComment);
  post.commentsCount = (post.commentsCount || 0) + 1;

  res.setHeader('Location', `/api/v1/posts/${post.id}/comments/${newComment.id}`);
  return res.status(201).sendNegotiated(newComment, 'comment');
});

/**
 * POST /api/v1/posts/:id/likes
 * Toggles like status on a post
 * Returns 200 OK or 404 Not Found
 */
router.post('/:id/likes', optionalAuth, async (req, res, next) => {
  const post = await mockNoSqlDb.collection('posts').findById(req.params.id);

  if (!post) {
    return next(new AppError(`Post with id "${req.params.id}" does not exist.`, 404, 'POST_NOT_FOUND'));
  }

  const wasLiked = Boolean(post.isLiked);
  post.isLiked = !wasLiked;
  post.likesCount = Math.max(0, post.likesCount + (post.isLiked ? 1 : -1));

  return res.status(200).sendNegotiated({
    postId: post.id,
    isLiked: post.isLiked,
    likesCount: post.likesCount,
    message: post.isLiked ? 'Post liked' : 'Post unliked'
  }, 'likeStatus');
});

module.exports = router;
