#include <stdio.h>
#include <windows.h>

typedef VOID (*MYPROC)(LPTSTR); 

int main (int argc, char **argv) {
    char dll[100];
    char funcion[100];
    
    
    HINSTANCE libreria;    
    MYPROC procadd;

    printf ("Busca offsets xDD. Introduce como primer argumento el nombre de la DLL,\n");
    printf ("y como segundo argumento la función dentro de esa DLL\n");
    printf ("Por ejemplo %s msvcrt.dll system\n\n", argv[0]);
    
    if (argc != 3){
        printf ("Introduce 2 argumentos como se explica mas arriba!!!\n");
        return 1;
        }
        
    memset(dll,0,sizeof(dll));
    memset(funcion,0,sizeof(funcion));
    
    memcpy (dll, argv[1], strlen(argv[1]));
    memcpy (funcion, argv[2], strlen(argv[2]));
    
    libreria = LoadLibrary(dll);
    procadd = (MYPROC)GetProcAddress (libreria,funcion);
    
    printf ("Offset de %s en la DLL %s es %x", funcion, dll, procadd);
    
    
}
