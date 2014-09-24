#include <iostream>

using namespace std;

int main()
{
    int suma(0), suma2(0);
    
    for(int i(1); i <= 200; i++)
            if( !(i%2) ) suma+=i;
            else       suma2+=i;
            
    cout << "Pares: " << suma << endl;
    cout << "Impares: " << suma2 << endl;
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
