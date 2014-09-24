//#define WINVER 0x0501            //<----esto es importante para que funcione para NT
//#define _WIN32_WINNT 0x0501 


#include <windows.h>
#include <Tlhelp32.h>
#include <stdio.h>

#define ID_LIST 1

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

char szClassName[ ] = "DrinkDump";
HWND miid;

void Opciones(HWND list)
{
	HANDLE CProc;
    PROCESSENTRY32 Proceso;
    
	int total;
 
	total = 0;
 
	CProc = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	Process32First(CProc,&Proceso);
 
	while(Process32Next(CProc,&Proceso))
	{
		 SendMessage(list, CB_ADDSTRING, 0,(LPARAM)Proceso.szExeFile);

		 total++;
	}
 
	CloseHandle(CProc);            
}
int Dumpear(char * nombreproc,char * noffsets)
{
    HANDLE CProc,idproc;
    PROCESSENTRY32 Proceso;
    char buffer[1000];
	char bl[5];
    int dir=1; 

	CProc = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	Process32First(CProc,&Proceso);
 
	while(Process32Next(CProc,&Proceso))
	{
		 if(lstrcmp(nombreproc,Proceso.szExeFile)==0)
		 {
			 break;
		 }
	}
 
	CloseHandle(CProc); 

	idproc = OpenProcess(PROCESS_ALL_ACCESS,false,Proceso.th32ProcessID);
    
	
	// aqui se dumpea el proceso
	return 0;
}
int WINAPI WinMain (HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nFunsterStil)
{
    HWND hwnd;              
    MSG messages;            
    WNDCLASSEX wincl;
 

	wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;     
    wincl.style = CS_DBLCLKS;                 
    wincl.cbSize = sizeof (WNDCLASSEX);

	wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 
    wincl.cbClsExtra = 0;                     
    wincl.cbWndExtra = 0;                     
    
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
 
    
    if (!RegisterClassEx (&wincl))
        return 0;
 
    hwnd = CreateWindowEx (
           0,               
           szClassName,         
           "Drink Dump v1.0 Beta",      
           WS_SYSMENU,
           CW_USEDEFAULT,       
           CW_USEDEFAULT,       
           300,                 
           150,                 
           HWND_DESKTOP,        
           NULL,                
           hThisInstance,       
           NULL                 
           );
 
	miid = hwnd;

    ShowWindow (hwnd, SW_SHOWDEFAULT);
	//AnimateWindow(hwnd, 300, AW_SLIDE |AW_VER_POSITIVE);

    while (GetMessage (&messages, NULL, 0, 0))
    {  
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
 
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hwndList,hwndboton,hwndlabel1,hwndlabel2,hwndtext,hwndboton2;
    int iIndex, iLength, cxChar, cyChar;
    char nombre[260];
    char numero[30];

	switch (message)                 
    {
    	case WM_CTLCOLORSTATIC:
		{   
            HDC hdcStatic = (HDC) wParam;

            SetBkColor(hdcStatic,RGB(211,208,201));
            return (INT_PTR)CreateSolidBrush(RGB(211,208,201));
		}
	    case WM_CREATE:
		{
            cxChar = LOWORD(GetDialogBaseUnits());
            cyChar = HIWORD(GetDialogBaseUnits());

			hwndlabel1 = CreateWindowEx(0,"static", "Selecciona el proceso a Dumpear:", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 10, 10, 230, 20, hwnd, 0, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
			hwndlabel2 = CreateWindowEx(0,"static", "Número de offsets a dumpear:", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 10, 60, 230, 20, hwnd, 0, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
			hwndList =  CreateWindow(TEXT("Combobox"), NULL, WS_CHILD | WS_VISIBLE |LBS_STANDARD, 10, 30, 200,60, hwnd, (HMENU)ID_LIST, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),NULL);
            hwndboton = CreateWindowEx(0,"BUTTON", "Refrescar", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 215, 30, 70, 20, hwnd, 0, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
			hwndtext = CreateWindowEx(0,"Edit", "", WS_CHILD|WS_VISIBLE|WS_BORDER, 215, 60, 70, 20, hwnd, 0, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
			hwndboton2 = CreateWindowEx(0,"BUTTON", "Dumpear!", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 10, 85, 275, 20, hwnd, 0, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
			
			Opciones(hwndList);
             
            return 0;
		}  
        case WM_COMMAND:
		{
			 if((HWND)lParam==hwndboton)
			 {
                 Opciones(hwndList);
				 MessageBoxA(miid,"Se a refrescado la lista de procesos","Drink Dump v1.0",MB_OK);
			 }
             if((HWND)lParam==hwndboton2)
			 {
                 GetWindowText(hwndtext,numero,10);
				 GetWindowText(hwndList,nombre,260);
                 Dumpear(nombre,numero);
			 }

             break;
		}
        case WM_DESTROY:
		{
			PostQuitMessage (0);       
            break;
		}
        default:                    
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
 
    return 0;
}
