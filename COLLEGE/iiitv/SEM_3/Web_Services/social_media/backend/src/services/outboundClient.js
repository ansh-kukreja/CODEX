/**
 * Outbound HTTP client helper with mandatory timeout and exponential backoff retry
 * Satisfies:
 * - "Timeout on every outbound call"
 * - "Retry with increasing backoff"
 */

/**
 * Executes an async function with exponential backoff and jitter
 * @param {Function} operation - Async function returning a promise
 * @param {Object} options
 * @param {number} options.maxRetries - Maximum number of retries (default 3)
 * @param {number} options.baseDelayMs - Base delay in ms (default 300ms)
 * @param {number} options.maxDelayMs - Max delay ceiling (default 3000ms)
 */
async function retryWithBackoff(operation, options = {}) {
  const maxRetries = options.maxRetries || 3;
  const baseDelayMs = options.baseDelayMs || 300;
  const maxDelayMs = options.maxDelayMs || 3000;
  const retryLog = [];

  let attempt = 0;
  while (true) {
    attempt++;
    const startTime = Date.now();
    try {
      const result = await operation(attempt);
      return {
        success: true,
        attempts: attempt,
        data: result,
        retryLog
      };
    } catch (err) {
      const duration = Date.now() - startTime;
      retryLog.push({
        attempt,
        error: err.message,
        durationMs: duration
      });

      if (attempt >= maxRetries) {
        throw new Error(`Outbound operation failed after ${attempt} attempts. Last error: ${err.message}`);
      }

      // Exponential backoff: base * 2^(attempt - 1) + jitter
      const exponentialDelay = baseDelayMs * Math.pow(2, attempt - 1);
      const jitter = Math.random() * 100;
      const delay = Math.min(maxDelayMs, exponentialDelay + jitter);

      await new Promise(resolve => setTimeout(resolve, delay));
    }
  }
}

/**
 * Outbound fetch call with enforced timeout
 * @param {string} url
 * @param {Object} options
 * @param {number} options.timeoutMs - Timeout limit (default 3000ms)
 */
async function fetchWithTimeout(url, options = {}) {
  const timeoutMs = options.timeoutMs || 3000;
  const controller = new AbortController();
  const timeoutId = setTimeout(() => controller.abort(), timeoutMs);

  try {
    const response = await fetch(url, {
      ...options,
      signal: controller.signal
    });
    return response;
  } catch (err) {
    if (err.name === 'AbortError') {
      throw new Error(`Outbound call to ${url} timed out after ${timeoutMs}ms`);
    }
    throw err;
  } finally {
    clearTimeout(timeoutId);
  }
}

module.exports = {
  retryWithBackoff,
  fetchWithTimeout
};
