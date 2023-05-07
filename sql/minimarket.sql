CREATE DATABASE IF NOT EXISTS minimarket;
USE minimarket;
CREATE TABLE IF NOT EXISTS productos (
  codigo INT (11) NOT NULL PRIMARY KEY,
  nombre VARCHAR (30) NOT NULL,
  costo INT (11) NOT NULL,
  impuesto INT (11) NOT NULL,
  precio INT (11) NOT NULL,
  familia VARCHAR (30) NOT NULL
);
CREATE TABLE IF NOT EXISTS proveedores (
  id_proveedor INT (11) NOT NULL PRIMARY KEY,
  nombre VARCHAR (11) NOT NULL,
  vendedor INT (11) NOT NULL,
  telefono INT (11) NOT NULL
);
CREATE TABLE IF NOT EXISTS roles (
  id INT (11) NOT NULL PRIMARY KEY,
  nombre VARCHAR (30) NOT NULL
);
CREATE TABLE IF NOT EXISTS usuarios (
  dni INT (8) NOT NULL PRIMARY KEY,
  nombres VARCHAR (30) NOT NULL,
  apellidos VARCHAR (30) NOT NULL,
  telefono VARCHAR (9) NOT NULL,
  correo VARCHAR (30) NOT NULL,
  rol INT (11) NOT NULL,
  password TEXT NOT NULL,
  CONSTRAINT usuarios_roles_fk1
    FOREIGN KEY (rol) REFERENCES roles (id)
);
CREATE TABLE IF NOT EXISTS compras (
  codigo_producto INT (11) NOT NULL,
  id_proveedor INT (11) NOT NULL,
  cantidad INT (11) NOT NULL,
  precio INT (11) NOT NULL,
  fecha DATE NOT NULL,
  CONSTRAINT compras_productos_fk1
    FOREIGN KEY (codigo_producto) REFERENCES productos (codigo),
  CONSTRAINT compras_proveedores_fk1
    FOREIGN KEY (id_proveedor) REFERENCES proveedores (id_proveedor)
);
CREATE TABLE IF NOT EXISTS ventas (
  codigo_producto INT (11) NOT NULL,
  dni_usuario INT (8) NOT NULL,
  precio INT (11) NOT NULL,
  cantidad INT (11) NOT NULL,
  fecha DATE NOT NULL,
  nro_boleta INT (11) NOT NULL,
  CONSTRAINT ventas_productos_fk1
    FOREIGN KEY (codigo_producto) REFERENCES productos (codigo),
  CONSTRAINT ventas_usuarios_fk1
    FOREIGN KEY (dni_usuario) REFERENCES usuarios (dni)
);