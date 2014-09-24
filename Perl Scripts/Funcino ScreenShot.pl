
#By Doddy H

use Win32::Clipboard;
use Win32::GuiTest qw(FindWindowLike SetForegroundWindow SendKeys);

capture_window();

sub capture_window {

SendKeys("%{PRTSCR}"); 

my $a = Win32::Clipboard::GetBitmap();

open (FOTO,">foto.bmp");
binmode(FOTO);
print FOTO $a;
close FOTO;

}