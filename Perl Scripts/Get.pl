use IO::Socket;

$web = "demohackwebtaul.zxq.net";

my $socket = IO::Socket::INET->new(
PeerAddr=> $web, #Host donde conectarnos
PeerPort=>"80", #Puerto donde bla bla
Proto=>"tcp"); #Protocolo que queremos

print $socket "GET /"."\r\n";

read $socket,$total,"1000";

print $total;