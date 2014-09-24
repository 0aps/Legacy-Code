#include <iostream>
#include <fstream>  // necesaria para ofstream
using namespace std;
 
int main() {
 
   ofstream impresora("PRN"); // abre el puerto de la impresora para mandar comandos ASCII
 
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@ Aqui va el cuerpo de la impresion @@@@@@@@@@@@@@@@@*/
 
      impresora<<"\n\n\n\t\thola mundo\a\f\f"<<endl; // manda el flujo a la impresora
 
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@ Fin de imprimir @@@@@@@@@@@@@@@@@*/     
 
   impresora.close();    // cierra la impresora/flujo
 
   return 0;
}
