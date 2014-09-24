#include <windows.h>

int main(){
  HANDLE hFile;
  DWORD dwReturn;
  hFile=CreateFile("\\\\.\\Ejemplo",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
  if(hFile){
    ReadFile(hFile,0,0,&dwReturn,NULL);
    WriteFile(hFile,0,0,&dwReturn,NULL);
    CloseHandle(hFile);
  }
  return 0;
}
