#include <iostream>

using namespace std;

int main()
{
    long double suma(0);
    
    for(int i(1); i <= 100; i++)
            suma += i*i;
    
    cout << "Suma de los cien primeros numeros naturales: " << suma;
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
