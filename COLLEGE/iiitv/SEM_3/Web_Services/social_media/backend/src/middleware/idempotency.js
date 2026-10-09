// In-memory idempotency cache for POST requests
const idempotencyStore = new Map();

/**
 * Idempotency middleware for POST requests
 * Detects 'Idempotency-Key' header, caches responses, and replays cached results on duplicate requests
 */
function idempotencyMiddleware(req, res, next) {
  if (req.method !== 'POST') {
    return next();
  }

  const idempotencyKey = req.header('idempotency-key') || req.header('Idempotency-Key');
  if (!idempotencyKey) {
    return next();
  }

  // Check if response is already cached
  if (idempotencyStore.has(idempotencyKey)) {
    const cached = idempotencyStore.get(idempotencyKey);
    res.setHeader('Idempotent-Replay', 'true');
    res.setHeader('X-Idempotency-Key', idempotencyKey);
    return res.status(cached.status).json(cached.body);
  }

  // Intercept response to store result
  const originalJson = res.json.bind(res);
  res.json = function (body) {
    if (res.statusCode >= 200 && res.statusCode < 400) {
      idempotencyStore.set(idempotencyKey, {
        status: res.statusCode,
        body,
        timestamp: Date.now()
      });
      res.setHeader('X-Idempotency-Key', idempotencyKey);
    }
    return originalJson(body);
  };

  next();
}

module.exports = idempotencyMiddleware;
