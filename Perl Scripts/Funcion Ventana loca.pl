#By Doddy H
use Win32::API;

sub movewin {
for my $n(1..20) {
Win32::API->new("user32","SetWindowPos",[qw(N N N N N NN)],'N')->Call($_[0],$n,$n,$n,$n,$n,$n);
}
}
