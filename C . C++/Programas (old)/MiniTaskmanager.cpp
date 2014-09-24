#include <windows.h>
#include <iostream>

typedef DWORD (WINAPI* TGetProcessImageFileName)(HANDLE, LPSTR, DWORD);
typedef DWORD (WINAPI* TGetModuleFileNameEx)(HANDLE, HMODULE, LPSTR, DWORD);
typedef BOOL (WINAPI* TEnumProcessModules)(HANDLE, HMODULE*, PDWORD);
typedef DWORD (WINAPI* TGetModuleBaseName)(HANDLE, HMODULE, LPSTR, DWORD);
typedef BOOL (WINAPI* TEnumProcesses)(PDWORD, DWORD, PDWORD);
typedef DWORD (WINAPI *TNtSuspendProcess)(HANDLE);
typedef DWORD (WINAPI *TNtResumeProcess)(HANDLE);

using namespace std;

TGetProcessImageFileName GetProcessImageFileName;
TGetModuleFileNameEx GetModuleFileNameEx;
TEnumProcessModules EnumProcessModules;
TGetModuleBaseName GetModuleBaseName;
TEnumProcesses EnumProcesses;
TNtSuspendProcess NtSuspendProcess;
TNtResumeProcess NtResumeProcess;

bool CongelaProceso(DWORD ProcessId){
     DWORD NtStatus;
     HANDLE hProcess;
     hProcess=OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
     if(!hProcess){
       printf("No se pudo abrir proceso %d\n", ProcessId);
       return false;
     }
     NtStatus=NtSuspendProcess(hProcess);
     if(NtStatus){
       printf("No se pudo congelar proceso %d (codigo de error: %d)\n", ProcessId, NtStatus);
       CloseHandle(hProcess);
       return false;
     }
     printf("Proceso congelado con exito %d\n", ProcessId);
     CloseHandle(hProcess);
     return true;
}

bool DescongelaProceso(DWORD ProcessId){
     DWORD NtStatus;
     HANDLE hProcess;
     hProcess=OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
     if(!hProcess){
       printf("No se pudo abrir proceso %d\n", ProcessId);
       return false;
     }
     NtStatus=NtResumeProcess(hProcess);
     if(NtStatus){
       printf("No se pudo descongelar proceso %d (codigo de error: %d)\n", ProcessId, NtStatus);
       CloseHandle(hProcess);
       return false;
     }
     printf("Proceso descongelado con exito %d\n", ProcessId);
     CloseHandle(hProcess);
     return true;
}

bool TerminaProceso(DWORD ProcessId){
     HANDLE hProcess;
     hProcess=OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
     if(!hProcess){
       printf("No se pudo abrir proceso %d\n", ProcessId);
       return false;
     }
     if(!TerminateProcess(hProcess, 0)){
          printf("No se pudo terminar proceso %d\n", ProcessId);
          CloseHandle(hProcess);
          return false;
     }
     printf("Proceso %d terminado con exito\n", ProcessId);
     CloseHandle(hProcess);
     return true;
}

void MostrarInformacion(HANDLE hProcess, DWORD ProcessId){
     LPSTR buffer;
     buffer=(char*)malloc(MAX_PATH);
     memset(buffer, 0, MAX_PATH);
     printf("ProcessId: %d\n", ProcessId);
     if(!GetModuleBaseName(hProcess, NULL, buffer, MAX_PATH)){
        printf("Proceso: ?????\n");
     }
     else{
        printf("Proceso: %s\n", buffer);
     }
     if(!GetModuleFileNameEx(hProcess, NULL, buffer, MAX_PATH)){
        printf("Ruta: ??????\n");
     }
     else{
        printf("Ruta: %s\n\n", buffer);
     }
     free(buffer);
}

