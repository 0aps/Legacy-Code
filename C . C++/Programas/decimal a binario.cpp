#include <iostream>

using namespace std;

/*
  Name: Decimal a binario 
  Copyright: GPL 
  Author: @aps
  Date: 12/10/11 19:02
  Description: 
*/


int main()
{
    int decimal, binario[10], aux(0); // aux para mostrar el arrey
        
    cout << "Ingrese el numero en decimal: ";
    cin >> decimal;
    
       for(int i(0); decimal >= 1 ; i++, aux++) //mientras el num sea mayor que 1
       {

                  if(decimal%2 == 0)  //si es par
                  {
                      binario[i] = 0;  //guardo 0 en un arrey
      
                           decimal /= 2;  // lo divido 
                           continue;      //vuelvo al  bucle
                   }

                  if(decimal%2 == 1)   // si es impar
                   {
                                binario[i] = 1;
                                
                                decimal -= 1;   // le resto uno
                                decimal /= 2;   // lo divido
                                continue;       //vuelvo a comparar
                   }

                   
                   

        }            
        
    cout << "\n\nEl numero en binario es: "; 
    for(int i = aux-1; i >= 0 ; i--)   //aux = el numero de veces que se guardo un num en el arrey
          cout << binario[i];
    
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}


