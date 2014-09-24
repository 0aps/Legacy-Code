#include <iostream>
/*
  Name: Encuentra la letra en la oracion.
  Copyright: OpenSource
  Author: @Aps
  Date: 26/04/11 15:23
  Description: :P
*/

// Fecha: 4/6/11
// Cosas a mejorar:
// - no hace diferencia entre mayus y minus.
// - comentar.

using namespace std;

int main()
{
    char oracion[100],letra;
    int i=0;
    bool si=false;
    cout << "Introduce la cadena: ";
    cin.getline(oracion,100);
    cout << "Introduce la letra a buscar:  ";
    cin >> letra;
    
    while(oracion[i])
  {              
                     
    if(oracion[i] == letra)
    {
      cout << "\n\nSi se encuentra la posicion en el caracter # " << i+1  << " de la oracion.";
      si=true;
    }
     i++;
  }
   if(si == false)
   cout << "\n\nNo se encontro la letra.";
        
 
  setbuf(stdin, NULL);
  cin.get();
  return 0;
}  
