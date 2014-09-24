#include <stdio.h>

//    return ( ( HPEN(__stdcall *) (int,int, COLORREF) ) Buffer-1)(fnPenStyle, nWidth, crColor) ;
    
void (*dec ( void(*)(char*) ) ) (char*);
void function(char*);

int main() {

    (*dec(function))("Hola Mundo");
    getchar();
    return 0;
}
void (*dec( void(*fptr)(char*) ) )(char*) {
    printf("Función decorada\n");
    return fptr;
}
void function(char *str) {
     printf("%s",str);
}
