const postCreateSchema = {
  type: 'object',
  required: ['caption', 'imageUrl'],
  additionalProperties: false,
  properties: {
    caption: {
      type: 'string',
      minLength: 1,
      maxLength: 1000
    },
    imageUrl: {
      type: 'string',
      minLength: 5
    },
    location: {
      type: 'string',
      maxLength: 120
    },
    eventTime: {
      type: 'string',
      maxLength: 50
    },
    capacity: {
      type: 'string',
      maxLength: 50
    },
    timeRemaining: {
      type: 'string',
      maxLength: 50
    },
    tags: {
      type: 'array',
      items: { type: 'string' }
    }
  }
};

const postUpdateSchema = {
  type: 'object',
  minProperties: 1,
  additionalProperties: false,
  properties: {
    caption: {
      type: 'string',
      minLength: 1,
      maxLength: 1000
    },
    location: {
      type: 'string',
      maxLength: 120
    },
    tags: {
      type: 'array',
      items: { type: 'string' }
    }
  }
};

module.exports = {
  postCreateSchema,
  postUpdateSchema
};
