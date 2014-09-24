#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void agregar_agenda();
void buscar_agenda();

struct estructura {
   char nombre[25];
   int edad;
   int telefono;
}guardar,tomar; 


int main()
{
    fstream archivo;
    char opcion;
    
   cout << "\t\tAgenda"    
        << "\n\nMenu:"
        << "\n\na)Agregar a la agenda."
        << "\nb)Buscar en la agenda."
        << "\nc)Salir.\n\n:";
   
   cin >> opcion;
   
   if(opcion == 'a' || opcion == 'A')
      agregar_agenda();
   if(opcion == 'b' || opcion == 'B')
      buscar_agenda();
   if(opcion == 'c' || opcion == 'C')
      exit(0);
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
    
}

void agregar_agenda()
{
     cout << "\n\nToma de contacto.";
     cout << "Nombre: ";
     cin.getline(guardar.nombre);
     cout << "Edad: ";
     cin.getline(guardar.edad);
     cout << "Telefono: ";
     cin.getlien(guardar.telefono);
     
     
     if (!archivo.good())    
          archivo.open("Agenda.txt", ios::out);
     else archivo.open("Agenda.txt", ios:app);
     
   archivo.write(reinterpret_cast<char *>(&guardar), 
   sizeof(estructura));
   
   //write: escribe el número de caracteres indicado 
   //en el segundo parámetro desde el buffer suministrado por el primero
   
   //read: lee el número de caracteres indicado en el segundo 
   //parámetro dendro del buffer suministrado por el primero.
   
   archivo.close(); 
     
}

void buscar_agenda()
{
     
    char opcion;
     cout << "\n\nBuscar por:"
          << "\na)Nombre."
          << "\nb)Edad. "
          << "\nc)Telefono.\n\n: ";
      
      cin >> opcion;
     
   if(opcion == 'a' || opcion == 'A')
      {
      char nombre[25];
      cout << "\n\n\Nombre: ";
      cin.getline(nombre, 25);
      
      archivo.open("Agenda.txt", ios::out);
      
      archivo.read(reinterpret_cast<char *>(&tomar), 
      sizeof(estructura));
      
      if(strcmp(nombre
             
             
             
             
             
             
             
   if(opcion == 'b' || opcion == 'B')
      buscar_por_edad();
   if(opcion == 'c' || opcion == 'C')
      buscar_por_telefono();
     

}

