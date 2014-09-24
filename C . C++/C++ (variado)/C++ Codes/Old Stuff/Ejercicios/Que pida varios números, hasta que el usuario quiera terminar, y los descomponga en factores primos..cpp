// Programa que descompone números en factores primos
// 26/07/2003 Salvador Pozo

#include <iostream> // biblioteca para uso de cout 
using namespace std;

int main()
{
   int numero;
   int factor;
   char resp[12];
   
   do {
      cout << "Introduce un número entero: ";
      cin >> numero;
      factor = 2;
      while(numero >= factor*factor) {
         if(!(numero % factor)) {
            cout << factor << " * ";
            numero = numero / factor;
            continue;
         }
         if(factor == 2) factor++;
         else factor += 2;
      }
      cout << numero << endl;
      cout << "Descomponer otro número?: ";
      cin >> resp;
   } while(resp[0] == 's' || resp[0] == 'S');
   return 0;
}
