<?php
session_start();
if (isset($_SESSION['nombre'])) {
    header('Location: listado.php');
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
    <style>
      .login-form {
        width: 340px;
        margin: 50px auto;
        font-size: 15px;
      }

      .login-form form {
        margin-bottom: 15px;
        background: #f7f7f7;
        box-shadow: 0px 2px 2px rgba(0, 0, 0, 0.3);
        padding: 30px;
      }

      .login-form h2 {
        margin: 0 0 15px;
      }

      .form-control,
      .btn {
        min-height: 38px;
        border-radius: 2px;
      }

      .btn {
        font-size: 15px;
        font-weight: bold;
      }
</style>
</head>

<body>
	<div class="login-form">
		<form method="POST" action="loginProceso.php">
			<h2 class="text-center">Iniciar sesión</h2>
			<div class="form-group">
				<input type="text" name="txtUsu" class="form-control" placeholder="Nombre de usuario" required="required"> </div>
			<div class="form-group">
				<input type="password" name="txtPass" class="form-control" placeholder="Contraseña" required="required"> </div>
			<div class="form-group">
				<button type="submit" class="btn btn-primary btn-block">Iniciar sesión</button>
			</div>
			<div class="clearfix">
				<label class="float-left form-check-label">
					<input type="checkbox"> Recuérdame</label> <a href="#" class="float-right">Olvidaste tu contraseña?</a> </div>
		</form>
		<p class="text-center"><a href="#">Crea una cuenta</a></p>
	</div>
	<!-- Bootstrap js -->
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</body>

</html>