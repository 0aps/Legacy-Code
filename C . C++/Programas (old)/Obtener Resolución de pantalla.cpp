#include <cstdlib>
#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
    int x , y;
 
   x=GetSystemMetrics( SM_CXSCREEN );
   y=GetSystemMetrics( SM_CYSCREEN );
 
    cout<<"ancho = "<<x<<" x "<<"alto = "<<y;
 
    getchar();
 
    return EXIT_SUCCESS;
}
 
