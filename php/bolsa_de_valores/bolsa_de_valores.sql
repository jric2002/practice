CREATE DATABASE IF NOT EXISTS bolsa_de_valores;
USE bolsa_de_valores;
SET FOREIGN_KEY_CHECKS = 0;
CREATE TABLE acciones (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  nombre_empresa VARCHAR (50) NOT NULL,
  precio_actual FLOAT NOT NULL
);
CREATE TABLE transacciones (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  id_usuario INT NOT NULL,
  id_accion INT NOT NULL,
  cantidad INT NOT NULL,
  precio_compra FLOAT NOT NULL,
  fecha_compra DATE NOT NULL,
  FOREIGN KEY (id_usuario) REFERENCES users(id),
  FOREIGN KEY (id_accion) REFERENCES acciones(id)
);
CREATE TABLE IF NOT EXISTS users (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  name TEXT NOT NULL,
  gender INT,
  email TEXT NOT NULL,
  dinero DECIMAL (10, 2),
  username TEXT NOT NULL,
  password TEXT NOT NULL,
  CONSTRAINT users_genders_fk1
    FOREIGN KEY (gender) REFERENCES genders (id)
);
CREATE TABLE IF NOT EXISTS genders (
  id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  gender CHAR (1) NOT NULL
);
INSERT INTO acciones (nombre_empresa, precio_actual) VALUES
('Apple', 127.14),
('Amazon', 3203.08),
('Tesla', 662.16),
('Netflix', 330.22),
('Intel', 153.20),
('Autodesk', 215.32),
('American Express', 174.33),
('Facebook Meta', 309.34),
('IBM', 132.85),
('Twitter', 53.7);
INSERT INTO genders (gender) VALUES
('M'),
('F');
INSERT INTO transacciones (id_usuario, id_accion, cantidad, precio_compra, fecha_compra) VALUES
(1, 2, 10, 3180.25, '2021-10-01'),
(2, 3, 5, 650.50, '2021-09-15');
SET FOREIGN_KEY_CHECKS = 1;