#!usr/bin/perl
#Manager (C) Doddy Hackman 2010
#Module neccesary
#ppm install http://trouchelle.com/ppm/Win32-Process-List.ppd 

use Win32::Process::List;
use Win32::Process;
use Tk;

if ($^O eq 'MSWin32') {
use Win32::Console; 
Win32::Console::Free();
}

$new = MainWindow->new(-background=>"black");
$new->geometry("250x300+20+20");
$new->resizable(0,0);
$new->title("Manager 0.1");
$new->Label(-background=>"black",-foreground=>"green",-font=>"Impact",-text=>"Process")->pack();
my $lists = $new->Listbox(-background=>"black",-foreground=>"green")->place(-y=>"50",-x=>"60");
$new->Button(-background=>"black",-foreground=>"green",-text=>"Close",-activebackground=>"green",-width=>"40",-command=>\&close)->place(-y=>"218");
$new->Button(-background=>"black",-foreground=>"green",-text=>"Refresh",-width=>"40",-activebackground=>"green",-command=>\&refresh)->place(-y=>"240");
$new->Button(-background=>"black",-foreground=>"green",-text=>"About",-width=>"40",-activebackground=>"green",-command=>\&about)->place(-y=>"263");	

&refresh;

MainLoop;


sub refresh {

my @pids;
my @procer;
my $limit;

$lists->delete(0.0,"end");

my $new = Win32::Process::List->new();  
my %process = $new->GetProcesses();
my $limit = -1;
for my $pid (keys %process) {
$limit++;
push (@procer,$process{$pid});
push (@pids,$pid);
}
print "\n\n[+] ".int(@procer)."\n\n";
for my $n(0..$limit) {
print $procer[$n]."\n";
$lists->insert("end",$procer[$n]);
}
	

}

sub close {

$d = $lists->curselection();

for my $id (@$d) {

my $proceso = $lists->get($id);

my $pida = Win32::Process::List->new();
my @pid = $pida->GetProcessPid($proceso);

Win32::Process::KillProcess(@pid[1],$proceso);
sleep 3;
&refresh();
}
}



sub about {
$about = MainWindow->new(-background=>"black");
$about->title("About");
$about->geometry("150x100+20+20");
$about->resizable(0,0);
$about->Label(-background=>"black",-foreground=>"green",-font=>"Impact",-text=>"Coded By Doddy H")->pack();
$about->Label(-background=>"black",-foreground=>"green")->pack();
$about->Label(-background=>"black",-foreground=>"green",-font=>"Impact",-text=>"2011")->pack();
}



# ¿ The End ? 