#include "BloodVEH.h"

HOOK_STRUCT MBOX;
 
UINT __stdcall _MsgBox(HWND h,char *Texto,char *Titulo,UINT Tipo)
{
     //Se llama a la funcion original
     UINT r=MessageBox(h,"Mensaje Manipulado",Titulo,Tipo);
     SwitchFuncion(MBOX,HOOK_FUNC);//Se llama a la funcion hook
     return r;
}
 
/*
Esta funcion habria que usarla para cada hook...
Estuve intentado varias veces, aunque en vano, en ponerla con macros cada vez que se hookeaba
por eso la dejo aca aclarando esto para que en caso de que hagan otro hook hacerlo de esta forma...
*/
LONG __stdcall ManejadordeMBOX(PEXCEPTION_POINTERS ep)
{
     if(ep->ExceptionRecord->ExceptionCode==EXCEPTION_ACCESS_VIOLATION)
     {
          if(ep->ContextRecord->Eip==(DWORD)MBOX.OrigFunc)
          {
               SwitchFuncion(MBOX,ORIG_FUNC);
               ep->ContextRecord->Eip=(DWORD)MBOX.HookFunc;
               return EXCEPTION_CONTINUE_EXECUTION;
          }
     }     return EXCEPTION_CONTINUE_SEARCH;
}
 
int main(int argc,char *argv[])
{
     MBOX.OrigFunc=((PDWORD)GetProcAddress(GetModuleHandle("user32.dll"),"MessageBoxA"));
     MBOX.HookFunc=((PDWORD)_MsgBox);
     HookFuncion(MBOX,ManejadordeMBOX);
     //Llamamos al hook
     MessageBox(0,"Texto","Titulo",0);
     //Cambiamos a la funcion original
     SwitchFuncion(MBOX,ORIG_FUNC);
     MessageBox(0,"Texto","Titulo",0);
     //Volvemos a llamar a la funcion falsa
     SwitchFuncion(MBOX,HOOK_FUNC);
     return 0;
}
