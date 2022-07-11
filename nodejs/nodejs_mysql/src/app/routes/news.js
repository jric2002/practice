const db_connection = require("../../config/dbConnection.js");

module.exports = (app) => {
    const connection = db_connection();
    app.get("/", (req, res) => {
        connection.query("SELECT * FROM news", (error, result) => {
        res.render("news/news.ejs", {
            news: result
        });
        });
    });
};