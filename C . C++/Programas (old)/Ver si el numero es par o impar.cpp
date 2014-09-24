#include <iostream> // << >>
using namespace std;

int main(int argc, char *argv)
{
    int n,x;
    cout << "Ingrese el numero: " ;
    cin >> n;
    x=n%2;
    if(x==0)
    {
        cout << "El numero es Par ";
    }
    else
    {
        cout << "El numero es Impar";
    }
cin.get();
return 0;
}
