
/* vuln1.c por Rojodos */

#include <stdio.h>  // librer�a stdio.h, funciones b�sicas de Entrada/Salida

int main (int argc, char **argv){  // La funci�n "principal" del programa funci�n
	char buffer[64]; //Declaramos un array con 64 bytes de espacio
	if (argc < 2){  // Si los argumentos son menores que 2...
		printf ("Introduzca un argumento al programa\n"); //Printeamos	
		return 0;  // y retornamos 0 a la funci�n main, y el programa acaba
        }
	strcpy (buffer, argv[1]); // Aqui es donde esta el fallo.

	return 0;  // Devolvemos 0 a main, y el programa acaba.
}
