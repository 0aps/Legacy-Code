#include "windows.h"
#include "stdio.h"


int main()
{
int n = 24;
DWORD pid;
HANDLE process; // Manejador a un evento de la ventna en este caso proceso.
BYTE *celda;

HWND wnd = FindWindow(0, "MinesWeeper"); // Manejador de la ventana.

GetWindowThreadProcessId(wnd, &pid);
printf("%x", pid);

process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

if ( ReadProcessMemory( process, (LPVOID)0x01005360, celda, 1, NULL) == 0)
puts("no se pudo leer la direccion de memoria");

*celda = 0x43;

WriteProcessMemory(process, (LPVOID)0x01005360, celda, 1, NULL);

getchar();
CloseHandle(process);

return 0;
}

//         WriteProccesMemory
// Procces = Manejador del proceso que se optien� con openprocces.
// (siempre que se valla a trabajar en memor�a se abr� el proceso (duh!)

// (LPVOID)0x100579c = Direcci�n de memor�a que vam�s a editar.
// Esta pued� estar almacenad� en una variable. (obio nuevamente!)

// &n = Valor que se va a ingresar en la memor�a
// Este valor es bueno que se� contante (const)

// 8 || sizeof(&n) Ver cu�ntos bytes ocupa el nuevo valor.

//  NULL = En esta parte la funci�n WPM verif�ca el tama�o que ocupar� el nuevo valor
// en la direcci�n de memor�a.
