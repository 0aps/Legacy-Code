#include <iostream>
#include <fstream>
using namespace std;
 
 /*
 
 Entrada = 'cin >>' cuando se toman datos del plano ya sea consola o archivo.
 Salida = 'cout <<' cuando se escribe en el plano ya sea consola o archivo.

*/
 
 
int main() {
   int i;
   char mes[][20] = {"Enero", "Febrero", "Marzo", 
      "Abril", "Mayo", "Junio", "Julio", "Agosto", 
      "Septiembre", "Octubre", "Noviembre", 
      "Diciembre"};
   char cad[20];
      
   ofstream fsalida("meses.dat", 
      ios::out | ios::binary);
   
   // Crear fichero con los nombres de los meses:
   cout << "Crear archivo de nombres de meses:" << endl;
   for(i = 0; i < 12; i++)
      fsalida.write(mes[i], 20);
   fsalida.close();

   ifstream fentrada("meses.dat", ios::in | ios::binary);
   
   // Acceso secuencial:
   cout << "\nAcceso secuencial:" << endl;
   fentrada.read(cad, 20);
   do {
      cout << cad << endl;
      fentrada.read(cad, 20);
   } while(!fentrada.eof());

   fentrada.clear();
   // Acceso aleatorio:
   cout << "\nAcceso aleatorio:" << endl;
   for(i = 11; i >= 0; i--) {
      fentrada.seekg(20*i, ios::beg); //se mueve desde el principio del archivo
                                     // hasta el byte 20*1
      fentrada.read(cad, 20);
      cout << cad << endl;
   }
 
   // Calcular el número de elementos 
   // almacenados en un fichero:
   // ir al final del fichero
   fentrada.seekg(0, ios::end); 
   // leer la posición actual
 int pos = fentrada.tellg(); 
   // El número de registros es el tamaño en 
   // bytes dividido entre el tamaño del registro:
   cout << "\nNúmero de registros: " << pos/20 << endl;
   fentrada.close();

cin.get();
   return 0;
}
