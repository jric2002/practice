const app = require("./config/server.js");
require("./app/routes/news.js")(app);

//Starting the server
app.listen(app.get("port"), () => {
    console.log("server on port " + String(app.get("port")));
});