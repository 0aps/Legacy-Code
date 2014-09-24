#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;
 
int main(int argc, char *argv[])
{
    HWND manejador1,manejador2;
 
    manejador1 = FindWindow("Shell_TrayWnd",NULL); //<--- obtiene el manejador de la barra de tareas
 
    EnableWindow(manejador1,FALSE);  //<--TRUE vuelve a habilitar la barra de tareas
 
    return EXIT_SUCCESS;
}
 
 
