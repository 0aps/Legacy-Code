
#ifndef _DLKDLL_H_
    #define _DLKDLL_H_
 
    #if BUILDING_DLL
    # define DLLIMPORT __declspec (dllexport)
    #else /* Not BUILDING_DLL */
    # define DLLIMPORT __declspec (dllimport)
    #endif /* Not BUILDING_DLL */
 
    DLLIMPORT BOOL DLKStart(void);
    DLLIMPORT BOOL DLKExit(void);
    DLLIMPORT BOOL DLKStartW(HWND,DWORD);
 
    #endif /* _DLKDLL_H_ */
