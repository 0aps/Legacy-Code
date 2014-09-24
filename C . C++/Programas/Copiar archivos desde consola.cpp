#include <iostream>
#include <fstream>
using namespace std;

//Copia un archivo a otro.
// @Aps.
// 9/07/11


int main(int argc, char *argv[]) 
{
    
    char c;
   // char dir[MAX_PATH];
   // short int len_dir = GetCurrentDirectory(MAX_PATH, dir);
    fstream origen, final;
    
    if(argc != 3)
    {
    cout << "\nUso: " << argv[0] << " <origen> <final>.\n\n";
    return 1;
    }
    
    
    origen.open(argv[1], ios::in);
    final.open(argv[2]);
    //ios::in = si existe bien, si no existe no lo crea.
    //ios::out = crea el archivo.
    //ios::out | ios:in = si existe bien, si no existe no lo crea.
    if(!origen.good())
    {
                      cout << "\nEl archivo " << argv[1] << " no existe."
                           << "\nDebe de existir este archivo.";
                      return 1;
    }
    if(!final.good())
    {
                     cout << "\nEl archivo " << argv[2] << " no existe."
                          << "\nSe procedera a crear uno en la ruta espeficicada.";
                     cin.get();
                     
                     final.open(argv[2],ios::out); //lo creo
                     final.clear();
                     final.close();
                     final.open(argv[2]); //lo abro para input
    }
   
   while(origen.get(c)) final.put(c); //mientras copio origen copio final.
   
   origen.close();
   final.close();
   
   setbuf(stdin, NULL);
   cin.get();
   return 0;

}
