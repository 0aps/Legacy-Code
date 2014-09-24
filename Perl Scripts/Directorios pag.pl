r/bin/perl
#Finder Paths
#(C) Doddy Hackman 2010

use WWW::Mechanize;
use HTTP::Response;
use URI::Split qw(uri_split);

if ($^O =~/Win32/ig) { system("cls"); } else { system("clear"); } 

my $new = WWW::Mechanize->new(autocheck => 0);
$new->agent("Mozilla/5.0 (Windows; U; Windows NT 5.1; nl; rv:1.8.1.12) Gecko/20080201 Firefox/2.0.0.12");

&head;
unless($ARGV[0]) {
&menu;
} else {
print "[Page] : $ARGV[0]\n\n";
&scan($ARGV[0]);
}
&finish;

sub menu {
print "[Page] : ";
chomp(my $pa = <STDIN>);
&scan($pa);
}

sub finish {
print "\n\n\n\n(C) Doddy Hackman 2010\n\n";
<STDIN>;
exit(1);
}

sub scan {
my @analizar;
toma($_[0]);
print "\n\n[Target confirmed] : $_[0]\n\n";
print "[Status] : Scanning\n";
@links = dame_link();
for my $junt(@links) {
my $com = $junt->url();
my ($scheme, $auth, $path, $query, $frag)  = uri_split($_[0]);
if ($path=~/\/(.*)$/) { 	
my $path1 = $1;
$_[0] =~s/$path1//ig;
my ($scheme, $auth, $path, $query, $frag)  = uri_split($com);
if ($path =~/(.*)\//) {
$code = toma($_[0].$1);
my $found = $1;
if ($code=~/Index Of (.*)<\/title>/ig) {
$ok = 1;
print "\n[Link] : ".$_[0].$found."\a";
savefile("indexs-found.txt",$_[0].$found);
}}}}
if ($ok ne 1) { 
print "[Status] : Finish\n"; 
}}

sub repes {
foreach my $palabra ( @_ ) {
next if $repety{ $palabra }++;
push @revisado,$palabra;
}
return @revisado;
}


sub toma {
return $new->get($_[0])->content;
}

sub dame_link {
return $new->find_all_links();
}

sub savefile {
open (SAVE,">>logs/".$_[0]);
print SAVE $_[1]."\n";
close SAVE; 
}


sub head {
print qq(


##########  #########  #########     #####   #   ##### ### ###  ###
 #  # #  ##  #  #   #   #  # #  #     #  #   #   # # #  #   #  #  #
 #    #  ##  #  #    #  #    #  #     #  #  # #    #    #   #  #   
 ###  #  # # #  #    #  ###  ###      ###   # #    #    #####   ## 
 #    #  # # #  #    #  #    # #      #    #####   #    #   #     #
 #    #  #  ##  #   #   #  # #  #     #    #   #   #    #   #  #  #
###  ######  # #####   ########  #   ###  ### ### ###  ### ### ### 




);
}


#The end
#Blog : doddy-hackman.blogspot.com
#Mail : lepuke[at]hotmail[com]
