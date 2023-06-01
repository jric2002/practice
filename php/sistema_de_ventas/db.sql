CREATE DATABASE IF NOT EXISTS sistema_de_ventas;
USE sistema_de_ventas;
CREATE TABLE IF NOT EXISTS clientes (
  id_cliente INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  nombres TEXT,
  apellidos TEXT,
  direccion TEXT
);
CREATE TABLE IF NOT EXISTS productos (
  id_producto INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  nombre TEXT,
  precio DECIMAL (10, 2),
  imagen TEXT
);
CREATE TABLE IF NOT EXISTS ventas (
  id_venta INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  id_cliente INT NOT NULL,
  fecha_venta DATE,
  fecha_registro_venta DATETIME,
  venta_total DECIMAL (10, 2),
  CONSTRAINT fk_ventas_clientes
    FOREIGN KEY (id_cliente) REFERENCES clientes (id_cliente)
);
CREATE TABLE IF NOT EXISTS detalles (
  id_detalle INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
  id_venta INT NOT NULL,
  id_producto INT NOT NULL,
  cantidad INT NOT NULL,
  CONSTRAINT fk_detalles_venta
    FOREIGN KEY (id_venta) REFERENCES ventas (id_venta),
  CONSTRAINT fk_detalles_producto
    FOREIGN KEY (id_producto) REFERENCES productos (id_producto)
);
INSERT INTO clientes (nombres, apellidos, direccion) VALUES
("Edwin", "Calderon", "Av. Floral"),
("Jose", "Castro", "Av. La Torre"),
("Hernan", "Apaza", "Jr. Los Incas"),
("Maria", "Nuñez", "Jr. Los claveles");
INSERT INTO productos (nombre, precio, imagen) VALUES
("Leche Gloria", 3.5, "img_1.jpg"),
("Arroz costeño", 5, "img_2.jpg"),
("Nescafe", 2, "img_3.jpg"),
("Ajinomen", 2.3, "img_4.jpg");
INSERT INTO ventas (id_cliente, fecha_venta, fecha_registro_venta, venta_total) VALUES
(2, CURRENT_DATE(), NOW(), 10.5),
(3, CURRENT_DATE() + INTERVAL 1 DAY, NOW() + INTERVAL 1 DAY + INTERVAL 10 SECOND, 5.5),
(1, CURRENT_DATE() + INTERVAL 2 DAY, NOW() + INTERVAL 2 DAY, 2.3),
(4, CURRENT_DATE() + INTERVAL 2 DAY, NOW() + INTERVAL 3 DAY + INTERVAL 5 SECOND, 5);