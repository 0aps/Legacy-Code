/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>

INPUT Input;
Input.type = INPUT_MOUSE;
Input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
Input.mi.dx = X * (65535.0f / (GetSystemMetrics(SM_CXSCREEN) -1));
Input.mi.dy = Y * (65535.0f / (GetSystemMetrics(SM_CYSCREEN) -1));
SendInput(true, &Input, sizeof(Input));



BOOL APIENTRY DllMain (HINSTANCE hInst     /* Library instance handle. */ ,
                       DWORD reason        /* Reason this function is being called. */ ,
                       LPVOID reserved     /* Not used. */ )
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
        break;

    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}
