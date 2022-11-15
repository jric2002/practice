# Author: José Rodolfo (jric2002)
[System.Collections.ArrayList]$frutas = "Manzana", "Durazno", "Pera", "Sandia"
for ($i = 0; $i -lt $frutas.Count; $i++) {
  if ($frutas[$i] -eq "Pera") {
    Write-Output "continue"
    continue
  }
  Write-Output "Fruta $($i + 1) -> $($frutas[$i])"
}
$ns = @(10, 20, 30, 40, 50)
foreach ($n in $ns) {
  Write-Host "$n " -NoNewLine
}
Write-Host
Write-Host "----------------"
$i = 0
while ($i -lt $ns.Count) {
  if ($ns[$i] -eq 50) {
    Write-Output "break"
    break
  }
  Write-Host "$($ns[$i]) " -NoNewLine
  $i++
}
Write-Host