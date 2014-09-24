#include <cstdlib>
#include <iostream>
#include <windows.h>
 
using namespace std;
 
bool apagarmonitor(int segundos){
    HWND hwnd;  //<---- manejador
    char str[100]; // <---- string
    DWORD t= sizeof(str);  //<---- obtiene el tamaño de str  y se lo asigna a DWORD
 
    GetConsoleTitleA(str,t);// <--- obtiene el nombre de la actual ventana de consola
    hwnd=FindWindow(NULL,str); // <--- busca la ventana y le asigna el manejador
 
    cout<<"se apago el monitor desde "<<str;
 
    SendMessage(hwnd,WM_SYSCOMMAND,SC_MONITORPOWER,2); //<--- manda un mensaje a la ventana actual para que se apague
    Sleep(segundos*2000); //<---- retraso de 20 segundos
    SendMessage(hwnd,WM_SYSCOMMAND,SC_MONITORPOWER,-1);//<--- manda un mensaje a la ventana actual para que se restablesca
    return TRUE; //<--- devuelve un true
    }
 
 
int main(int argc, char *argv[])
{  
 
 
if (apagarmonitor(1)==FALSE)  //<--- si el monitor devuelve false no se apaga
{
    cout<<"no se apago el monitor";
    }   
 
    getchar();
    return EXIT_SUCCESS;
}
