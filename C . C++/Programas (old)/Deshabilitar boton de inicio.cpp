#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;
 
int main(int argc, char *argv[])
{
    HWND manejador1,manejador2;
 
    manejador1 = FindWindow("Shell_TrayWnd",NULL); //<--- obtiene el manejador de la barra de tareas
    manejador2 = FindWindowEx(manejador1,0,"Button",NULL);  //<-- obtiene el manejador del boton de inicio
                                                           // de la barra de tareas
 
    EnableWindow(manejador2,FALSE);  //<--TRUE vuelve a habilitar el boton
 
    return EXIT_SUCCESS;
}
 
