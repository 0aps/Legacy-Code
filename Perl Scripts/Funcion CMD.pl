#By Doddy H

use Win32::Job;

sub cmd {

my $job = Win32::Job->new;
$job->spawn("cmd",qq{cmd /C $_[0]},{
no_window => "true",
stdout => "logx.txt",
stderr => "logx.txt"
}
);
$ok = $job->run("30");

open (F,"logx.txt");
@words = <F>;
close F;

unlink("logx.txt");

return @words;
 
}