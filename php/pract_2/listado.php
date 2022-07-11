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
}
else
{
    echo "Error en el sistema";
} ?>
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
			<ul class="navbar-nav > <li class=" nav-item "> <a class="nav-link " href="listado.php ">Listado</a> </li> <li class="nav-item "> <a class="nav-link " href="registro.php ">Registro</a> </li> <li class="nav-item "> <a class="nav-link btn btn-success btn-sm " href="cerrar.php ">Cerrar sesion</a> </li>
            </ul>
</div>
</nav>
<div class="container mt-4">
	<h3>Relación de estudiantes</h3>
	<table class="table table-striped">
		<thead>
			<tr>
				<th scope="col">Código</th>
				<th scope="col">Apellido paterno</th>
				<th scope="col">Apellido materno</th>
				<th scope="col">Nombres</th>
				<th scope="col">Nota 1</th>
				<th scope="col">Nota 2</th>
				<th scope="col">Promedio</th>
				<th scope="col">Editar</th>
				<th scope="col">Eliminar</th>
			</tr>
		</thead>
		<?php foreach ($alumnos as $dato) { ?>
			<tbody>
				<tr>
					<td>
						<?php echo $dato->id_alumno; ?>
					</td>
					<td>
						<?php echo $dato->ap_paterno; ?>
					</td>
					<td>
						<?php echo $dato->ap_materno; ?>
					</td>
					<td>
						<?php echo $dato->nombre; ?>
					</td>
					<td>
						<?php echo $dato->ex_parcial; ?>
					</td>
					<td>
						<?php echo $dato->ex_final; ?>
					</td>
					<td>
						<?php echo ($dato->ex_final + $dato->ex_parcial)/2; ?>
					</td>
					<td>
						<a href="editar.php?id=<?php echo $dato->id_alumno; ?>">
							<button type="button" class="btn btn-success btn-sm">&#x2714;</button>
						</a>
					</td>
					<td>
						<a href="eliminar.php?id=<?php echo $dato->id_alumno; ?>">
							<button type="button" class="btn btn-danger btn-sm"> X </button>
						</a>
					</td>
				</tr>
			</tbody>
            <?php } ?>
	</table>
	</div>
	<!-- Bootstrap js -->
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
	</body>

	</html>