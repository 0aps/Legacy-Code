#include <iostream>

using namespace std;
//Uso de la función For

int main()
{
    int i;
    for(i=0; i<101; i++)
    cout << "Carga de la trasnferencia " << i << "\n";
    if (i<=101)
    {
        system("Cls");
    cout << "Carga completa\n\n";
    system("\npause");
}
    else if(i>101) 
    {
    system("Cls");
    cout << "Carga incompleta\n\n";
    system("\npause");
}
    return 1;
}
