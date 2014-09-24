#include <stdio.h>
#include <string.h>

//env puntero a arrey de caracteres que almacena las variables de entorno
int main ( int argc, char *argv[], char *env[] )
{
	char * solicitud = argv [1];
	int n;

	if ( argc == 1 )
	{
		printf ( "Con argumento pls:\n\n\t%s VARIABLE\n\n¿Ok?\n", argv [0] );
		return -1;
	}

	for ( n = 0 ; env [n] != NULL; n++ )
	{
        //busco en las variables de entorno cualquier variable que empieze o que contega 
        // lo escrito en solicitud
		if ( strstr ( env[n], solicitud ) )
			printf ( "%s\n", env[n] );
	}
    return 0;
}
