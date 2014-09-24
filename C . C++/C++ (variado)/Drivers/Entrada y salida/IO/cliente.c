#include <windows.h>
#include <stdio.h>

int main(){
  HANDLE hFile;DWORD dwReturn;
  CHAR buffer[512],*msg="Este es un mensaje para el kernel!";;

  hFile=CreateFile("\\\\.\\Ejemplo",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
  if(hFile){
    printf("Escribiendo en el driver: \"%s\"\n",msg);
    WriteFile(hFile,msg,strlen(msg)+1,&dwReturn,NULL);
    printf("Leyendo del driver!\n");
    ReadFile(hFile,buffer,512,&dwReturn,NULL);
    printf("Mensaje Leido: \"%s\"\n",msg);
    CloseHandle(hFile);
  }

  system("pause");
  return 0;
}
