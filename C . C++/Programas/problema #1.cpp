//Hacer un programa que lea diez valores enteros en un array desde el teclado y
//calcule y muestre: la suma, el valor promedio, el mayor y el menor.

/*
  Name: Problema #1 de c.conclase
  Copyright: Distribuido bajo licencia GPL.
  Author: @Aps
  Date: 27/12/10 17:00
  Description: Mi primer programa "comentado".   
*/


#include <iostream>
using namespace std;

int main()
{    
     
    int acomulador(0),i;       // acomulador para la suma y el promedio, variable para el for
    int valores[10];           // valores ingresados y mostrados
    int mayor(0), menor(100000); // variable para el # mayor y el menor

for (i=0;i<10; i++)        // ciclo for   para toma de datos
{
    
    cout << i+1 << " numero: ";  // toma de datos
    cin >> valores[i+1];         //toma de datos
    
acomulador += valores[i+1];  // le sumo a acomulador "cada" valor del arrey valores[i]

if(valores[i+1] > mayor)  // si un valor del arrey es mayor que la variable mayor
mayor = valores[i+1];     //  se le asigna a la variable el valor del arrey que es mayor.

if(valores[i+1] < menor)  // se usa el mismo algoritmo 
menor = valores[i+1];     //pero con diferente operador
}

   cout << "\nLos numeros ingresados son: ";  
   
for (i=0;i<10; i++)   // ciclo for para impresion del arrey (datos)
{
                 
    cout << valores[i+1];   // imprimo valores del arrey
    
    if(i==9)                //Si i es igual a 9 se imprime punto
    cout << ". "; else cout << ",";  // de lo contrario se imprime coma
    
}   


cout << "\n\n\nLa suma de estos es: " << acomulador << endl;    //se imprime la suma del arrey
cout << "El promedio de estos es: " << acomulador/10 << endl;   //se imprime el valor del arrey
cout << "El mayor de estos es: " << mayor << endl;              //se imprime el # mayor del arrey
cout << "El menor de estos es: " <<  menor;                     //se  imprime el #menor del arrey

setbuf(stdin, NULL); //limpio
cin.get(); //pause
 
return 0; //devuevlo al main
} //cierro
