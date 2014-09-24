#include <iostream>

using namespace std;

int main()
{
    int num, mayor(0);
    
    while (cin >> num && num != -99)
          {
               if( num > mayor ) mayor = num;
               if( num < 0) cout << "Se leyo un numero negativo. " << endl;
          }
    
    cout << "El numero mayor es: " << mayor;
    
    setbuf(stdin, NULL);
    cin.get();
    
    return 0;
}
    
