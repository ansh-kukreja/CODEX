FROM node:20-alpine

WORKDIR /app

COPY package*.json ./
RUN npm install --omit=dev

COPY . .

EXPOSE 5005

ENV NODE_ENV=production
ENV PORT=5005

CMD ["node", "src/server.js"]
