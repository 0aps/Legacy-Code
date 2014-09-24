    #include <windows.h>
    #include <iostream>

    BOOL NT_SetConsoleDisplayMode(HANDLE hOutputHandle, DWORD dwNewMode)
    {
    typedef BOOL (WINAPI *SCDMProc_t) (HANDLE, DWORD, LPDWORD);
    SCDMProc_t SetConsoleDisplayMode;
    HMODULE hKernel32;
    BOOL bFreeLib = FALSE, ret;
    const char KERNEL32_NAME[] = "kernel32.dll";
    hKernel32 = GetModuleHandleA(KERNEL32_NAME);
    if (hKernel32 == NULL)
    {
    hKernel32 = LoadLibraryA(KERNEL32_NAME);
    if (hKernel32 == NULL)
    return FALSE;
    bFreeLib = true;
    }//if
    SetConsoleDisplayMode =
    (SCDMProc_t)GetProcAddress(hKernel32, "SetConsoleDisplayMode");
    if (SetConsoleDisplayMode == NULL)
    {
    SetLastError(ERROR_CALL_NOT_IMPLEMENTED);
    ret = FALSE;
    }//if
    else
    {
    DWORD dummy;
    ret = SetConsoleDisplayMode(hOutputHandle, dwNewMode, &dummy);
    }//else
    if (bFreeLib)
    FreeLibrary(hKernel32);
    return ret;
    }//NT_SetConsoleDisplayMode

    int main( void )
    {
    NT_SetConsoleDisplayMode( GetStdHandle( STD_OUTPUT_HANDLE ), 1 );
    std::cin.get();

    return 0;
    }
