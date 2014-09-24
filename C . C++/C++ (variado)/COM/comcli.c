/*
  Copyright: InExInferis Inc.
  URL: http://www.inexinferis.co.nr
  Author: Karman
  Date: 26/10/05 13:27
*/

#include <windows.h>
#include "coms.h"

#define bstr_w(a) ((OLECHAR*)(a))

//Main Proc
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR CmdLine, INT nCmdShow){

  HRESULT hr;IMyMessageBox *pIMMC;

  // 1. Inicilizamos la librer�a COM (hace que Windows abra las DLLs).
  CoInitialize(NULL);

  // 2. Creamos un objeto COM de nuestra Interfaz
  hr = CoCreateInstance(&CLSID_MyServerCOM,NULL,
  CLSCTX_INPROC_SERVER,&IID_IMyMessageCOM,(void**)&pIMMC);
    
  if(SUCCEEDED(hr)){
    // 3� Utilizamos nuestra Funci�n...
    hr = pIMMC->lpVtbl->MyMessageBox(pIMMC,bstr_w(L"MyMessageBox"),bstr_w(L"Hola Mundo COM!!!"));
    // 4� Liberamos la interface.
    pIMMC->lpVtbl->Release(pIMMC);
  }else{
    MessageBox(NULL,"CoCreateInstance() failed.",0,MB_ICONEXCLAMATION | MB_OK);
  }
  // 5� Finalizamos la librer�a COM.
  CoUninitialize();
  return 0;
}
