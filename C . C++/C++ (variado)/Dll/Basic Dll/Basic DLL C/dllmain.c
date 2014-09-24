/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

DLLIMPORT void HelloWorld ()
{
    MessageBox (0, "Hello World from DLL!\n", "Hi", MB_ICONINFORMATION);
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
