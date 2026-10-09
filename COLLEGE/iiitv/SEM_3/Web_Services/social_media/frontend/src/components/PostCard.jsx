import React, { useState } from 'react';
import { Heart, MessageCircle, X, Check, Clock, MapPin } from 'lucide-react';
import { toggleLike } from '../services/api';

export default function PostCard({ post, onOpenComments }) {
  const [isLiked, setIsLiked] = useState(post.isLiked || false);
  const [likesCount, setLikesCount] = useState(post.likesCount || 0);
  const [isAttending, setIsAttending] = useState(false);
  const [isDismissed, setIsDismissed] = useState(false);

  const handleLike = async (e) => {
    e.stopPropagation();
    // Optimistic UI update
    const nextState = !isLiked;
    setIsLiked(nextState);
    setLikesCount(prev => Math.max(0, prev + (nextState ? 1 : -1)));

    try {
      await toggleLike(post.id);
    } catch {
      // Revert on error
      setIsLiked(!nextState);
      setLikesCount(prev => Math.max(0, prev + (!nextState ? 1 : -1)));
    }
  };

  if (isDismissed) {
    return null;
  }

  const isCancelled = post.status === 'Cancelled';

  return (
    <article className="post-card" id={`post-${post.id}`}>
      {/* Top message text block */}
      <div className="card-top-message">
        <h2 className="card-headline-text">{post.caption}</h2>
        <div className="card-remaining-time">
          <Clock size={14} color="#93c5fd" />
          <span>{post.timeRemaining || 'Active event'}</span>
          {post.location && (
            <span style={{ marginLeft: '10px', display: 'flex', alignItems: 'center', gap: '3px' }}>
              <MapPin size={13} />
              {post.location.split(',')[0]}
            </span>
          )}
        </div>
      </div>

      {/* Main Image with floating Author and Action pills */}
      <div className="card-media-wrapper">
        <img
          src={post.imageUrl}
          alt={post.caption}
          className="card-image"
          loading="lazy"
        />

        {/* Floating Author Pill */}
        <div className="floating-author-pill">
          <img
            src={post.author?.avatar || 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=100'}
            alt={post.author?.name || 'Author'}
            className="author-pill-avatar"
          />
          <div className="author-info-names">
            <span className="author-fullname">{post.author?.name}</span>
            <span className="author-handle">@{post.author?.username}</span>
          </div>
        </div>

        {/* Floating Actions: Dismiss & Like */}
        <div className="floating-media-actions">
          <button
            className="media-pill-btn"
            onClick={() => setIsDismissed(true)}
            title="Dismiss card"
          >
            <X size={17} />
          </button>

          <button
            className={`media-pill-btn ${isLiked ? 'liked' : ''}`}
            onClick={handleLike}
            title={isLiked ? 'Unlike' : 'Like'}
          >
            <Heart size={18} fill={isLiked ? '#f43f5e' : 'none'} color={isLiked ? '#f43f5e' : '#ffffff'} />
          </button>
        </div>
      </div>

      {/* Card bottom bar with pills matching reference */}
      <div className="card-bottom-bar">
        <div className="event-chips-cluster">
          {isCancelled ? (
            <span className="meta-pill status-cancelled">Cancelled</span>
          ) : (
            <>
              {post.eventTime && (
                <span className="meta-pill">{post.eventTime}</span>
              )}
              {post.capacity && (
                <span className="meta-pill highlight">{post.capacity}</span>
              )}
            </>
          )}

          <button
            onClick={() => onOpenComments && onOpenComments(post)}
            className="meta-pill"
            style={{
              cursor: 'pointer',
              display: 'flex',
              alignItems: 'center',
              gap: '5px',
              background: 'rgba(37, 99, 235, 0.3)'
            }}
            title="View comments"
          >
            <MessageCircle size={13} />
            <span>{post.commentsCount || 0}</span>
          </button>
        </div>

        {/* Checkmark attendance button */}
        {!isCancelled && (
          <button
            onClick={() => setIsAttending(prev => !prev)}
            style={{
              width: '38px',
              height: '38px',
              borderRadius: '50%',
              background: isAttending ? '#4ade80' : 'rgba(255, 255, 255, 0.15)',
              border: isAttending ? 'none' : '1px solid rgba(255, 255, 255, 0.25)',
              color: isAttending ? '#09122c' : '#ffffff',
              display: 'flex',
              alignItems: 'center',
              justifyContent: 'center',
              cursor: 'pointer',
              transition: 'all 0.2s',
              boxShadow: isAttending ? '0 0 15px rgba(74, 222, 128, 0.5)' : 'none'
            }}
            title={isAttending ? 'Joined event!' : 'Join event'}
          >
            <Check size={18} strokeWidth={isAttending ? 3 : 2} />
          </button>
        )}
      </div>
    </article>
  );
}
