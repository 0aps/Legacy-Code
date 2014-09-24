#!/usr/bin/perl
use Win32::OLE;
use Win32::SAM;
$| = 1;
$Win32::OLE::Warn = 3;
print "Ingresa la url : \n";
$nav=<STDIN>;
print "Ingresa tu Usuario : \n";
$usuario=<STDIN>;
print "Ingresa tu Password : \n";
$password=<STDIN>;
StartIE();
my $segundos = Navigate("http://$nav/index.php?action=login");
SetEditBox("user","$usuario");
SetEditBox("passwrd","$password");
ClickFormButton("Ingresar");
my $segundos = Navigate("http://$nav/index.php");