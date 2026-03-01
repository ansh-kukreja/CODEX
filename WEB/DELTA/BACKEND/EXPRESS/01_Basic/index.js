const express = require('express')
const app = express()
const port = 8080


app.use((req, res) => {
    console.log("Request Received!");

    // res.send('Hello World!')
    res.send("<h1>Dil to Bacha hai Ji</h1> <br><br> <p>Thora kachha hai ji..</p>");
})


app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})