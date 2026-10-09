import React, { useState } from 'react';
import { Compass, Hash, Sparkles } from 'lucide-react';

const POPULAR_TAGS = ['All', 'music', 'concert', 'boston', 'art', 'trail', 'beach'];

export default function ExploreView({ posts = [], onSelectTag, activeTag }) {
  return (
    <div style={{ padding: '16px 20px 100px 20px' }}>
      <div style={{ display: 'flex', alignItems: 'center', gap: '8px', marginBottom: '16px' }}>
        <Compass size={22} color="#38bdf8" />
        <h2 style={{ fontSize: '1.25rem', fontWeight: 700 }}>Explore Events & Vibes</h2>
      </div>

      {/* Tags Carousel */}
      <div style={{ display: 'flex', gap: '8px', overflowX: 'auto', paddingBottom: '14px', scrollbarWidth: 'none' }}>
        {POPULAR_TAGS.map((tag) => {
          const isSelected = (tag === 'All' && !activeTag) || (activeTag === tag);
          return (
            <button
              key={tag}
              onClick={() => onSelectTag(tag === 'All' ? null : tag)}
              style={{
                background: isSelected ? 'linear-gradient(135deg, #2563eb, #38bdf8)' : 'rgba(255, 255, 255, 0.12)',
                border: isSelected ? 'none' : '1px solid rgba(255, 255, 255, 0.18)',
                borderRadius: '20px',
                padding: '6px 14px',
                color: '#ffffff',
                fontSize: '0.8rem',
                fontWeight: 600,
                cursor: 'pointer',
                whiteSpace: 'nowrap',
                display: 'flex',
                alignItems: 'center',
                gap: '4px'
              }}
            >
              <Hash size={13} />
              {tag}
            </button>
          );
        })}
      </div>

      {/* Discovery Grid */}
      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(2, 1fr)', gap: '12px' }}>
        {posts.map((post) => (
          <div
            key={post.id}
            style={{
              background: 'rgba(255, 255, 255, 0.08)',
              border: '1px solid rgba(255, 255, 255, 0.15)',
              borderRadius: '20px',
              overflow: 'hidden',
              cursor: 'pointer',
              transition: 'transform 0.2s',
              display: 'flex',
              flexDirection: 'column'
            }}
          >
            <div style={{ position: 'relative', width: '100%', height: '140px' }}>
              <img
                src={post.imageUrl}
                alt={post.caption}
                style={{ width: '100%', height: '100%', objectFit: 'cover' }}
              />
              <span style={{
                position: 'absolute',
                bottom: '8px',
                left: '8px',
                background: 'rgba(15, 27, 76, 0.8)',
                backdropFilter: 'blur(10px)',
                padding: '3px 8px',
                borderRadius: '12px',
                fontSize: '0.68rem',
                fontWeight: 600
              }}>
                {post.eventTime || 'Live'}
              </span>
            </div>
            <div style={{ padding: '10px 12px' }}>
              <span style={{ fontSize: '0.72rem', color: '#93c5fd', fontWeight: 700 }}>
                @{post.author?.username}
              </span>
              <p style={{
                fontSize: '0.82rem',
                color: '#ffffff',
                marginTop: '4px',
                lineHeight: 1.3,
                display: '-webkit-box',
                WebkitLineClamp: 2,
                WebkitBoxOrient: 'vertical',
                overflow: 'hidden'
              }}>
                {post.caption}
              </p>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}
