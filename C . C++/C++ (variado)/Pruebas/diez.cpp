#include <iostream>
using namespace std;
 
void funcion(int *q);
 
int main() { 
   int a; 
   int *p;
 
   a = 100; 
   p = &a; 
   // Llamamos a funcion con un puntero 
   funcion(p); // (1)
   cout << "Variable a: " << a << endl; 
   cout << "Variable *p: " << *p << endl; 
   // Llamada a funcion con la dirección de "a" (constante) 
   funcion(&a);  // (2)
   cout << "Variable a: " << a << endl; 
   cout << "Variable *p: " << *p << endl; 
 
getchar();
  
   return 0; 
}
 
void funcion(int *q) { 
   // Cambiamos el valor de la variable apuntada por 
   // el puntero 
   *q += 50; 
   q++; 
}
