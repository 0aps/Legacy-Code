// Muestra el alfabeto de mayúsculas y minúsculas: 
// AbCdEfGhIjKlMnOpQrStUvWxYz 
// aBcDeFgHiJkLmNoPqRsTuVwXyZ
// ABcdEFghIJklMNopQRstUVwxYZ
// abCDefGHijKLmnOPqrSTuvWXyz 

#include <iostream> 
#include <cctype> 
using namespace std;

int main() 
{ 
   char alfabeto[27]; // Cadena que contendrá el alfabeto 
   int i; // variable auxiliar para los bucles 
   // Aunque podríamos haber iniciado alfabeto directamente, 
   // lo haremos con un bucle 
   for(i = 0; i < 26; i++) alfabeto[i] = 'a' + i; 
   alfabeto[26] = 0; // No olvidemos poner el fin de cadena 
   // Aplicamos el primer procedimiento si la posición es 
   // par convertimos el carácter a minúscula, si es impar 
   // a mayúscula 
   for(i = 0; alfabeto[i]; i++) 
      if(i % 2) alfabeto[i] = tolower(alfabeto[i]); 
      else alfabeto[i] = toupper(alfabeto[i]); 
   cout << alfabeto << endl; // Mostrar resultado 
  
   // Aplicamos el segundo procedimiento si el carácter era 
   // una mayúscula lo cambiamos a minúscula, y viceversa 
   for(i = 0; alfabeto[i]; i++) 
      if(isupper(alfabeto[i])) 
         alfabeto[i] = tolower(alfabeto[i]); 
      else 
         alfabeto[i] = toupper(alfabeto[i]); 
   cout << alfabeto << endl; // Mostrar resultado 

   // Aplicamos el tercer procedimiento, pondremos los dos 
   // primeros caracteres directamente a mayúsculas, y 
   // recorreremos el resto de la cadena, si el carácter 
   // dos posiciones a la izquierda es mayúscula cambiamos 
   // el carácter actual a minúscula, y viceversa 
   alfabeto[0] = 'A'; 
   alfabeto[1] = 'B'; 
   for(i = 2; alfabeto[i]; i++) 
      if(isupper(alfabeto[i-2])) 
         alfabeto[i] = tolower(alfabeto[i]); 
      else 
         alfabeto[i] = toupper(alfabeto[i]); 
   // Mostrar resultado:
   cout << alfabeto << endl; 

   // El último procedimiento, es tan simple como aplicar 
   // el segundo de nuevo 
   for(i = 0; alfabeto[i]; i++) 
      if(isupper(alfabeto[i])) 
         alfabeto[i] = tolower(alfabeto[i]); 
		
         alfabeto[i] = toupper(alfabeto[i]); 
   // Mostrar resultado:
   cout << alfabeto << endl; 
   
   setbuf(stdin, NULL);
   cin.get();
   return 0; 
}
