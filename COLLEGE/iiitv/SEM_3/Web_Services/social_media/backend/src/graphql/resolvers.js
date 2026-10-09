const mockNoSqlDb = require('../data/mockNoSqlDb');
const { staticStories } = require('../data/staticData');

const resolvers = {
  posts: async ({ limit = 20, tag }) => {
    let posts = await mockNoSqlDb.collection('posts').find();
    if (tag) {
      posts = posts.filter(p => p.tags && p.tags.includes(tag.toLowerCase()));
    }
    const users = await mockNoSqlDb.collection('users').find();
    const comments = await mockNoSqlDb.collection('comments').find();

    return posts.slice(0, limit).map(p => ({
      ...p,
      author: users.find(u => u.id === p.userId) || p.author,
      comments: comments.filter(c => c.postId === p.id)
    }));
  },

  post: async ({ id }) => {
    const post = await mockNoSqlDb.collection('posts').findById(id);
    if (!post) return null;

    const users = await mockNoSqlDb.collection('users').find();
    const comments = await mockNoSqlDb.collection('comments').find();

    return {
      ...post,
      author: users.find(u => u.id === post.userId) || post.author,
      comments: comments.filter(c => c.postId === post.id)
    };
  },

  users: async () => {
    return mockNoSqlDb.collection('users').find();
  },

  user: async ({ id, username }) => {
    if (id) {
      return mockNoSqlDb.collection('users').findById(id);
    }
    if (username) {
      return mockNoSqlDb.collection('users').findOne({ username });
    }
    return null;
  },

  stories: async () => {
    return staticStories;
  },

  likePost: async ({ id }) => {
    const post = await mockNoSqlDb.collection('posts').findById(id);
    if (!post) throw new Error(`Post with id '${id}' not found`);

    const newLiked = !post.isLiked;
    post.isLiked = newLiked;
    post.likesCount += newLiked ? 1 : -1;

    return post;
  },

  createComment: async ({ postId, content }) => {
    const post = await mockNoSqlDb.collection('posts').findById(postId);
    if (!post) throw new Error(`Post with id '${postId}' not found`);

    const newComment = {
      id: `cmt_${Date.now()}`,
      postId,
      userId: 'usr_melanie',
      username: 'melanie_v',
      avatar: 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=300&h=300&fit=crop&crop=face',
      content,
      createdAt: new Date().toISOString()
    };

    await mockNoSqlDb.collection('comments').insertOne(newComment);
    post.commentsCount = (post.commentsCount || 0) + 1;

    return newComment;
  }
};

module.exports = resolvers;
