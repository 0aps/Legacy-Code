use Net::FTP;

$ftp = "apsq.zzl.org";
$user = "apsq_zzl";
$pass = "maricona";

my $socket = Net::FTP->new($ftp);
$socket->login($user,$pass);

menu:

print "comando : ";
$comando = <stdin>;

if ($comando =~ /cd (.*)/)
{
$socket->cwd($1); 
}

if ($comando =~ /pwd/) 
{
print $socket->pwd(); #mostramos el directorio actual
}

goto menu;