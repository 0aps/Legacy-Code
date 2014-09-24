#!usr/bin/perl
#FTP Manager
#(C) Doddy Hackman 2010

use Net::FTP;

&head;

print "\n\n[FTP Server] : ";
chomp (my $ftp = <stdin>);
print "[User] : ";
chomp (my $user = <stdin>);
print "[Pass] : ";
chomp (my $pass = <stdin>);


if (my $socket = Net::FTP->new($ftp)) {
if ($socket->login($user,$pass)) {

print "\n[+] Enter of the server FTP\n\n";

menu:

print "\n\n>>";
chomp (my $cmd = <stdin>);
print "\n\n";

if ($cmd=~/help/) {
print q(

help : show information
cd : change directory <dir>
dir : list a directory 
mdkdir : create a directory <dir>
rmdir : delete a directory <dir>
pwd : directory  
del : delete a file <file>
rename : change name of the a file <file1> <file2>
size : size of the a file <file>
put : upload a file <file>
get : download a file <file>
cdup : change dir <dir>


);
}

if ($cmd=~/dir/ig) {
if (my @files = $socket->dir()) {
for(@files) {
print "[+] ".$_."\n";
}
} else {
print "\n\n[-] Error\n\n";
}
}

if ($cmd=~/pwd/ig) {
print "[+] Path : ".$socket->pwd()."\n";
}

if ($cmd=~/cd (.*)/ig) {
if ($socket->cwd($1)) {
print "[+] Directory changed\n";
} else {
print "\n\n[-] Error\n\n";
}
}

if ($cmd=~/cdup/ig) {
if (my $dir = $socket->cdup()) {
print "\n\n[+] Directory changed\n\n";
} else {
print "\n\n[-] Error\n\n";
}
}

if ($cmd=~/del (.*)/ig) {
if ($socket->delete($1)) {
print "[+] File deleted\n";
} else {
print "\n\n[-] Error\n\n";
}
}

if ($cmd=~/rename (.*) (.*)/ig) {
if ($socket->rename($1,$2)) {
print "[+] File Updated\n";
} else {
print "\n\n[-] Error\n\n";
}
}

if ($cmd=~/mkdir (.*)/ig) {
if ($socket->mkdir($1)) {
print "\n\n[+] Directory created\n";
} else {
print "\n\n[-] Error\n\n";
}
}

if ($cmd=~/rmdir (.*)/ig) {
if ($socket->rmdir($1)) {
print "\n\n[+] Directory deleted\n"; 
} else {
print "\n\n[-] Error\n\n";
}
}

if ($cmd=~/exit/ig) {
copyright();
exit(1);
}

if ($cmd=~/get (.*) (.*)/ig) {
print "\n\n[+] Downloading file\n\n";
if ($socket->get($1,$2)) {
print "[+] Download completed";
} else {
print "\n\n[-] Error\n\n";
}
}

if ($cmd=~/put (.*) (.*)/ig) {
print "\n\n[+] Uploading file\n\n";
if ($socket->put($1,$2)) {
print "[+] Upload completed";
} else {
print "\n\n[-] Error\n\n";
}
}

goto menu;

} else {
print "\n\n[-] Failed the login\n\n";
}

} else {
print "\n\n[-] Error\n\n";
}

sub head {
print "\n\n -- == FTP Manager == --\n\n";
}

sub copyright {
print "\n\n(C) Doddy Hackman 2010\n\n";
}


# ¿ The End ? 