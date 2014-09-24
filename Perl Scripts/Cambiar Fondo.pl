#By Doddy H

use Win32::API;

sub cambiar_fondo {

my $a = new Win32::API("user32","SystemParametersInfo", [L,L,P,L],L);
$a->Call(20,0,$_[0],0);

}