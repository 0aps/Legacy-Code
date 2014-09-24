#include<windows.h>
#include<io.h>
#include<stdio.h>

const int BUTTON1=102;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
bool compare(char *mask, char *filename, char *retorno);
int checkar(char *cadena1, char *cadena2);

/*  Make the class name into a global variable  */

char szClassName[ ] = "WA";
HINSTANCE auxinstance;

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    auxinstance=hThisInstance;

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
    wincl.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Cambiador Masivo de Nombres --- By Avoidance25",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           490,                 /* The programs width */
           190,                 /* and height in pixels */
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
    HFONT hFont;
    char modelo[260], neonombre[260], X[260], nombrea[260], ruta[260], mnsg[260];
    int i, j, cantidad;
    _finddata_t c_file;
    long hFile;
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            hFont = CreateFont(14, 0, 0, 0, 100, 0, 0, 0,0, 0, 0, 0,
            VARIABLE_PITCH | FF_SWISS, "Helv");
            
            static HWND hwndText1=CreateWindowEx
            (   WS_EX_CLIENTEDGE,
                "EDIT","Nombre actual de los archivos ( \"#\" es el comodin)",
                WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
                15, 22, 450, 25, hwnd,  NULL, auxinstance, NULL
            );
            SendMessage(hwndText1,EM_LIMITTEXT,260,0L);
            SendMessage(hwndText1,WM_SETFONT,(WPARAM)hFont,TRUE);
            
            static HWND hwndText2=CreateWindowEx
            (   WS_EX_CLIENTEDGE,
                "EDIT","Nuevo nombre de los archivos (usando el mismo comodin)",
                WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
                15, 65, 450, 25, hwnd,  NULL, auxinstance, NULL
            );
            SendMessage(hwndText2,EM_LIMITTEXT,260,0L);
            SendMessage(hwndText2,WM_SETFONT,(WPARAM)hFont,TRUE);
            
            hFont = CreateFont(16, 0, 0, 0, 100,0,0,0,0,0,0,0,
            VARIABLE_PITCH | FF_SWISS, "Helv");
            static HWND hwndButton1=CreateWindow
            (   "BUTTON","Acceptar",
                WS_CHILD|WS_VISIBLE|BS_CENTER,
                200, 110, 75, 25, hwnd, (HMENU)BUTTON1, auxinstance, NULL
            );
            SendMessage(hwndButton1,WM_SETFONT,(WPARAM)hFont,TRUE);
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case BUTTON1:
                    GetWindowText(hwndText1, modelo, 260);
                    GetWindowText(hwndText2, neonombre, 260);
                    
                    switch(checkar(modelo, neonombre))
                    {
                        case -1:
                        MessageBox(hwnd, "Debe haber la misma cantidad de comodines en ambos cuadros", "Error", MB_OK | MB_ICONERROR);
                        return 0;
                        case -2:
                        MessageBox(hwnd, "Se debe usar al menos un comodin", "Error", MB_OK | MB_ICONERROR);
                        return 0;
                    }
                    GetModuleFileNameA(GetModuleHandleA(0),ruta,260);
                    for(i=strlen(ruta)-1;i>=0;i--)
                    {
                        if(ruta[i]=='\\')
                        {
                            ruta[i]=0;
                            break;
                        }
                    }
                    SetCurrentDirectory(ruta);
                    if ( (hFile = _findfirst("*.*", &c_file)) == -1L )
                    {
                        MessageBox(hwnd, "No se pudo habrir el directorio", "Error", MB_OK | MB_ICONERROR);
                        return 0;
                    }
                    cantidad=0;
                    do
                    {
                        if((c_file.attrib & _A_SUBDIR) == 0)
                        {
                            if(compare(modelo,c_file.name, X))
                            {
                                strcpy(nombrea, neonombre);
                                j=0;
                                for(i=strlen(nombrea)-1;i>=0;i--)
                                {
                                    if(nombrea[i]=='#')
                                    {
                                        nombrea[i]=X[j];
                                        if(++j==strlen(X))break;
                                    }
                                }
                                rename(c_file.name, nombrea);
                                cantidad++;
                            }
                        }
                    } while ( _findnext(hFile, &c_file) == 0 );
                    _findclose(hFile);
                    sprintf(mnsg, "Se ha cambiado el nombre de %i archivos", cantidad);
                    MessageBox(NULL, mnsg, "Listo !!!", MB_OK);
                    PostQuitMessage (0);
                    break;
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



int checkar(char *cadena1, char *cadena2)
{
    int c1=0, c2=0, i;
    for(i=strlen(cadena1)-1;i>=0;i--)
    {
        if(cadena1[i]=='#') c1++;
    }
    for(i=strlen(cadena2)-1;i>=0;i--)
    {
        if(cadena2[i]=='#') c2++;
    }
    if(c1!=c2) return -1;
    if(!c1 || !c2) return -2;
    return 0;
}



bool compare(char *mask, char *filename, char *retorno)
{
    int i;
    char aux[2];
    aux[1]=0;
    strcpy(retorno,"");
    if(strlen(mask)!=strlen(filename)) return false;
    
    for(i=strlen(mask)-1;i>=0;i--)
    {
        if(mask[i]=='#')
        {
            aux[0]=filename[i];
            strcat(retorno,aux);
            continue;
        }
        if(mask[i]!=filename[i])
        {
            strcpy(retorno,"");
            return false;
        }
    }
    return true;
}
