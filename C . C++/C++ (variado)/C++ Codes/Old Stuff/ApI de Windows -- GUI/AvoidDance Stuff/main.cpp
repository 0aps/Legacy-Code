#include <windows.h>
 
#define SYSTR WM_USER+1
 
 
char *teclas[]=
{
    "",//0
    "click izquierdo",
    "click derecho",
    "",
    "click central",
    "",//5
    "",
    "",
    "retroceso",
    "tab",
    "",//10
    "",
    "clear",
    "enter",
    "",
    "",//15
    "shift",
    "control",
    "alt",
    "pausa",
    "mayus",//20
    "",
    "",
    "",
    "",
    "",//25
    "",
    "escape",
    "",
    "",
    "",//30
    "",
    "espacio",
    "pagina ant",
    "pagina sig",//??
    "fin",//35
    "inicio",
    "izquierda",
    "arriba",
    "derecha",
    "abajo",//40
    "",
    "imprimir",
    "",
    "",
    "insertar",//45
    "suprimir",
    "ayuda",
    "0",
    "1",
    "2",//50
    "3",
    "4",
    "5",
    "6",
    "7",//55
    "8",
    "9",
    "",
    "",
    "",//60
    "",
    "",
    "",
    "",
    "A",//65
    "B",
    "C",
    "D",
    "E",
    "F",//70
    "G",
    "H",
    "I",
    "J",
    "K",//75
    "L",
    "M",
    "N",
    "O",
    "P",//80
    "Q",
    "R",
    "S",
    "T",
    "U",//85
    "V",
    "W",
    "X",
    "Y",
    "Z",//90
    "windows",
    "",
    "propiedades",
    "",
    "",//95
    "numpad_0",
    "numpad_1",
    "numpad_2",
    "numpad_3",
    "numpad_4",//100
    "numpad_5",
    "numpad_6",
    "numpad_7",
    "numpad_8",
    "numpad_9",//105
    "*",
    "+",
    "",
    "-",
    "",//110
    "/",
    "F1",
    "F2",
    "F3",
    "F4",//115
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",//120
    "F10",
    "F11",
    "F12",
    "",
    "",//125
    "",
    "",
    "",
    "",
    "",//130
    "",
    "",
    "",
    "",
    "",//135
    "",
    "",
    "",
    "",
    "",//140
    "",
    "",
    "",
    "num bloq",
    ""
};
 
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI hilo2(void*);
 
/*  Make the class name into a global variable  */
char szClassName[ ] = "CTecla2";
 
NOTIFYICONDATA nid;
HINSTANCE miinstance;
int modo;
short teclaa=0, teclab=0;
HANDLE hThread;
bool end=false;
bool cambiando=false;
 
/*#define INPUT_KEYBOARD 0x00000001
typedef struct tagKEYBDINPUT {
  WORD wVk;
  WORD wScan;
  DWORD dwFlags;
  DWORD time;
  ULONG_PTR dwExtraInfo;
} KEYBDINPUT,*PKEYBDINPUT;
typedef struct tagINPUT {
  DWORD type;
  _ANONYMOUS_UNION union {
		//MOUSEINPUT mi;
		KEYBDINPUT ki;
		//HARDWAREINPUT hi;
  } DUMMYUNIONNAME;
} INPUT,*PINPUT,*LPINPUT;
 
INPUT input;*/
 
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    HICON hIcono;
    modo=nCmdShow;
    miinstance=hThisInstance;
 
    //input.type=INPUT_KEYBOARD;
 
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);
 
    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (hThisInstance, "ICONO");
    wincl.hIconSm = LoadIcon (hThisInstance, "ICONO");
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_WINDOW;
    //CreateSolidBrush(RGB(0,0,0));
 
    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;
 
    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "CTecla2 --- By Avoidance25",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           GetSystemMetrics(SM_CXSCREEN)-215,       /* Windows decides the position */
           GetSystemMetrics(SM_CYSCREEN)-110,       /* where the window ends up on the screen */
           215,                 /* The programs width */
           80,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
 
    /* Make the window visible on the screen */
    hIcono = LoadIcon(hThisInstance, "ICONO");
 
	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hIcon = hIcono;
	nid.hWnd = hwnd;
	nid.uCallbackMessage = SYSTR;
	nid.uFlags = NIF_ICON|NIF_TIP|NIF_MESSAGE;
	lstrcpy(nid.szTip, "CTecla2 --- Hecho por Avoidance25");
	nid.uID = 0;
	Shell_NotifyIcon(NIM_ADD, &nid);
 
	DWORD  dwThreadID;
    hThread=CreateThread(NULL,0,hilo2,NULL,0,&dwThreadID);
 
    ShowWindow (hwnd, nCmdShow);
 
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }
 
    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}
 
 
