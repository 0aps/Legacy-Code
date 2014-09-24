#include <iostream>

using namespace std;

class p 
{
      private:
              char *nombre;
              int edad;
      public:
              ~p(); // Destructor
              char* get_nombre();
              int   get_edad();
};

char* p::get_nombre()
{
      nombre = new char [1024]; // Se reserva un char de 1024 bytes en tiempo de ejecucion
      cin.getline(nombre, 1024);
      
    return nombre;
}

int p::get_edad()
{
    cin >> edad;
     
    return edad;
}

p::~p()
{
    delete[] nombre;
}       

int main(int argc, char *argv[])
{
    p Cnombre;
    char *nombre;
    int edad;
    
    while(1)
{
    
   // system("cls");
    cout << "\nIngrese un nombre: ";
    nombre = Cnombre.get_nombre();
    
    cout << "Ingrese la edad: ";
    edad = Cnombre.get_edad();   
    
    cout << "\nEl nombre ingresado es: " << nombre;
    cout << "\nLa edad ingresada es: " << edad;
    
    setbuf(stdin, NULL);
    cin.get();

}    
    
    return 0;
}
