CREATE DATABASE IF NOT EXISTS empresa;
USE empresa;
CREATE TABLE empleado (
  nombre VARCHAR (30),
  apellido VARCHAR (30),
  ci VARCHAR (10) NOT NULL,
  fecha_n DATE,
  direccion VARCHAR (30),
  sexo CHAR (1),
  salario INTEGER (4),
  superci VARCHAR (10),
  dno INTEGER (1)
);
CREATE TABLE departamento (
  dnombre VARCHAR (30),
  dnumero INTEGER (1) NOT NULL,
  jefeci VARCHAR (10),
  jefe_fi DATE
);
CREATE TABLE localizacion (
  dnumero INTEGER (1) NOT NULL,
  dep_loca VARCHAR (30)
);
CREATE TABLE trabaja_en (
  eci VARCHAR (10) NOT NULL,
  pno INTEGER (2) NOT NULL,
  horas DOUBLE (4,2)
);
CREATE TABLE proyecto (
  pnombre VARCHAR (30),
  pnumero INTEGER (2) NOT NULL,
  plocal VARCHAR (30),
  dnum INTEGER (1)
);
CREATE TABLE carga_f (
  eci VARCHAR (10) NOT NULL,
  dep_nom VARCHAR (30),
  sexo VARCHAR (1),
  fechan_n DATE,
  relacion VARCHAR (10)
);

ALTER TABLE empleado ADD PRIMARY KEY (ci);
ALTER TABLE departamento ADD PRIMARY KEY (dnumero);
ALTER TABLE proyecto ADD PRIMARY KEY (pnumero);

ALTER TABLE empleado
ADD FOREIGN KEY (dno) REFERENCES departamento (dnumero)
ON DELETE SET NULL
ON UPDATE CASCADE,
ADD FOREIGN KEY (superci) REFERENCES empleado (ci)
ON DELETE SET NULL
ON UPDATE CASCADE;

ALTER TABLE departamento
ADD FOREIGN KEY (jefeci) REFERENCES empleado (ci)
ON DELETE SET NULL
ON UPDATE CASCADE;

ALTER TABLE localizacion
ADD FOREIGN KEY (dnumero) REFERENCES departamento (dnumero)
ON DELETE CASCADE
ON UPDATE CASCADE;

ALTER TABLE trabaja_en
ADD FOREIGN KEY (eci) REFERENCES empleado (ci)
ON DELETE CASCADE
ON UPDATE CASCADE,
ADD FOREIGN KEY (pno) REFERENCES proyecto (pnumero)
ON DELETE CASCADE
ON UPDATE CASCADE;

ALTER TABLE proyecto
ADD FOREIGN KEY (dnum) REFERENCES departamento (dnumero)
ON DELETE SET NULL
ON UPDATE CASCADE;

ALTER TABLE carga_f
ADD FOREIGN KEY (eci) REFERENCES empleado (ci)
ON DELETE CASCADE
ON UPDATE CASCADE;

SET FOREIGN_KEY_CHECKS = 0;
INSERT INTO empleado VALUES
("Juan", "Polo", "123456789", "1959-03-03", "Sucre 7-12", "M", 3000, "333445555", 5),
("Humberto", "Pons", "333445555", "1960-12-25", "Bolivar 5-67", "M", 4000, "888665555", 5),
("Irma", "Vega", "999887777", "1950-11-13", "P Cordova 3-45", "F", 2500, "987654321", 4),
("Elena", "Tapia", "987654321", "1961-05-03", "Ordoñez 7-29", "F", 4300, "888665555", 4),
("Pablo", "Castro", "666884444", "1955-09-15", "Bolivar 1-50", "M", 3800, "333445555", 5),
("Marcia", "Mora", "453453453", "1960-03-29", "Colombia 4-23", "F", 2500, "333445555", 5),
("Manuel", "Bonilla", "987987987", "1958-07-16", "B. Malo 1-10", "M", 2500, "987654321", 4),
("Jaime", "Pérez", "888665555", "1957-04-05", "Sangurima 8-34", "M", 5500, NULL, 1);

INSERT INTO localizacion VALUES
(1, "Cuenca"),
(4, "Guayaquil"),
(5, "Quito"),
(5, "Manta"),
(5, "Cuenca");

INSERT INTO proyecto VALUES
("ProductoX", 1, "Quito", 5),
("ProductoY", 2, "Manta", 5),
("ProductoZ", 3, "Cuenca", 5),
("Computadora", 10, "Guayaquil", 4),
("Reorganizar", 20, "Cuenca", 1),
("Beneficios", 30, "Guayaquil", 4);

INSERT INTO carga_f VALUES
("333445555", "María", "F", "1986-02-02", "Hija"),
("333445555", "Teodoro", "M", "1990-10-10", "Hijo"),
("333445555", "Ana", "F", "1965-09-15", "Cónyuge"),
("987654321", "Alberto", "M", "1967-07-06", "Cónyuge"),
("123456789", "Miguel", "M", "1984-11-05", "Hijo"),
("123456789", "María", "F", "1987-01-09", "Hija"),
("123456789", "Elizabeth", "F", "1960-12-12", "Cónyuge");

INSERT INTO departamento VALUES
("Investigación", 5, "333445555", "1980-05-12"),
("Administrativo", 4, "987654321", "1982-12-05"),
("Compras", 1, "888665555", "1978-06-06");

INSERT INTO trabaja_en VALUES
("123456789", 1, 12.5),
("123456789", 2, 15.6),
("666884444", 3, 14.7),
("453453453", 1, 10),
("453453453", 2, 10),
("333445555", 2, 20),
("333445555", 3, 10),
("333445555", 10, 10),
("333445555", 20, 10),
("999887777", 30, 30),
("999887777", 10, 5),
("987987987", 10, 15),
("987987987", 30, 17),
("987654321", 30, 10),
("987654321", 20, 12),
("888665555", 20, NULL);
SET FOREIGN_KEY_CHECKS = 1;