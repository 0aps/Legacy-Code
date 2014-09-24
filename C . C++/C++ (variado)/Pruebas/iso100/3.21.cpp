#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
            
    for(int i(0); i < num; i++) cout << i << " multiplo de 4: " << 4*i << endl;
    
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
