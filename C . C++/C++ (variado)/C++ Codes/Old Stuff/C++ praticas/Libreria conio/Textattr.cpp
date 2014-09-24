#include <conio.h>
#include <iostream> 
using namespace std;

int main() {
   /* Azul de fondo y rojo claro de texto */
   int atributo=BLUE << 4 | LIGHTRED;

   cprintf( "Ejemplo de \"textattr\"\r\n\r\n" );
   textattr( atributo );
   cprintf( "Este mensaje tiene otro color de fondo y de texto.\r\n" );
   textattr( atributo + BLINK );
   cprintf( "Este mensaje está parpadeando.\r\n" );
   normvideo();
   cprintf( "Pulsa una tecla para continuar...\r\n" );
   
   return 0;
}
