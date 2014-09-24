#include <iostream>

using namespace std;

int main()
{
    int suma(0);
    
    for(int i(2); i <= 100; i++)
            if( !(i%2) ) suma+= i;
    
    cout << "Suma de los numeros pares del 2 al cien: " << suma << endl;
    
    setbuf(stdin, NULL);
    cin.get();
}
