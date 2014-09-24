#include <windows.h>

const int MN_ARCHIVO = 1026;
const int MN_NUEVO = 1027;
const int MN_ABRIR = 1028;
const int MN_SALIR = 1029;

const int MN_EDITAR = 1030;
const int MN_COPIAR  = 1031;
const int MN_PEGAR = 1032;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";
HINSTANCE miinstance;

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    miinstance=hThisInstance;
    HICON hIcono;
    
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (miinstance, "ICONO");
    wincl.hIconSm = LoadIcon (miinstance, "ICONO");
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0,0,0));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "1er Programa",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           600,                 /* The programs width */
           400,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);
    
    /* Make the window visible on the screen */
    hIcono = LoadIcon(hThisInstance, "ICONO");

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
                
            static HWND hwndStatic2= CreateWindowEx(0,"STATIC","APS",WS_CHILD | WS_VISIBLE | WS_TABSTOP | SS_BITMAP,
            0, 100, 0, 0, hwnd,  NULL, miinstance, NULL);
            static HWND hwndButton1 = CreateWindowEx(0,"BUTTON", "Aceptar", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 25, 0, 500, 30, hwnd, 0, miinstance, NULL);
            static HWND hwndEdit1 = CreateWindowEx(0,"Edit", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 0, 68, 593, 60, hwnd, 0, miinstance, NULL);
                
                HMENU menu1 = CreateMenu ();
                HMENU menu2 = CreateMenu ();
                HMENU menu3 = CreateMenu ();
                HMENU menu4 = CreateMenu ();
            AppendMenu(menu1, MF_STRING | MF_POPUP, (UINT)menu2, "&Archivo");
            AppendMenu(menu2, MF_STRING, MN_NUEVO, "&Nuevo");
            AppendMenu(menu2, MF_STRING, MN_ABRIR, "&Abrir");
            AppendMenu(menu2, MF_SEPARATOR, 0, 0);
            AppendMenu(menu2, MF_STRING, MN_SALIR, "&Salir");
            AppendMenu(menu3, MF_STRING | MF_POPUP, (UINT)menu4, "&Editar");
            AppendMenu(menu4, MF_STRING, MN_COPIAR, "&Copiar");
            AppendMenu(menu4, MF_STRING, MN_PEGAR, "&Pegar");
            SetMenu(hwnd, menu3);
            SetMenu(hwnd, menu1);
          
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
