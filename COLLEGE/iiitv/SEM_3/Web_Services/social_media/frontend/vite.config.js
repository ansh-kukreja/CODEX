import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';

export default defineConfig({
  plugins: [react()],
  server: {
    port: 5173,
    proxy: {
      '/api': {
        target: 'http://localhost:5005',
        changeOrigin: true
      },
      '/graphql': {
        target: 'http://localhost:5005',
        changeOrigin: true
      },
      '/soap': {
        target: 'http://localhost:5005',
        changeOrigin: true
      },
      '/api-docs': {
        target: 'http://localhost:5005',
        changeOrigin: true
      }
    }
  }
});
