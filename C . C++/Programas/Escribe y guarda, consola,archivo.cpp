#include <iostream>
#include <fstream>
using namespace std;

//Escribes por consola y se guarda en un archivo.
// @Aps.
// 9/07/11


int main() 
{
   fstream fichero("myfile.txt", ios::out | ios::app);  //ios::app coloca el puntero al final.
   char c;
   
   if(fichero.is_open())
   {
                  cout << "Escribe todo lo que quieras:\n\n";
                  while( (c = cin.get()) != 0x2B ) //sea diferente a '+'
               {
                  fichero << c;   
               }
   fichero.close();
   
   fichero.open("myfile.txt", ios::in);
   cout << "Has escrito: \n";
   while(fichero.get(c))  cout.put(c);
   
   fichero.close();
   }else cout << "No se pudo abrir el archivo.";
   
   setbuf(stdin, NULL);
   cin.get();
   return 0;
}
