const express = require('express');
const path = require('path');
const swaggerUi = require('swagger-ui-express');
const YAML = require('yamljs');
const { createHandler } = require('graphql-http/lib/use/express');

// Middleware imports
const correlationIdMiddleware = require('./middleware/correlationId');
const structuredLogger = require('./middleware/logger');
const deliberateCors = require('./middleware/cors');
const etagMiddleware = require('./middleware/etag');
const contentNegotiationMiddleware = require('./middleware/contentNegotiation');
const idempotencyMiddleware = require('./middleware/idempotency');
const { globalRateLimiter } = require('./middleware/rateLimiter');
const { notFoundHandler, centralErrorHandler } = require('./middleware/errorHandler');

// GraphQL imports
const { schema } = require('./graphql/schema');
const resolvers = require('./graphql/resolvers');

// SOAP imports
const { WEATHER_WSDL, handleSoapRequest } = require('./services/soapService');

// Route imports
const authRoutes = require('./routes/v1/authRoutes');
const postRoutes = require('./routes/v1/postRoutes');
const userRoutes = require('./routes/v1/userRoutes');
const servicesRoutes = require('./routes/v1/servicesRoutes');
const { staticStories } = require('./data/staticData');
const { publicCache } = require('./middleware/cacheControl');

const app = express();

// 1. Correlation ID for structured request tracking
app.use(correlationIdMiddleware);

// 2. Structured JSON logging
app.use(structuredLogger);

// 3. Deliberate CORS configuration
app.use(deliberateCors);

// 4. Body parsers: JSON and XML/Text for SOAP
app.use(express.json({ limit: '5mb' }));
app.use(express.text({ type: ['text/xml', 'application/xml', 'application/soap+xml'], limit: '5mb' }));
app.use(express.urlencoded({ extended: true }));

// 5. REST protocol middlewares
app.use(etagMiddleware);
app.use(contentNegotiationMiddleware);
app.use(idempotencyMiddleware);

// 6. Global Rate Limiter for all API routes
app.use('/api/', globalRateLimiter);

// 7. OpenAPI Document & Swagger UI served from service
const openApiDocument = YAML.load(path.join(__dirname, 'docs/openapi.yaml'));
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(openApiDocument, {
  customSiteTitle: 'NamoGram API Documentation',
  customCss: '.swagger-ui .topbar { background-color: #1e3a8a; }'
}));
app.get('/api-docs.json', (req, res) => res.json(openApiDocument));

// 8. SOAP Service & WSDL Endpoint
app.all('/soap/weather', (req, res) => {
  if (req.query.wsdl !== undefined || req.query.WSDL !== undefined) {
    res.set('Content-Type', 'text/xml; charset=utf-8');
    return res.send(WEATHER_WSDL);
  }
  if (req.method === 'POST') {
    return handleSoapRequest(req, res);
  }
  return res.status(405).send('Use POST to submit SOAP Envelope, or append ?wsdl to inspect service definition.');
});

// 9. GraphQL endpoint alongside REST
app.all('/graphql', createHandler({
  schema,
  rootValue: resolvers,
  context: (req) => ({
    correlationId: req.raw.correlationId
  })
}));

// 10. REST API v1 Routes
app.use('/api/v1/auth', authRoutes);
app.use('/api/v1/posts', postRoutes);
app.use('/api/v1/users', userRoutes);
app.use('/api/v1/services', servicesRoutes);

// Stories route
app.get('/api/v1/stories', publicCache, (req, res) => {
  return res.status(200).sendNegotiated({
    count: staticStories.length,
    data: staticStories
  }, 'storiesList');
});

// Root welcome & API index
app.get('/', (req, res) => {
  return res.status(200).sendNegotiated({
    name: 'NamoGram Web Services API',
    version: 'v1.0.0',
    description: 'Instagram-like social media platform adhering to RESTful service design guidelines',
    theme: 'Electric Royal Blue Gradient & Glassmorphism',
    endpoints: {
      swaggerDocs: '/api-docs',
      openApiSpec: '/api-docs.json',
      graphQLEndpoint: '/graphql',
      soapWsdl: '/soap/weather?wsdl',
      restApiV1: '/api/v1/posts'
    },
    checklistCoverage: [
      'Correct HTTP methods (GET, POST, PUT, PATCH, DELETE, OPTIONS, HEAD)',
      'At least eight distinct status codes (200, 201, 204, 304, 400, 401, 403, 404, 409, 422, 429, 503)',
      'One consistent error body, everywhere',
      'Idempotency key on a POST',
      'ETag and a working 304 response',
      'Deliberate Cache-Control on every GET',
      'JSON Schema validation, using ajv',
      'Content negotiation — JSON and XML',
      'Resource-shaped URLs, no verbs',
      'Versioning under /v1',
      'Cursor pagination with a next link',
      'Rate-limit headers and a 429',
      'Hand-written OpenAPI document',
      'Swagger UI served from own service',
      'Reading a WSDL, and one SOAP call',
      'GraphQL endpoint alongside REST',
      'Timeout on outbound calls',
      'Retry with increasing backoff',
      'Circuit breaker pattern',
      'Structured logging with correlation ID',
      'In-memory parameterized SQL & NoSQL query engines (static data)',
      'JWT authentication & authorization'
    ]
  }, 'apiIndex');
});

// 11. 404 and Centralized Error Handling
app.use(notFoundHandler);
app.use(centralErrorHandler);

module.exports = app;
