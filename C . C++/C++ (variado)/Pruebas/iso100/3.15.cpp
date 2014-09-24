#include <iostream>

using namespace std;

int main()
{
    int numero, acc(0);
    
    for(int i(0); i < 500; i++)
    {
            cin >> numero;
            if(numero > 0) acc++;
    }
    
    cout << "Hay " << acc << " numeros positivos. ";
    
    setbuf(stdin, NULL);
    cin.get();
    
    return 0;
}      
