#include <winsock2.h>

int main(int argc, char *argv)
{

char DllPath[MAX_PATH]="C:\\hack.dll";
HWND Buscaminas;
DWORD BuscaminasPID;
HANDLE BuscaminasHandle;
HMODULE hKernel;
PVOID LoadLibraryAddress, RemoteVirtualAddress;
BOOL bSuccess;
HANDLE hRemoteThread;
 
/*Obtenemos la direccion base de la libreria kernel32 donde reside LoadLibraryA*/
hKernel=GetModuleHandle("kernel32.dll"); 
 
/*Buscamos en la libreria la funcion exportada*/
LoadLibraryAddress=(PVOID)GetProcAddress(hKernel, "LoadLibraryA"); 

/*Nota: Aqui no nos preocupamos por la memoria virtual del contexto del otro proceso con respecto a las funciones que acabos de recabar, ya que todas son proyectadas en la misma direccion de memoria en todos los procesos =)*/
 
/*Intentamos encontrar el handle a la ventana del buscaminas*/
Buscaminas=FindWindow(NULL, "Buscaminas");

if(!Buscaminas)
 return 1; //error 
  
/*Recabamos el processId del proceso que posee la ventana*/
GetWindowThreadProcessId(Buscaminas, &BuscaminasPID);
 
/*Abrimos una referencia al proceso con el process id obtenido*/ 
BuscaminasHandle=OpenProcess(PROCESS_ALL_ACCESS, FALSE, BuscaminasPID); 
 
/*Alojamos memoria en el proceso remoto =)*/
RemoteVirtualAddress=VirtualAllocEx(BuscaminasHandle, NULL, strlen(DllPath), MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE); 

if(!RemoteVirtualAddress)
 return 1; //error
 
/*Escribimos en el espacio remoto que acabamos de alojar el string al camino de la dll*/
bSuccess=WriteProcessMemory(BuscaminasHandle, RemoteVirtualAddress, DllPath, strlen(DllPath), NULL); 

if(!bSuccess)
 return 1; //error
 
/*Creamos el hilo remoto y pasamos de parametro la direccion de memoria donde se encuentra nuestra cadena de caracteres que tiene la ruta de nuestro ejecutable =D*/
hRemoteThread=CreateRemoteThread(BuscaminasHandle, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryAddress, (LPVOID)RemoteVirtualAddress, NULL, NULL); 

if(!hRemoteThread)
 return 1; //error
 
/*Esperamos a que el thread remoto termine de ejecutarse, este paso es opcional*/
WaitForSingleObject(hRemoteThread, INFINITE); 

return 0;

}
