const express = require("express");
const router = express.Router();
const mysql_connection = require("../database/db_connection.js");

router.put("/:id", async (req, res) => {
    const db_connection = await mysql_connection();
    const results = await db_connection.query("UPDATE task SET ? WHERE id = ?", [
        req.body,
        req.params.id
    ]);
    res.sendStatus(204);
});

module.exports = router;