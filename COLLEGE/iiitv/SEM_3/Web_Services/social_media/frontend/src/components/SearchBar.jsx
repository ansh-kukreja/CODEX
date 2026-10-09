import React from 'react';
import { Search, SlidersHorizontal } from 'lucide-react';

export default function SearchBar({ searchTerm, onSearchChange, onFilterClick }) {
  return (
    <div className="search-filter-section">
      <div className="search-pill-box">
        <Search size={18} color="rgba(255, 255, 255, 0.6)" />
        <input
          type="text"
          className="search-input"
          placeholder="Search friends, concerts, vibes..."
          value={searchTerm}
          onChange={(e) => onSearchChange(e.target.value)}
        />
        <button
          onClick={onFilterClick}
          style={{
            background: 'transparent',
            border: 'none',
            color: 'rgba(255, 255, 255, 0.75)',
            cursor: 'pointer',
            display: 'flex',
            alignItems: 'center'
          }}
          title="Filter categories"
        >
          <SlidersHorizontal size={18} />
        </button>
      </div>
    </div>
  );
}
