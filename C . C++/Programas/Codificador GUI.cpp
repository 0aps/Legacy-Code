#include<windows.h>
#include<string.h>
//#include<time.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
char codificar(char*);

/*  Make the class name into a global variable  */
char szClassName[ ] = "JS";
HINSTANCE auxinstance;

const int CODIFICAR=101;
const int HELP=102;
const char contenidoHelp[]="Para codificar debes escribir el texto en el cuadro de arriba y hacer click en codificar.\nPara decodificar debes copiar el texto codificado en el cuadro de arriba y hacer click en codificar.\n\nHecho por Avoidance25";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    
//    tm* tiempo;
//    time_t timer;
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    auxinstance=hThisInstance;
/*
    timer=time(NULL);
    tiempo=localtime(&timer);
    if(tiempo->tm_hour!=0)
    {
        MessageBox(NULL,"Memoria virtual insuficiente para completar operacion.","Error",MB_OK | MB_ICONERROR);
        return -1;
    }
*/
    
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
    wincl.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(236,233,216));

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "By Avoidance25",    /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           350,                 /* The programs width */
           275,                 /* and height in pixels */
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
    char textoACodificar[1024];
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            static HWND hwndEditDesde=CreateWindowEx
            (   WS_EX_CLIENTEDGE,
                "EDIT","",
                WS_CHILD | WS_VSCROLL | ES_MULTILINE | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
                10, 10, 200, 100, hwnd,  NULL, auxinstance, NULL
            );
            SendMessage(hwndEditDesde, EM_LIMITTEXT, 1000, 0L);
              
            static HWND hwndEditHasta=CreateWindowEx
            (   WS_EX_CLIENTEDGE,
                "EDIT","",
                WS_CHILD | WS_VSCROLL | ES_MULTILINE | WS_VISIBLE | WS_BORDER | WS_TABSTOP,
                10, 125, 200, 100, hwnd,  NULL, auxinstance, NULL
            );
            //SendMessage(hwndEditHasta, WM_ENABLE, 0, 0 );
            
            static HWND hwndAceptar = CreateWindow
            (   "button", "Codificar",
                WS_CHILD|WS_VISIBLE|BS_CENTER,
                220, 10, 110, 180, hwnd, (HMENU)CODIFICAR, auxinstance, NULL
            );
            
            static HWND hwndHelp = CreateWindow
            (   "button", "?",
                WS_CHILD|WS_VISIBLE|BS_CENTER,
                220, 195, 110, 30, hwnd, (HMENU)HELP, auxinstance, NULL
            );
            
            
            
            SetFocus(hwndEditDesde);
            break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case CODIFICAR:
                    GetWindowText(hwndEditDesde, textoACodificar, 1000);
                    codificar(textoACodificar);
                    SendMessage(hwndEditHasta, WM_SETTEXT, 0, (long int) textoACodificar );
                    break;
                case HELP:
                    MessageBox(NULL,contenidoHelp,"Ayuda",MB_OK | MB_ICONQUESTION);
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


char codificar(char *entrada)
{
    int len, i;
    char aux;
    len=strlen(entrada);
    for(i=0;i<len;i++)
    {
        if((entrada[i]>64)&&(entrada[i]<91))
		{
			entrada[i]+=32;
		}
		
		if((entrada[i]>96)&&(entrada[i]<123))
		{
			entrada[i]-=96;
			entrada[i]=27-entrada[i];
			entrada[i]+=96;
		}
		if((entrada[i]>47)&&(entrada[i]<58))
		{
			entrada[i]-=47;
			entrada[i]=11-entrada[i];
			entrada[i]+=47;
		}
    }
    for(i=0;i<len/2;i++)
    {
        aux=entrada[i];
        entrada[i]=entrada[len-i-1];
        entrada[len-i-1]=aux;
    }
    for(i=0;i<len;i++)
    {
        if(entrada[i]==13) entrada[i]=10;
        else if(entrada[i]==10) entrada[i]=13;
    }
}

