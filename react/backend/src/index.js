const express = require("express");
const dotenv = require("dotenv");
const morgan = require("morgan");
const color = require("./colors.js");

const app = express();
dotenv.config();
//Settings
app.set("host", process.env.HOST ?? "localhost");
app.set("port", process.env.PORT ?? 3000);

//Middlewares
app.use(morgan("dev"));
app.use(express.json());

//Routes
app.use("/task/update", require("./routes/update_task.js"));
app.use("/task/delete", require("./routes/delete_task.js"));
app.use("/task/save", require("./routes/save_task.js"));
app.use("/task/count", require("./routes/count.js"));
app.use("/task", require("./routes/get_task.js"));

app.listen(app.get("port"), () => {
    console.log("The server is active on port " + app.get("port"));
    console.log("See: " + color.bold + "http://" + app.get("host") + ":" + app.get("port") + "/  o  " + "http://" + (((app.get("host") == "localhost")) ? "127.0.0.1" : "Error") + ":" + app.get("port") + color.reset);
});