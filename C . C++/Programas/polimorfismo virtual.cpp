#include <iostream>
#include <cstring>
using namespace std;
 
class Persona {
  public:
   Persona(const char *n) { strcpy(nombre, n); }
   Persona(const Persona &p);
   virtual void VerNombre() { 
      cout << nombre << endl; 
   }
   virtual Persona* Clonar() { return new Persona(*this); }
  protected:
   char nombre[30];
};

Persona::Persona(const Persona &p) {
   strcpy(nombre, p.nombre);
   cout << "Per: constructor copia." << endl;
}

class Empleado : public Persona {
  public:
   Empleado(const char *n) : Persona(n) {}
   Empleado(const Empleado &e);
   void VerNombre() { 
      cout << "Emp: " << nombre << endl; 
   }
   virtual Persona* Clonar() { return new Empleado(*this); }
};

Empleado::Empleado(const Empleado &e) : Persona(e) {
   cout << "Emp: constructor copia." << endl;
}

class Estudiante : public Persona {
  public:
   Estudiante(const char *n) : Persona(n) {}
   Estudiante(const Estudiante &e);
   void VerNombre() { 
      cout << "Est: " << nombre << endl; 
   }
   virtual Persona* Clonar() { 
      return new Estudiante(*this); 
   }
};

Estudiante::Estudiante(const Estudiante &e) : Persona(e) {
   cout << "Est: constructor copia." << endl;
}

int main() {
   Persona *Pepito = new Estudiante("Jose");
   Persona *Carlos = new Empleado("Carlos");
   Persona *Gente[2];

   Carlos->VerNombre();
   Pepito->VerNombre();
   
   Gente[0] = Carlos->Clonar();
   Gente[0]->VerNombre();

   Gente[1] = Pepito->Clonar();
   Gente[1]->VerNombre();
   
   delete Pepito;
   delete Carlos;
   delete Gente[0];
   delete Gente[1];
   
   
   cin.get();
   return 0;
   
}

