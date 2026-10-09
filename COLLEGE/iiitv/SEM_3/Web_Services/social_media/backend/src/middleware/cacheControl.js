const config = require('../config/env');

/**
 * Middleware factory to inject deliberate Cache-Control directives
 * @param {string} directive
 */
function setCacheControl(directive) {
  return function cacheControlMiddleware(req, res, next) {
    if (req.method === 'GET' || req.method === 'HEAD') {
      const value = directive || `public, max-age=${config.cacheMaxAgeSeconds}, stale-while-revalidate=30`;
      res.setHeader('Cache-Control', value);
    } else {
      res.setHeader('Cache-Control', 'no-store');
    }
    next();
  };
}

module.exports = {
  publicCache: setCacheControl(`public, max-age=${config.cacheMaxAgeSeconds}, stale-while-revalidate=30`),
  privateCache: setCacheControl('private, no-cache, no-store, must-revalidate'),
  noStore: setCacheControl('no-store'),
  customCache: setCacheControl
};
