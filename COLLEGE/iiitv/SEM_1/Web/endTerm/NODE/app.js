var express = require('express'); 

var app = express();

app.get('/',  (req, res) => { 
    res.send('This is Demo of express!');
});
app.listen(5000);




// const express = require('express');
// const app = express();

// app.all((req, res, next) => {
//     console.log('Accessing the secret section ...')
//     next()
// })

// app.get('/', (req, res) => {
//     res.send('hello world') });

//     app.get('/home', (req, res) => { 
//         res.send('home page'
//     )
// })

// app.get('/*', (req, res) => {
//     res.send('error 404 page not found')
// })

// app.post('/', (req, res) => {
//     res.send('POST request to the homepage')
// })

// app.listen(8080, () => {
//     console.log('server started on port 8080')
// })
