<html>
<HEAD>
<TITLE>Comunidad Hispana</TITLE>
</HEAD>

<BODY>
<?php

$lIP = fopen("datos.txt", "r") or
die ("No se pudo abrir el archivo");

while(!feof($lIP))
{
$linea = fgets($lIP);
$linea = nl2br($linea);
echo $linea;
}
fclose($lIP);
?>


</BODY>

</html>
