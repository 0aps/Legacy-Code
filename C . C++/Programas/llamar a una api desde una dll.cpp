#include <windows.h>

//Definimos una nueva funcion (API)
//Con todos sus par�metros
typedef int (WINAPI *_MessageBox)(
  HWND hWnd,
  LPCTSTR lpText,
  LPCTSTR lpCaption,
  UINT uType
);

int main()
{
   //Declaramos a __MessageBox como si fuera estructura
    //de _Messagebox colocandole un valor nulo (Limpiando)
    _MessageBox __MessageBox = NULL;
    //Llamamos a obtener la direcci�n de la funci�n
    __MessageBox = (_MessageBox)GetProcAddress(LoadLibraryA("USER32.DLL"), "MessageBoxA");
    //Usamos la funci�n
    __MessageBox(0,"soy extraido de la dll","d",0);
    return 0;   
}
