#include <iostream>
using namespace std;
class Persona {
public:
Persona(char *n) { strcpy(nombre, n); }
void VerNombre() { cout << nombre << endl; }
private:
        char nombre[30];
};


int main() {
Persona *Pepito = new Persona("lucas");

Pepito[0]->VerNombre();
delete Pepito;
cin.get();
return 0;
}
