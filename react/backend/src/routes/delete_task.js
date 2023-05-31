const express = require("express");
const router = express.Router();
const mysql_connection = require("../database/db_connection.js");

router.delete("/:id", async (req, res) => {
    const db_connection = await mysql_connection();
    const result = await db_connection.query("DELETE FROM task WHERE id = ?", [req.params.id]);
    res.sendStatus(204);
});

module.exports = router;