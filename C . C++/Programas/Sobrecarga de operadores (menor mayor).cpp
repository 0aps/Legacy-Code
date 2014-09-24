#include <iostream>
#include <cstring>
using namespace std;
 
class Registro {
  public:
   Registro(char *, int, char *);
   const char* LeeNombre() const {return nombre;}
   int LeeEdad() const {return edad;}
   const char* LeeTelefono() const {return telefono;}

  private:
   char nombre[64];
   int edad;
   char telefono[10];
};

Registro::Registro(char *n, int e, char *t) : edad(e) {
   strcpy(nombre, n);
   strcpy(telefono, t);
}

ostream& operator<<(ostream &os, Registro& reg) {
   os << "Nombre: " << reg.LeeNombre() <<"\nEdad: " <<
      reg.LeeEdad() << "\nTelefono: " << reg.LeeTelefono();

   return os;
}
 
int main() {
   Registro Pepe("José", 32, "61545552");
   
   cout << Pepe << endl;
   cin.get();
   return 0;
}
