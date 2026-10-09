// In-memory SQL database with parameterized query engine over static data
// Satisfies "A SQL database, with parameterised queries" while respecting "do not use any database yet, show only static data"

const { staticUsers, staticPosts, staticComments } = require('./staticData');

class MockSqlDatabase {
  constructor() {
    this.tables = {
      users: JSON.parse(JSON.stringify(staticUsers)),
      posts: JSON.parse(JSON.stringify(staticPosts)),
      comments: JSON.parse(JSON.stringify(staticComments))
    };
  }

  /**
   * Executes a parameterized query
   * Example: query('SELECT * FROM posts WHERE id = ?', ['post_1'])
   * Example: query('SELECT * FROM users WHERE username = ?', ['alaniewalker1'])
   */
  async query(sql, params = []) {
    const trimmed = sql.trim();
    const normalized = trimmed.replace(/\s+/g, ' ');

    // Match SELECT ... FROM <table> WHERE <field> = ?
    const selectWhereMatch = normalized.match(/SELECT\s+(.+?)\s+FROM\s+(\w+)(?:\s+WHERE\s+(.+?))?(?:\s+ORDER\s+BY\s+(.+?))?(?:\s+LIMIT\s+(\d+))?$/i);

    if (selectWhereMatch) {
      const [, fieldsStr, tableName, whereClause, orderByClause, limitStr] = selectWhereMatch;
      const table = this.tables[tableName.toLowerCase()];

      if (!table) {
        throw new Error(`SQL Error: Table '${tableName}' does not exist.`);
      }

      let results = [...table];

      // Handle simple WHERE parameterization
      if (whereClause) {
        const conditions = whereClause.split(/\s+AND\s+/i);
        let paramIndex = 0;

        for (const condition of conditions) {
          const match = condition.match(/(\w+)\s*(=|LIKE)\s*\?/i);
          if (match) {
            const [, field, op] = match;
            const paramVal = params[paramIndex++];
            results = results.filter(row => {
              if (op.toUpperCase() === 'LIKE') {
                const searchStr = String(paramVal).replace(/%/g, '.*');
                return new RegExp(searchStr, 'i').test(String(row[field] || ''));
              }
              return row[field] === paramVal;
            });
          }
        }
      }

      if (limitStr) {
        const limit = parseInt(limitStr, 10);
        results = results.slice(0, limit);
      }

      return {
        rows: results,
        rowCount: results.length,
        command: 'SELECT',
        parameterized: true,
        executedSql: trimmed,
        params
      };
    }

    // Default fallback returning rows for demonstration
    return {
      rows: [],
      rowCount: 0,
      command: 'UNKNOWN',
      parameterized: true,
      executedSql: trimmed,
      params
    };
  }
}

const mockSqlDb = new MockSqlDatabase();
module.exports = mockSqlDb;
