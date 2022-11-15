# Author: José Rodolfo (jric2002)
$v = 1
if ($v -eq 1) {
  Write-Output "Numero 1"
}
elseif ($v -eq 2) {
  Write-Output "Numero 2"
}
elseif ($v -eq 3) {
  Write-Output "Numero 3"
}
else {
  Write-Output "Otro numero"
}
$color = "VERDE"
switch -CaseSensitive ($color) {
  'amarillo' {
    Write-Output "Yellow"
  }
  'verde' {
    Write-Output "Green"
  }
  'rojo' {
    Write-Output "Red"
  }
  default {
    Write-Output "Colour"
  }
}