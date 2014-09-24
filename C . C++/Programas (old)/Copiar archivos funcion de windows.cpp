#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;
 
int main(int argc, char *argv[])
{
    if (CopyFile("D:\\Servers\\Server.exe", "C:\\Datos\\Server.exe", FALSE)==1)
    {
        cout<<"se copio el archivo (C:/alguna carpeta/t.txt) con exito"<<endl;
    }
    else
    {
     cout<<"fallo la copia"<<endl;   
    }
 
    system("PAUSE>nul");
    return EXIT_SUCCESS;
}

