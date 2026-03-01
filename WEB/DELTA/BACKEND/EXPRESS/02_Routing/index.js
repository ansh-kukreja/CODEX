const express = require('express')
const app = express()
const port = 8080


app.get("/", (req, res) => {
    res.send("Home Page");
})

app.get("/Mango", (req, res) => {
    res.send("Mango Page");
})

app.post("/", (req, res) => {
    res.send("You sendin me a Post Request beech");
})


app.use((req, res) => {
    res.send("Dayyuuumm! WTF are you searching... Whatever it is.. i can't find it");
});



app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
}) 