<?php session_start();
if (!isset($_SESSION['nombre']))
{
    header('Location: login.php');
}
elseif (isset($_SESSION['nombre']))
{
    include 'conexion.php';
    $sentencia = $bd->query("SELECT * FROM alumno;");
    $alumnos = $sentencia->fetchAll(PDO::FETCH_OBJ);
    //print_r($alumnos); }else{ echo "Error en el sistema";
}
?>
<!doctype html>
<html lang="es">

<head>
	<!-- Required meta tags -->
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
	<!-- Bootstrap CSS -->
	<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
	<title>Sistema académico</title>
	<style>
	.card {
		width: 60%;
	}
	</style>
</head>

<body>
	<nav class="navbar navbar-expand-lg navbar-dark bg-dark"> <a class="navbar-brand" href="#">Sistema académico</a>
		<div class="collapse navbar-collapse d-flex justify-content-end" id="navbarSupportedContent">
			<ul class="navbar-nav ml-auto">
				<li class="nav-item"> <a class="nav-link" href="listado.php">Listado</a> </li>
				<li class="nav-item"> <a class="nav-link" href="registro.php">Registro</a> </li>
				<li class="nav-item"> <a class="nav-link btn btn-success btn-sm" href="cerrar.php">Cerrar sesion</a> </li>
			</ul>
		</div>
        </nav>
<div class="container my-4">
	<div class="card mx-auto">
		<div class="card-header">
			<h3>Registro de estudiante</h3></div>
		<div class="card-body">
			<form method="POST" action="insertar.php">
				<div class="form-group row">
					<label for="inputEmail3" class="col-sm-3 col-form-label">Apellido paterno</label>
					<div class="col-sm-9">
						<input type="text" class="form-control" placeholder="Ingrese apellido paterno" name="txtPaterno"> </div>
				</div>
				<div class="form-group row">
					<label for="inputPassword3" class="col-sm-3 col-form-label">Apellido materno</label>
					<div class="col-sm-9">
						<input type="text" class="form-control" placeholder="Ingrese apellido materno" name="txtMaterno"> </div>
				</div>
				<div class="form-group row">
					<label for="inputEmail3" class="col-sm-3 col-form-label">Nombres</label>
					<div class="col-sm-9">
						<input type="text" class="form-control" placeholder="Ingrese el nombre" name="txtNombre"> </div>
				</div>
				<div class="form-group row">
					<label for="inputPassword3" class="col-sm-3 col-form-label">Nota 1</label>
					<div class="col-sm-9">
						<input type="number" class="form-control" placeholder="Ingrese la nota 1" name="txtParcial"> </div>
				</div>
				<div class="form-group row">
					<label for="inputPassword3" class="col-sm-3 col-form-label">Nota 2</label>
					<div class="col-sm-9">
                    <input type="number" class="form-control" placeholder="Ingrese la nota 2" name="txtFinal"> </div>
</div>
<input type="hidden" name="oculto" value="1">
<div class="form-group row">
	<div class="col-sm-10">
		<button type="submit" class="btn btn-primary">Registrar estudiante</button>
	</div>
</div>
</form>
</div>
</div>
</div>
<!-- Bootstrap js -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html>