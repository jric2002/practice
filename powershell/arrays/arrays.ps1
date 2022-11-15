# Author: José Rodolfo (jric2002)
# [System.Collections.ArrayList]$frutas = "manazana", "durazno", "platano"
# $frutas = "manazana", "durazno", "platano"
$frutas = @("manazana", "durazno", "platano")
Write-Output "[+] Frutas"
$output = $frutas -Join ' '
Write-Output $output
$frutas += "sandia"
# $frutas.Add("sandia")
$output = $frutas -Join ' '
Write-Output $output
# $frutas.Remove("manzana")
Write-Output "[+] Argumentos pasados al script"
Write-Output $args
$output = "Cantidad de argumentos: " + ($args).Count
Write-Output $output
Write-Output "[+] Numeros"
$nums = 10..20
Write-Output $nums[0..2]
Write-Output "--------"
Write-Output $nums[-3..-1]
Write-Output "--------"
Write-Output $nums[-1..-3]
Write-Output "--------"
Write-Output $nums[0,1,2+5..7]