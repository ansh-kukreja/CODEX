const { create } = require('xmlbuilder2');

/**
 * Content negotiation middleware supporting JSON and XML based on Accept header
 */
function contentNegotiationMiddleware(req, res, next) {
  res.setHeader('Vary', 'Accept');

  // Helper method to respond in negotiated format
  res.sendNegotiated = function (data, rootName = 'response') {
    const acceptHeader = req.get('accept') || '';

    if (acceptHeader.includes('application/xml') || acceptHeader.includes('text/xml')) {
      res.type('application/xml');
      try {
        // Sanitize object keys for XML (e.g., arrays or special keys)
        const xmlString = create({ [rootName]: data }).end({ prettyPrint: true });
        return res.send(xmlString);
      } catch (err) {
        // Fallback to simple XML serialization if complex object
        const fallbackXml = `<${rootName}><error>XML Serialization Error</error><raw>${JSON.stringify(data)}</raw></${rootName}>`;
        return res.send(fallbackXml);
      }
    }

    // Default to JSON
    res.type('application/json');
    return res.json(data);
  };

  next();
}

module.exports = contentNegotiationMiddleware;
