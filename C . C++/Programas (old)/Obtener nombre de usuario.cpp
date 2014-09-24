#include <iostream>
#include <windows.h>  // <-----  necesaria para GetUserName()
using namespace std;
int main()
{
    char NombredeUsuario[100];
    DWORD nNombredeUsuario = sizeof(NombredeUsuario);
 
    if (GetUserName( NombredeUsuario, &nNombredeUsuario ) == 1 ) {
        cout << "El nombre de usuario es: <" << NombredeUsuario <<">" << endl;
 
    }
    else {
         cout << "No se logro obtener el nombre de usuario" << endl;
}
    getchar();
    return 0;
}
 
