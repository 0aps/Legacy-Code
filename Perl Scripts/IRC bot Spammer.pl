#Programa = King Spam
#Autor = Doddy
#Website = doddyhacking.wordpress.com & doddyhacking.blogspot.com



use IO::Socket;


if ($#ARGV != 4) {
print "\n\t\t\tSpam King By Doddy\t\t\t\n";
print "\nModo de uso = $0 <SERVER> <PORT> <CANAL> <BOT NAME> <WEB SPAM>\n";
print "<SERVER> = Nombre del servidor  irc\n";
print "<PORT> = Puerto a conectar al servidor IRC\n";
print "<CANAL> = Canal a conectar #dementes\n";
print "<BOT NAME> = Nombre del bot que jodera\n";
print "<WEB SPAM> = Web a publicitar\n\n";
exit 1;
}




my $server = $ARGV[0];
my $port = $ARGV[1];
my $canal = $ARGV[2];
my $nick = $ARGV[3];
my $texto = $ARGV[4];


@mensajes = (
         "Visita $texto",
         'Hola como andan?',
         'ajajajajajajaj',);


my $sock = new IO::Socket::INET(   PeerAddr =>$server,
                                                                     PeerPort => $port,
                                                                      Proto => 'tcp' );

if (!$sock) {
print "\nNo se puedo conectar en  $server $port\n";
exit 1;
}

print "\n\nServer = $server\n";
print "Canal = $canal\n";
print "Puerto = $port\n";
print "Bot = $nick\n";
print "Web malvada = $texto\n";


print "\nPresional Control + C para detener la agonia de $canal\n";

print $sock "NICK $nick\r\n";
print $sock "USER $nick 1 1 1 1\r\n";
print $sock "JOIN $canal\r\n";


print "\nDentro!\n\n";

while ( my $log = <$sock> ) { 
chomp($log);

 if ($log =~ /^PING(.*)$/i){
print  $sock "PONG $1\r\n";
}



if ($log =~ m/:(.*) 353 (.*) = (.*) :(.*)/ig){

while(true){
sleep 50;
my @nicks = split " ", $4;

sleep 3;
$t = int(rand($#mensajes));
        $spam = $mensajes[$t];

foreach $names(@nicks) {
print $sock "MSG $names $spam\r\n";
print "Spam a $names\n";

}
}
}






}

print "\nGood Bye\n";
