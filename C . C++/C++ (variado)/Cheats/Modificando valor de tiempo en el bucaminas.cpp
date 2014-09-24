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
// Procces = Manejador del proceso que se optiené con openprocces.
// (siempre que se valla a trabajar en memoría se abré el proceso (duh!)

// (LPVOID)0x100579c = Dirección de memoría que vamós a editar.
// Esta puedé estar almacenadá en una variable. (obio nuevamente!)

// &n = Valor que se va a ingresar en la memoría
// Este valor es bueno que seá contante (const)

// 8 || sizeof(&n) Ver cuántos bytes ocupa el nuevo valor.

//  NULL = En esta parte la función WPM verifíca el tamaño que ocupará el nuevo valor
// en la dirección de memoría.
