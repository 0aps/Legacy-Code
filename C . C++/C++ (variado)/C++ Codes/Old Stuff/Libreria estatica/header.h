#include <iostream>
#include <windows.h>

using namespace std;

int Astrlen(char*);

int Astrlen(char *cadena)
{
 char *aux = cadena;
 while( *cadena++ );
 
 return cadena - aux;
}    
