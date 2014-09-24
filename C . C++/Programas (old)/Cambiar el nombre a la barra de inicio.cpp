#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;
 
int main(int argc, char *argv[])
{
    HWND manejador1,manejador2;
    char texto[10];
 
    cout<<"\t Procederemos a cambiar el texto de el boton de inicio"<<endl<<endl;
    cout<<"\t introduzca el texto:";
    cin.getline(texto,7);
 
    manejador1 = FindWindow("Shell_TrayWnd",NULL); //<--- obtiene el manejador de la barra de tareas
    manejador2 = FindWindowEx(manejador1,0,"Button",NULL);  //<-- obtiene el manejador del boton de inicio de la barra de tareas
    SetWindowText(manejador2,texto);  // <--- asigna el texto
    SendMessage(manejador2,WM_MOUSEMOVE,0,0); // <--- esto es usado para mandarle el texto a el boton de la barra de tareas
 
 
    return EXIT_SUCCESS;
}
 
