#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main(int argc, char *argv[])
{
 
HWND hwnd;
char str[100]; // <---- string
    DWORD t= sizeof(str);  //<---- obtiene el tamano de str  y se lo asigna a DWORD
    GetConsoleTitleA(str,t);// <--- obtiene el nombre de la actual ventana de consola
    hwnd=FindWindow(NULL,str); // <--- busca la ventana y le asigna el manejador
 
 char num[][100]={"\t\t\n 1111\n"
                         "  111\n"
                         "  111\n"
                         "  111\n"
                         "  111\n"
                         "1111111\n",
                         "\t\t\n 222222\n"
                               "    222\n"
                              "  222 \n" 
                             " 222 \n" 
                            "222 \n"
                            "2222222\n",
                            "\t\t\n3333333\n"
                                  "    333\n"
                                  " 33333 \n"
                                  "    333\n"
                                  "    333\n"
                                  "3333333\n"};
 
for(int i=0;i<3;i++){
        system("color F");
        system("CLS");
        cout<<"Se activara el protector de pantalla";  
        Sleep(500); 
        system("color A");
        cout<<num[i];
        Sleep(200);
      }
 
SendMessage ( hwnd , WM_SYSCOMMAND , SC_SCREENSAVE , 1  );
 
return 0;
}
 
