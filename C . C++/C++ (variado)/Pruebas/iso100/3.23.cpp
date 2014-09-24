#include <iostream>

using namespace std;

int main()
{
    int suma(0), mediai(0), pares(0), num;
    
    for(int i(0); i<10; i++)
            {
                  cin >> num;
                  if( !(num%2) ) suma+=num, pares++;
                  else mediai += num;
            }
    
    cout << "Existen " << pares << " numeros pares, su suma es: " 
         << suma << endl
         << "La media aritmetica de los impares es: " << mediai/(10-pares);
         
        
    setbuf(stdin, NULL);
    cin.get();
    return 0;
} 
