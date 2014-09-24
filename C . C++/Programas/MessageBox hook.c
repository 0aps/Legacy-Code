#include <windows.h>
#include <stdio.h>

void HookMsgBox();
int __stdcall MessageBoxA_Detour(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);

int main()
{
  HookMsgBox();
  MessageBox(0, "HOLA", "MUNDO", 0);
  printf("fin del programa");
}

void HookMsgBox()
{
  HMODULE MySelf = GetModuleHandle(0);
  HMODULE User32 = GetModuleHandle("User32.dll");
  DWORD Msg = (DWORD)GetProcAddress(User32, "MessageBoxA");
  PIMAGE_DOS_HEADER Img = (PIMAGE_DOS_HEADER)MySelf;
  PIMAGE_NT_HEADERS Pe  = (PIMAGE_NT_HEADERS) ((BYTE*)Img + Img->e_lfanew);
  LPDWORD ImportAddr = (LPDWORD)((DWORD)Pe->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress + (DWORD)Img);
  DWORD old;
  VirtualProtect(ImportAddr, 0x1000, PAGE_READWRITE, &old);      
  for (int x = 0; x < Pe->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size; x += 4, ImportAddr++)
  {
    LPDWORD ImportFnc = (LPDWORD)((DWORD)*ImportAddr + (DWORD)MySelf);
    if (*ImportFnc == Msg)
    {
      *ImportFnc = (DWORD)&MessageBoxA_Detour;
    }		
  }
}

int __stdcall MessageBoxA_Detour(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
  printf("%s - %s\r\n", lpText, lpCaption);
  return 0;
}
