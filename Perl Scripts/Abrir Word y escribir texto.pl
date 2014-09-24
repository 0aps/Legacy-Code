#By Doddy H

use Win32::Clipboard;
use Win32::GuiTest qw(FindWindowLike SetForegroundWindow SendKeys);

sub loadword {

system("start winword.exe");

sleep 4;

SendKeys($_[0]); 

}S