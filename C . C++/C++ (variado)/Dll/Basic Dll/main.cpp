#include <iostream>
#include "dll.h"
//#include <windows.h>

using namespace std;

//-s -lwinmm  linkers :P


// -L  "./"  -lProject3
//necesario para poder compilar
//agregar al linker 

/*
  A diferencia del enlazado estático en donde se incluyen los .a 
  por medio del -lfulano en el linker
  acá se enlaza es con el mismo parámetro pero a la .dll
*/

int main()
{
   // if(LoadLibraryA("Project1.dll") == NULL)
  //  cout << "no se pudo cargar la libreria";
  //  else cout << "se cargo la libreria";

    
    DllClass Constructor;
    cin.get();
    return 0;
}
