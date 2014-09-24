#include <stdio.h>
#include <windows.h>
 
#define pause() setbuf(stdin, NULL); getchar();
 
const long direccion=0x0022ff50;
 
int main(int argc, char *argv[])
{
    int nuevo_valor=0;
    HWND hwnd;
    DWORD pid;
    HANDLE pHandle;
    printf("Introduzca el nuevo valor: ");
    scanf("%i", &nuevo_valor);
    hwnd=FindWindow(NULL, "Hackme");
    if(!hwnd)
    {
        printf("No se encuentra la ventana");
        pause();
        return -1;
    }
    GetWindowThreadProcessId(hwnd, &pid);
    pHandle=OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
    if(!pHandle)
    {
        printf("No se pudo abrir el proceso");
        pause();
        return -2;
    }
    WriteProcessMemory(pHandle, (LPVOID)direccion, (LPVOID)&nuevo_valor, 4, 0);
    printf("Se ha modificado el valor");
    pause();
    CloseHandle(pHandle);
    return 0;
}
