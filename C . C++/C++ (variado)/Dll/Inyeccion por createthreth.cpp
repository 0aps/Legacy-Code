
#include <windows.h>
#include <stdio.h>

int main()
{

DWORD pid; 
HANDLE proc;

char buf[MAX_PATH]="";
char laDll[]="C:\\Documents and Settings\\Owner\\Desktop\\Programming\\C . C++\\C++ (variado)\\Hooks\\HookMessageBoxEx\\HookMessageBoxEx.dll";

LPVOID RemoteString;
LPVOID nLoadLibrary;
char Entrada[255];

printf("Ejemplo CreateRemoteThread by MazarD\nhttp://www.mazard.info\n");
printf("Introduce el PID del programa (puedes verlos en el taskmanager):");
fgets(Entrada,255,stdin);


pid=(DWORD)atoi(Entrada);
proc = OpenProcess(PROCESS_ALL_ACCESS, false, pid);

if(proc == NULL)
printf("no se pudo abrir el proceso");


//Aquí usamos directamente GetModuleHandle en lugar de loadlibrary ya que
//kernel32 la cargan todos los ejecutables
//Con esto tenemos un puntero a LoadLibraryA
nLoadLibrary = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"),
               "LoadLibraryA");


//Reservamos memoria en el proceso abierto
RemoteString = (LPVOID)VirtualAllocEx(proc,0,strlen(laDll),
                MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);

//Escribimos la ruta de la dll en la memoria reservada del proceso remoto
WriteProcessMemory(proc,(LPVOID)RemoteString,laDll,strlen(laDll),NULL);

//Lanzamos el hilo remoto en loadlibrary pasandole la dirección de la cadena
CreateRemoteThread(proc,NULL,0,(LPTHREAD_START_ROUTINE)nLoadLibrary,
                  (LPVOID)RemoteString,0,0);



CloseHandle(proc);

return true;
}
