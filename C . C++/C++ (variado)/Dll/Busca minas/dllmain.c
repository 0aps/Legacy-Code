/* Replace "dll.h" with the name of your header */

#include <windows.h>
#include <Tlhelp32.h>
#include <stdio.h>

/*
  Name: trainer buscaminas
  Author: @aps
  Date: 14/12/11 17:51
*/

void HookImport();
HPEN __stdcall CreatePenF( int , int , COLORREF  );

BOOL APIENTRY DllMain (HINSTANCE hInst     /* Library instance handle. */ ,
                       DWORD reason        /* Reason this function is being called. */ ,
                       LPVOID reserved     /* Not used. */ )
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
          HookImport();
        break;

      case DLL_PROCESS_DETACH:
        break;

      case DLL_THREAD_ATTACH:
        break;

      case DLL_THREAD_DETACH:
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}

void HookImport()
{ 
  HMODULE Prog  = GetModuleHandle(0);
  HMODULE Gdi32   = GetModuleHandle("Gdi32.dll");
  DWORD CreatePen = (DWORD)GetProcAddress(Gdi32, "CreatePen");
  int x;
  
  PIMAGE_DOS_HEADER Img = (PIMAGE_DOS_HEADER)Prog;
 
  //e lfanew apunta a donde empieza el encabezado nt
  PIMAGE_NT_HEADERS Pe  = (PIMAGE_NT_HEADERS) ((BYTE*)Img + Img->e_lfanew); 
  
  // obtengo la direccion del import en la seccion .text
  LPDWORD ImportAddr = (LPDWORD)(
  Pe->OptionalHeader.BaseOfCode + (DWORD)Img);
  
  DWORD old;
  
  //le cambio los privilegios 
  VirtualProtect(ImportAddr, 
  Pe->OptionalHeader.SizeOfCode, PAGE_READWRITE, &old); 
       
  
  for ( x= 0; x < Pe->OptionalHeader.SizeOfCode; x += 4, ImportAddr++)
  {
   //si la funcion es CreatePen
      if (*ImportAddr == CreatePen)
     {
        //cambio los primeros cuatro bytes que apuntan a la direccion de memoria de CreatePen
        //por los de mi funcion
       *ImportAddr = (DWORD)&CreatePenF;
        break;
      }		
    
   }

}


HPEN __stdcall CreatePenF( int fnPenStyle, int nWidth, COLORREF crColor )
{
    fnPenStyle = PS_DASHDOT;
    nWidth     = 20; 
    crColor    = RGB(255, 0, 0);
    
    BYTE  *Buffer = (BYTE *)malloc(5); 
    BYTE  *DirApi = (BYTE *)GetProcAddress(GetModuleHandle("Gdi32.dll"),"CreatePen");
    
    *Buffer=0xE9;
    Buffer++;
    
    //api menos el principio del buffer
    *((signed int *) Buffer) = DirApi - Buffer - 4;
   
    return ( (HPEN(__stdcall *) (int,int, COLORREF) ) Buffer-1)(fnPenStyle, nWidth, crColor);
	
}
