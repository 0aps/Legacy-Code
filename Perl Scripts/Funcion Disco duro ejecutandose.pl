#By Doddy H
use Cwd;


sub getdrive {

$path = getcwd();

if ($path=~/(.*):\/\//ig or $path=~/(.*):\//) {
return $1.":/";
} 

}
