const mysql = require("mysql");

module.exports = () => {
    return mysql.createConnection({
        host: "localhost",
        user: "root",
        password: "admin",
        database: "news_portal_nodejs"
    });
};