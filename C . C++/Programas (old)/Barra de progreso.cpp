/*#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    int i;
system("title Barra de progreso");
system("mode con cols=40 lines=1");

for(i=0; i<=38; i++)
{
    Sleep(100);
cout << "Û";
}
system("msg * Carga completa");

}*/
/////////////////////////////////////////////////////////////////////////////////
/*
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
int i=1;

system("title Barra de progreso");
system("mode con cols=40 lines=1");

do
  {
printf("Û");
Sleep(100);
i++;
  }
  while(i<=40);          
MessageBox(0, "Carga Completa", "Atención", MB_OK); 

} 
/*
