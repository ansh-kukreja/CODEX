import React from 'react';

export default function StoriesBar({ stories = [], onSelectStory }) {
  return (
    <div className="stories-strip">
      {stories.map((story) => (
        <div
          key={story.id}
          className="story-item"
          onClick={() => onSelectStory && onSelectStory(story)}
        >
          <div className={`story-ring ${story.hasUnread ? '' : 'seen'}`}>
            <img
              src={story.avatar}
              alt={story.username}
              className="story-avatar"
            />
          </div>
          <span className="story-name">{story.username}</span>
        </div>
      ))}
    </div>
  );
}
