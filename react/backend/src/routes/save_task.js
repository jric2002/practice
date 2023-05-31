const express = require("express");
const router = express.Router();
const mysql_connection = require("../database/db_connection.js");

router.post("/", async (req, res) => {
    const db_connection = await mysql_connection();
    const results = await db_connection.query("INSERT INTO task (title, description) VALUES (?, ?)", [
        req.body.title,
        req.body.description
    ]);
    res.json({
        id: results[0]["insertId"],
        title: req.body.title,
        description: req.body.description
    });
});

module.exports = router;