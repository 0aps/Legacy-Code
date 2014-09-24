#include <windows.h>

const int SIg=61;
const int DO=65;
const int RE=73;
const int MI=82;
const int FA=87;
const int SOL=98;
const int LA=110;
const int SI=123;
const int DOa=130;
const int REa=146;

const int NOTA_MAX=20;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void hacerlinea(HDC hDC, int x1, int y1, int x2, int y2);

/*  Make the class name into a global variable  */
char szClassName[ ] = "CodeBlocksWindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
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
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Piano",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           640,                 /* The programs width */
           120,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
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
    static struct
    {
        int nota;
        int lugar;
        //int largo;
    }notas[NOTA_MAX];

    static int largo=100;
    static int pos=0;

    switch (message)                  /* handle the messages */
    {
        case WM_KEYDOWN:
            if(pos<NOTA_MAX-1)
            switch(wParam)
            {
                case 96:
                    Beep(SIg, largo);
                    notas[pos].nota=SIg;
                    notas[pos].lugar=72;
                    pos++;
                    break;
                case 97:
                    Beep(DO, largo);
                    notas[pos].nota=DO;
                    notas[pos].lugar=66;
                    pos++;
                    break;
                case 98:
                    Beep(RE, largo);
                    notas[pos].nota=RE;
                    notas[pos].lugar=60;
                    pos++;
                    break;
                case 99:
                    Beep(MI, largo);
                    notas[pos].nota=MI;
                    notas[pos].lugar=54;
                    pos++;
                    break;
                case 100:
                    Beep(FA, largo);
                    notas[pos].nota=FA;
                    notas[pos].lugar=48;
                    pos++;
                    break;
                case 101:
                    Beep(SOL, largo);
                    notas[pos].nota=SOL;
                    notas[pos].lugar=42;
                    pos++;
                    break;
                case 102:
                    Beep(LA, largo);
                    notas[pos].nota=LA;
                    notas[pos].lugar=36;
                    pos++;
                    break;
                case 103:
                    Beep(SI, largo);
                    notas[pos].nota=SI;
                    notas[pos].lugar=30;
                    pos++;
                    break;
                case 104:
                    Beep(DOa, largo);
                    notas[pos].nota=DOa;
                    notas[pos].lugar=24;
                    pos++;
                    break;
                case 105:
                    Beep(REa, largo);
                    notas[pos].nota=REa;
                    notas[pos].lugar=18;
                    pos++;
                    break;
            }

            //MessageBox(0,0,0,0);
            //UpdateWindow(hwnd);
            break;
        case WM_PAINT:
            PAINTSTRUCT ps;
            HDC hDC;
            hDC = BeginPaint(hwnd, &ps);


            for(int i=0;i<pos;i++)
                Ellipse(hDC, 25+i*15, notas[i].lugar, 37+i*15, notas[i].lugar+12);

            hacerlinea(hDC, 0, 12, 625, 12);
            hacerlinea(hDC, 0, 24, 625, 24);
            hacerlinea(hDC, 0, 36, 625, 36);
            hacerlinea(hDC, 0, 48, 625, 48);
            hacerlinea(hDC, 0, 60, 625, 60);
            hacerlinea(hDC, 10, 10, 10, 62);

            EndPaint(hwnd, &ps);
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void hacerlinea(HDC hDC, int x1, int y1, int x2, int y2)
{
    MoveToEx(hDC, x1, y1, NULL);
    LineTo(hDC, x2, y2);
}
