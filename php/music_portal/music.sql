CREATE DATABASE IF NOT EXISTS music;
USE music;
SET FOREIGN_KEY_CHECKS = 0;
CREATE TABLE IF NOT EXISTS artists (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  name TEXT NOT NULL
);
CREATE TABLE IF NOT EXISTS songs (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  title TEXT NOT NULL,
  album INT,
  genre INT,
  artist INT NOT NULL,
  duration TIME NOT NULL,
  location TEXT NOT NULL,
  CONSTRAINT songs_artists_fk1
    FOREIGN KEY (artist) REFERENCES artists (id),
  CONSTRAINT songs_albums_fk1
    FOREIGN KEY (album) REFERENCES albums (id),
  CONSTRAINT songs_genres_fk1
    FOREIGN KEY (genre) REFERENCES genres (id)
);
CREATE TABLE IF NOT EXISTS albums (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  artist INT NOT NULL,
  name INT NOT NULL,
  CONSTRAINT albums_artists_fk1
    FOREIGN KEY (artist) REFERENCES artists (id)
);
CREATE TABLE IF NOT EXISTS genres (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  name TEXT NOT NULL
);
CREATE TABLE IF NOT EXISTS collaborations (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  song INT NOT NULL,
  feat INT NOT NULL,
  CONSTRAINT collaborations_songs_fk1
    FOREIGN KEY (song) REFERENCES songs (id),
  CONSTRAINT collaborations_artists_fk1
    FOREIGN KEY (feat) REFERENCES artists (id)
);
CREATE TABLE IF NOT EXISTS users (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  name TEXT NOT NULL,
  gender INT,
  email TEXT NOT NULL,
  username TEXT NOT NULL,
  password TEXT NOT NULL,
  CONSTRAINT users_genders_fk1
    FOREIGN KEY (gender) REFERENCES genders (id)
);
CREATE TABLE IF NOT EXISTS genders (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  gender CHAR (1) NOT NULL
);
INSERT INTO users (name, gender, email, username, password) VALUES
("miguel", NULL, "miguel@gmail.com", "miguel", "miguel");
SET FOREIGN_KEY_CHECKS = 1;
INSERT INTO artists (name) VALUES
("OneRepublic"),
("Danny Ocean"),
("Harry Styles"),
("Laura Pausini"),
("Nacho"),
("Yandel"),
("Bad Bunny");
INSERT INTO songs (title, artist, duration, location) VALUES
("Me Rehúso", 2, "00:03:25", "1"),
("As It Was", 3, "00:02:45", "2"),
("En Cambio No", 4, "00:03:57", "3"),
("Counting Stars", 1, "00:04:43", "4"),
("Báilame (Remix)", 5, "00:03:46", "5");
INSERT INTO collaborations (song, feat) VALUES
(5, 6),
(5, 7);