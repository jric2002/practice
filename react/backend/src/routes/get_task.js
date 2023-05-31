const express = require("express");
const router = express.Router();
const mysql_connection = require("../database/db_connection.js");

router.get("/", async (req, res) => {
    const db_connection = await mysql_connection();
    const [rows] = await db_connection.query("SELECT * FROM task");
    res.json(rows);
});
router.get("/:id", async (req, res) => {
    const db_connection = await mysql_connection();
    const [rows] = await db_connection.query("SELECT * FROM task WHERE id = ?", [req.params.id]);
    res.json(rows);
});

module.exports = router;