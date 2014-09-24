#include <windows.h>
#include <stdio.h>
 
HHOOK hHook;
MSG messages;
 
LRESULT CALLBACK hook_teclado(int nCode, WPARAM wParam, LPARAM lParam);
 
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)hook_teclado, hThisInstance, NULL);
 
    while(GetMessage(&messages, NULL, NULL, NULL)){
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
 
    return messages.wParam;
    
}
 
LRESULT CALLBACK hook_teclado(int nCode, WPARAM wParam, LPARAM lParam){
    if(nCode < 0)
        return CallNextHookEx(hHook, nCode, wParam, lParam);
 
    if(wParam == WM_KEYDOWN){
        PKBDLLHOOKSTRUCT teclado = (PKBDLLHOOKSTRUCT)lParam;
        teclado->vkCode = VK_SPACE;
        printf("%c", teclado->vkCode);
        
        free(teclado);
    }
 
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}
