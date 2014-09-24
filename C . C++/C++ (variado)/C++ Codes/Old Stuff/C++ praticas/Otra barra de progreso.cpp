#include <iostream>
#include <windows.h>
 
void ShowBar(int porcentaje,int tamMax,char* Msg)
{
    int i = 0,a = 0;
    for(i = tamMax+strlen(Msg)+2; i>=0; --i) putchar('\b'); // vamos al principio de la barrita
 
    putchar('[');
        for(i = (porcentaje*tamMax)/100; a<i; ++a) putchar('+');
        for(; a < tamMax; ++a) putchar('-');
    putchar(']');
 
    printf(" %s",Msg);
    fflush(stdout);
}
 
 
 
int main()
{
int i = 0;
/*system("clear"); */
    printf("Haciendo algo que tarda un poco .... \n\n");
    for( i = 0; i < 12; ++i)
    {
        ShowBar((i*100/11),50,"  Completado");
        Sleep(1000);
    }
 
}
