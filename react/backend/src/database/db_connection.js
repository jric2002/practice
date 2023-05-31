const mysql2 = require("mysql2/promise");
const config = require("./database");

const connect = async function() {
    const connection = await mysql2.createConnection(config);
    return connection;
};

module.exports = connect;