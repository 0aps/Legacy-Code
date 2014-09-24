#include <iostream>
#include "strlen.cpp"

using namespace std;
//extern int strlenn(char*);
int mayor(int [], int);

int main()
{
    int cadena[10] = { 1,2,3,88,5,6,7,8,9,10};
    
    cout << strlenn( cadena) << endl;
    cout << mayor(cadena, 10);
    cin.get();
    return 0;
}

int mayor(int a[], int elementos)
{
    int mayor(0);
    for(int i=0; i<elementos; i++)
    {
        //    cout << mayor << endl;
          //  cin.get();
    
            if(a[i] > mayor)
            mayor = a[i];
            
    }
    return mayor;
}        

