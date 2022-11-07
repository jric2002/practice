# Author: José Rodolfo (jric2002)
$output = $null
$name = "José Rodolfo"
$output = "My name is " + $name
Write-Output $output
$numeros = 1, 2, 3
$a, $b, $c = 10, 20, 30
$output = "Numeros: " + $a + " " + $b + " " + $c
Write-Output $output
$output = "a = " + $a + "    b = " + $b + "    c = " + $c
Write-Output $output
$output = "Suma de 'a', 'b' y 'c': " + ($a + $b + $c)
Write-Output $output
Write-Output "Eliminar valor de las variables 'name', 'numeros'..."
Clear-Variable -name name, numeros
# $name = $numeros = $null # Otra forma de eliminar valor de una variable
Write-Output "Eliminar variables..."
Remove-Variable -Name a, b
Remove-Item -Path Variable:\c
Write-Output "Tipos de variables..."
[string]$n = 12
$n += 10
Write-Output $n
[int]$a = "12"
$a += 10
Write-Output $a
Write-Output "Nombre de variables con caracteres especiales..."
${hola-mundo} = "Hola mundo"
${var prueba} = "Variable de prueba"
Write-Output ${hola-mundo}
Write-Output ${var prueba}