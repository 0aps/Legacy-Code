#include <iostream>

using namespace std;

int main()
{
    for(int i(0); i < 100; i++)
            cout << i << endl;
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
