const express = require("express");
const router = express.Router();
const db = require("./../database/db_connection.js");

router.get("/", async (req, res) => {
    const db_connection = await db();
    const [rows] = await db_connection.query("SELECT COUNT(*) FROM task");
    console.log("rows");
    res.json(rows[0]["COUNT(*)"]);
});

module.exports = router;