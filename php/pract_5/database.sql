CREATE DATABASE IF NOT EXISTS biblioteca;
USE biblioteca;
CREATE TABLE IF NOT EXISTS libro (
  id_libros INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  titulo VARCHAR (50) NOT NULL,
  descripcion TEXT
);
INSERT INTO libro (titulo, descripcion) VALUES
("Libro de JavaScript", "Con este libro aprenderas a programar en JavaScript"),
("Libro de Html5", "Html5 es un lenguaje de marcado"),
("Libro de Css", "Aprende CSS para darle estilo a tu pagina web");
CREATE TABLE IF NOT EXISTS usuario (
  id_usuario INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  usuario TEXT NOT NULL,
  password TEXT NOT NULL
);
INSERT INTO usuario (usuario, password) VALUES
("jose", "jose"),
("daniel", "daniel"),
("marco", "marco");