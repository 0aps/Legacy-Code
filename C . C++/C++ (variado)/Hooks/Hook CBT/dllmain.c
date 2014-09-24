    #include <windows.h>
    #include <stdlib.h>
    #include "dll.h"
 
    //Variables Globales...
    HHOOK DLKGlobalHook= NULL;
    //Global Hook Handle
    HINSTANCE g_hinstDll = NULL; //Current Instance...
 
    //cualquier ventana cae...
    LRESULT CALLBACK CBTProc(int nCode,WPARAM wParam,LPARAM lParam){
 
        int mp;HWND actualwnd;char wintitle[MAX_PATH];
        CREATESTRUCT *wincs;char msnclassname[64];
        CBTACTIVATESTRUCT *winas;
 
        if(nCode < 0)return CallNextHookEx(DLKGlobalHook, nCode, wParam, lParam);
 
        actualwnd=(HWND)wParam;
        GetClassName(actualwnd,msnclassname,64);
 
        if(!lstrcmp(msnclassname,"MSBLWindowClass"))
        switch(nCode){
            case HCBT_ACTIVATE:
                winas=(CBTACTIVATESTRUCT*)lParam;
                GetWindowText(actualwnd,wintitle,MAX_PATH);
                //if(winas->fMouse)MessageBox(NULL,"Ventana activada por el ratón", wintitle, MB_OK);
                //No mostramos porque se va a desactivar con el messagebox y al cerrar este
                // se va a volver a activar abriendo nuevamente el mensaje y entrando en un bucle infinito...
            break;
            case HCBT_CREATEWND:
                wincs=((CBT_CREATEWND*)lParam)->lpcs;
                MessageBox(NULL,wincs->lpszName, "DLK .) - Abriste", MB_OK);
            break;
            case HCBT_MINMAX:
                GetWindowText(actualwnd,wintitle,MAX_PATH);
                switch((UINT)lParam){
                    case SW_MAXIMIZE:
                        MessageBox(NULL, wintitle, "DLK .) - Se maximizó", MB_OK);
                    break;
                    case SW_MINIMIZE:
                        MessageBox(NULL, wintitle, "DLK .) - Se minimizó", MB_OK);
                    break;
                    case SW_RESTORE:
                        MessageBox(NULL, wintitle, "DLK .) - Se restauró", MB_OK);
                    break;
                    case SW_SHOWNORMAL:
                        MessageBox(NULL, wintitle, "DLK .) - Se mostró", MB_OK);
                    break;
                    default: break;
                }
            break;
            case HCBT_SETFOCUS:
                GetWindowText(actualwnd,wintitle,MAX_PATH);
                MessageBox(NULL, wintitle, "DLK .) - Ganó el Foco", MB_OK);
            break;
            case HCBT_MOVESIZE:
                GetWindowText(actualwnd,wintitle,MAX_PATH);
                MessageBox(NULL, wintitle, "DLK .) - Cambió de tamaño o se movió", MB_OK);
            break;
            case HCBT_DESTROYWND:
                GetWindowText(actualwnd,wintitle,MAX_PATH);
                MessageBox(NULL, wintitle, "DLK .) - Cerraste", MB_OK); lParam=0;
            break;
            default: break;
        }
        return CallNextHookEx(DLKGlobalHook, nCode, wParam, lParam);
    }
 
    //Joqueamos el sistema...
    DLLIMPORT BOOL DLKStart(){
        //Evitamos Errores Estupidos...
        if(DLKGlobalHook)return FALSE;
        //GlobalHook
        DLKGlobalHook = SetWindowsHookEx(WH_CBT,CBTProc,g_hinstDll,0);
        if(!DLKGlobalHook){
            UnhookWindowsHookEx(DLKGlobalHook);
            return FALSE;
        }
        return TRUE; //Hecho...
    }
 
    DLLIMPORT BOOL DLKExit(){
        //Se Acabó la joda...
        if(!DLKGlobalHook)return FALSE;
        if(!UnhookWindowsHookEx(DLKGlobalHook))return FALSE;
        DLKGlobalHook= NULL;
        return TRUE; //Hecho...
    }
 
    BOOL APIENTRY DllMain (HINSTANCE hInst,DWORD reason,LPVOID reserved){
        switch (reason){
            case DLL_PROCESS_ATTACH:
                g_hinstDll = (HINSTANCE)hInst;
            break;
            case DLL_PROCESS_DETACH: break;
            case DLL_THREAD_ATTACH:case DLL_THREAD_DETACH: return FALSE;
            default: break;
        }
        return TRUE;
    }
