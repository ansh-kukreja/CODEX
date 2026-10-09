const Ajv = require('ajv');
const addFormats = require('ajv-formats');

const ajv = new Ajv({ allErrors: true, coerceTypes: true, removeAdditional: false });
addFormats(ajv);

/**
 * Middleware factory for validating request body or query against an Ajv JSON Schema
 * Returns 422 Unprocessable Entity with details if validation fails
 */
function validateSchema(schema, target = 'body') {
  const validate = ajv.compile(schema);

  return function schemaValidationMiddleware(req, res, next) {
    const data = req[target];
    const valid = validate(data);

    if (!valid) {
      const errorDetails = validate.errors.map(err => ({
        field: err.instancePath.replace(/^\//, '') || err.params?.missingProperty || 'root',
        message: err.message,
        rule: err.keyword,
        params: err.params
      }));

      return res.status(422).json({
        error: {
          code: 'VALIDATION_ERROR',
          message: 'Request payload failed JSON schema validation.',
          details: errorDetails,
          timestamp: new Date().toISOString(),
          correlationId: req.correlationId || 'unknown'
        }
      });
    }

    next();
  };
}

module.exports = {
  ajv,
  validateSchema
};
