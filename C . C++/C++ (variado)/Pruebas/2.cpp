
#include <stdio.h>
#include <string.h>
 
int main ( void )
{
        char palabra [] = "PortalHacker";
        int i = -1, caracteres = strlen (palabra);
        printf ( "palabra tiene una longitud de: %d\n", caracteres );
        puts ( "veamos todos sus valores en hexadecimal:");
        do {
                i++;
                printf ( "Casilla %d:\t [%c]\t[%x]\n", i, palabra [i], palabra [i] );
                setbuf(stdin, NULL);
        } while ( palabra [i] != '\0' );
 
        puts ( "Ahora voy a asignar un caracter a la casilla que en teoria no existe (!)" );
        palabra [ strlen (palabra) ] = '!';
 
        printf ( "Pues me lo expliquen ya que %s[%d]\t es igual a: (%x) y no a (\\0)!!\n",
                        palabra, caracteres, palabra [ caracteres ] );
        printf ( "Y me a variado el strlen = %d!!!\n????\nSaludOS\n",
                        strlen (palabra) );
                        getchar();
        return 0;
}
