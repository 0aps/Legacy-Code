#include <windows.h>
 
#define ID_5SEGUNDOS 101
 
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
 
/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";
 
void procesar();
 
HINSTANCE instancia;
 
UINT TimerID = 0;
 
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)
 
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
 
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);
 
    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(0,200,0));
 
    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;
 
    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Hwnd-Class Finder   bY: SEKTOR",       /* Title Text */
           WS_SYSMENU, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           90,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
 
    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);
 
   /* establece el timer  */
   TimerID = SetTimer( hwnd , ID_5SEGUNDOS , 250 , NULL);
 
 
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
    switch (message)                  /* handle the messages */
    {
           
           case WM_CREATE:
static HFONT fuente = CreateFont(18, 0, 0, 0, 100, 0, 0, 0,0, 0, 0, 0,
 VARIABLE_PITCH | FF_SWISS, "Helv");
static HWND title = CreateWindowEx(0,"static", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP,
 5, 10, 50, 18, hwnd, 0, instancia, NULL);
static HWND clas = CreateWindowEx(0,"static", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP,
 5, 30, 50, 18, hwnd, 0,instancia, NULL);
static HWND edit1 = CreateWindowEx(0,"static", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP,
 60, 10, 470, 18, hwnd, 0, instancia, NULL);
static  HWND edit2 = CreateWindowEx(0,"static", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP,
 60, 30, 470, 18, hwnd, 0,instancia, NULL);
 
   SendMessage(edit1, WM_SETFONT, (WPARAM) fuente, true);
   SendMessage(edit2, WM_SETFONT, (WPARAM) fuente, true);
                     
                break;
 
  case WM_TIMER: // SE DISPARA EL MENSAJE TRAS CUMPLIRSE EL TIEMPO
               
    HWND hwnd2;  // el manejador de la ventana a trabajar
    POINT pt;          // Puntero para las cordenadas
    char titulo[100],clase[100];    // nuestros arrays para los nombres
    GetCursorPos(&pt);                 // La funcion que dara las cordenadas
    hwnd2 = WindowFromPoint(pt);     // la funcion que extraera el manejador de la ventana
    GetWindowText(hwnd2,titulo,100);    // La funcion que obtendra el nombre
    GetClassNameA(hwnd2,clase,100);   //La funcion que extraera la class
    SetWindowText(title,"Caption");      
    SetWindowText(clas,"Class");      
    SetWindowText(edit1,titulo);       // Mostramos el nombre
    SetWindowText(edit2,clase);      // Mostramos el nombre
                        break ;
 
 
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
 
    return 0;
}
