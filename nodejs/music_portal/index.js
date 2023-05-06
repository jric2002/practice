const express = require("express");
const path = require("path");
const app = express();
const port = 80;
var mysql = require("mysql");
var connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: 'admin',
  database: 'music_portal'
});
connection.connect();
app.use('/', express.static(__dirname + '/public'));
app.use(express.json());
app.post('/search', function(req, res) {
  console.log(req.body);
  const query = 'SELECT songs.id, songs.title, artists.name FROM songs, artists WHERE title LIKE "%' + req.body["song"] + '%" AND songs.artist = artists.id';
  connection.query(query, function(err, rows, fields) {
    if (err) {
      throw err;
    }
    console.log(rows);
    res.json(rows);
  });
});
app.get('/song/:id', function(req, res) {
  res.sendFile(path.normalize(path.join(__dirname, "songs", (req.params.id).toString(), "cover.jpg")))
});
app.listen(port, () => {
  console.log("Server online");
});
app.use(function(req, res, next) {
  res.status(404).send("<h1 style=\"text-align: center; margin: 3rem auto;\">Error 404</h1>")
});