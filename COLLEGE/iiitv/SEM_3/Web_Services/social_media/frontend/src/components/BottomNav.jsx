import React from 'react';
import { Flag, Compass, Plus, MessageSquare, User } from 'lucide-react';

export default function BottomNav({ currentTab, onSelectTab, onOpenCreate }) {
  return (
    <nav className="bottom-floating-nav" aria-label="Main Navigation">
      <button
        className={`nav-tab-pill ${currentTab === 'feed' ? 'active' : ''}`}
        onClick={() => onSelectTab('feed')}
        title="Feed"
        aria-label="Feed"
      >
        <Flag size={20} />
      </button>

      <button
        className={`nav-tab-pill ${currentTab === 'explore' ? 'active' : ''}`}
        onClick={() => onSelectTab('explore')}
        title="Explore"
        aria-label="Explore"
      >
        <Compass size={21} />
      </button>

      {/* Floating center plus button for creating new post */}
      <button
        className="nav-tab-pill"
        onClick={onOpenCreate}
        style={{
          background: 'linear-gradient(135deg, #2563eb, #38bdf8)',
          color: '#ffffff',
          boxShadow: '0 4px 15px rgba(56, 189, 248, 0.4)'
        }}
        title="Create New Post"
        aria-label="Create New Post"
      >
        <Plus size={22} strokeWidth={2.8} />
      </button>

      <button
        className={`nav-tab-pill ${currentTab === 'activity' ? 'active' : ''}`}
        onClick={() => onSelectTab('activity')}
        title="Messages & Activity"
        aria-label="Messages & Activity"
      >
        <MessageSquare size={20} />
      </button>

      <button
        className={`nav-tab-pill ${currentTab === 'profile' ? 'active' : ''}`}
        onClick={() => onSelectTab('profile')}
        title="Profile"
        aria-label="Profile"
      >
        <User size={20} />
      </button>
    </nav>
  );
}
