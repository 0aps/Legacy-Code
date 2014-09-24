	

    #include <windows.h>
     
    // char uninitialized_data[4096] __attribute__((section (".data")));
     
    void Func(void);
     
    typedef int( *_MessageBox)(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType);
    _MessageBox mMessageBox;
     
    int mainCRTStartup(void)
    {
      
        Func();
     
        mMessageBox(0, 0, 0, 0);
     
        return 0;
    }
     
    void Func(void)
    {
        mMessageBox = (_MessageBox)GetProcAddress(LoadLibrary("User32.dll"), "MessageBoxW");
    }

