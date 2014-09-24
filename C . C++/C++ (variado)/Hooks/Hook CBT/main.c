
    #include <windows.h>
    #include <stdio.h>
    
    #include "dll.h"
 
    int main( void ){
 
        printf("Hooks Tutorial Vr. 0.5\n");
        printf("==========================================\n\n");
 
        DLKStart();
 
        printf("Presione una tecla Para Finalizar... .)\n\n");
        getchar();
 
        DLKExit();
        return 0;
    }
