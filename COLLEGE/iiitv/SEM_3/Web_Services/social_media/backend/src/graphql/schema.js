const { buildSchema } = require('graphql');

const typeDefs = `
  type User {
    id: ID!
    username: String!
    name: String!
    avatar: String
    bio: String
    location: String
    followersCount: Int
    followingCount: Int
    postsCount: Int
    verified: Boolean
  }

  type Comment {
    id: ID!
    postId: ID!
    userId: ID!
    username: String!
    avatar: String
    content: String!
    createdAt: String!
  }

  type Post {
    id: ID!
    userId: ID!
    author: User
    caption: String!
    imageUrl: String!
    location: String
    eventTime: String
    capacity: String
    timeRemaining: String
    likesCount: Int
    commentsCount: Int
    isLiked: Boolean
    isSaved: Boolean
    tags: [String!]
    comments: [Comment!]
    createdAt: String!
    updatedAt: String
  }

  type Story {
    id: ID!
    userId: ID!
    username: String!
    avatar: String
    hasUnread: Boolean
    mediaUrl: String
  }

  type Query {
    posts(limit: Int, tag: String): [Post!]!
    post(id: ID!): Post
    users: [User!]!
    user(id: ID, username: String): User
    stories: [Story!]!
  }

  type Mutation {
    likePost(id: ID!): Post
    createComment(postId: ID!, content: String!): Comment
  }
`;

const schema = buildSchema(typeDefs);

module.exports = {
  typeDefs,
  schema
};
