#include <windows.h>    // include the basic windows header file

// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nShowCmd)
{
    // create a "Hello World" message box using MessageBox()
    MessageBox(NULL, "Hello World!", "Just another Hello World program!", MB_ICONEXCLAMATION | MB_OK);

    // return 0 to Windows
    return 0;
}
