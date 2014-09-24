#include <windows.h>
#include <stdio.h>
#include <Tlhelp32.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

void Buscar_Dll   (HWND);
void CrearVentana (HWND);
int Inyectar      ();
int Buscar_Proceso();
int Existe_A      (char *);

/*  Make the class name into a global variable  */
char szClassName [   ]   = "WindowsApp";
char ruta_dll    [256];
char n_Proceso   [100];
char mensaje     [256];

HANDLE CProc;              //Para crear la captura de la lista de procesos
HANDLE hProceso;           //Para guardar el manejador del proceso
PROCESSENTRY32 Proceso;    //Necesario para realizar la captura de procesos

HWND   Button1, Button2, Button3, Edit1, Edit2, ComboBox, Static1, Static2;
HINSTANCE instancia;      

HBRUSH hbrBackground = CreateSolidBrush(RGB(258, 205, 255));

HANDLE  hProc;
DWORD   pid;
LPVOID  dDll;
LPVOID  dLoadLibrary;


int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;                   /* This is the handle for our window          */
    MSG messages;               /* Here messages to the application are saved */
    WNDCLASSEX wincl;          /* Data structure for the windowclass         */
    instancia = hThisInstance;
    
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                /* Catch double-clicks                 */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(258, 205, 255));
    
    
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
                          CrearVentana(hwnd);
                          break;
          
          
          case WM_COMMAND:
            
            //buscar dll
            if( (HWND)lParam == Button1)
            {
                       Buscar_Dll(hwnd);                       
            }
            
            //edit d la ruta
            if( (HWND)lParam == Edit1  )
            {
                 GetWindowText(Edit1, ruta_dll, 255); 
            }
            
            //edit del proceso
            if( (HWND)lParam  == Edit2)
            {
                 GetWindowText(Edit2, n_Proceso, 255);          
            } 
            
            //buscar proceso
            if( (HWND)lParam == Button2 )
            {
                 ( Buscar_Proceso() == 0 )  ?          
                 
                 MessageBox(0, "El proceso esta corriendo", "Proceso", 0)    :        
                 MessageBox(0, "El proceso no esta corriendo", "Proceso", 0) ;             
            }  
            
            //inyectar 
            if( (HWND)lParam == Button3 )
            {
                  
                switch( Inyectar() )
                {
                                case  0: 
                                case -1:
                                case -2:
                                case -3:                     
                                case -4:
                                case -5:
                                SendMessage(ComboBox, WM_SETTEXT, 0, (LPARAM)mensaje);
                                break;
    
                }
                   
            }
        
            break; 
        
        //mensaje para cambiarle el fondo al static
        case WM_CTLCOLORSTATIC:
        {
           SetBkMode((HDC)wParam, TRANSPARENT);
           //// SetTextColor((HDC)wParam, RGB(0,0,0) ) ;
           return (LONG)hbrBackground;
        }
         
        case WM_DESTROY:

            CloseHandle(hProc); 
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */

            break;
 
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void CrearVentana(HWND hwnd)
{
     
//Static // ruta
Static1 = CreateWindowEx(0,"STATIC", "Ruta:", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 
                         10, 10, 45, 20, hwnd, 0, instancia, NULL);
                         
//Static2 // proceso
Static2 = CreateWindowEx(0,"STATIC", "Proceso:", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 
                         10, 50, 65, 20, hwnd, 0, instancia, NULL);
                         
//Edit // ruta
Edit1   = CreateWindowEx(0,"EDIT", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP|WS_BORDER|ES_AUTOHSCROLL, 
                         70, 10, 400, 20, hwnd, 0, instancia, NULL);
                         
//Edit2 // proceso
Edit2   = CreateWindowEx(0,"EDIT", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP|WS_BORDER|ES_AUTOHSCROLL, 
                         85, 50, 100, 20, hwnd, 0, instancia, NULL);
//ComboBox        
ComboBox   = CreateWindowEx(0,"EDIT", "", 
                            WS_CHILD|WS_VISIBLE | WS_VSCROLL | ES_MULTILINE |WS_BORDER,
                            85, 130, 350, 100, hwnd, 0, instancia, NULL);
                         
                         

//Boton
Button1 = CreateWindowEx(0,"BUTTON", "Buscar", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 
                         80, 300, 100, 20, hwnd, 0, instancia, NULL);
//Boton 2
Button2 = CreateWindowEx(0,"BUTTON", "Verificar Proceso", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 
                         200, 300, 120, 20, hwnd, 0, instancia, NULL);
           
//Boton 3
Button3 = CreateWindowEx(0,"BUTTON", "Inyectar", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 
                         330, 300, 100, 20, hwnd, 0, instancia, NULL);
     
}

