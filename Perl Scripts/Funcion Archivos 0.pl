#By Doddy H
sub savefile {
open (SAVE,">>".$_[0]);
print SAVE $_[1];
close SAVE; 
}