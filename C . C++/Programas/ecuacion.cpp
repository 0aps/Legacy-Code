#include <iostream>

using namespace std;

int main()
{
    int i=0;
    char ecuacion[100];
    cout << " Ingrese la ecuacion: ";
    cin.getline(ecuacion, 100);
    
    cout << endl << endl << "=======================\nEcuacion\n\n" << ecuacion << "\n\n=======================\n\n\n";
    while(ecuacion[i])
    {
                      if(ecuacion[i] >= 'a' || ecuacion[i] <= 'z')
                    //  ecuacion
                      cout << "\n\nsi" << endl << ecuacion << endl << ecuacion[i] << endl << i << endl;
              else    cout << "\n\nno" << endl << ecuacion << endl << ecuacion[i] << endl << i << endl;
     i++;
     }
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
    
}