void Buscar_Dll(HWND hwnd)
{
        OPENFILENAME  ofn;

        ZeroMemory(&ofn, sizeof(ofn));
                
        ofn.lStructSize     =  sizeof(ofn);
        ofn.hwndOwner       =  hwnd;
        ofn.lpstrFile       =  ruta_dll;
        *ofn.lpstrFile      =  0;
        ofn.nMaxFile        =  MAX_PATH;
        ofn.lpstrFilter     =  "Archivos Dll\0*.dll\0Archivos de texto\0*.TXT\0Todos los archios\0*.*\0";
        ofn.nFilterIndex    =  1;
        ofn.lpstrInitialDir =  "%homepath%";
        ofn.Flags           =  OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

                GetOpenFileName(&ofn) ?
                SendMessage(Edit1, WM_SETTEXT, false, (long int) ofn.lpstrFile): 
                SendMessage(Edit1, WM_SETTEXT, false, (long int) "Error al obtener el archivo");
}
            
int Buscar_Proceso()
{
   
    //Con esto creamos una captura de la lista de procesos y la guardamos en CProc
    CProc          =   CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);   
	
    Proceso.dwSize =   sizeof(PROCESSENTRY32);
    
    Process32First(CProc,&Proceso);    //Leemos el primer proceso

    //Mientras haya procesos para leer leemos el siguiente
	while(Process32Next(CProc,&Proceso))   
	{
                                           
	  if(!strcmp(Proceso.szExeFile, n_Proceso) )
         {
           pid = Proceso.th32ProcessID;
                
	       return 0;
         }
    }
    
    pid    = 0; 
    return   1;
}

int Inyectar()
{
          if( (hProc = OpenProcess(PROCESS_ALL_ACCESS, false, pid) ) == NULL)
                {    
                strcpy(mensaje,
                "No se pudo abrir el proceso ya sea porque no se esta ejecutando o poque no se verifico"); 
               
                 return -1;                  
                }
                
          if(  (dLoadLibrary = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"),
                                                      "LoadLibraryA") ) == NULL )
                {
                strcpy(mensaje,
                       "Error al encontrar la direccion de LoadLibrary"); 
               
                return -2;
                }
                
          if(  (Existe_A(ruta_dll)) == 1 )
               {
                       strcpy(mensaje,
                              "Verifique la ruta de la DLL"); 
                
                       return -3;
                }
                
          if(  (dDll = (LPVOID)VirtualAllocEx(hProc,0,strlen(ruta_dll),
                                 MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE) ) == NULL )
               {
                strcpy(mensaje,
                       "Error al reservar memoria en el proceso remoto"); 
                
                return -4;
                }
                
           if(  ( WriteProcessMemory(hProc,(LPVOID)dDll,ruta_dll,
                  strlen(ruta_dll),NULL) ) == 0 )

               {
                strcpy(mensaje,
                       "Error al escribir en el proceso remoto"); 
                     
                return -5;
               }
               
           if( (CreateRemoteThread(hProc, NULL ,0,(LPTHREAD_START_ROUTINE)dLoadLibrary,
                  (LPVOID)dDll , 0 , 0) ) == NULL )
               {
                strcpy(mensaje,
                       "Error al crear el hilo remoto"); 
               
                 return -6;
               }   

strcpy(mensaje,  "Se inyecto la dll en el proceso!");
return 0;

}

int Existe_A(char *ruta)
{
    FILE *arc = fopen(ruta, "r");
 
    if(!arc)
    {
        return 1;
    }
    
    fclose(arc);
    return 0;
}
   
