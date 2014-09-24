#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;
 
int main(int argc, char *argv[])
{   
 
HWND hwnd,hwnd2; // Declaramos los manejadores
hwnd=FindWindow(NULL,"Sin título - Bloc de notas");// El caption de el notepad.exe
hwnd2= FindWindowEx(hwnd,NULL,"Edit",NULL);// La clase de el notepad.exe "edit"

LRESULT result = SendMessage(hwnd2,WM_SETTEXT,0,LPARAM(":d"));// el parametro a mandar
 
SetWindowText(hwnd ,"Se cambio el caption y el frame"); //Cambiamos el titulo de la ventana
 
SetWindowLong(hwnd,GWL_EXSTYLE,WS_EX_TOOLWINDOW); // cambiamos el frame a toolwindow
 
if (result==1)           // comprobamos que se mande el flujo
cout<<"Se a enviado el flujo a el bloc de notas";
else
cout<<"Fallo en el envio de el flujo";
    getchar();
    return EXIT_SUCCESS;
}
 
