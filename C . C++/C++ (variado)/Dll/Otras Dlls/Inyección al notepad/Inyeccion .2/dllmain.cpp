/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>

void Inyeccion();
void Bucle();


BOOL APIENTRY DllMain (HINSTANCE hInst     /* Library instance handle. */ ,
                       DWORD reason        /* Reason this function is being called. */ ,
                       LPVOID reserved     /* Not used. */ )
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Bucle, 0, 0, 0);
        break;

      case DLL_PROCESS_DETACH:
        break;

      case DLL_THREAD_ATTACH:
        break;

      case DLL_THREAD_DETACH:
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}

void Inyeccion()
{
    if(GetAsyncKeyState(VK_INSERT)&1)
    {
        keybd_event(0x41, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x4E, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x47, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x45, 0, KEYEVENTF_EXTENDEDKEY,0); 
        keybd_event(0x4C, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_EXTENDEDKEY,0); 
        keybd_event(VK_SPACE, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x57, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x41, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x53, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x48, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x45, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x52, 0, KEYEVENTF_EXTENDEDKEY,0);
        keybd_event(0x45, 0, KEYEVENTF_EXTENDEDKEY,0);
    }
    if(GetAsyncKeyState(VK_NUMPAD1)&1)
    {
    ExitProcess(NULL);
    }
}

void Bucle()
{
    while(1)
    {
        Inyeccion();
    }
}

    
    


