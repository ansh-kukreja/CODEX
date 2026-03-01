const express = require('express')
const app = express()
const port = 8080


app.get("/", (req, res) => {
    res.send("Home Page");
})



// http://localhost:8080/search?q=IPhone18ProMaxUltraAI

app.get("/search", (req, res) => {
    let { q } = req.query;

    if(!q){
        res.send("<h1>Nothing Searched</h1>");
    }
    
    res.send(`Search Result of Query: ${q}`);
})




app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
}) 