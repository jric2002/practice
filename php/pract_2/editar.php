<?php session_start();
if (!isset($_GET['id']))
{
    header('Location: listado.php');
}
if (!isset($_SESSION['nombre']))
{
    header('Location: login.php');
}
elseif (isset($_SESSION['nombre']))
{
    include 'conexion.php';
    $id = $_GET['id'];
    $sentencia = $bd->prepare("SELECT * FROM alumno WHERE id_alumno = ?;");
    $sentencia->execute([$id]);
    $persona = $sentencia->fetch(PDO::FETCH_OBJ); //print_r($persona);
}else{ echo "Error en el sistema"; } ?>
<!DOCTYPE html>
<html>

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
	<div class="container my-4">
		<div class="card mx-auto">
			<div class="card-header">
				<h3>Editar estudiante</h3></div>
			<div class="card-body">
				<form method="POST" action="editarProceso.php">
					<div class="form-group row">
						<label for="inputEmail3" class="col-sm-3 col-form-label">Apellido paterno</label>
						<div class="col-sm-9">
							<input type="text" class="form-control" name="txt2Paterno" value="<?php echo $persona->ap_paterno; ?>"> </div>
					</div>
					<div class="form-group row">
						<label for="inputPassword3" class="col-sm-3 col-form-label">Apellido materno</label>
						<div class="col-sm-9">
							<input type="text" class="form-control" name="txt2Materno" value="<?php echo $persona->ap_materno; ?>"> </div>
					</div>
                    <div class="form-group row">
	<label for="inputEmail3" class="col-sm-3 col-form-label">Nombres</label>
	<div class="col-sm-9">
		<input type="text" class="form-control" name="txt2Nombre" value="<?php echo $persona->nombre; ?>"> </div>
</div>
<div class="form-group row">
	<label for="inputPassword3" class="col-sm-3 col-form-label">Nota 1</label>
	<div class="col-sm-9">
		<input type="number" class="form-control" name="txt2Parcial" value="<?php echo $persona->ex_parcial; ?>"> </div>
</div>
<div class="form-group row">
	<label for="inputPassword3" class="col-sm-3 col-form-label">Nota 2</label>
	<div class="col-sm-9">
		<input type="number" class="form-control" name="txt2Final" value="<?php echo $persona->ex_final; ?>"> </div>
</div>
<input type="hidden" name="oculto" value="1">
<div class="form-group row">
	<div class="col-sm-10">
		<input type="hidden" name="oculto">
		<input type="hidden" name="id2" value="<?php echo $persona->id_alumno; ?>">
		<button type="submit" class="btn btn-primary">Guardar</button>
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