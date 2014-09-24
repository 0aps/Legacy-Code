#include <windows.h>
 
int main(int argc, char *argv[])
 
{  
   HWND manejador1,manejador2;
   manejador2 = FindWindow("Shell_TrayWnd",NULL);
 
   ShowWindow(manejador2,SW_HIDE /*show*/); // <---- esconde/muestra la barra de tareas
 
   return EXIT_SUCCESS;
}
