-- MariaDB --
CREATE DATABASE IF NOT EXISTS music_portal;
USE music_portal;
CREATE TABLE IF NOT EXISTS songs (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  title VARCHAR (50) NOT NULL,
  artist INT NOT NULL,
  genre INT,
  CONSTRAINT fk_songs_artists
    FOREIGN KEY (artist) REFERENCES artists (id),
  CONSTRAINT fk_songs_genres
    FOREIGN KEY (genre) REFERENCES genres (id)
);
CREATE TABLE IF NOT EXISTS artists (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR (50) NOT NULL
);
CREATE TABLE IF NOT EXISTS genres (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR (50) NOT NULL
);

INSERT INTO artists (name) VALUES ("J Balvin");
INSERT INTO artists (name) VALUES ("Nacho");
INSERT INTO artists (name) VALUES ("Makano");
INSERT INTO artists (name) VALUES ("Danny Ocean");
INSERT INTO artists (name) VALUES ("Laura Pausini");

INSERT INTO genres (name) VALUES ("Urbano Latino");
INSERT INTO genres (name) VALUES ("Pop");
INSERT INTO genres (name) VALUES ("Hip-Hop");
INSERT INTO genres (name) VALUES ("Jazz");
INSERT INTO genres (name) VALUES ("K-Pop");

INSERT INTO songs (title, artist, genre) VALUES (
  "Yo Te Lo Dije",
  1,
  1
);
INSERT INTO songs (title, artist, genre) VALUES (
  "Bailame",
  2,
  1
);
INSERT INTO songs (title, artist, genre) VALUES (
  "Dejame Entrar",
  3,
  1
);
INSERT INTO songs (title, artist, genre) VALUES (
  "Me rehúso",
  4,
  1
);
INSERT INTO songs (title, artist, genre) VALUES (
  "En Cambio No",
  5,
  2
);