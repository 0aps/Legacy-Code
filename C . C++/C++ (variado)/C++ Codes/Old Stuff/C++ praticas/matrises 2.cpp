#include <stdio.h>

int main ( void )
{
	//short notas[3][5];
	int i,d;
	float f;

	float notas[3][5] = {
		5.8, 3.5, 4.8,
		2.5, 6.2, 7.0,
		3.9, 5.5, 6.2,
		2.6, 1.9, 4.6,
		6.8, 7.0, 5.8
	};

	puts ( "Ejemplo de array bidimensional" );
	puts ( "------------------------------" );
	puts ( "\ntenemos el siguiente array bidireccional:" );
	puts ( "\t\tnota 1\tnota 2\tnota 3" );
	for ( i=0; i<5; i++ ) 
		printf ( "Alumno %i\t %.1f\t %.1f\t %.1f\n", i + 1,
			notas[0][i], notas[1][i], notas[2][i] );
	puts ( "\nAhora vamos a cambiar los valores:" );
	for ( i=0; i<5; i++ )
	{
		for ( d=0; d<3; d++ )
		{
			printf ( "Ingrese la %d nota del alumno %d: ", d + 1, i + 1 );
			scanf ( "%f", &f );
			notas [d][i] = f;
		}
		puts ( "" );
	}
	puts ( "\nY mostramos la tabla de nuevo con los valores modificados:" );
	for ( i=0; i<5; i++ ) 
		printf ( "Alumno %i\t %.1f\t %.1f\t %.1f\n", i + 1,
			notas[0][i], notas[1][i], notas[2][i] );
	puts ( "Pulsa return para finalizar ..." );
	setbuf ( stdin, NULL );
	getchar ();
	return 0;
}
