#include <iostream> //<< >>
#include <conio.h>
using namespace std;

#define ANCHURA 25
#define ALTURA 2

int main() {
   cprintf( "Ejemplo de \"movetext\"\r\n\r\n" );
   cprintf( "El rect�ngulo ser� de un �rea relativamente peque�a.\r\n" );
   cprintf( "Copiaremos esta l�nea...\r\n...y �sta tambi�n.\r\n" );
   cprintf( "Las dimensiones son: %d (de ancho) x %d (de alto).\r\n", ANCHURA, ALTURA );
   cprintf( "\"movetext\" ha retornado: %d\r\n", movetext( 1, 4, ANCHURA, 3+ALTURA, 5, 15 ) );
   cprintf( "Pulsa una tecla para continuar..." );
   getchar();
   return 0;
}
