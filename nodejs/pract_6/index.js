const express = require("express");
const app = express();
require("dotenv").config();

function logger(req, res, next) {
    console.log(`Route received: ${req.protocol}://${req.get("host")}${req.originalUrl}`);
    next();
}

//Settings
app.set("appName", "Express");
app.set("view engine", "ejs");

//Middlewares
app.use(express.json());
app.use(logger);

app.get("/", (req, res) => {
    const db_users = [
        {name: "john"},
        {name: "jose"}
    ];
    res.render("index.ejs", {people: db_users});
});

app.all("/user", (req, res, next) => {
    console.log("Por aqui paso");
    next();
});

app.get("/user", function(req, res) {
    res.json({
        "username": "jric2002",
        "name": "jose"
    });
});

app.post("/user/:id", (req, res) => {
    console.log(req.body);
    console.log(req.params);
    res.send("user received");
});

app.put("/contact/:id", (req, res) => {
    res.send("Contacto " + String(req.params.id));
});

app.delete("/user/:userID", (req, res) => {
    res.send("User " + String(req.params.userID));
});

app.use(express.static("public"));

app.listen(process.env.PORT, function() {
    console.log("Server active on port " + String(process.env.PORT));
    console.log(app.get("appName"));
});