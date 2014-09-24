#include <iostream>
#define para cin.get()

using namespace std; 

void predesp(int x, int& a, int& b)
{
    a=x-1;
    b=x+1;
}

int main()
{
    int x,y,z;
cout << "Ingresa un numero: ";
cin >> x;
predesp(x,y,z);
cout << "El numero antes del ingresado es: " << y;
cout << "\n\nEl numero despues del ingresado es: " << z;
para;
para;
return 0;
}
