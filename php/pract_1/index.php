<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>pratica de php</title>
    </head>
    <body>
        <h1>PHP</h1>
        <form action="save.php" method="post" name="form">
            <input type="text" name="name">
            <input type="text" name="age">
            <input type="submit" value="Guardar datos">
        </form>
        <form action="delete.php" method="post" name="deleteform">
            <input type="file" name="archivo">
            <input type="submit" value="Delete File">
        </form>
    </body>
</html>