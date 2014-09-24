#include <windows.h>
#define  MIICONO ICON "icono.ico"

// Menu #Archivo
const int MN_NEW=1026;
const int MN_ABRIR=1027;
const int MN_SALIR=1028;

// Menu #Editar
const int MN_PEGAR=1030;
const int MN_COPIAR=1031;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";
HINSTANCE txt;

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    txt=hThisInstance;
    
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (txt, "MIICONO");
    wincl.hIconSm = LoadIcon (txt, "MIICONO");
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH)COLOR_WINDOW+1;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Primer Programa",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

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
    static char texto[256];
    switch (message)                  /* handle the messages */
    { 
               case WM_CREATE:
            HMENU menu1 = CreateMenu();
            HMENU menu2 = CreateMenu();
            HMENU menu3 = CreateMenu();
            AppendMenu(menu2, MF_STRING | MF_POPUP, (UINT)menu3, "&Abrir");
            
            AppendMenu(menu3, MF_STRING, MN_NEW, "&Nuevo");
            AppendMenu(menu2, MF_SEPARATOR, 0, NULL);
            AppendMenu(menu2, MF_STRING, MN_SALIR, "&Salir");
            
            AppendMenu(menu1, MF_STRING | MF_POPUP, (UINT)menu2, "&Archivo");
            AppendMenu(menu3, MF_STRING, MN_PEGAR, "&Pegar");
            AppendMenu(menu3, MF_STRING, MN_COPIAR, "&Copiar");
            SetMenu (hwnd, menu1);
            
        
            static HWND hwndButton1 = CreateWindowEx(0,"BUTTON", "Comentario", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 60, 160, 100, 20, hwnd, 0, txt, NULL);
            static HWND hwndEdit1 = CreateWindowEx(0,"Edit", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 0, 200, 300, 100, hwnd, 0, txt, NULL);
          
            break;
            case WM_COMMAND:
                if((HWND)lParam==hwndButton1)
                {
                    GetWindowText(hwndEdit1, texto, 256);
                    MessageBox(NULL, texto, "0", MB_OK | MB_ICONEXCLAMATION);
                    SendMessage(hwndEdit1, WM_SETTEXT, false, (long int) "");
            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

