#include <windows.h>
#include <stdio.h>

// la import table son las funciones que utiliza el programa propias no externas.
// las exportadas son las que se usan desde una dll o otros archivos que
// no son propias del ejecutable.


void HookMsgBox();
int __stdcall MessageBoxA_Detour(HWND , LPCSTR , LPCSTR , UINT );

int main()
{
  HookMsgBox();
  MessageBox(0, "HOLA", "MUNDOddddddddd", 0);
  printf("fin del programa");
  getchar();
}

void HookMsgBox()
{
  HMODULE MySelf = GetModuleHandle(0);
  HMODULE User32 = GetModuleHandle("User32.dll");
  DWORD Msg = (DWORD)GetProcAddress(User32, "MessageBoxA");
 
  PIMAGE_DOS_HEADER Img = (PIMAGE_DOS_HEADER)MySelf;
 
  //e lfanew apunta a donde empieza el encabezado nt
  PIMAGE_NT_HEADERS Pe  = (PIMAGE_NT_HEADERS) ((BYTE*)Img + Img->e_lfanew); 
  
  // obtengo la direccion del import table el principio
  LPDWORD ImportAddr = (LPDWORD)((DWORD)Pe->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress + (DWORD)Img);
 
  DWORD old;
 // VirtualProtect(ImportAddr, 0x1000, PAGE_READWRITE, &old);      
 // IMAGE_DATA_DIRECTOR Y DataDirector, 
 // esta estructura que contiene la direccion de las secciones en el archivo 
 // y los tamaños de estas secciones.
 
  //le cambio los privilegios a toda la import table
  VirtualProtect(ImportAddr, 
  Pe->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size, PAGE_READWRITE, &old); 
       
 
  for (int x = 0; x < Pe->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size; x += 4, ImportAddr++)
  {
      //funcion dentro del import table
      //para obternerla se suma el contenido de la import table mas el modulo del programa 
      //actual
       LPDWORD ImportFnc = (LPDWORD)((DWORD)*ImportAddr + (DWORD)MySelf);
   
   //si la funcion es messageboxa
      if (*ImportFnc == Msg)
     {
        //cambio los primeros cuatro bytes que apuntan a la direccion de memoria de messagebox
        //por los de mi funcion
       *ImportFnc = (DWORD)&MessageBoxA_Detour;
        break;
      }		
    
   }
}

int __stdcall MessageBoxA_Detour(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
  printf("%s - %s\r\n", lpText, lpCaption);
  return 0;
}
