import React, { useState, useEffect } from 'react';
import { BadgeCheck, MapPin, Grid, Bookmark, Users, Heart } from 'lucide-react';
import { fetchUserProfile } from '../services/api';

export default function ProfileView({ userPosts = [] }) {
  const [profile, setProfile] = useState(null);
  const [activeTab, setActiveTab] = useState('grid');

  useEffect(() => {
    async function load() {
      try {
        const res = await fetchUserProfile('usr_melanie');
        setProfile(res);
      } catch {
        setProfile({
          name: 'Melanie Vance',
          username: 'melanie_v',
          avatar: 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=300&h=300&fit=crop&crop=face',
          bio: 'Digital creator & music lover 🎶 Living between Boston & NYC. Discovering new friendships!',
          location: 'Boston, MA',
          followersCount: 1420,
          followingCount: 380,
          postsCount: 12,
          verified: true
        });
      }
    }
    load();
  }, []);

  if (!profile) return null;

  return (
    <div style={{ padding: '16px 20px 100px 20px' }}>
      {/* Profile Header Block */}
      <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', textAlign: 'center', marginBottom: '24px' }}>
        <div style={{ position: 'relative', marginBottom: '14px' }}>
          <div style={{
            padding: '4px',
            borderRadius: '50%',
            background: 'linear-gradient(135deg, #38bdf8, #2563eb, #818cf8)',
            boxShadow: '0 8px 25px rgba(37, 99, 235, 0.4)'
          }}>
            <img
              src={profile.avatar}
              alt={profile.name}
              style={{ width: '90px', height: '90px', borderRadius: '50%', objectFit: 'cover', display: 'block', border: '3px solid #0f1b4c' }}
            />
          </div>
          {profile.verified && (
            <div style={{
              position: 'absolute',
              bottom: '2px',
              right: '2px',
              background: '#2563eb',
              borderRadius: '50%',
              padding: '2px',
              display: 'flex'
            }}>
              <BadgeCheck size={18} color="#ffffff" fill="#38bdf8" />
            </div>
          )}
        </div>

        <h2 style={{ fontSize: '1.35rem', fontWeight: 800, marginBottom: '2px' }}>{profile.name}</h2>
        <span style={{ fontSize: '0.85rem', color: '#93c5fd', fontWeight: 600, marginBottom: '8px' }}>
          @{profile.username}
        </span>

        <p style={{ fontSize: '0.88rem', color: 'rgba(255, 255, 255, 0.85)', maxWidth: '340px', lineHeight: 1.4, marginBottom: '12px' }}>
          {profile.bio}
        </p>

        {profile.location && (
          <div style={{ display: 'flex', alignItems: 'center', gap: '4px', fontSize: '0.78rem', color: '#93c5fd', marginBottom: '18px' }}>
            <MapPin size={13} />
            <span>{profile.location}</span>
          </div>
        )}

        {/* Stats Strip */}
        <div style={{
          display: 'grid',
          gridTemplateColumns: '1fr 1fr 1fr',
          width: '100%',
          maxWidth: '380px',
          background: 'rgba(255, 255, 255, 0.08)',
          border: '1px solid rgba(255, 255, 255, 0.15)',
          borderRadius: '24px',
          padding: '14px 10px',
          marginBottom: '18px'
        }}>
          <div>
            <div style={{ fontSize: '1.15rem', fontWeight: 800 }}>{userPosts.length || profile.postsCount}</div>
            <div style={{ fontSize: '0.72rem', color: '#93c5fd', textTransform: 'uppercase' }}>Posts</div>
          </div>
          <div style={{ borderLeft: '1px solid rgba(255, 255, 255, 0.12)', borderRight: '1px solid rgba(255, 255, 255, 0.12)' }}>
            <div style={{ fontSize: '1.15rem', fontWeight: 800 }}>{(profile.followersCount / 1000).toFixed(1)}k</div>
            <div style={{ fontSize: '0.72rem', color: '#93c5fd', textTransform: 'uppercase' }}>Followers</div>
          </div>
          <div>
            <div style={{ fontSize: '1.15rem', fontWeight: 800 }}>{profile.followingCount}</div>
            <div style={{ fontSize: '0.72rem', color: '#93c5fd', textTransform: 'uppercase' }}>Following</div>
          </div>
        </div>

        {/* Action Buttons */}
        <div style={{ display: 'flex', gap: '10px', width: '100%', maxWidth: '380px' }}>
          <button className="submit-pill-btn" style={{ padding: '10px', fontSize: '0.88rem' }}>
            Edit Profile
          </button>
          <button style={{
            flex: 1,
            background: 'rgba(255, 255, 255, 0.15)',
            border: '1px solid rgba(255, 255, 255, 0.25)',
            borderRadius: '26px',
            color: '#ffffff',
            fontWeight: 600,
            fontSize: '0.88rem',
            cursor: 'pointer'
          }}>
            Share Profile
          </button>
        </div>
      </div>

      {/* Grid Tabs */}
      <div style={{ display: 'flex', borderBottom: '1px solid rgba(255, 255, 255, 0.12)', marginBottom: '16px' }}>
        <button
          onClick={() => setActiveTab('grid')}
          style={{
            flex: 1,
            background: 'transparent',
            border: 'none',
            padding: '10px',
            color: activeTab === 'grid' ? '#38bdf8' : 'rgba(255, 255, 255, 0.5)',
            borderBottom: activeTab === 'grid' ? '2px solid #38bdf8' : 'none',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            gap: '6px',
            cursor: 'pointer',
            fontWeight: 600
          }}
        >
          <Grid size={16} /> Grid
        </button>
        <button
          onClick={() => setActiveTab('saved')}
          style={{
            flex: 1,
            background: 'transparent',
            border: 'none',
            padding: '10px',
            color: activeTab === 'saved' ? '#38bdf8' : 'rgba(255, 255, 255, 0.5)',
            borderBottom: activeTab === 'saved' ? '2px solid #38bdf8' : 'none',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            gap: '6px',
            cursor: 'pointer',
            fontWeight: 600
          }}
        >
          <Bookmark size={16} /> Saved
        </button>
      </div>

      {/* Photo Grid */}
      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(3, 1fr)', gap: '6px' }}>
        {userPosts.map((post) => (
          <div
            key={post.id}
            style={{
              position: 'relative',
              paddingTop: '100%',
              borderRadius: '12px',
              overflow: 'hidden',
              cursor: 'pointer'
            }}
          >
            <img
              src={post.imageUrl}
              alt={post.caption}
              style={{ position: 'absolute', top: 0, left: 0, width: '100%', height: '100%', objectFit: 'cover' }}
            />
          </div>
        ))}
      </div>
    </div>
  );
}
