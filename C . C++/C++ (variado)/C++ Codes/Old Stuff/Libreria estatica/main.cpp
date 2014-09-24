#include "header.h"

int main()
{
    char *cadena = "Funcion de header.h";
    cout << "Funcion de la libreria iostream";
    MessageBox (0, "Libreria windows.h", "Funcion", 0);
    cout << endl << endl
         << "Header.h" << endl << endl
         << "Longitud de cadena: " <<  cadena
         << endl << Astrlen(cadena);
    
    cin.get();     
    return 0;
}
    
