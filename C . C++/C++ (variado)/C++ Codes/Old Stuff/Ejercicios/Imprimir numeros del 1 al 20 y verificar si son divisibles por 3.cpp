

// Este programa muestra una lista de n�meros, 
// indicando para cada uno si es o no m�ltiplo de 3.

#include <iostream> //<< >>
using namespace std;

int main(int argc, char *argv)
{
    int i;
    for(i=1;i <=20; i++)
    if(i%3==0)
    cout << i << "\tDivisible\n";
    else cout << i << "\tNo Divisible\n";
    cin.get();
    cin.get();
    return 0;
}



// Este programa muestra una lista de n�meros, 
// indicando para cada uno si es o no m�ltiplo de 3.

#include <iostream> //<< >>
using namespace std;

bool VerificarDivicion(int a); // Declaraci�n del prototipo de la funci�n.

int main()
{
    int x=1;
while(x<=20)
{
cout << x;
if(VerificarDivicion(x)) 
cout <<"\tDivisible"; 
else cout <<"\tNo divisible";
x++;
cout << endl;
}   
cin.get();       // Incremento de la variable 
return 0;  //Verificar que todo haya ido bien
}

bool VerificarDivicion(int a)  // Definici�n de la funci�n
{
    if(a%3) return false; else return true;
}






















