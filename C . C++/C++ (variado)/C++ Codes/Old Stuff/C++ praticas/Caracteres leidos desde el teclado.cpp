// Cuenta letras 
#include <iostream> 
#include <cstdio>
#include <cctype> 
using namespace std;

int main() 
{ 
   int consonantes = 0; 
   int vocales = 0; 
   int digitos = 0; 
   int mayusculas = 0; 
   int minusculas = 0; 
   int espacios = 0; 
   int puntuacion = 0; 
   char c; // caracteres leídos desde el teclado
 
   cout << "Contaremos caracteres hasta que se pulse ^Z" 
        << endl; 
   while((c = getchar()) != EOF) 
   { 
      if(isdigit(c)) digitos++; 
      else if(isspace(c)) espacios++; 
      else if(ispunct(c)) puntuacion++; 
      else if(isalpha(c)) 
      { 
         if(isupper(c)) mayusculas++; else minusculas++; 
         switch(tolower(c)) { 
            case 'a': 
            case 'e': 
            case 'i': 
            case 'o': 
            case 'u': 
               vocales++; 
               break; 
            default: 
               consonantes++; 
         } 
      } 
   } 
   cout << "Resultados:" << endl; 
   cout << "Dígitos:     " << digitos << endl; 
   cout << "Espacios:    " << espacios << endl; 
   cout << "Puntuación:  " << puntuacion << endl; 
   cout << "Alfabéticos: " << mayusculas+minusculas << endl; 
   cout << "Mayúsculas:  " << mayusculas << endl; 
   cout << "Minúsculas:  " << minusculas << endl; 
   cout << "Vocales:     " << vocales << endl; 
   cout << "Consonantes: " << consonantes << endl; 
   cout << "Total: " << digitos + espacios + vocales + 
      consonantes + puntuacion << endl; 
cin.get();
cin.get();
   return 0; 
}