/*  This function is called by the Windows function DispatchMessage()  */
 
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int cual=0;
    static int estado=modo;
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            static HFONT hFont = CreateFont(14, 0, 0, 0, 100, 0, 0, 0,0, 0, 0, 0, VARIABLE_PITCH | FF_SWISS, "Helv");
            static HWND hwndStatic1 = CreateWindowEx(0,"STATIC", "  ---->", WS_CHILD|WS_VISIBLE, 85, 15, 30, 15, hwnd, 0, miinstance, NULL);
            static HWND hwndEdit1 = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT", "Tecla 1", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 10, 15, 75, 15, hwnd, 0, miinstance, NULL);
            static HWND hwndEdit2 = CreateWindowEx(WS_EX_CLIENTEDGE,"EDIT", "Tecla 2", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 115, 15, 75, 15, hwnd, 0, miinstance, NULL);
            SendMessage(hwndStatic1, WM_SETFONT, (WPARAM) hFont, true);
            SendMessage(hwndEdit1, WM_SETFONT, (WPARAM) hFont, true);
            SendMessage(hwndEdit2, WM_SETFONT, (WPARAM) hFont, true);
            SendMessage(hwndEdit1, WM_ENABLE, (WPARAM) false, true);
            SendMessage(hwndEdit2, WM_ENABLE, (WPARAM) false, true);
            break;
        case WM_SYSCOMMAND:
            switch(wParam)
            {
                case SC_MINIMIZE:
                    estado=SW_HIDE;
                    ShowWindow (hwnd, SW_HIDE);
                    return 0;
                    break;
                case SC_MAXIMIZE:
                    return 0;
            }
            break;
        case SYSTR:
            switch(lParam)
            {
                case WM_LBUTTONDOWN:
                    if(estado==modo)
                    {
                        estado=SW_HIDE;
                        ShowWindow (hwnd, estado);
                    }
                    else
                    {
                        estado=modo;
                        ShowWindow (hwnd, estado);
                        SetForegroundWindow(hwnd);
                    }
                    break;
            }
            break;
        case WM_COMMAND:
            if((HWND)lParam==hwndEdit1)
            {
                cual=1;
                cambiando=true;
                SendMessage(hwndEdit1, WM_ENABLE, (WPARAM) true, true);
                SendMessage(hwndEdit2, WM_ENABLE, (WPARAM) false, true);
                SetFocus(hwnd);
            }
            else if((HWND)lParam==hwndEdit2)
            {
                cual=2;
                cambiando=true;
                SendMessage(hwndEdit2, WM_ENABLE, (WPARAM) true, true);
                SendMessage(hwndEdit1, WM_ENABLE, (WPARAM) false, true);
                SetFocus(hwnd);
            }
            break;
        case WM_KEYDOWN:
            if(cual==1)
            {
                if(wParam==(UINT)teclab) break;
                SendMessage(hwndEdit1, WM_SETTEXT, false, (long int) teclas[wParam]);
                SendMessage(hwndEdit1, WM_ENABLE, (WPARAM) false, true);
                teclaa=wParam;
            }
            else if(cual==2)
            {
                if(wParam==(UINT)teclaa) break;
                SendMessage(hwndEdit2, WM_SETTEXT, false, (long int) teclas[wParam]);
                SendMessage(hwndEdit2, WM_ENABLE, (WPARAM) false, true);
                teclab=wParam;
            }
            cual=0;
            cambiando=false;
            break;
        case WM_DESTROY:
            end=true;
            Shell_NotifyIcon(NIM_DELETE, &nid);
            WaitForSingleObject(hThread,750);
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
 
    return DefWindowProc (hwnd, message, wParam, lParam);
}
 
DWORD WINAPI hilo2(void*)
{
 
    while((teclaa==0 || teclab==0) && !end) Sleep(25);
    while(!end)
    {
        while(cambiando)Sleep(25);
 
        if(GetAsyncKeyState(teclaa)/*==-32767*/)
        {
            keybd_event(teclab,MapVirtualKey(teclab,0),0,0);
            keybd_event(teclab,MapVirtualKey(teclab,0),KEYEVENTF_KEYUP,0);
            Sleep(80);
            GetAsyncKeyState(teclaa);
            GetAsyncKeyState(teclab);
            //keybd_event(teclab,0xb8,KEYEVENTF_KEYUP,0);
        }
        Sleep(20);
    }
    return 0;
}
 
