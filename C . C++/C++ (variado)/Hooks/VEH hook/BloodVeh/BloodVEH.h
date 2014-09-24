/*
VEH HOOK:
Modificado por BloodSharp
 
Uso:
HookFuncion(hook,funcion_manejador_del_hook);
 
Fuente http://foro.elhacker.net/analisis_y_diseno_de_malware/veh_api_hook-t288587.0.html
*/
#ifndef BLOOD_VEH
#define BLOOD_VEH
 
#ifndef _WIN32_WINNT
     #define _WIN32_WINNT 0x0500
#else
     #undef _WIN32_WINNT
     #define _WIN32_WINNT 0x0500
#endif
 
#include<windows.h>
 
#define ORIG_FUNC 0x100
#define HOOK_FUNC 0x101
 
typedef struct
{
     PVOID OrigFunc,HookFunc;
     DWORD Proteccion;
}HOOK_STRUCT;
 
void HookFuncion(HOOK_STRUCT,PVECTORED_EXCEPTION_HANDLER);
BOOL SwitchFuncion(HOOK_STRUCT,int);
 
#endif
//FIN DEL VEHHOOK.H
 
