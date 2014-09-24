#include "BloodVEH.h"
void HookFuncion(HOOK_STRUCT Hook,PVECTORED_EXCEPTION_HANDLER Manejador)
{
     AddVectoredExceptionHandler(1,Manejador);
     SwitchFuncion(Hook,HOOK_FUNC);
}
BOOL SwitchFuncion(HOOK_STRUCT Hook,int Tipo)
{
     switch(Tipo)
     {
          case 0x100://Cambiar a la funcion original
               return VirtualProtect(Hook.OrigFunc,1,PAGE_EXECUTE_READWRITE,&Hook.Proteccion);
          case 0x101://Cambiar a la funcion hook
               return VirtualProtect(Hook.OrigFunc,1,PAGE_NOACCESS,&Hook.Proteccion);
      }
}
