# Author: José Rodolfo (jric2002)
Write-Output "[+] Argumentos del script"
Write-Host "`$args: " -NoNewLine; $args -Join ' '
function Get-Name {
  return "José Rodolfo"
}
# Get-Name
Write-Host $(Get-Name)
function Sum($a = 1, $b = 1) {
  return $a + $b
}
Sum 20 40