#include <windows.h>

#define MAX 100000        

/*
  Name: Visor de archivos
  Copyright: GPL
  Author: @aps
  Date: 13/01/12 12:29
  Description: visor de archivos 
*/



/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

void CrearVentana (HWND);
void Directorios  (HWND);

HWND Edit1, ComboBox, Static1;
HINSTANCE instancia;

HBRUSH hbrBackground = CreateSolidBrush(RGB(258, 205, 255));

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";
char path[MAX_PATH] = "C:\\";

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
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(258, 205, 255));
    
    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Visor de Archivos @aps",       /* Title Text */
           WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, /* default window */
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
    while (GetMessage (&messages, NULL, 0, 0) > 0)
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
             SetWindowText(Edit1, path);
             break;
              //mensaje para cambiarle el fondo al static
        
       case WM_COMMAND:
    
              //edit d la ruta
            if( (HWND)lParam == Edit1  )
            {
                 
                 GetWindowText(Edit1, path, MAX_PATH); 
                 Directorios(ComboBox);
            }
            
            break;        
    
       
        case WM_CTLCOLORSTATIC:
        {
           SetBkMode((HDC)wParam, TRANSPARENT);
           //// SetTextColor((HDC)wParam, RGB(0,0,0) ) ;
           return (LONG)hbrBackground;
        }
       
              
        case WM_DESTROY:
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
                         0, 5, 45, 20, hwnd, 0, instancia, NULL);

//Edit // ruta
Edit1   = CreateWindowEx(0,"EDIT", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP|WS_BORDER|ES_AUTOHSCROLL, 
                         40, 2, 470, 20, hwnd, 0, instancia, NULL);

 // ComboBox        
ComboBox   = CreateWindowEx(0,"EDIT", "", 
                            WS_CHILD|WS_VISIBLE | ES_MULTILINE | WS_VSCROLL ,
                            0, 35, 535, 307, hwnd, 0, instancia, NULL); 
}

void Directorios(HWND hwnd)
{
     
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    
    int x(0), d(0), a(0), z[MAX];
   
	char* dir = new char[MAX_PATH],* cadena = new char[MAX];
    char directorio[] = "[Directorio]", archivo[] = "[Archivo]";
    
    ZeroMemory(dir, MAX_PATH);
    ZeroMemory(cadena, MAX);
        
    strcat (dir,path);
    strcat (dir, "*"); //hace que se muestren los archivos
    
 
   //organizar 
   for(int o(0);  o < 2; o++)
{ 
    hFind = FindFirstFile(dir, &findFileData);
       
    if (hFind == INVALID_HANDLE_VALUE)
     SetWindowText(hwnd,"No se pudo leer el directorio.\n");      
   
   if(hFind)
 {
 
    do
      {
       
        if(o == 0) //directorios primero
       
        if(findFileData.dwFileAttributes  == FILE_ATTRIBUTE_DIRECTORY)
          {   
      
              strncpy(cadena, directorio, strlen(directorio) ) ;  //copio el subfijo directorio
              cadena += strlen(directorio);
              d++;      
              
              z[x] = strlen(findFileData.cFileName);   
              strncpy(cadena, findFileData.cFileName, z[x]) ;     //copio el nombre del directorio 
              cadena += z[x];
              
              *(WORD*)cadena = 0x0a0d; //salto de linea
               cadena+=2;
               x++;  
        
          }
        
        if(o == 1) //archivos después
        
        if(findFileData.dwFileAttributes == FILE_ATTRIBUTE_ARCHIVE)
          {
              strncpy(cadena, archivo, strlen(archivo) ) ;  //copio el subfijo archivo
              cadena += strlen(archivo);
              a++;
              
              z[x] = strlen(findFileData.cFileName);   
              strncpy(cadena, findFileData.cFileName, z[x]) ;     //copio el nombre del archivo 
              cadena += z[x];
              
              *(WORD*)cadena = 0x0a0d; //salto de linea
               cadena+=2;
               x++;  
          
          }
             
          
      }
          // Listamos todos los ficheros restantes
        while (FindNextFile( hFind, &findFileData) != 0);
      
 }
 
}
    z[x] = 0; //final de cadena
    for(int i = 0; i < x; i++) //sumo el largo de los directorios nombrados
    z[x] += z[i];

cadena -= (z[x]+ (x*2) + (strlen(directorio)*d) + (strlen(archivo)*a) ); //vuelvo al principio de cadena. Resto nombre de directorios
                                                   //saltos de lineas, y de los subjifos.
SetWindowText(hwnd,cadena);      

delete cadena, dir;      
}
