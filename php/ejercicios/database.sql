CREATE DATABASE IF NOT EXISTS ejemplo_db;
USE ejemplo_db;
CREATE TABLE IF NOT EXISTS datos (
  id INT NOT NULL AUTO_INCREMENT,
  user VARCHAR (30),
  pass TEXT,
  PRIMARY KEY (id)
);
INSERT INTO datos (user, pass) VALUES ("admin", "admin");