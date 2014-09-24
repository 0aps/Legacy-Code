#include <iostream>
#include <cstdlib>
#include <windows.h>
 
using namespace std;
 
void pause()
{
    setbuf(stdin, NULL);
    getchar();
}
 
int main()
{
    int ancho=GetSystemMetrics(SM_CXSCREEN);
    int alto=GetSystemMetrics(SM_CYSCREEN);
    int x;
    int y;
    int pixel;
    for(x=0;x<ancho;x+=1)
    {
        for(y=0;y<alto;y+=1)
        {
            SetCursorPos(x,y);
            pixel++;
        }
    }
    cout<<"Nº de pixeles recorridos: "<<pixel;
    pause();
    return 0;
}
 
