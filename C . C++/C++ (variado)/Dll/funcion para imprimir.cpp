#include <stdio.h>
#include <windows.h>

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
                    
    char *cadena = "hola mundo.";
    printf("%s", cadena);
    
    const long direccion = 0x00403000;
    SetConsoleTitle("Hackme");
        
    char *contenido;
    char mensaje[256];
    
    
    HWND hwnd;
    DWORD pid;
    HANDLE phandle;
    
    
    hwnd = FindWindow(NULL, "Hackme");
    if(!hwnd)
    {
        MessageBox(NULL, "No se esta ejecutando Pinball", "Error", MB_OK | MB_ICONERROR);
        return -1;
    }
    GetWindowThreadProcessId(hwnd, &pid);
    phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
    if(!phandle)
    {
        MessageBox(NULL, "Error al obtener el handle del proceso", "Error", MB_OK | MB_ICONERROR);
        return -2;
    }
    
   // 00403000=funcion_. (ASCII "hola mundo.")

    
    ReadProcessMemory(phandle,(LPVOID)direccion,(LPVOID)&contenido,sizeof(contenido),0);
    
  // sprintf(mensaje, "Tu puntuacion es %ld .", contenido);
    printf("%s", &contenido);
    
  //  WriteProcessMemory(phandle, (LPVOID)direccion, (LPVOID) &nuevaPuntuacion, sizeof(nuevaPuntuacion), 0);
    
  //  sprintf(mensaje, "Tu puntuacion ha cambiado de %ld a %ld", viejaPuntuacion, nuevaPuntuacion);
    
 //   MessageBox(NULL, mensaje, "Listo", MB_OK);
    
    getchar();
    return 0;
}
