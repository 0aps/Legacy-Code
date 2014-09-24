#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
DWORD FindXBytes(DWORD inicio,LPVOID bytes,LPSTR proceso,DWORD tam)
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  ZeroMemory( &si, sizeof(si) );
  ZeroMemory( &pi, sizeof(pi) );
  si.cb = sizeof(si);
  DWORD leidos;
  char *value;
  value=(char *)malloc(tam);
  memset(value,0,tam);
  if(CreateProcess(proceso,"",NULL,NULL,FALSE,NULL,NULL,NULL,&si,&pi))
  {
    ResumeThread(pi.hThread);
    while(ReadProcessMemory(pi.hProcess, (LPVOID)inicio, &value, tam, &leidos))
    {
      if(memcmp(bytes,&value,tam)==0)
      {
        TerminateProcess(pi.hProcess,0);
        return inicio;
      }
      inicio++;
    }
    TerminateProcess(pi.hProcess,0);
    return 0;
  }
  else
  {
    return 0;
  }
}
int main()
{
  //->Ejemplo de uso 
  char buscar[5]={0xFF,0x35,0x50,0x20,0x40,0x00};
  int posicion=FindXBytes(0x401000,buscar,"c:\\crackme2.exe",4);
  if(posicion!=0)
    printf("%s esta en la direccion en memoria-> %X",buscar,posicion);
  else printf("no se encontro %s en la memoria virtual del programa");
  getchar();
  return 0;
}
