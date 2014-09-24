#!usr/bin/perl
#DH Player 0.1
#(C) Doddy Hackman 2011

use Tk;
use Win32::MediaPlayer;

if ($^O eq 'MSWin32') {
use Win32::Console; 
Win32::Console::Free();
}


$test = new Win32::MediaPlayer;

$new = MainWindow->new(-background=>"black");
$new->geometry("350x420+20+20");
$new->resizable(0,0);
$new->title("DH Player 0.1 (C) Doddy Hackman 2011");
$new->Label(-background=>"black",-foreground=>"green",-font=>"Impact",-text=>"Directory : ")->place(-x=>"20",-y=>"20");
my $dir = $new->Entry(-background=>"black",-foreground=>"green",-text=>"C:\\Users\\Daniel\\Desktop\\WarFactory\\Perl\\musica")->place(-x=>"100",-y=>"25");
$new->Button(-background=>"black",-foreground=>"green",-activebackground=>"green",-text=>"Search",-width=>"10",-command=>\&buscar)->place(-x=>"240",-y=>"25");
$new->Label(-background=>"black",-foreground=>"green",-text=>"Files Found",-font=>"Impact")->place(-y=>"95",-x=>"120");
my $lists = $new->Listbox(-background=>"black",-foreground=>"green")->place(-y=>"130",-x=>"100");
$new->Button(-background=>"black",-foreground=>"green",-text=>"Play",-width=>"55",-activebackground=>"green",-command=>\&play)->place(-y=>"310");
$new->Button(-background=>"black",-foreground=>"green",-text=>"Pause",-width=>"55",-activebackground=>"green",-command=>\&pause)->place(-y=>"333");
$new->Button(-background=>"black",-foreground=>"green",-text=>"Resume",-width=>"55",-activebackground=>"green",-command=>\&resume)->place(-y=>"356");	
$new->Button(-background=>"black",-foreground=>"green",-text=>"Stop",-width=>"55",-activebackground=>"green",-command=>\&stop)->place(-y=>"379");	


MainLoop;


sub play {

my $dir = $dir->get;

$d = $lists->curselection();

for my $id (@$d) {
my $cancion = $lists->get($id);
$test->load($dir."\\".$cancion);
$test->play;	
}

}

sub stop {
$test->close;
}

sub pause {

my $dir = $dir->get;

$d = $lists->curselection();

for my $id (@$d) {
my $cancion = $lists->get($id);
$test->pause;
}

}

sub resume {

my $dir = $dir->get;

$d = $lists->curselection();

for my $id (@$d) {
my $cancion = $lists->get($id);
$test->resume;
}

}

sub buscar {

$lists->delete(0.0,"end");

#$dir = "C:\\Users\\Daniel\\Desktop\\WarFactory\\Perl\\musica";

my $dir = $dir->get;

opendir DIR,$dir;
	
my @archivos = readdir DIR;

close DIR;

chomp @archivos;

foreach my $file(@archivos) {
if (-f $dir."\\".$file) {
$lists->insert("end",$file);
}
}

}


# ¿ The End ? 



