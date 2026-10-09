// Static data for NamoGram (social media platform like Instagram with modern blue theme)
// Contains initial mock database data as requested ("do not use any database yet, show only static data")

const staticUsers = [
  {
    id: 'usr_melanie',
    username: 'melanie_v',
    name: 'Melanie Vance',
    avatar: 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=300&h=300&fit=crop&crop=face',
    bio: 'Digital creator & music lover 🎶 Living between Boston & NYC. Discovering new friendships!',
    location: 'Boston, MA',
    followersCount: 1420,
    followingCount: 380,
    postsCount: 12,
    role: 'user',
    verified: true
  },
  {
    id: 'usr_alan',
    username: 'alaniewalker1',
    name: 'Alan Walker',
    avatar: 'https://images.unsplash.com/photo-1507003211169-0a1dd7228f2d?w=300&h=300&fit=crop&crop=face',
    bio: 'Touring & jamming. Always down for live concerts 🎸 Boston, Willson Str.',
    location: 'Boston, MA',
    followersCount: 28900,
    followingCount: 520,
    postsCount: 45,
    role: 'creator',
    verified: true
  },
  {
    id: 'usr_sussie',
    username: 'sussie_limberg',
    name: 'Sussie Limberg',
    avatar: 'https://images.unsplash.com/photo-1517841905240-472988babdf9?w=300&h=300&fit=crop&crop=face',
    bio: 'Art director & cafe hopper ☕ Always organizing meetups.',
    location: 'Boston, MA',
    followersCount: 3450,
    followingCount: 610,
    postsCount: 28,
    role: 'user',
    verified: false
  },
  {
    id: 'usr_matt',
    username: 'matt_iven',
    name: 'Matt Iven',
    avatar: 'https://images.unsplash.com/photo-1500648767791-00dcc994a43e?w=300&h=300&fit=crop&crop=face',
    bio: 'Urban photography & hiking expeditions 🏔️ Boston tech scene.',
    location: 'Boston, MA',
    followersCount: 8900,
    followingCount: 410,
    postsCount: 64,
    role: 'user',
    verified: true
  },
  {
    id: 'usr_amber',
    username: 'amber_winston',
    name: 'Amber Winston',
    avatar: 'https://images.unsplash.com/photo-1494790108377-be9c29b29330?w=300&h=300&fit=crop&crop=face',
    bio: 'Sunset chaser 🌅 Community lead @ Boston Creative Collective.',
    location: 'Boston, MA',
    followersCount: 12400,
    followingCount: 890,
    postsCount: 51,
    role: 'user',
    verified: true
  },
  {
    id: 'usr_nicky',
    username: 'nicky_tenyson',
    name: 'Nicky Tenyson',
    avatar: 'https://images.unsplash.com/photo-1539571696357-5a69c17a67c6?w=300&h=300&fit=crop&crop=face',
    bio: 'Electronic sound designer & vinyl collector 🎧',
    location: 'Boston, MA',
    followersCount: 5200,
    followingCount: 330,
    postsCount: 19,
    role: 'user',
    verified: false
  }
];

