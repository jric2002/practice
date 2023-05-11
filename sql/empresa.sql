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

INSERT INTO empleado VALUES
("Juan", "Polo", "123456789", "3-mar-59", "Sucre 7-12", "M", 3000, "333445555", 5),
("Humberto", "Pons", "333445555", "25-dic-60", "Bolivar 5-67", "M", 4000, "888665555", 5),
("Irma", "Vega", "999887777", "13-nov-50", "P Cordova 3-45", "F", 2500, "987654321", 4),
("Elena","Tapia","987654321","03-may-61","Ordoñez 7-29","F", 4300, "888665555", 4),
("Pablo","Castro","666884444","15-sep-55","Bolivar 1-50","M", 3800, "333445555", 5),
("Marcia", "Mora", "453453453", "29-mar-60", "Colombia 4-23", "F", 2500, "333445555", 5),
("Manuel", "Bonilla", "987987987", "16-jul-58", "B. Malo 1-10", "M", 2500, "987654321", 4),
("Jaime", "Pérez", "888665555", "5-abr-57", "Sangurima 8-34", "M", 5500, NULL, 1);
INSERT INTO localizacion VALUES
(1, "Cuenca");