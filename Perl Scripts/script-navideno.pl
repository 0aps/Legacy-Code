#!usr/bin/perl
#El script navideño
#Coded By Doddy H
 
while(true) {
 
my($dia,$mes,$anio,$hora,$minutos,$segundos) = agarrate_la_hora();
 
unless($dia eq "25" and $mes eq "12") {
syswrite STDOUT,"[+] Fecha y hora : $dia/$mes/$anio $hora:$minutos:$segundos \r";
} else {
syswrite STDOUT,"\n\n[+] Feliz navidad !";
<stdin>;
exit(1);
}
 
}
 
sub agarrate_la_hora {
 
my ($a,$b,$c,$d,$e,$f,$g,$h,$i) = localtime(time);
 
$f+= 1900;
$e++;
 
return($d,$e,$f,$c,$b,$a);
 
}
 
#The End ? 