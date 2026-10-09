# NamoGram - Social Media Platform (MERN Stack REST Architecture)

A social media web platform inspired by Instagram, styled with a modern electric royal blue gradient and glassmorphism aesthetic (matching the "Fizzy" design reference), and compliant with the RESTful Web Services Checklist.

---

## 🌟 Visual Theme & Design System
- **Color Palette**: Electric Royal Blue (`#1d4ed8`), Cobalt Blue (`#2563eb`), Neon Sky Blue (`#38bdf8`), Deep Navy (`#091129`).
- **Glassmorphism**: Translucent frosted surfaces (`backdrop-filter: blur(28px)`), glowing borders, micro-animations.
- **Reference Elements**: Dynamic island, status badges, floating author pills (`@alaniewalker1`), event chips, and the floating frosted-glass navigation bar.
- **Static Data Mode**: Static seed data with no external database requirements.

---

## 📋 The Checklist & Architecture Mapping

### Module 2: RESTful Services
1. **Correct HTTP method for every operation**:
   - `GET /api/v1/posts` (Read list)
   - `GET /api/v1/posts/:id` (Read one)
   - `POST /api/v1/posts` (Create)
   - `PUT /api/v1/posts/:id` (Full replace)
   - `PATCH /api/v1/posts/:id` (Partial update)
   - `DELETE /api/v1/posts/:id` (Delete, 204 No Content)
   - `OPTIONS` & `HEAD` supported.
2. **At least eight distinct status codes**:
   - `200 OK`, `201 Created`, `204 No Content`, `304 Not Modified`, `400 Bad Request`, `401 Unauthorized`, `403 Forbidden`, `404 Not Found`, `409 Conflict`, `422 Unprocessable Entity`, `429 Too Many Requests`, `503 Service Unavailable`.
3. **One consistent error body, everywhere**:
   - Standard structure: `{ "error": { "code": "...", "message": "...", "details": ..., "timestamp": "...", "correlationId": "..." } }`.
4. **Idempotency key on a POST**:
   - `Idempotency-Key` header cached in memory; duplicate submissions return identical response with `Idempotent-Replay: true`.
5. **ETag and a working 304 response**:
   - Response hashing with `ETag` generation; conditional `If-None-Match` returns `304 Not Modified` with 0-byte body.
6. **Deliberate Cache-Control on every GET**:
   - `Cache-Control: public, max-age=60, stale-while-revalidate=30` configured deliberately via middleware.
7. **JSON Schema validation, using ajv**:
   - Ajv compiler validates payloads; violations return `422 Unprocessable Entity` with exact field error details.
8. **Content negotiation — JSON and XML**:
   - Inspects `Accept: application/json` vs `Accept: application/xml` and serializes responses dynamically.
9. **Resource-shaped URLs, no verbs**:
   - Clean URLs: `/api/v1/posts`, `/api/v1/posts/:id/comments`, `/api/v1/users/:id`.
10. **Versioning under /v1**:
    - All routes mounted strictly under `/api/v1/`.
11. **Cursor pagination with a next link**:
    - Keyset cursor pagination returning `data`, `pagination: { nextCursor, hasMore }`, and RFC-compliant `links: { self, next }`.
12. **Rate-limit headers and a 429**:
    - Headers `X-RateLimit-Limit`, `X-RateLimit-Remaining`, `X-RateLimit-Reset`; returns `429 Too Many Requests` when exceeded.

### Modules 1, 3, 4 & Laboratory Requirements
13. **A hand-written OpenAPI document**:
    - Complete OpenAPI 3.0.3 spec located at `backend/src/docs/openapi.yaml`.
14. **Swagger UI served from your own service**:
    - Interactive Swagger UI served at `http://localhost:5005/api-docs`.
15. **Reading a WSDL, and one SOAP call**:
    - WSDL served at `http://localhost:5005/soap/weather?wsdl`; SOAP client builds envelope and makes request to query city weather.
16. **A GraphQL endpoint alongside the REST one**:
    - GraphQL server running at `http://localhost:5005/graphql`.
17. **Timeout on every outbound call**:
    - Outbound fetch helper configured with `AbortSignal.timeout(ms)`.
18. **Retry with increasing backoff**:
    - Outbound wrapper with exponential backoff (`base * 2^attempt + jitter`).
19. **A circuit breaker**:
    - State machine (`CLOSED`, `OPEN`, `HALF_OPEN`) tracking failure threshold with automatic fallback.
20. **Express middleware and central error handling**:
    - Central error handler capturing `AppError` instances and uncaught exceptions.
21. **Structured logging with a correlation id**:
    - Structured JSON logs with unique `x-correlation-id` attached to every request.
22. **A SQL database, with parameterised queries**:
    - Static in-memory parameterized query engine (`SELECT * FROM users WHERE username = ?`).
23. **A NoSQL document store**:
    - Static in-memory MongoDB-like collection document store (`find()`, `findOne()`, `insertOne()`).
24. **JWT authentication and authorisation**:
    - `/api/v1/auth/login`, signed JWT tokens, bearer token verification, and role-based access control.
25. **CORS configured deliberately**:
    - Explicitly configured origins, allowed methods, and exposed headers.
26. **Automated tests with Jest and supertest**:
    - Complete automated test suite: `npm test` runs 21 passing tests covering all checklist requirements.
27. **Docker, and twelve-factor configuration**:
    - `Dockerfile`, `docker-compose.yml`, and `.env.example` following 12-factor principles.

---

## 🚀 Getting Started

### 1. Install Dependencies
```bash
npm run install:all
```

### 2. Run Automated Tests
```bash
npm test
```

### 3. Run Locally (Concurrent Backend + Frontend)
```bash
npm run dev
```
- **Frontend App**: `http://localhost:5173`
- **Backend API**: `http://localhost:5005`
- **Swagger Documentation**: `http://localhost:5005/api-docs`
- **GraphQL Endpoint**: `http://localhost:5005/graphql`
- **SOAP Service WSDL**: `http://localhost:5005/soap/weather?wsdl`

---

## 🔍 Live Architecture Inspector
Click the sparkling blue **Inspector** button at the top of the app to open the slide-out verification drawer. You can run one-click tests for:
- 304 ETag response
- XML vs JSON content negotiation
- 429 Rate limiting
- Ajv schema validation (422)
- Idempotency-Key replay
- 8+ distinct status codes
- Live GraphQL queries
- Live SOAP 1.1 WSDL calls
- Circuit Breaker failure tripping and recovery
