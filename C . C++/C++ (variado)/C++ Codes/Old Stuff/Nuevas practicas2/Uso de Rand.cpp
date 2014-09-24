#include <windows.h>
 
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
 
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;
    char szClassName[21];
 
 
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
 
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
 
    if (!RegisterClassEx (&wincl))
        return 0;
 
    hwnd = CreateWindowEx (
           0,
           szClassName,
           "Jodete",
           WS_OVERLAPPEDWINDOW,
           CW_USEDEFAULT,
           CW_USEDEFAULT,
           75,
           75,
           HWND_DESKTOP,
           NULL,
           hThisInstance,
           NULL
           );
 
    ShowWindow (hwnd, nCmdShow);
    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    //WinMain (hThisInstance, hPrevInstance, lpszArgument, nCmdShow);
    return messages.wParam;
}
 
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_MOUSEMOVE:
            MoveWindow(hwnd, rand()%(GetSystemMetrics(SM_CXSCREEN)-50), rand()%(GetSystemMetrics(SM_CYSCREEN)-50), 75, 75, true);
            break;
        case WM_SYSCOMMAND:
                PostQuitMessage(0);
            break;
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

