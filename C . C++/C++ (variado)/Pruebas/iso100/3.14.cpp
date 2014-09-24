#include <iostream>

using namespace std;

int main()
{
    long double suma(0), producto(1);
    
    for(int i(20); i <= 200; i++)
            if ( !(i%2) ) suma+=i, producto *= i;
    
    cout << "Suma de los numeros pares: " << suma << endl
         << "Productos de los numeros pares: " << producto;
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
