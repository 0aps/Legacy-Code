#By Doddy H
use Win32::GuiTest qw(MouseMoveAbsPix SendMessage);

sub crazymouse {
for my $number(1..$_[0]) {
MouseMoveAbsPix($number,$number);
} 
}