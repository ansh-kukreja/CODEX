const app = require('./app');
const config = require('./config/env');

const server = app.listen(config.port, () => {
  console.log(`🚀 NamoGram API server running on http://localhost:${config.port}`);
  console.log(`📖 Swagger UI Documentation: http://localhost:${config.port}/api-docs`);
  console.log(`⚡ GraphQL Endpoint: http://localhost:${config.port}/graphql`);
  console.log(`🧼 SOAP WSDL: http://localhost:${config.port}/soap/weather?wsdl`);
});

// Graceful shutdown handling
process.on('SIGTERM', () => {
  console.log('SIGTERM signal received. Closing NamoGram HTTP server...');
  server.close(() => {
    console.log('HTTP server closed.');
    process.exit(0);
  });
});

process.on('SIGINT', () => {
  console.log('SIGINT signal received. Closing NamoGram HTTP server...');
  server.close(() => {
    console.log('HTTP server closed.');
    process.exit(0);
  });
});
