const commentCreateSchema = {
  type: 'object',
  required: ['content'],
  additionalProperties: false,
  properties: {
    content: {
      type: 'string',
      minLength: 1,
      maxLength: 500
    }
  }
};

module.exports = {
  commentCreateSchema
};
