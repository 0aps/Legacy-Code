/*
  Copyright: InExInferis Inc.
  URL: http://www.inexinferis.co.nr
  Author: Karman
  Date: 26/10/05 13:27
*/

/******************* Classhook.c  **********************/
#include <windows.h>
#include <stdlib.h>
#include "Classhook.h"

//Variables Globales...
HHOOK DLKGlobalHook;			  //Global Hook Handle 
HINSTANCE g_hinstDll = NULL;	//Current Instance...

BOOL ShowClassName(HWND hWnd){
	CHAR szClassName[MAX_PATH];int nRet;
	
  nRet=GetClassName(hWnd, szClassName, MAX_PATH);
  if(nRet==0){ 
    //Maybe a long class name, just let it go
    MessageBox(NULL,"Error: Class Name So Long...","DLK .(", MB_OK);
    return FALSE; 
  }
	szClassName[nRet] = 0;
	
	//Unnamed Window Class
	if(szClassName[0]!='#')
	//Standart Windows Classes...
	if(lstrcmp(szClassName,"Button")&&lstrcmp(szClassName,"Static")&&lstrcmp(szClassName,"Edit")&&lstrcmp(szClassName,"ScrollBar"))
	if(lstrcmp(szClassName,"msctls_hotkey32")&&lstrcmp(szClassName,"msctls_progress32")&&lstrcmp(szClassName,"msctls_statusbar32"))
	if(lstrcmp(szClassName,"ToolbarWindow32")&&lstrcmp(szClassName,"tooltips_class32")&&lstrcmp(szClassName,"msctls_trackbar32"))
	if(lstrcmp(szClassName,"msctls_updown32")&&lstrcmp(szClassName,"SysAnimate32")&&lstrcmp(szClassName,"SysDateTimePick32"))
	if(lstrcmp(szClassName,"SysMonthCal32")&&lstrcmp(szClassName,"ReBarWindow32")&&lstrcmp(szClassName,"ComboBoxEx32"))
	if(lstrcmp(szClassName,"SysIPAddress32")&&lstrcmp(szClassName,"SysListView32")&&lstrcmp(szClassName,"SysTabControl32"))
	if(lstrcmp(szClassName,"SysTreeView32")&&lstrcmp(szClassName,"SysHeader32")&&lstrcmp(szClassName,"SysPager"))
	if(lstrcmp(szClassName,"NativeFontCtl")&&lstrcmp(szClassName,"ListBox")&&lstrcmp(szClassName,"ComboBox"))
	  MessageBox(NULL,szClassName, "DLK .)", MB_OK);
	
	return TRUE;
}
		
//cualquier ventana cae...
LRESULT CALLBACK CBTProc(int nCode,WPARAM wParam,LPARAM lParam){
  
	HWND actualwnd;
	if(nCode < 0)return CallNextHookEx(DLKGlobalHook, nCode, wParam, lParam);
	
  actualwnd=(HWND)wParam;
  if(nCode==HCBT_CREATEWND)ShowClassName(actualwnd);

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

/******************* Classhook.c  **********************/
