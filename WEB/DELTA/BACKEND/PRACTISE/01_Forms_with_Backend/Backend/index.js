const express = require("express");
const app = express();
const PORT = 8080;


// By default, we can't read data from "req.body", we have to parse the data first using
// these two middlewares
app.use(express.urlencoded({extended: true}));
app.use(express.json());


app.get("/register", (req, res) => {
    let {user,  password} = req.query;
    res.send(`Standard GET Response, Welcome ${user}`);
});

app.post("/register", (req, res) => {
    let {user,  password} = req.body;
    res.send(`Standard POST Response, Welcome ${user}`);
});

app.listen(PORT, () => {
    console.log(`listening on PORT: ${PORT}`);
});