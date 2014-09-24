#include <cstdlib>
#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
    FreeConsole();
 
    char archivo[]="C:/Archivos de programa/Mozilla Firefox/firefox.exe"; // nombre y ruta de el archivo
    HWND hwnd;  //<---- manejador
    char str[100]; // <---- string
    DWORD t= sizeof(str);  //<---- obtiene el tamano de str  y se lo asigna a DWORD
    GetConsoleTitleA(str,t);// <--- obtiene el nombre de la actual ventana de consola
    hwnd=FindWindow(0,str); // <--- asigna el nombre de la ventana a hwnd
    FILE *fp = fopen(archivo,"r");
 
    if( fp ) {           // <---esto busca si esta instalado firefox en el ordenador
 
    ShellExecute(hwnd,NULL,"C:/Archivos de programa/Mozilla Firefox/firefox.exe",
    "http://foro.portalhacker.net/index.php",NULL,SW_SHOWMAXIMIZED);
      }                   //<--- executa firefox y abre la pagina seleccionada
 
      else {              //<------ NO se encontro firefox
 
    MessageBox(NULL,"Instale una version de Mozilla Firefox en su ordenador\n\n ¬¬!",
		"OOOPS!", MB_ICONWARNING);
 
            }
 
 
    return EXIT_SUCCESS;
}
 
