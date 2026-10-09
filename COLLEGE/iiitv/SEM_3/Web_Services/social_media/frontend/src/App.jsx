import React, { useState, useEffect } from 'react';
import TopHeader from './components/TopHeader';
import SearchBar from './components/SearchBar';
import StoriesBar from './components/StoriesBar';
import Feed from './components/Feed';
import ExploreView from './components/ExploreView';
import ProfileView from './components/ProfileView';
import BottomNav from './components/BottomNav';
import CreatePostModal from './components/CreatePostModal';
import CommentsModal from './components/CommentsModal';
import ChecklistInspector from './components/ChecklistInspector';
import { fetchPosts, fetchStories } from './services/api';
import { Bell, Heart, MessageSquare, Check, Sparkles } from 'lucide-react';

export default function App() {
  const [currentTab, setCurrentTab] = useState('feed');
  const [posts, setPosts] = useState([]);
  const [pagination, setPagination] = useState({});
  const [links, setLinks] = useState({});
  const [stories, setStories] = useState([]);
  const [loading, setLoading] = useState(false);
  const [searchTerm, setSearchTerm] = useState('');
  const [activeTag, setActiveTag] = useState(null);

  // Modals state
  const [isCreateOpen, setIsCreateOpen] = useState(false);
  const [isCommentsOpen, setIsCommentsOpen] = useState(false);
  const [selectedPost, setSelectedPost] = useState(null);
  const [isInspectorOpen, setIsInspectorOpen] = useState(false);

  // Load initial feed
  useEffect(() => {
    loadFeed({ reset: true, search: searchTerm, tag: activeTag });
  }, [searchTerm, activeTag]);

  // Load stories
  useEffect(() => {
    async function loadStoriesData() {
      try {
        const res = await fetchStories();
        setStories(res.data || []);
      } catch (err) {
        console.error('Failed to load stories:', err);
      }
    }
    loadStoriesData();
  }, []);

  const loadFeed = async ({ reset = false, cursor = null, search = null, tag = null } = {}) => {
    setLoading(true);
    try {
      const res = await fetchPosts({
        cursor,
        limit: 5,
        search,
        tag
      });

      if (reset) {
        setPosts(res.data);
      } else {
        setPosts(prev => [...prev, ...res.data]);
      }
      setPagination(res.pagination);
      setLinks(res.links);
    } catch (err) {
      console.error('Error fetching posts:', err);
    } finally {
      setLoading(false);
    }
  };

  const handleLoadMore = () => {
    if (pagination.nextCursor) {
      loadFeed({
        reset: false,
        cursor: pagination.nextCursor,
        search: searchTerm,
        tag: activeTag
      });
    }
  };

  const handlePostCreated = (newPost) => {
    setPosts(prev => [newPost, ...prev]);
  };

  const handleOpenComments = (post) => {
    setSelectedPost(post);
    setIsCommentsOpen(true);
  };

  return (
    <div className="app-viewport">
      {/* Centered Mobile Phone Aesthetic Canvas matching Fizzy UI */}
      <main className="mobile-canvas" role="main">
        {/* Dynamic Island Notch */}
        <div className="top-island">
          <div className="notch-pill" />
        </div>

        {/* Top Header */}
        <TopHeader
          onOpenInspector={() => setIsInspectorOpen(true)}
          currentTab={currentTab}
          setCurrentTab={setCurrentTab}
        />

        {/* Search Bar on Feed & Explore */}
        {(currentTab === 'feed' || currentTab === 'explore') && (
          <SearchBar
            searchTerm={searchTerm}
            onSearchChange={setSearchTerm}
            onFilterClick={() => setCurrentTab('explore')}
          />
        )}

        {/* Stories Bar on Feed */}
        {currentTab === 'feed' && !searchTerm && !activeTag && (
          <StoriesBar
            stories={stories}
            onSelectStory={(s) => console.log('Story clicked:', s)}
          />
        )}

        {/* Content Body Based on Navigation Tab */}
        {currentTab === 'feed' && (
          <Feed
            posts={posts}
            loading={loading}
            pagination={pagination}
            links={links}
            onLoadMore={handleLoadMore}
            onOpenComments={handleOpenComments}
          />
        )}

        {currentTab === 'explore' && (
          <ExploreView
            posts={posts}
            activeTag={activeTag}
            onSelectTag={(tag) => {
              setActiveTag(tag);
              setCurrentTab('feed');
            }}
          />
        )}

        {currentTab === 'activity' && (
          <div style={{ padding: '20px', display: 'flex', flexDirection: 'column', gap: '14px' }}>
            <h2 style={{ fontSize: '1.3rem', fontWeight: 800 }}>Activity & Invitations</h2>
            {[
              { text: 'Alan Walker invited you to "My brothers band live"', time: '23m ago', icon: <Heart size={16} color="#f43f5e" /> },
              { text: 'Matt Iven liked your sunrise trail photo', time: '1h ago', icon: <Heart size={16} color="#38bdf8" /> },
              { text: 'Amber Winston commented: "Saving 2 spots for me and Sarah"', time: '3h ago', icon: <MessageSquare size={16} color="#4ade80" /> }
            ].map((item, i) => (
              <div
                key={i}
                style={{
                  background: 'rgba(255, 255, 255, 0.09)',
                  border: '1px solid rgba(255, 255, 255, 0.16)',
                  borderRadius: '20px',
                  padding: '14px',
                  display: 'flex',
                  alignItems: 'center',
                  gap: '12px'
                }}
              >
                <div style={{
                  width: '38px',
                  height: '38px',
                  borderRadius: '50%',
                  background: 'rgba(255, 255, 255, 0.12)',
                  display: 'flex',
                  alignItems: 'center',
                  justifyContent: 'center'
                }}>
                  {item.icon}
                </div>
                <div style={{ flex: 1 }}>
                  <p style={{ fontSize: '0.88rem', fontWeight: 500, lineHeight: 1.3 }}>{item.text}</p>
                  <span style={{ fontSize: '0.72rem', color: '#93c5fd' }}>{item.time}</span>
                </div>
              </div>
            ))}
          </div>
        )}

        {currentTab === 'profile' && (
          <ProfileView userPosts={posts.filter(p => p.userId === 'usr_melanie' || p.author?.username === 'melanie_v')} />
        )}

        {/* Floating Frosted Bottom Navigation Pill */}
        <BottomNav
          currentTab={currentTab}
          onSelectTab={setCurrentTab}
          onOpenCreate={() => setIsCreateOpen(true)}
        />
      </main>

      {/* Create Post Modal with Idempotency Key & Schema Validation */}
      <CreatePostModal
        isOpen={isCreateOpen}
        onClose={() => setIsCreateOpen(false)}
        onPostCreated={handlePostCreated}
      />

      {/* Comments Drawer */}
      <CommentsModal
        post={selectedPost}
        isOpen={isCommentsOpen}
        onClose={() => {
          setIsCommentsOpen(false);
          setSelectedPost(null);
        }}
      />

      {/* Slide-out Architecture & REST Checklist Inspector */}
      <ChecklistInspector
        isOpen={isInspectorOpen}
        onClose={() => setIsInspectorOpen(false)}
      />
    </div>
  );
}
