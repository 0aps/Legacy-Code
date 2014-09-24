#include <iostream>

using namespace std;

int main()
{
    int num, suma(0);
    
    for(int i(0); i < 10; i++, suma+=num)
            cin >> num;
            
    cout << "La suma de los 10 numeros introducidos es: " << suma;
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
