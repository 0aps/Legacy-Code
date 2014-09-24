/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>

DllClass::DllClass()
{
MessageBoxA(0, "Se ha declarado el constructor", "Declaracion", 0);
}


DllClass::~DllClass ()
{
MessageBoxA(0, "Se ha destruido el constructor", "Declaracion", 0);
}

        

BOOL WINAPI DllMain    (HINSTANCE hInst     /* Library instance handle. */ ,
                       DWORD reason        /* Reason this function is being called. */ ,
                       LPVOID reserved     /* Not used. */ )
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
        MessageBoxA(0, "procces attach", "mensaje", 0);
        break;

      case DLL_PROCESS_DETACH:
        MessageBoxA(0, "procces detach", "mensaje", 0);
        break;

      case DLL_THREAD_ATTACH:
        MessageBoxA(0, "thread atach", "mensaje", 0);
        break;

      case DLL_THREAD_DETACH:
        MessageBoxA(0, "thread detach", "mensaje", 0);
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}