const staticStories = [
  {
    id: 'sty_1',
    userId: 'usr_melanie',
    username: 'Your Story',
    avatar: 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=300&h=300&fit=crop&crop=face',
    hasUnread: false,
    mediaUrl: 'https://images.unsplash.com/photo-1511671782779-c97d3d27a1d4?w=800&h=1200&fit=crop'
  },
  {
    id: 'sty_2',
    userId: 'usr_alan',
    username: 'alaniewalker1',
    avatar: 'https://images.unsplash.com/photo-1507003211169-0a1dd7228f2d?w=300&h=300&fit=crop&crop=face',
    hasUnread: true,
    mediaUrl: 'https://images.unsplash.com/photo-1470225620780-dba8ba36b745?w=800&h=1200&fit=crop'
  },
  {
    id: 'sty_3',
    userId: 'usr_sussie',
    username: 'sussie_limberg',
    avatar: 'https://images.unsplash.com/photo-1517841905240-472988babdf9?w=300&h=300&fit=crop&crop=face',
    hasUnread: true,
    mediaUrl: 'https://images.unsplash.com/photo-1501386761578-eac5c94b800a?w=800&h=1200&fit=crop'
  },
  {
    id: 'sty_4',
    userId: 'usr_matt',
    username: 'matt_iven',
    avatar: 'https://images.unsplash.com/photo-1500648767791-00dcc994a43e?w=300&h=300&fit=crop&crop=face',
    hasUnread: true,
    mediaUrl: 'https://images.unsplash.com/photo-1464822759023-fed622ff2c3b?w=800&h=1200&fit=crop'
  },
  {
    id: 'sty_5',
    userId: 'usr_amber',
    username: 'amber_winston',
    avatar: 'https://images.unsplash.com/photo-1494790108377-be9c29b29330?w=300&h=300&fit=crop&crop=face',
    hasUnread: true,
    mediaUrl: 'https://images.unsplash.com/photo-1507525428034-b723cf961d3e?w=800&h=1200&fit=crop'
  }
];

const staticPosts = [
  {
    id: 'post_1',
    userId: 'usr_alan',
    author: {
      id: 'usr_alan',
      username: 'alaniewalker1',
      name: 'Alan Walker',
      avatar: 'https://images.unsplash.com/photo-1507003211169-0a1dd7228f2d?w=300&h=300&fit=crop&crop=face',
      verified: true
    },
    caption: 'Hi, tomorrow we will go check out my brothers band, I have few extra tickets, whos in?',
    imageUrl: 'https://images.unsplash.com/photo-1514525253161-7a46d19cd819?w=1080&h=800&fit=crop',
    location: 'Boston, Willson Str. 16, 10989',
    eventTime: 'Tomorrow 8:00pm',
    capacity: '7/10 people',
    timeRemaining: '23:46 min remaining',
    likesCount: 342,
    commentsCount: 18,
    isLiked: false,
    isSaved: false,
    tags: ['music', 'concert', 'boston', 'tickets'],
    createdAt: '2026-09-08T18:30:00.000Z',
    updatedAt: '2026-09-08T18:30:00.000Z'
  },
  {
    id: 'post_2',
    userId: 'usr_sussie',
    author: {
      id: 'usr_sussie',
      username: 'sussie_limberg',
      name: 'Sussie Limberg',
      avatar: 'https://images.unsplash.com/photo-1517841905240-472988babdf9?w=300&h=300&fit=crop&crop=face',
      verified: false
    },
    caption: 'Gallery opening night & rooftop acoustic session under the blue twilight. Come say hi!',
    imageUrl: 'https://images.unsplash.com/photo-1492684223066-81342ee5ff30?w=1080&h=800&fit=crop',
    location: 'Boston, Willson Str. 36, 11989',
    eventTime: 'Tomorrow 11:30am',
    capacity: '4/4 people',
    timeRemaining: '8:51 min remains',
    status: 'Cancelled',
    likesCount: 189,
    commentsCount: 9,
    isLiked: false,
    isSaved: true,
    tags: ['art', 'boston', 'acoustic', 'rooftop'],
    createdAt: '2026-09-08T16:15:00.000Z',
    updatedAt: '2026-09-08T16:15:00.000Z'
  },
  {
    id: 'post_3',
    userId: 'usr_matt',
    author: {
      id: 'usr_matt',
      username: 'matt_iven',
      name: 'Matt Iven',
      avatar: 'https://images.unsplash.com/photo-1500648767791-00dcc994a43e?w=300&h=300&fit=crop&crop=face',
      verified: true
    },
    caption: 'Sunrise mountain trail run before the city wakes up. 12k with breathtaking views.',
    imageUrl: 'https://images.unsplash.com/photo-1506744038136-46273834b3fb?w=1080&h=800&fit=crop',
    location: 'Boston, Abriam First Str. 2, 12624',
    eventTime: 'Tomorrow 9:15am',
    capacity: '4/5 people',
    timeRemaining: '7:14 min remains',
    likesCount: 820,
    commentsCount: 34,
    isLiked: true,
    isSaved: false,
    tags: ['trail', 'running', 'nature', 'fitness'],
    createdAt: '2026-09-08T12:00:00.000Z',
    updatedAt: '2026-09-08T12:00:00.000Z'
  },
  {
    id: 'post_4',
    userId: 'usr_amber',
    author: {
      id: 'usr_amber',
      username: 'amber_winston',
      name: 'Amber Winston',
      avatar: 'https://images.unsplash.com/photo-1494790108377-be9c29b29330?w=300&h=300&fit=crop&crop=face',
      verified: true
    },
    caption: 'Golden hour at Limonwin beach house. Bonfire, chill tunes, and warm sea breeze 🌊',
    imageUrl: 'https://images.unsplash.com/photo-1507525428034-b723cf961d3e?w=1080&h=800&fit=crop',
    location: 'Boston, Limonwin Str. 78, 11475',
    eventTime: '12.6.2026 6:30pm',
    capacity: '4/7 people',
    timeRemaining: '3 d 7 min remains',
    likesCount: 1450,
    commentsCount: 52,
    isLiked: false,
    isSaved: false,
    tags: ['beach', 'chill', 'goldenhour', 'summer'],
    createdAt: '2026-09-07T20:45:00.000Z',
    updatedAt: '2026-09-07T20:45:00.000Z'
  },
  {
    id: 'post_5',
    userId: 'usr_nicky',
    author: {
      id: 'usr_nicky',
      username: 'nicky_tenyson',
      name: 'Nicky Tenyson',
      avatar: 'https://images.unsplash.com/photo-1539571696357-5a69c17a67c6?w=300&h=300&fit=crop&crop=face',
      verified: false
    },
    caption: 'Late night modular synth recording session. Dropping the blue tape tomorrow!',
    imageUrl: 'https://images.unsplash.com/photo-1598488035139-bdbb2231ce04?w=1080&h=800&fit=crop',
    location: 'Boston, Studio 9',
    eventTime: 'Completed',
    capacity: 'Done',
    timeRemaining: 'Archived',
    likesCount: 630,
    commentsCount: 21,
    isLiked: true,
    isSaved: true,
    tags: ['musicproduction', 'synths', 'studio'],
    createdAt: '2026-09-06T23:10:00.000Z',
    updatedAt: '2026-09-06T23:10:00.000Z'
  }
];

