#include <windows.h>  //NOTA: se debe incluir en el linker -lwinmm
 
int main(int argc, char *argv[])
{   
    FreeConsole();
 
    mciSendString("Set CDAudio Door Open",NULL,0,NULL); // abre la bandeja
 
    MessageBox ( 0, "Se Abrio la Bandeja de la Lectora\n\n"\
                     "     Desea Cerrarla?",
		"Coded By DlD", MB_OK | MB_ICONEXCLAMATION );
 
    mciSendString("Set CDAudio Door Closed",NULL,0,NULL);  // cierra la bandeja
 
return EXIT_SUCCESS;
}
