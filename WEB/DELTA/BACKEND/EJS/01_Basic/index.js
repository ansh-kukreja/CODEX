const express = require("express");
const app = express();
const port = 8080;
const path = require("path");


app.use(express.static("public"));  // This is helping me to use "style.css" in "ejs" files
app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "/views"));




app.get("/", (req, res) => {
    res.render("home.ejs");
});

app.get("/rolldice", (req, res) => {
    let diceNum = Math.floor(Math.random() * 6) + 1;

    res.render("rolldice.ejs", { diceNum });
});

app.get("/ig/:username", (req, res) => {
    let { username } = req.params
    const instagramData = require("./data.json");
    let data = instagramData[username];

    res.render("instagram.ejs", { data, username });
});




app.listen(port, () => {
    console.log(`listening on Port ${port}`);
});
