#include <windows.h>
 
 
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
 
/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";
 
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
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
 
    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;
 
    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           WS_EX_TOOLWINDOW,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "USB-DETECTOR",       /* Title Text */
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
    ShowWindow (hwnd,/* nFunsterStil*/SW_HIDE);
 
    /* Coded by SEKTOR From CPH */  
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
 
      char token[][10] =
    {"C:/","D:/","E:/" ,"F:/","G:/" ,
    "H:/","I:/","J:/","K:/","L:/","M:/",
    "N:/","Ñ:/","O:/","P:/","Q:/","R:/","S:/",
    "T:/","U:/","V:/","W:/","X:/","Y:/","Z:/"};
    int count=0,tipo=0; 
 
    switch (message)                  /* handle the messages */
    {
 
              case WM_DEVICECHANGE:
 
                 while ( GetDriveType(token[count])!=tipo){  
 
                 if(  GetDriveType(token[count])==2){                      
                token[count];                  /* 2 es el numero de las unidades removibles*/
                }     
                count++;  
                tipo++;   
                }
                                         /* detecta cuando se inserta una unidad removible */
                if ( wParam==0x8000 || GetDriveType(token[count])==2 )
                MessageBox(hwnd,token[count], "Aviso: Se conecto una unidad USB en la etiqueta:", 
                MB_OK | MB_ICONWARNING );
 
                                      /* detecta cuando se retira una unidad removible */
                else if ( wParam==0x8004 || GetDriveType(token[count])==2)
 
                MessageBox(hwnd,token[count], "Aviso: Se retiro una unidad USB en la etiqueta:", 
                MB_OK | MB_ICONWARNING );
                break;
 
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
 
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
 
    return 0;
}
 