const staticComments = [
  {
    id: 'cmt_1',
    postId: 'post_1',
    userId: 'usr_melanie',
    username: 'melanie_v',
    avatar: 'https://images.unsplash.com/photo-1534528741775-53994a69daeb?w=300&h=300&fit=crop&crop=face',
    content: 'Count me in Alan! Dying to hear the new guitar solos 🎸✨',
    createdAt: '2026-09-08T19:00:00.000Z'
  },
  {
    id: 'cmt_2',
    postId: 'post_1',
    userId: 'usr_matt',
    username: 'matt_iven',
    avatar: 'https://images.unsplash.com/photo-1500648767791-00dcc994a43e?w=300&h=300&fit=crop&crop=face',
    content: 'Saving 2 spots for me and Sarah if still available!',
    createdAt: '2026-09-08T19:12:00.000Z'
  },
  {
    id: 'cmt_3',
    postId: 'post_2',
    userId: 'usr_amber',
    username: 'amber_winston',
    avatar: 'https://images.unsplash.com/photo-1494790108377-be9c29b29330?w=300&h=300&fit=crop&crop=face',
    content: 'Oh no! Reschedule for next week please, we will all join! ❤️',
    createdAt: '2026-09-08T17:05:00.000Z'
  }
];

module.exports = {
  staticUsers,
  staticStories,
  staticPosts,
  staticComments
};
