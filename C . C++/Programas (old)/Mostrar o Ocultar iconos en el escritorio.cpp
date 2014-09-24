#include <cstdlib>
#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main(int argc, char *argv[])
 
{  
   HWND manejador1;
   manejador1 = FindWindowEx(0,0,"Progman",NULL);  // obtiene el manejador de la ventana Child de el escritorio (iconos)
   int estado;
   char estadox,x;
 
do { 
   Sleep(100); 
   system("cls");
   cout<<"\t\tOcultar iconos del escritorio? "<<endl
   <<endl<<"\t\tOcultar [ 0 ]"<<endl<<"\t\tMostrar [ 1 ]"<<endl<<"\t\tSalir [ x ]";
   cin>>estadox;
   if (estadox=='0' || estadox=='1'){          //<----- FILTRO 0 y 1
   if (estadox=='0'){                                    // <----Ocultando Mostrando
                  estado=0;
    cout<<"\t\tse an ocultado los iconos";
    }
 
   else {
        estado=1; 
   cout<<"\t\ticonos mostrandose";
}
   ShowWindow(manejador1,estado);  //<---- esconde/muestra la ventana de el escritorio
Sleep(100);
}
 
else{cout<<endl<<endl<<"\t\tOOOOPS!"<<endl<<"\t\tIntrodusca 0-1";Sleep(100);}
}
while(estadox!='x');
   return EXIT_SUCCESS;
}
