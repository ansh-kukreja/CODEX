import React, { useState } from 'react';
import { X, Image, Sparkles, Send } from 'lucide-react';
import { createPost } from '../services/api';

const SAMPLE_IMAGES = [
  { label: 'Concert Band', url: 'https://images.unsplash.com/photo-1514525253161-7a46d19cd819?w=1080' },
  { label: 'Beach Twilight', url: 'https://images.unsplash.com/photo-1507525428034-b723cf961d3e?w=1080' },
  { label: 'Studio Synths', url: 'https://images.unsplash.com/photo-1598488035139-bdbb2231ce04?w=1080' },
  { label: 'Mountain Trail', url: 'https://images.unsplash.com/photo-1506744038136-46273834b3fb?w=1080' }
];

export default function CreatePostModal({ isOpen, onClose, onPostCreated }) {
  const [caption, setCaption] = useState('');
  const [imageUrl, setImageUrl] = useState(SAMPLE_IMAGES[0].url);
  const [location, setLocation] = useState('Boston, MA');
  const [eventTime, setEventTime] = useState('Tomorrow 8:00pm');
  const [capacity, setCapacity] = useState('5/10 people');
  const [tags, setTags] = useState('music, boston, meetup');
  const [submitting, setSubmitting] = useState(false);
  const [errorDetails, setErrorDetails] = useState(null);
  const [successInfo, setSuccessInfo] = useState(null);

  if (!isOpen) return null;

  const handleSubmit = async (e) => {
    e.preventDefault();
    setSubmitting(true);
    setErrorDetails(null);
    setSuccessInfo(null);

    // Client-generated UUID Idempotency-Key for POST
    const idempotencyKey = `idemp_${Date.now()}_${Math.random().toString(36).substring(2, 7)}`;

    try {
      const payload = {
        caption,
        imageUrl,
        location,
        eventTime,
        capacity,
        timeRemaining: 'Active event',
        tags: tags.split(',').map(t => t.trim()).filter(Boolean)
      };

      const result = await createPost(payload, idempotencyKey);

      if (result.status === 201) {
        setSuccessInfo({
          message: 'Post created successfully (201 Created)!',
          location: result.headers.location,
          idempotentReplay: result.headers.idempotentReplay || 'false (first execution)'
        });
        if (onPostCreated) {
          onPostCreated(result.data);
        }
        setTimeout(() => {
          onClose();
        }, 1200);
      } else {
        setErrorDetails(result.data?.error || { message: 'Failed to create post.' });
      }
    } catch (err) {
      setErrorDetails({ message: err.message });
    } finally {
      setSubmitting(false);
    }
  };

  return (
    <div className="modal-overlay" onClick={onClose}>
      <div className="modal-sheet" onClick={(e) => e.stopPropagation()}>
        <div className="modal-header">
          <h3 className="modal-title">Share New Event</h3>
          <button className="close-modal-btn" onClick={onClose}>
            <X size={20} />
          </button>
        </div>

        {successInfo && (
          <div style={{ background: 'rgba(74, 222, 128, 0.2)', border: '1px solid #4ade80', borderRadius: '16px', padding: '12px', marginBottom: '16px', fontSize: '0.85rem' }}>
            <p style={{ fontWeight: 700, color: '#86efac' }}>{successInfo.message}</p>
            <p style={{ fontSize: '0.75rem', marginTop: '4px' }}>Location: {successInfo.location}</p>
            <p style={{ fontSize: '0.75rem' }}>Idempotent Replay: {successInfo.idempotentReplay}</p>
          </div>
        )}

        {errorDetails && (
          <div style={{ background: 'rgba(248, 113, 113, 0.2)', border: '1px solid #f87171', borderRadius: '16px', padding: '12px', marginBottom: '16px', fontSize: '0.85rem' }}>
            <p style={{ fontWeight: 700, color: '#fca5a5' }}>Error: {errorDetails.code || 'Validation Error'}</p>
            <p style={{ fontSize: '0.78rem' }}>{errorDetails.message}</p>
          </div>
        )}

        <form onSubmit={handleSubmit}>
          <label className="input-label">Event Message / Caption</label>
          <input
            type="text"
            className="form-input-pill"
            placeholder="What's happening? (e.g. Band rehearsal extra tickets)"
            value={caption}
            onChange={(e) => setCaption(e.target.value)}
            required
          />

          <label className="input-label">Select Photo Asset</label>
          <div style={{ display: 'flex', gap: '8px', marginBottom: '14px', flexWrap: 'wrap' }}>
            {SAMPLE_IMAGES.map((img) => (
              <button
                key={img.label}
                type="button"
                onClick={() => setImageUrl(img.url)}
                style={{
                  padding: '6px 12px',
                  borderRadius: '16px',
                  background: imageUrl === img.url ? '#2563eb' : 'rgba(255, 255, 255, 0.1)',
                  border: imageUrl === img.url ? '1px solid #38bdf8' : '1px solid rgba(255, 255, 255, 0.15)',
                  color: '#ffffff',
                  fontSize: '0.75rem',
                  cursor: 'pointer',
                  fontWeight: 600
                }}
              >
                {img.label}
              </button>
            ))}
          </div>

          <label className="input-label">Image URL</label>
          <input
            type="url"
            className="form-input-pill"
            placeholder="https://..."
            value={imageUrl}
            onChange={(e) => setImageUrl(e.target.value)}
            required
          />

          <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: '12px' }}>
            <div>
              <label className="input-label">Location</label>
              <input
                type="text"
                className="form-input-pill"
                placeholder="Boston, MA"
                value={location}
                onChange={(e) => setLocation(e.target.value)}
              />
            </div>
            <div>
              <label className="input-label">Event Time</label>
              <input
                type="text"
                className="form-input-pill"
                placeholder="Tomorrow 8:00pm"
                value={eventTime}
                onChange={(e) => setEventTime(e.target.value)}
              />
            </div>
          </div>

          <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: '12px' }}>
            <div>
              <label className="input-label">Capacity / Status</label>
              <input
                type="text"
                className="form-input-pill"
                placeholder="7/10 people"
                value={capacity}
                onChange={(e) => setCapacity(e.target.value)}
              />
            </div>
            <div>
              <label className="input-label">Tags (comma separated)</label>
              <input
                type="text"
                className="form-input-pill"
                placeholder="music, concert, boston"
                value={tags}
                onChange={(e) => setTags(e.target.value)}
              />
            </div>
          </div>

          <button
            type="submit"
            className="submit-pill-btn"
            disabled={submitting}
            style={{ display: 'flex', alignItems: 'center', justifyContent: 'center', gap: '8px' }}
          >
            <Send size={18} />
            {submitting ? 'Creating with Idempotency Key...' : 'Post with Idempotency Key'}
          </button>
        </form>
      </div>
    </div>
  );
}
