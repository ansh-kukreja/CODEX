const express = require("express");
const mysql = require("mysql2");
const app = express();

app.use(express.json()); // To read JSON body

// --- MySQL Connection ---
const db = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "",
    database: "testdb"
});

// Connect to database
db.connect((err) => {
    if (err) throw err;
    console.log("MySQL Connected");
});

// ------------------------
//        CRUD API
// ------------------------

// CREATE (Insert)
app.post("/users", (req, res) => {
    const { name, email } = req.body;
    const sql = "INSERT INTO users (name, email) VALUES (?, ?)";
    db.query(sql, [name, email], (err, result) => {
        if (err) throw err;
        res.send("User added");
    });
});

// READ (Get all)
app.get("/users", (req, res) => {
    const sql = "SELECT * FROM users";
    db.query(sql, (err, rows) => {
        if (err) throw err;
        res.json(rows);
    });
});

// UPDATE
app.put("/users/:id", (req, res) => {
    const { name, email } = req.body;
    const { id } = req.params;
    const sql = "UPDATE users SET name = ?, email = ? WHERE id = ?";
    db.query(sql, [name, email, id], (err, result) => {
        if (err) throw err;
        res.send("User updated");
    });
});

// DELETE
app.delete("/users/:id", (req, res) => {
    const { id } = req.params;
    const sql = "DELETE FROM users WHERE id = ?";
    db.query(sql, [id], (err, result) => {
        if (err) throw err;
        res.send("User deleted");
    });
});

// Start server
app.listen(3000, () => {
    // console.log("Server running on port 3000");
});
