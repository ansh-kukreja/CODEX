var http = require('http');

const server = http.createServer( (req, res) => { 
    res.write("Response from Server"); 
    res.end();
});

server.listen((3000), () => {
    console.log("Server is running at Port 3000");
});




// // server.mjs
// import { createServer } from 'node:http';

// const server = createServer((req, res) => {
//   res.writeHead(200, { 'Content-Type': 'text/plain' });
//   res.end('Hello World!\n');
// });

// // starts a simple http server locally on port 3000
// server.listen(3000, '127.0.0.1', () => {
//   console.log('Listening on 127.0.0.1:3000');
// });

// // run with `node server.mjs`
