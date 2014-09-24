#include <stdio.h>

int main()
{
   FILE *fichero;
   char nombre[10] = "datos.txt";

   fichero = fopen( nombre, "w" );
   printf( "Fichero: %s -> ", nombre );
   if( fichero )
      printf( "creado (ABIERTO)\n" );
   else
   {
      printf( "Error (NO ABIERTO)\n" );
      return 1;
   }

   if( !fclose(fichero) )
      printf( "Fichero cerrado\n" );
   else
   {
      printf( "Error: fichero NO CERRADO\n" );
      return 1;
   }

   return 0;
}
