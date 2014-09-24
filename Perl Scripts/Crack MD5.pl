#Search MD5 
#Version : Tk
#Author : Doddy Hackman


use Tk;
use Digest::MD5;
use Tk::FileSelect;
use Tk::ROText;

if ($^O eq 'MSWin32') {
use Win32::Console; 
Win32::Console::Free();
}

my $w = MainWindow->new(-background=>"black");
$w->title("Search MD5");
$w->geometry("500x200+20+20");
$w->resizable(0,0);
$w->Label(-text=>"Search MD5",-background=>"black",-foreground=>"cyan",-font=>"Impact")->pack();
$w->Label(-text=>"Hash",-background=>"black",-foreground=>"green")->place(-x =>40, -y => 55);
my $hash = $w->Entry(-text=>"30d554c3665c8f204622b2003c77d994",-background=>"black",-foreground=>"green")->place(-x =>90, -y => 55);
$w->Label(-text=>"Salt",-background=>"black",-foreground=>"green")->place(-x =>260, -y => 55);
my $salt = $w->Entry(-text=>"X",-background=>"black",-foreground=>"green")->place(-x =>290, -y => 55);
$w->Label(-text=>"Wordlist",-background=>"black",-foreground=>"green")->place(-x =>40, -y => 100);
my $o = $w->Entry(-textvariable=>\$file,-background=>"black",-foreground=>"green")->place(-x =>90, -y => 100);
$w->Button(-text=>"Browse",-background=>"black",-foreground=>"red",-activebackground=>"red",-command=>\&oper)->place(-x =>230, -y => 100);
$w->Button(-text=>"Crack!",-foreground=>"green",-background=>"black",-command=>\&crack,-activebackground=>"green")->place(-x =>180, -y => 160);
$w->Button(-text=>"About",-foreground=>"green",-background=>"black",-command=>\&about,-activebackground=>"green")->place(-x =>240, -y => 160);
$w->Button(-text=>"Exit",-foreground=>"green",-background=>"black",-command=>[$w =>'destroy'],-activebackground=>"green")->place(-x =>300, -y => 160);

sub oper{ 
$w->update;
$browse = $w->FileSelect(-directory => "/");
my $file = $browse->Show;
$o->configure (-text =>$file);
}

sub about {
my $venta = MainWindow->new(-background=>"black");
$venta->geometry("300x180+20+20");
$venta->title("About");
$venta->resizable(0,0);
$venta->Label(-text=>"\nSearch MD5\n\n\nProgrammer : Doddy Hackman\n\nContact : lepuke[at]hotmail[com]\n\n",-background=>"black",-foreground=>"yellow")->pack();
$venta->Button(-text=>"Exit",-foreground=>"yellow",-background=>"black",-command => [$venta => 'destroy'],-activebackground=>'yellow')->pack()
}

sub crack {
my $hash = $hash->get;
my $salt = $salt->get;
my $wordlist = $o->get;

my $console = MainWindow->new(-background=>"black");
$console->title("Status");
$console->resizable(0,0);
$console->geometry("400x320+20+20");
$console->Label(-text=>"Status",-background=>"black",-foreground=>"green",-font=>"Impact")->pack();
my $box = $console->ROText(-background=>"black",-foreground=>"green",-width=> 45,-height=> 15)->place(-x =>40,-y=>50);
$console->Button(-text=>"Exit",-background=>"black",-foreground=>"green",-activebackground=>"green",-command=> [$console => 'destroy'],-width=>"20")->place(-x =>130, -y => 280);
if ($salt eq "X") { $salt = "";}
unless (-f $wordlist) { $box->insert('end',"\n\n[-] Wordlist dont exist!\n\n");next;}
if(length($hash)==32) {
$box->insert('end',"[Hash] : $hash\n[Salt] : $salt\n[Wordlist] : $wordlist\n\n");
open word,$wordlist;
@words = <word>;
close word;
for my $pass(@words) {
chomp $pass;
$console->update;
$box->insert('end',"[+] Trying with $pass\n");
$digest = Digest::MD5->md5_hex($pass.$salt);chomp $digest;
if ($digest == $hash) {print "\a\a";$box->insert('end',"\n[Hash encoded] : $hash\n[Hash decoded] : $pass\n\n");$ok="1";last;}
}} else { $box->insert('end',"\n\n[-] The hash is incorrect\n\n");next;}
unless ($ok eq "1") {$box->insert('end',"\n\n[-] Sorry , hash not cracked\n\n");next;}}

MainLoop;
