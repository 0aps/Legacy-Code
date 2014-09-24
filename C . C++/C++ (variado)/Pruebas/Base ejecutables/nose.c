
    #include <windows.h>
     
    int iState;
    void Func(void);
     
   
    int mainCRTStartup(void) {
        iState = 0;
        Func();
        MessageBoxW(0, 0, 0, iState);
     
        return 0;
    }
     
    void Func(void)
    {
        iState = 0;
    }

