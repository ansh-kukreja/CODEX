const request = require('supertest');
const app = require('../src/app');

describe('NamoGram RESTful Web Services Test Suite', () => {

  describe('Module 2 Checklist: Status Codes & Error Bodies', () => {
    test('1. Returns 200 OK for GET /api/v1/posts', async () => {
      const res = await request(app).get('/api/v1/posts');
      expect(res.status).toBe(200);
      expect(res.body).toHaveProperty('data');
      expect(Array.isArray(res.body.data)).toBe(true);
    });

    test('2. Returns 201 Created for POST /api/v1/posts with Location header', async () => {
      const newPost = {
        caption: 'Automated test concert post! #test',
        imageUrl: 'https://images.unsplash.com/photo-1514525253161-7a46d19cd819?w=1080',
        location: 'Boston, MA',
        tags: ['test', 'music']
      };

      const res = await request(app)
        .post('/api/v1/posts')
        .send(newPost);

      expect(res.status).toBe(201);
      expect(res.headers).toHaveProperty('location');
      expect(res.body.caption).toBe(newPost.caption);
    });

    test('3. Returns 204 No Content for DELETE /api/v1/posts/:id', async () => {
      // Create a dummy post first
      const createRes = await request(app)
        .post('/api/v1/posts')
        .send({
          caption: 'To be deleted',
          imageUrl: 'https://images.unsplash.com/photo-1514525253161-7a46d19cd819?w=1080'
        });

      const postId = createRes.body.id;
      const delRes = await request(app).delete(`/api/v1/posts/${postId}`);
      expect(delRes.status).toBe(204);
      expect(delRes.text).toBe('');
    });

    test('4. Returns 400 Bad Request for invalid query parameters', async () => {
      const res = await request(app).get('/api/v1/posts?limit=-5');
      expect(res.status).toBe(400);
      expect(res.body.error).toBeDefined();
      expect(res.body.error.code).toBe('INVALID_LIMIT');
      expect(res.body.error).toHaveProperty('correlationId');
      expect(res.body.error).toHaveProperty('timestamp');
    });

    test('5. Returns 401 Unauthorized when accessing protected route without JWT', async () => {
      const res = await request(app).get('/api/v1/auth/me');
      expect(res.status).toBe(401);
      expect(res.body.error.code).toBe('UNAUTHORIZED');
      expect(res.body.error).toHaveProperty('correlationId');
    });

    test('6. Returns 404 Not Found for non-existent post', async () => {
      const res = await request(app).get('/api/v1/posts/non_existent_id_999');
      expect(res.status).toBe(404);
      expect(res.body.error.code).toBe('POST_NOT_FOUND');
    });

    test('7. Returns 422 Unprocessable Entity for schema validation failure', async () => {
      // Missing required imageUrl
      const invalidPost = {
        caption: 'Missing image field'
      };

      const res = await request(app)
        .post('/api/v1/posts')
        .send(invalidPost);

      expect(res.status).toBe(422);
      expect(res.body.error.code).toBe('VALIDATION_ERROR');
      expect(Array.isArray(res.body.error.details)).toBe(true);
    });

    test('8. Consistent error body schema everywhere', async () => {
      const res = await request(app).get('/api/v1/non-existent-resource-xyz');
      expect(res.status).toBe(404);
      expect(res.body).toHaveProperty('error');
      expect(res.body.error).toHaveProperty('code');
      expect(res.body.error).toHaveProperty('message');
      expect(res.body.error).toHaveProperty('timestamp');
      expect(res.body.error).toHaveProperty('correlationId');
    });
  });

  describe('Module 2 Checklist: ETag & 304 Conditional Response', () => {
    test('Returns ETag header and 304 Not Modified when If-None-Match matches', async () => {
      // Step 1: Initial GET
      const initialRes = await request(app).get('/api/v1/posts/post_1');
      expect(initialRes.status).toBe(200);
      const etag = initialRes.headers['etag'];
      expect(etag).toBeDefined();

      // Step 2: Conditional GET with If-None-Match
      const conditionalRes = await request(app)
        .get('/api/v1/posts/post_1')
        .set('If-None-Match', etag);

      expect(conditionalRes.status).toBe(304);
      expect(conditionalRes.text).toBe('');
    });
  });

  describe('Module 2 Checklist: Deliberate Cache-Control', () => {
    test('Deliberate Cache-Control header is present on GET /api/v1/posts', async () => {
      const res = await request(app).get('/api/v1/posts');
      expect(res.headers['cache-control']).toBeDefined();
      expect(res.headers['cache-control']).toContain('public');
      expect(res.headers['cache-control']).toContain('max-age=');
    });
  });

  describe('Module 2 Checklist: Idempotency Key on POST', () => {
    test('Returns identical response and Idempotent-Replay header for duplicate key', async () => {
      const idempotencyKey = `idemp_test_${Date.now()}`;
      const payload = {
        caption: 'Idempotency test post',
        imageUrl: 'https://images.unsplash.com/photo-1514525253161-7a46d19cd819?w=1080'
      };

      // First call
      const firstRes = await request(app)
        .post('/api/v1/posts')
        .set('Idempotency-Key', idempotencyKey)
        .send(payload);

      expect(firstRes.status).toBe(201);
      const createdId = firstRes.body.id;

      // Second call with same idempotency key
      const secondRes = await request(app)
        .post('/api/v1/posts')
        .set('Idempotency-Key', idempotencyKey)
        .send(payload);

      expect(secondRes.status).toBe(201);
      expect(secondRes.headers['idempotent-replay']).toBe('true');
      expect(secondRes.body.id).toBe(createdId);
    });
  });

  describe('Module 2 Checklist: Content Negotiation (JSON & XML)', () => {
    test('Returns XML when Accept: application/xml is requested', async () => {
      const res = await request(app)
        .get('/api/v1/posts/post_1')
        .set('Accept', 'application/xml');

      expect(res.status).toBe(200);
      expect(res.headers['content-type']).toContain('application/xml');
      expect(res.text).toContain('<?xml');
      expect(res.text).toContain('<postDetail>');
    });

    test('Returns JSON by default or when Accept: application/json', async () => {
      const res = await request(app)
        .get('/api/v1/posts/post_1')
        .set('Accept', 'application/json');

      expect(res.status).toBe(200);
      expect(res.headers['content-type']).toContain('application/json');
      expect(res.body.id).toBe('post_1');
    });
  });

  describe('Module 2 Checklist: Cursor Pagination with Next Link', () => {
    test('Provides cursor pagination with next link', async () => {
      const res = await request(app).get('/api/v1/posts?limit=2');
      expect(res.status).toBe(200);
      expect(res.body.pagination).toBeDefined();
      expect(res.body.pagination.limit).toBe(2);
      expect(res.body.links).toBeDefined();
      expect(res.body.links.next).toBeDefined();
      expect(res.body.links.next).toContain('cursor=');
    });
  });

  describe('Module 2 Checklist: Rate Limit Headers & 429', () => {
    test('Sets X-RateLimit headers on responses', async () => {
      const res = await request(app).get('/api/v1/posts');
      expect(res.headers['x-ratelimit-limit']).toBeDefined();
      expect(res.headers['x-ratelimit-remaining']).toBeDefined();
      expect(res.headers['x-ratelimit-reset']).toBeDefined();
    });

    test('Returns 429 Too Many Requests when strict rate limit is exceeded', async () => {
      // Fire requests past limit (limit is 3 for rate-limit-test)
      await request(app).get('/api/v1/services/rate-limit-test');
      await request(app).get('/api/v1/services/rate-limit-test');
      await request(app).get('/api/v1/services/rate-limit-test');
      const overflowRes = await request(app).get('/api/v1/services/rate-limit-test');

      expect(overflowRes.status).toBe(429);
      expect(overflowRes.body.error.code).toBe('RATE_LIMIT_EXCEEDED');
      expect(overflowRes.headers['retry-after']).toBeDefined();
    });
  });

  describe('Modules 1, 3, 4: Advanced Services (SOAP, GraphQL, OpenAPI)', () => {
    test('Serves WSDL document at /soap/weather?wsdl', async () => {
      const res = await request(app).get('/soap/weather?wsdl');
      expect(res.status).toBe(200);
      expect(res.text).toContain('<definitions');
      expect(res.text).toContain('NamoGramWeatherService');
    });

    test('Executes SOAP request via /api/v1/services/soap-call', async () => {
      const res = await request(app).get('/api/v1/services/soap-call?city=Boston');
      expect(res.status).toBe(200);
      expect(res.body.protocol).toBe('SOAP 1.1');
      expect(res.body.parsedData).toBeDefined();
      expect(res.body.parsedData.city).toBe('Boston');
    });

    test('Serves GraphQL endpoint at /graphql', async () => {
      const query = {
        query: `
          query {
            posts(limit: 2) {
              id
              caption
              likesCount
            }
          }
        `
      };

      const res = await request(app)
        .post('/graphql')
        .send(query);

      expect(res.status).toBe(200);
      expect(res.body.data.posts).toBeDefined();
      expect(res.body.data.posts.length).toBeLessThanOrEqual(2);
    });

    test('Serves Swagger UI at /api-docs and spec at /api-docs.json', async () => {
      const resDoc = await request(app).get('/api-docs/');
      expect(resDoc.status).toBe(200);

      const resJson = await request(app).get('/api-docs.json');
      expect(resJson.status).toBe(200);
      expect(resJson.body.info.title).toBe('NamoGram RESTful Web Services API');
    });

    test('Tests In-memory Parameterized SQL query execution', async () => {
      const res = await request(app)
        .post('/api/v1/services/sql-query')
        .send({
          sql: 'SELECT * FROM users WHERE username = ?',
          params: ['melanie_v']
        });

      expect(res.status).toBe(200);
      expect(res.body.parameterized).toBe(true);
      expect(res.body.rows.length).toBe(1);
      expect(res.body.rows[0].username).toBe('melanie_v');
    });
  });
});
