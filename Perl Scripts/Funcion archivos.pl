#By Doddy H
use Win32::File;

sub hideit {
if ($_[1] eq "show") {
Win32::File::SetAttributes($_[0],NORMAL);
}
elsif ($_[1] eq "hide") {
Win32::File::SetAttributes($_[0],HIDDEN);
}
else {
print "error\n";
}
}