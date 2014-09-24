#include <cstdlib>
#include <iostream>
#include <windows.h>
using namespace std;
 
int main(int argc, char *argv[])
{
    HWND hwnd;
    char ventana[100]="";
    system("color E");
 
    cout<<"introduzca el nombre de la ventana activa a cerrar"<<endl<<endl
    <<"NOTA: recuerde poner mayusculas y minusculas!"<<endl<<endl<<"nombre ventana : ";
 
    cin.getline(ventana,100);
 
    hwnd=FindWindow(NULL,ventana);
 
 if (hwnd==NULL){
 cout<<"no se encontro la ventana"<<endl;
} 
 
else 
{
     SendMessage(hwnd,WM_CLOSE,0,0);
    cout<<"se encontro la ventana y se cerro"<<endl;
    }
 
    system("PAUSE");
    return EXIT_SUCCESS;
}
 
