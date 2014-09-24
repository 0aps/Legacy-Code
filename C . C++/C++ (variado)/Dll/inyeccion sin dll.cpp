#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

//puntero a funcion para guardar la direccion de MessageBoxA
//y para pasarle los parametros
typedef int (WINAPI *datMessageBoxA) (HWND, LPCTSTR, LPCTSTR, UINT);
 
//estructura de datos a inyectar 
struct datos
{
datMessageBoxA apiMessageBoxA; //manejador del puntero a funcion
char titulo [20];
char mensaje [20];
};
 

// funcion para obtener la direccion de una funcion
DWORD GetAdres(char *module, char *function); 
 
//funcion para a la cual se le lanza el hilo  
DWORD inyectada (datos *data)
{
data -> apiMessageBoxA (0, data->mensaje, data->titulo, 0);
return 0;
}
 
void inyectora()
{
int pid;
HANDLE proc;
datos dat;
DWORD TamFun; //tamano de la funcion
void* esp;
 
HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0); 
PROCESSENTRY32 procinfo = { sizeof(PROCESSENTRY32) };

while(Process32Next(handle, &procinfo))
{
                            if(!strcmp(procinfo.szExeFile, "notepad.exe"))
                            {
                              CloseHandle(handle);
                              pid = procinfo.th32ProcessID;
                            }
}
 
proc = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, false, pid);

//almaceno la direccion de messageboxA 
dat.apiMessageBoxA = (datMessageBoxA) GetAdres ("USER32.DLL", "MessageBoxA");
 
sprintf(dat.mensaje,"holaaaaaa!!!");
sprintf(dat.titulo,"titulo!!!");
 
//reservo espacio para los datos y escribo la estructura
datos *dat_ = (datos*) VirtualAllocEx(proc, 0, sizeof(datos), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
WriteProcessMemory(proc, dat_, &dat, sizeof(datos), NULL);
 
TamFun = (long unsigned int) inyectora - (long unsigned int)inyectada;
 
//reservo espacio para la funcion inyectada a la cual se le pasa como parametro
// la estructura (*dat_)
esp = VirtualAllocEx(proc, 0, TamFun, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
WriteProcessMemory(proc, esp, (void*)inyectada, TamFun, NULL);

//lanzo el hilo
CreateRemoteThread(proc, NULL, 0, (LPTHREAD_START_ROUTINE) esp, dat_, 0, NULL);

}
 
int main()
{
inyectora();
}
 
DWORD GetAdres(char *module, char *function)
{

HMODULE dh = LoadLibrary(module);
DWORD pf = (DWORD)GetProcAddress(dh,function);
FreeLibrary(dh);
return pf;

}
