#include <iostream>
using namespace std;

int main()
{
    
int numeros[10] = { 1, 2, 3, 9 , 2, 3, 5 , 7, 5, 9 }; /*Define los numeros*/
int elemento = 0;
int mayor;

for ( elemento = 0; elemento < 10; elemento++ ) /*Ciclo for*/
if ( numeros[elemento] > mayor )
mayor = numeros[elemento];

/*Eso declara un ciclo for en el que se encuentra el mayor, despues nada mas necesitarias hacer un:*/

cout << "El numero mas grande es: " << mayor << endl;
cin.get();

}
