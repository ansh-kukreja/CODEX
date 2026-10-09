const authLoginSchema = {
  type: 'object',
  required: ['username', 'password'],
  additionalProperties: false,
  properties: {
    username: {
      type: 'string',
      minLength: 3,
      maxLength: 50
    },
    password: {
      type: 'string',
      minLength: 4,
      maxLength: 100
    }
  }
};

module.exports = {
  authLoginSchema
};
