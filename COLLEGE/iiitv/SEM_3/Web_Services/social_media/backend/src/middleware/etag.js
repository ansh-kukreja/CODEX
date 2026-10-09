const crypto = require('crypto');

/**
 * Computes an ETag for a string or buffer
 */
function generateETag(body) {
  const hash = crypto.createHash('sha1').update(body).digest('base64').substring(0, 27);
  return `"${hash}"`;
}

/**
 * ETag and 304 Not Modified middleware
 * Intercepts res.send/res.json to generate ETag and handle conditional requests
 */
function etagMiddleware(req, res, next) {
  const originalSend = res.send.bind(res);

  res.send = function (body) {
    // Only apply conditional ETag checking for GET and HEAD
    if ((req.method === 'GET' || req.method === 'HEAD') && res.statusCode >= 200 && res.statusCode < 300) {
      if (typeof body === 'object' && body !== null && !Buffer.isBuffer(body)) {
        body = JSON.stringify(body);
      }

      if (body) {
        const etag = generateETag(body);
        res.setHeader('ETag', etag);

        const clientEtag = req.header('if-none-match') || req.header('If-None-Match');
        if (clientEtag) {
          // Check match (handling quotes or weak tags)
          const cleanClient = clientEtag.replace(/^W\//, '').trim();
          const cleanServer = etag.replace(/^W\//, '').trim();

          if (cleanClient === cleanServer || cleanClient === '*') {
            res.statusCode = 304;
            res.removeHeader('Content-Type');
            res.removeHeader('Content-Length');
            return res.end();
          }
        }
      }
    }

    return originalSend(body);
  };

  next();
}

module.exports = etagMiddleware;
