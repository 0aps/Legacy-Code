#!usr/bin/perl
#Paste Bin Uploader (C) Doddy Hackman 2011

use LWP::UserAgent;
use HTTP::Request::Common;	

my $nave = LWP::UserAgent->new();
$nave->timeout(10);
$nave->agent("Mozilla/5.0 (Windows; U; Windows NT 5.1; nl; rv:1.8.1.12) Gecko/20080201Firefox/2.0.0.12");

menu();

sub menu {

clean();
header();

print "\n\n[Options]\n\n";
print "[1] : Upload a file\n";
print "[2] : Upload a directory\n";
print "[3] : Exit\n\n";
print "[Option] : ";
chomp(my $op = <stdin>);

if ($op eq 1) {
print "\n\n[File] : ";
chomp(my $file = <stdin>);

if (-f $file)  {

($name,$exta) =verfile($file);

my $ext = extensiones($exta);

if ($ext ne "Yet") {


$code = openfile($file);

$re = lleva($name,$code,$ext);

print "\n\n[+] File : $file\n";
print "[+] Link : ".$re."\n";

savefile("uploads_paste.txt","\n[+] File : $file");
savefile("uploads_paste.txt","[+] Link : ".$re);

}


} else {
print "\n\n[-] Error\n\n";
}
reload();
}

elsif ($op eq 2) {

print "\n\n[Directory] : ";
chomp(my $dir = <stdin>);

if (-d $dir) {

my @files = verdir($dir);

print "\n\n[+] Loading directory\n";

for my $file(@files) {

chomp $file;

my ($name,$exta) =verfile($file);

my $ext = extensiones($exta);

if ($ext ne "Yet") {

my $code = openfile($dir."/".$file);

$re = lleva($name,$code,$ext);

print "\n\n[+] File : $file\n";
print "[+] Link : ".$re."\n";

savefile("uploads_paste.txt","\n[+] File : $file");
savefile("uploads_paste.txt","[+] Link : ".$re);

}
}
} else {
print "\n\n[-] Error\n\n";
}

reload();
}

elsif ($op eq 3) {
copyright();
<stdin>;
exit(1);
}

else {
menu();
}
}

sub copyright {
print "\n\n(C) Doddy Hackman 2011\n\n";
}

sub header {

print q(

 PPPP     AA     SSSSTTTTTTEEEE    BBBB   II NN   NN     UU  UU  PPPP 
 PP PP    AA    SS  S  TT  EE      BB BB  II NNN  NN     UU  UU  PP PP
 PP PP   AAAA   SS     TT  EE      BB BB  II NNNN NN     UU  UU  PP PP
 PPPP    A  A    SSS   TT  EEEE    BBBB   II NN N NN     UU  UU  PPPP 
 PP     AAAAAA     SS  TT  EE      BB BB  II NN NNNN     UU  UU  PP   
 PP     AA  AA  S  SS  TT  EE      BB BB  II NN  NNN     UUUUUU  PP   
 PP     AA  AA  SSSS   TT  EEEE    BBBB   II NN   NN      UUUU   PP   


);

}

sub clean {
system("cls");
}



sub verdir{
my @archivos;
opendir DIR,$_[0];
my @archivos = readdir DIR;
for (@archivos) {
if (-f $_[0]."/".$_) {
push(@files,$_)
}
}
return @files;
}

sub verfile {
if ($_[0]=~/(.*)\.(.*)/ig) {
return ($1,$2);
}
}

sub extensiones {

if ($_[0] =~/py/ig) {
$code  = "python";
}
elsif ($_[0] =~/pl/ig) {
$code = "perl";
}
elsif ($_[0] =~/rb/ig) {
$code = "ruby";
}
elsif ($_[0] =~/php/ig) {
$code = "php";
}
elsif ($_[0] =~/txt/ig) {
$code = "";
}
else {
$code = "Yet";
}
return $code;
}

sub reload {
print "\n\n[?] Enter for continue\n\n";
<stdin>;
menu();
}



sub savefile {
open (SAVE,">>logs/".$_[0]);
print SAVE $_[1]."\n";
close SAVE; 
}

sub openfile {
	
my $r;

open (FILE,$_[0]);
@wor = <FILE>;
close FILE;
for(@wor) {
$r.= $_;
}
return $r;
}

sub lleva {
return $nave->post('http://pastebin.com/api_public.php',{ paste_code => $_[1],paste_name=> $_[0],paste_format=>$_[2],paste_expire_date=>'N',paste_private=>"public",submit=>'submit'})->content;
} 

# ¿ The End ? 
