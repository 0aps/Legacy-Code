#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "wtfurl";
HINSTANCE miinstance;
WNDPROC editera;

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    miinstance=hThisInstance;

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
           "wtfurl",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           100,                 /* and height in pixels */
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

LRESULT CALLBACK EditProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if(message==WM_CHAR && wParam==13)
    {
        char text1[1024], text2[1024];
        int i, j, c;
        GetWindowText(hwnd, text1, 1023);
        for(i=0, j=0;text1[i]!=0;i++,j++)
        {
            if(text1[i]!='%') text2[j]=text1[i];
            else
            {
                c='_';
                //-48
                i++;
                if(text1[i]>=48 && text1[i]<=57)c=(text1[i]-48)*16;
                else if(text1[i]>=65 && text1[i]<=70)c=(text1[i]-55)*16;
                else if(text1[i]>=97 && text1[i]<=102)c=(text1[i]-87)*16;
                i++;
                if(text1[i]>=48 && text1[i]<=57)c+=(text1[i]-48);
                else if(text1[i]>=65 && text1[i]<=70)c+=(text1[i]-55);
                else if(text1[i]>=97 && text1[i]<=102)c+=(text1[i]-87);
                text2[j]=c;
            }
        }
        text2[j]=0;
        SetWindowText(hwnd, text2);
        return 0;
    }
    return editera(hwnd, message, wParam, lParam);
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            static HFONT hFont = CreateFont(14, 0, 0, 0, 100, 0, 0, 0,0, 0, 0, 0, VARIABLE_PITCH | FF_SWISS, "Helv");
            static HWND edit1=CreateWindowEx(0,"Edit", 0, WS_CHILD|WS_VISIBLE|WS_TABSTOP|WS_BORDER|ES_MULTILINE, 10, 10, 512, 45, hwnd, 0, miinstance, NULL);
            SendMessage(edit1, WM_SETFONT, (WPARAM) hFont, true);
            SetFocus(edit1);
            editera=(WNDPROC)GetWindowLong(edit1, GWL_WNDPROC);
            SetWindowLong(edit1, GWL_WNDPROC, (long)EditProcedure);
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
