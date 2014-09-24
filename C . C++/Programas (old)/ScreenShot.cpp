#include <windows.h>
#include <iostream>
#include "captura.h"

using namespace std;

int main(int argc, char *argv[])
{
    char name[15];
    for(int i=0;i<10;i++)
    {
            name[0]='\0';
            strcat(name,"D:\\");
            char n[2];
            n[0]='\0';
            sprintf(n,"%i",i);
            strcat(name,n);
            strcat(name,".jpg");
    CapturaPantalla(0,0,800,600,name);
 Sleep(1000);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
