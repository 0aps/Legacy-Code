use LWP::UserAgent;
use HTTP::Request::Common;

my $nave = LWP::UserAgent->new();

$nave->timeout(5);

$nave->agent("Mozilla/5.0 (Windows; U; Windows NT 5.1; nl; rv:1.8.1.12) Gecko/20080201Firefox/2.0.0.12");

my $web = "http://www.apsq.zzl.org";
my $contenido = $nave->request (GET $web)->content;

open (FILE, ">respuesta.txt");

print FILE $contenido;