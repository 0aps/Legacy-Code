#include <windows.h>
#include <Tlhelp32.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

void Crear_Ventana(HWND hwnd);
void inyectar();

HINSTANCE instancia;
DWORD pid; 
HANDLE proc;

char buf[MAX_PATH]="";
char laDll[]="C:\\Documents and Settings\\Owner\\Desktop\\Programming\\C . C++\\C++ (variado)\\Dll\\Project1.dll";

LPVOID RemoteString;
LPVOID nLoadLibrary;
HWND Button2;

    
    int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    instancia = hThisInstance;    
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
   // wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
   // wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Windows App",       /* Title Text */
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
    while ( GetMessage (&messages, NULL, 0, 0) == 1)
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
           Crear_Ventana(hwnd);
           break;
          
            case WM_COMMAND:
                 
            if((HWND)lParam == Button2 )
            {
            inyectar();
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

void Crear_Ventana(HWND hwnd)
{
     //Boton 2
Button2 = CreateWindowEx(0,"BUTTON", "Buscar P", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 
                         100, 300, 100, 20, hwnd, 0, instancia, NULL);
}

void inyectar()
{

pid=(DWORD)atoi("400");

proc = OpenProcess(PROCESS_ALL_ACCESS, false, pid);

if(proc == NULL)
MessageBox(0, "adf adsfads", "afgjka sd", 0);


     //Aquí usamos directamente GetModuleHandle en lugar de loadlibrary ya que
//kernel32 la cargan todos los ejecutables
//Con esto tenemos un puntero a LoadLibraryA
nLoadLibrary = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"),
               "LoadLibraryA");


//Reservamos memoria en el proceso abierto
RemoteString = (LPVOID)VirtualAllocEx(proc,0,strlen(laDll),
                MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);

//Escribimos la ruta de la dll en la memoria reservada del proceso remoto
WriteProcessMemory(proc,(LPVOID)RemoteString,laDll,strlen(laDll),NULL);

//Lanzamos el hilo remoto en loadlibrary pasandole la dirección de la cadena
CreateRemoteThread(proc,NULL,0,(LPTHREAD_START_ROUTINE)nLoadLibrary,
                  (LPVOID)RemoteString,0,0); 
}
