/**
 * Circuit Breaker pattern implementation
 * States:
 * - CLOSED: Requests pass through normally. Tracks failures.
 * - OPEN: Immediately fails or invokes fallback without executing target function.
 * - HALF_OPEN: Sends a canary request to test downstream service health.
 */
class CircuitBreaker {
  constructor(options = {}) {
    this.name = options.name || 'default_breaker';
    this.failureThreshold = options.failureThreshold || 3;
    this.recoveryTimeMs = options.recoveryTimeMs || 5000;
    this.state = 'CLOSED'; // 'CLOSED', 'OPEN', 'HALF_OPEN'
    this.failureCount = 0;
    this.successCount = 0;
    this.lastFailureTime = null;
    this.nextAttemptTime = null;
  }

  async execute(action, fallback = null) {
    const now = Date.now();

    // Check if open state has expired
    if (this.state === 'OPEN') {
      if (now > this.nextAttemptTime) {
        this.state = 'HALF_OPEN';
      } else {
        if (fallback) {
          return {
            fallback: true,
            circuitBreakerState: 'OPEN',
            result: await fallback(new Error(`Circuit breaker '${this.name}' is OPEN. Fast-failing request.`))
          };
        }
        throw new Error(`Circuit breaker '${this.name}' is OPEN. Requests blocked until ${new Date(this.nextAttemptTime).toISOString()}`);
      }
    }

    try {
      const result = await action();
      this.onSuccess();
      return {
        fallback: false,
        circuitBreakerState: this.state,
        result
      };
    } catch (err) {
      this.onFailure();
      if (fallback) {
        return {
          fallback: true,
          circuitBreakerState: this.state,
          result: await fallback(err)
        };
      }
      throw err;
    }
  }

  onSuccess() {
    this.failureCount = 0;
    if (this.state === 'HALF_OPEN') {
      this.state = 'CLOSED';
    }
    this.successCount++;
  }

  onFailure() {
    this.failureCount++;
    this.lastFailureTime = Date.now();

    if (this.state === 'HALF_OPEN' || this.failureCount >= this.failureThreshold) {
      this.state = 'OPEN';
      this.nextAttemptTime = Date.now() + this.recoveryTimeMs;
    }
  }

  getStatus() {
    return {
      name: this.name,
      state: this.state,
      failureCount: this.failureCount,
      failureThreshold: this.failureThreshold,
      recoveryTimeMs: this.recoveryTimeMs,
      nextAttemptTime: this.nextAttemptTime ? new Date(this.nextAttemptTime).toISOString() : null
    };
  }

  reset() {
    this.state = 'CLOSED';
    this.failureCount = 0;
    this.nextAttemptTime = null;
  }
}

// Global instance for external weather/location service
const externalServiceBreaker = new CircuitBreaker({
  name: 'ExternalWeatherBreaker',
  failureThreshold: 3,
  recoveryTimeMs: 6000
});

module.exports = {
  CircuitBreaker,
  externalServiceBreaker
};
