import React from 'react';
import { Globe, Bell, Sparkles, Sliders } from 'lucide-react';

export default function TopHeader({ onOpenInspector, currentTab, setCurrentTab }) {
  return (
    <header className="top-nav-bar">
      <div className="app-brand">
        <span className="brand-sub">Social Web Services</span>
        <h1 className="greeting-text">Hi, Melanie</h1>
      </div>

      <div className="top-actions">
        {/* Toggle live REST Checklist & Architecture Inspector */}
        <button
          className="icon-btn-circle active-badge"
          onClick={onOpenInspector}
          title="Open REST & Checklist Inspector"
          style={{ background: 'rgba(37, 99, 235, 0.3)', borderColor: '#38bdf8' }}
        >
          <Sparkles size={20} color="#38bdf8" />
        </button>

        <button
          className="icon-btn-circle"
          onClick={() => setCurrentTab('explore')}
          title="Explore Discovery"
        >
          <Globe size={19} />
        </button>

        <button className="icon-btn-circle" title="Notifications">
          <Bell size={19} />
        </button>
      </div>
    </header>
  );
}
