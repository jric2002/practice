const http = require("http");
const color = require("./colors.js");

const hostname = "127.0.0.1";
const port = 4545;

/*
const server = http.createServer((req, res) => {
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/plain");
    res.end("Hello world");
});
*/

//server.listen(port, hostname, () => {
    console.log(color.bright + 'Server running at http://${hostname}:${port}/' + color.reset);
    console.log(color.dim + 'Server running at http://${hostname}:${port}/' + color.reset);
    console.log(color.underscore + 'Server running at http://${hostname}:${port}/' + color.reset);
    console.log(color.blink + 'Server running at http://${hostname}:${port}/' + color.reset);
    console.log(color.reverse + 'Server running at http://${hostname}:${port}/' + color.reset);
    console.log(color.white + 'Server running at http://${hostname}:${port}/' + color.reset);
    console.log(color.green + 'Server running at http://${hostname}:${port}/' + color.reset);
    console.log("\n");
//});