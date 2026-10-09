// In-memory NoSQL Document Store over static collections
// Satisfies "A NoSQL document store" while respecting "do not use any database yet, show only static data"

const { staticUsers, staticPosts, staticComments, staticStories } = require('./staticData');

class MockCollection {
  constructor(name, initialDocuments = []) {
    this.name = name;
    this.documents = JSON.parse(JSON.stringify(initialDocuments));
  }

  async find(filter = {}) {
    const keys = Object.keys(filter);
    if (keys.length === 0) {
      return [...this.documents];
    }
    return this.documents.filter(doc => {
      return keys.every(key => doc[key] === filter[key]);
    });
  }

  async findOne(filter = {}) {
    const results = await this.find(filter);
    return results[0] || null;
  }

  async findById(id) {
    return this.documents.find(doc => doc.id === id) || null;
  }

  async insertOne(doc) {
    const newDoc = {
      id: doc.id || `doc_${Date.now()}_${Math.random().toString(36).substr(2, 6)}`,
      ...doc,
      createdAt: doc.createdAt || new Date().toISOString()
    };
    this.documents.unshift(newDoc);
    return { acknowledged: true, insertedId: newDoc.id, document: newDoc };
  }

  async updateOne(filter, update) {
    const doc = await this.findOne(filter);
    if (!doc) {
      return { matchedCount: 0, modifiedCount: 0 };
    }
    const updateFields = update.$set ? update.$set : update;
    Object.assign(doc, updateFields, { updatedAt: new Date().toISOString() });
    return { matchedCount: 1, modifiedCount: 1, document: doc };
  }

  async deleteOne(filter) {
    const index = this.documents.findIndex(doc => {
      return Object.keys(filter).every(k => doc[k] === filter[k]);
    });
    if (index === -1) {
      return { deletedCount: 0 };
    }
    const removed = this.documents.splice(index, 1);
    return { deletedCount: 1, document: removed[0] };
  }
}

class MockNoSqlDatabase {
  constructor() {
    this.collections = {
      users: new MockCollection('users', staticUsers),
      posts: new MockCollection('posts', staticPosts),
      comments: new MockCollection('comments', staticComments),
      stories: new MockCollection('stories', staticStories)
    };
  }

  collection(name) {
    if (!this.collections[name]) {
      this.collections[name] = new MockCollection(name, []);
    }
    return this.collections[name];
  }
}

const mockNoSqlDb = new MockNoSqlDatabase();
module.exports = mockNoSqlDb;
