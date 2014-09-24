#include <windows.h>
#include <stdio.h>
 
int main(void){
  
  if( (LoadLibrary("HookMessageBoxEx\\HookMessageBoxExA.dll") ) == NULL)
  MessageBoxExA(NULL,"Fallo al cargar la DLL","ApiHooking",0,0);
  
  MessageBoxExA(NULL,"Soy un messagebox NO hookeado","ApiHooking",0,0);
  return 0;
}
