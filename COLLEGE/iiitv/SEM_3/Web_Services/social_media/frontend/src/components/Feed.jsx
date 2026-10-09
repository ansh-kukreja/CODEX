import React from 'react';
import PostCard from './PostCard';
import { ArrowDown, RefreshCw } from 'lucide-react';

export default function Feed({
  posts = [],
  loading = false,
  pagination = {},
  links = {},
  onLoadMore,
  onOpenComments
}) {
  return (
    <div className="feed-stream">
      {posts.length === 0 && !loading && (
        <div style={{ textAlign: 'center', padding: '40px 20px', color: 'rgba(255, 255, 255, 0.7)' }}>
          <p style={{ fontSize: '1.1rem', marginBottom: '8px' }}>No events or posts found</p>
          <span style={{ fontSize: '0.85rem', color: '#93c5fd' }}>Try adjusting your search query or filters</span>
        </div>
      )}

      {posts.map((post) => (
        <PostCard
          key={post.id}
          post={post}
          onOpenComments={onOpenComments}
        />
      ))}

      {/* Keyset Cursor Pagination Section demonstrating checklist next link */}
      {pagination?.hasMore && (
        <div style={{ textAlign: 'center', marginTop: '10px', marginBottom: '20px' }}>
          <button
            onClick={onLoadMore}
            disabled={loading}
            className="submit-pill-btn"
            style={{
              display: 'inline-flex',
              alignItems: 'center',
              justifyContent: 'center',
              gap: '8px',
              padding: '12px 28px',
              width: 'auto',
              fontSize: '0.9rem'
            }}
          >
            {loading ? <RefreshCw className="animate-spin" size={16} /> : <ArrowDown size={16} />}
            Load More (Cursor: {pagination.nextCursor})
          </button>
          {links?.next && (
            <p style={{ fontSize: '0.7rem', color: '#93c5fd', marginTop: '6px', opacity: 0.8 }}>
              REST Link: {links.next}
            </p>
          )}
        </div>
      )}
    </div>
  );
}
