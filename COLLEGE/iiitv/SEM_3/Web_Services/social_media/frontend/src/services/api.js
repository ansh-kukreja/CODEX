// API service for NamoGram frontend interacting with REST, GraphQL, and SOAP backend

const API_BASE = '/api/v1';

export async function fetchPosts({ cursor = null, limit = 5, tag = null, search = null } = {}) {
  const params = new URLSearchParams();
  if (cursor) params.append('cursor', cursor);
  if (limit) params.append('limit', limit);
  if (tag) params.append('tag', tag);
  if (search) params.append('search', search);

  const res = await fetch(`${API_BASE}/posts?${params.toString()}`, {
    headers: { 'Accept': 'application/json' }
  });
  const data = await res.json();
  return {
    data: data.data || [],
    pagination: data.pagination || {},
    links: data.links || {},
    status: res.status,
    headers: {
      etag: res.headers.get('etag'),
      cacheControl: res.headers.get('cache-control'),
      rateLimitRemaining: res.headers.get('x-ratelimit-remaining'),
      correlationId: res.headers.get('x-correlation-id')
    }
  };
}

export async function fetchPostById(id, ifNoneMatch = null) {
  const headers = { 'Accept': 'application/json' };
  if (ifNoneMatch) {
    headers['If-None-Match'] = ifNoneMatch;
  }

  const res = await fetch(`${API_BASE}/posts/${id}`, { headers });
  if (res.status === 304) {
    return { status: 304, notModified: true };
  }
  const data = await res.json();
  return {
    status: res.status,
    data,
    headers: {
      etag: res.headers.get('etag'),
      cacheControl: res.headers.get('cache-control')
    }
  };
}

export async function createPost(postData, idempotencyKey = null) {
  const headers = {
    'Content-Type': 'application/json',
    'Accept': 'application/json'
  };
  if (idempotencyKey) {
    headers['Idempotency-Key'] = idempotencyKey;
  }

  const res = await fetch(`${API_BASE}/posts`, {
    method: 'POST',
    headers,
    body: JSON.stringify(postData)
  });

  const data = await res.json();
  return {
    status: res.status,
    data,
    headers: {
      location: res.headers.get('location'),
      idempotentReplay: res.headers.get('idempotent-replay'),
      correlationId: res.headers.get('x-correlation-id')
    }
  };
}

export async function toggleLike(postId) {
  const res = await fetch(`${API_BASE}/posts/${postId}/likes`, {
    method: 'POST',
    headers: { 'Accept': 'application/json' }
  });
  return res.json();
}

export async function fetchComments(postId) {
  const res = await fetch(`${API_BASE}/posts/${postId}/comments`, {
    headers: { 'Accept': 'application/json' }
  });
  return res.json();
}

export async function addComment(postId, content) {
  const res = await fetch(`${API_BASE}/posts/${postId}/comments`, {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Accept': 'application/json'
    },
    body: JSON.stringify({ content })
  });
  return res.json();
}

export async function fetchStories() {
  const res = await fetch(`${API_BASE}/stories`);
  return res.json();
}

export async function fetchUserProfile(userId) {
  const res = await fetch(`${API_BASE}/users/${userId}`);
  return res.json();
}

// Service & Architecture Checklist API calls for live inspector
export async function executeSoapCall(city = 'Boston') {
  const res = await fetch(`${API_BASE}/services/soap-call?city=${encodeURIComponent(city)}`);
  return res.json();
}

export async function executeGraphQL(query) {
  const res = await fetch('/graphql', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ query })
  });
  return res.json();
}

export async function testCircuitBreaker(shouldFail = false) {
  const res = await fetch(`${API_BASE}/services/circuit-breaker?fail=${shouldFail}`);
  const data = await res.json();
  return { status: res.status, data };
}

export async function resetCircuitBreaker() {
  const res = await fetch(`${API_BASE}/services/circuit-breaker/reset`, { method: 'POST' });
  return res.json();
}

export async function testRetryDemo(failTimes = 2) {
  const res = await fetch(`${API_BASE}/services/retry-demo?failTimes=${failTimes}`);
  return res.json();
}

export async function testRateLimit() {
  const res = await fetch(`${API_BASE}/services/rate-limit-test`);
  const data = await res.json();
  return {
    status: res.status,
    data,
    headers: {
      limit: res.headers.get('x-ratelimit-limit'),
      remaining: res.headers.get('x-ratelimit-remaining'),
      reset: res.headers.get('x-ratelimit-reset'),
      retryAfter: res.headers.get('retry-after')
    }
  };
}

export async function testStatusCode(code) {
  const res = await fetch(`${API_BASE}/services/status-codes/${code}`);
  let body;
  try {
    body = await res.json();
  } catch {
    body = await res.text();
  }
  return { status: res.status, body };
}

export async function testContentNegotiation(format = 'json') {
  const acceptHeader = format === 'xml' ? 'application/xml' : 'application/json';
  const res = await fetch(`${API_BASE}/posts/post_1`, {
    headers: { 'Accept': acceptHeader }
  });
  const text = await res.text();
  return {
    status: res.status,
    contentType: res.headers.get('content-type'),
    payload: text
  };
}

export async function testSqlQuery(sql, params) {
  const res = await fetch(`${API_BASE}/services/sql-query`, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ sql, params })
  });
  return res.json();
}
