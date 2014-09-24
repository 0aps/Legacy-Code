#include <windows.h>

HANDLE ThreadHandle;
DWORD threadId = 0;

DWORD WINAPI my_thread(void *par);` 

BOOL APIENTRY DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        MessageBox(NULL,"Se ha inyectado la dll","CEvent",MB_OK);
        //ThreadHandle = CreateThread(0, 0x1000, &my_thread, 0, 0, &threadId);
        break;
        
    case DLL_PROCESS_DETACH:
        break;
        
    case DLL_THREAD_ATTACH:
        break;
        
    case DLL_THREAD_DETACH:
        break;
    }
    
    return TRUE;
}

DWORD WINAPI my_thread(void *par)
{
    while(true)
    {
        MessageBox(NULL,"Se ha inyectado la dll","CEvent",MB_OK);
        Sleep(1000);
    }
}

