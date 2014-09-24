<?php
/*
C O D E D
                By
					      C A R L M Y C O L
                modificado por "0aps"
*/
function azar() 
{
//creo mi funcio para randomizar la firma ^^
$base=0;
//creo la variable que me ayudara en la creacion de mi array
$conteo=0;
//creo variable que me ayudara a contar cuantos archivos hay
$d = dir("Imagenes/");
//creo mi variable donde estan las firmas

   //hago un while para que cada vez que lea un archivo  
   while ($entry = $d->read()) 
   {
   $imagenes[$base]=$d->path.$entry;
   //voy creando mi array con base
   
   $conteo++;
   //conteo entonces es uno mas cada ves que encuentra un nuevo archivo ^^
   //ven la cosa toma forma despues de todo ^^
   $base++;
   //como no sabemos cuantos archivos va a haber base es igual pero mas 1
   //para que la próxima vez que pase el while ya sea el siguiente número del array
  }

  //terminó mi ciclo

   $d->close();   
   //cerramos nuestro directorio
   
   $azar=rand(0,$conteo);
   //conteo era 1 despues del ciclo es el nuúmero total de archivos en el directorio



$partes_ruta = pathinfo($imagenes[$azar]);
//creo array para obtener datos de lo que quedo randomizado 


if ($partes_ruta['extension']=!".jpg") 
{
//creo un if a partir de la variable anterior para saber si es jpg o no ^^
$azar++;
//si no es jpg entonces reducimos el el azar en 1 para que quede diferente
}



$firmafinal=$imagenes[$azar];
//definimos variable que va a retornar la funcion ^^

    return $firmafinal;
	//la retornamos
}

$firma = azar();
//definimos variable que obtendra el resultado de la funcion
//ese siete lo puse para que no quedara solo pero ese siete no hace nada
//porque ese siete seria el valor de la variable im pero esa variable no influye ^^

$firmafinal = imagecreatefromjpeg($firma);
//a partir de la variable anterior creamos una imagen con el fondo de la misma

header("Content-type: image/jpeg");
//decimos que lo que se devuelbe es de tipo jpg

imagejpeg($firmafinal);
//y listop xDD
?>