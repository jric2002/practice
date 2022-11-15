# Author: José Rodolfo (jric2002)
# $persona = @{nombre="José"; edad="20"; "esta-vivo"="si"} # Desordenado
$persona = [ordered]@{nombre="José"; edad="20"; "esta-vivo"="si"} # Ordenado
Write-Output $persona
Write-Output "--------------"
# $persona["genero"] = 'm'
$persona.Add("genero", 'm')
Write-Output $persona
Write-Output "--------------"
Write-Output "[+] Keys"
Write-Output $persona.Keys
Write-Output "[+] Values"
Write-Output $persona.Values