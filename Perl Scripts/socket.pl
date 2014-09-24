use IO::Socket;

my $socket = IO::Socket::INET->new(
PeerAddr=>"google.com", 
PeerPort=>"80",
Proto=>"tcp");

print $socket "GET /"."\r\n";

read ($socket,$total,"1000");

open(FILE, ">>respuesta.txt");

print FILE $total;

close($respueta);