bool ListaProcesos(){
     HANDLE hProcess;
     DWORD Returned, i;
     PDWORD Lista;
     Lista=(PDWORD)malloc(100*sizeof(DWORD));
     memset(Lista, 0, 100*sizeof(DWORD));
     if(!EnumProcesses(Lista, 100*sizeof(DWORD), &Returned)){
         printf("Ocurrio un error al listar los procesos");
         free(Lista);
         return false;
     }
     for(i=0; i<(Returned/sizeof(DWORD)); i++){
         hProcess=OpenProcess(PROCESS_ALL_ACCESS, FALSE, Lista[i]);
         if(hProcess){
              MostrarInformacion(hProcess, Lista[i]);
              CloseHandle(hProcess);
         }
     }
     free(Lista);
     return true;
}

bool Inicializa(){
    HMODULE PspAddress, ntdllAddress;
    PspAddress=LoadLibrary("psapi.dll");
    if(!PspAddress){
        printf("No se pudo cargar psapi.dll\n");
        return false;
    }
    ntdllAddress=GetModuleHandle("ntdll.dll");
    if(!ntdllAddress){
        printf("No se pudo obtener direccion de ntdll.dll\n");
        return false;
    }
    EnumProcesses=(TEnumProcesses)GetProcAddress(PspAddress, "EnumProcesses");
    if(!EnumProcesses){
        printf("No se encontro funcion EnumProcesses\n");
        return false;
    }
    GetProcessImageFileName=(TGetProcessImageFileName)GetProcAddress(PspAddress, "GetProcessImageFileNameA");
    if(!GetProcessImageFileName){
       printf("No se encontro funcion GetProcessImageFileName\n");
       return false;
    }
    GetModuleFileNameEx=(TGetModuleFileNameEx)GetProcAddress(PspAddress, "GetModuleFileNameExA");
    if(!GetModuleFileNameEx){
       printf("No se encontro funcion GetModuleFileNameEx\n");
       return false;
    }
    EnumProcessModules=(TEnumProcessModules)GetProcAddress(PspAddress, "EnumProcessModules");
    if(!EnumProcessModules){
       printf("No se encontro funcion EnumProcessModules\n");
       return false;
    }
    GetModuleBaseName=(TGetModuleBaseName)GetProcAddress(PspAddress, "GetModuleBaseNameA");
    if(!GetModuleBaseName){
       printf("No se encontro funcion EnumProcessModules\n");
       return false;
    }
    NtSuspendProcess=(TNtSuspendProcess)GetProcAddress(ntdllAddress, "ZwSuspendProcess");
    if(!NtSuspendProcess){
        printf("No se encontro NtSuspendProcess\n");
        return false;
    }
    NtResumeProcess=(TNtResumeProcess)GetProcAddress(ntdllAddress, "NtResumeProcess");
    if(!NtResumeProcess){
        printf("No se encontro NtResumeProcess \n");
        return false;
    }
    return true;
}

char comando[250]={0};
int PID=0;

int main(){
    if(Inicializa()==false){
       system("pause");
       return 1;
    }
    printf("MiniTaskmanager [http://unrealord.blogspot.com]\n");
    printf("Escribe un comando:\n");
    printf("listaprocesos\n");
    printf("terminaproceso\n");
    printf("congelaproceso\n");
    printf("descongelaproceso\n");
    printf("salir\n\n");
    while(1){
       printf("Comando> ");
       scanf("%s", comando);
       if(!stricmp(comando, "salir")){
          return 0;
       }
       if(!stricmp(comando, "listaprocesos")){
         printf("\n");
         ListaProcesos();
         continue;
       }
       if(!stricmp(comando, "terminaproceso")){
          printf("PID?> ");
          scanf("%d", &PID);
          TerminaProceso(PID);
          continue;
       }
       if(!stricmp(comando, "congelaproceso")){
          printf("PID?> ");
          scanf("%d", &PID);
          CongelaProceso(PID);
          continue;
       }
       if(!stricmp(comando, "descongelaproceso")){
          printf("PID?> ");
          scanf("%d", &PID);
          DescongelaProceso(PID);
          continue;
       }
       printf("Comando desconocido\n");
    }
    //ListaProcesos();
    system("pause");
}
