import React, { useState, useEffect } from 'react';
import { X, Send } from 'lucide-react';
import { fetchComments, addComment } from '../services/api';

export default function CommentsModal({ post, isOpen, onClose }) {
  const [comments, setComments] = useState([]);
  const [newComment, setNewComment] = useState('');
  const [loading, setLoading] = useState(false);

  useEffect(() => {
    if (isOpen && post) {
      loadComments();
    }
  }, [isOpen, post]);

  const loadComments = async () => {
    try {
      const res = await fetchComments(post.id);
      setComments(res.comments || []);
    } catch {
      setComments([]);
    }
  };

  const handleAddComment = async (e) => {
    e.preventDefault();
    if (!newComment.trim()) return;

    setLoading(true);
    try {
      const res = await addComment(post.id, newComment.trim());
      setComments(prev => [...prev, res]);
      setNewComment('');
    } catch (err) {
      console.error(err);
    } finally {
      setLoading(false);
    }
  };

  if (!isOpen || !post) return null;

  return (
    <div className="modal-overlay" onClick={onClose}>
      <div className="modal-sheet" onClick={(e) => e.stopPropagation()}>
        <div className="modal-header">
          <h3 className="modal-title">Comments</h3>
          <button className="close-modal-btn" onClick={onClose}>
            <X size={20} />
          </button>
        </div>

        <div style={{ maxHeight: '340px', overflowY: 'auto', display: 'flex', flexDirection: 'column', gap: '14px', marginBottom: '16px' }}>
          {comments.length === 0 ? (
            <p style={{ color: 'rgba(255, 255, 255, 0.6)', textAlign: 'center', padding: '20px' }}>
              No comments yet. Be the first to chime in!
            </p>
          ) : (
            comments.map((c) => (
              <div key={c.id} style={{ display: 'flex', gap: '12px', alignItems: 'flex-start' }}>
                <img
                  src={c.avatar || 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=100'}
                  alt={c.username}
                  style={{ width: '32px', height: '32px', borderRadius: '50%', objectFit: 'cover' }}
                />
                <div style={{ background: 'rgba(255, 255, 255, 0.08)', borderRadius: '18px', padding: '10px 14px', flex: 1 }}>
                  <span style={{ fontSize: '0.82rem', fontWeight: 700, color: '#93c5fd', display: 'block', marginBottom: '3px' }}>
                    @{c.username}
                  </span>
                  <p style={{ fontSize: '0.88rem', lineHeight: 1.4 }}>{c.content}</p>
                </div>
              </div>
            ))
          )}
        </div>

        <form onSubmit={handleAddComment} style={{ display: 'flex', gap: '8px' }}>
          <input
            type="text"
            className="form-input-pill"
            style={{ marginBottom: 0 }}
            placeholder="Add a comment as @melanie_v..."
            value={newComment}
            onChange={(e) => setNewComment(e.target.value)}
            required
          />
          <button
            type="submit"
            className="submit-pill-btn"
            disabled={loading}
            style={{ width: 'auto', padding: '0 18px', display: 'flex', alignItems: 'center', justifyContent: 'center' }}
          >
            <Send size={18} />
          </button>
        </form>
      </div>
    </div>
  );
}
