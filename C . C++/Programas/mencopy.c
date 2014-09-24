#include <stdio.h>
#include <string.h>

int main()
{
   char a[7] = "abcdefg";
   char *ptr;
   int i;
   //reservo memoria para el puntero
   ptr=(char*)malloc(10); 
   //copio los cinco primeros bytes de la direccion de a
   memcpy( ptr, a, 5 );
   
   for( i=0; i<7; i++ )
     printf( "a[%d]=%c ", i, a[i] );
     
   printf( "\n" );
   for( i=0; i<8; i++ )
     printf( "ptr[%d]=%c ", i, ptr[i] );
   printf( "\n" );
   
   getchar();
   return 0;
}
