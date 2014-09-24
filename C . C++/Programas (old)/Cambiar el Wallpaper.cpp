#include <cstdlib>
#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
 
FreeConsole();
 
 
    char imagenBMP[]="C:/1.mp";   // Debe ser Bitmap, la imagen a cargar
                                          // tirara error si no es .bmp al cargarla  
 
if (SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, imagenBMP
     , SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE)==0)    // si la funcion falla
                                                          // devuelve 0
     {
          SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, NULL  
          , SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);  // deja el wallpaper anterior                                                  
                                                          // si falla la funcion
 
          MessageBox ( 0, "No se Realizo el Cambio del Papel Tapiz",
			"Coded By DlD", MB_OK | MB_ICONERROR );}
 
		else	
			MessageBox ( 0, "Se Realizo el Cambio del Papel Tapiz con Exito",
			"Coded By DlD", MB_OK | MB_ICONEXCLAMATION );
 
    return EXIT_SUCCESS;
}
 
