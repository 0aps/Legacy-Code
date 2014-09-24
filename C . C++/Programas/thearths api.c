#include <windows.h>
#include <stdio.h>
DWORD av;    //<- La variable está disponible tanto para el programa principal como para el thread... (es global)
UCHAR msg[256];
HANDLE m_hThread; //Identificador del thread...
DWORD thid;
 
DWORD WINAPI mythreadproc(LPVOID params){
  //nota...
  MessageBox(NULL,"El thread se ejecuta en forma independiente aunque el proceso principal quede en espera...","Nota",MB_ICONEXCLAMATION | MB_OK);
  //Mostramos el argumento...
  sprintf(msg,"\nArgumento: %d\n\n",(LPDWORD)params);
  MessageBox(NULL,msg,"Argumentos",MB_ICONEXCLAMATION | MB_OK);
  //Hacemos algo...
  for(av=0,msg[0]='\0';av<3;av++){
    lstrcat(msg,"Hola ");
    MessageBox(NULL,msg,"Proceso???",MB_ICONEXCLAMATION | MB_OK);
  }
  //Finalizamos thread...
  ExitThread(0);
}
 
//Main Proc
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR CmdLine, INT nCmdShow){
  av=100;m_hThread=0;
  //lanzamos thread...
  m_hThread=CreateThread(NULL, 0, mythreadproc,(LPVOID)av, 0, &thid);
  if(!m_hThread)
    MessageBox(NULL,"Error al crear thread...","Error",MB_ICONEXCLAMATION | MB_OK);
  //Esperamos fin...
  MessageBox(NULL,"\n\n\n\n\n\n\t\t\tPresione aceptar para continuar...\t\t\t\n\n\n\n\n\n","Salir",MB_ICONEXCLAMATION|MB_OK);
  return 0;
}
