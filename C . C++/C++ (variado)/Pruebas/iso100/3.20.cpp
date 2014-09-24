#include <iostream>

using namespace std;

int main()
{
    int num, suma(0);
    
    for(int i(0); i < 50; i++, suma+=num)
            cin >> num;
            
    cout << "La media de los 50 numeros introducidos es: " << suma/50;
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
