//////////////////////////////
//  Listando directorios y  //
//  carpetas de una ruta    //
//  By E0N                  //
//////////////////////////////
 
#include <iostream>
#include <windows.h>
 
using namespace std;
 
 
void listarDirectorio(char* dir)
{
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
 
    strcat (dir,"\\*");
 
    //hFind = FindFirstFile(dir, &findFileData);
 
  //  if (hFind == INVALID_HANDLE_VALUE)
 	//    std::cout << "Ruta incorrecta";         
   // else
   // {
//	std::cout << findFileData.cFileName << '\n'; //El primer fichero
 
        // Listamos todos los ficheros restantes
        while (FindNextFile( (HANDLE*)dir, &findFileData) != 0)
			std::cout << findFileData.cFileName << '\n';
    //}
}
 
int main()
{
	char* dir = new char[MAX_PATH];
 
        cout << "Introduzca el nombre de la  ruta a explorar: ";
        cin  >> dir; 

	cout << "\n\n";
 
	listarDirectorio(dir);
 
	delete(dir);
	setbuf(stdin, NULL);
getchar();
}
 
