// Muestra el alfabeto de may�sculas y min�sculas: 
// AbCdEfGhIjKlMnOpQrStUvWxYz 
// aBcDeFgHiJkLmNoPqRsTuVwXyZ
// ABcdEFghIJklMNopQRstUVwxYZ
// abCDefGHijKLmnOPqrSTuvWXyz 

#include <iostream> 
#include <cctype> 
using namespace std;

int main() 
{ 
   char alfabeto[27]; // Cadena que contendr� el alfabeto 
   int i; // variable auxiliar para los bucles 
   // Aunque podr�amos haber iniciado alfabeto directamente, 
   // lo haremos con un bucle 
   for(i = 0; i < 26; i++) alfabeto[i] = 'a' + i; 
   alfabeto[26] = 0; // No olvidemos poner el fin de cadena 
   // Aplicamos el primer procedimiento si la posici�n es 
   // par convertimos el car�cter a min�scula, si es impar 
   // a may�scula 
   for(i = 0; alfabeto[i]; i++) 
      if(i % 2) alfabeto[i] = tolower(alfabeto[i]); 
      else alfabeto[i] = toupper(alfabeto[i]); 
   cout << alfabeto << endl; // Mostrar resultado 
  
   // Aplicamos el segundo procedimiento si el car�cter era 
   // una may�scula lo cambiamos a min�scula, y viceversa 
   for(i = 0; alfabeto[i]; i++) 
      if(isupper(alfabeto[i])) 
         alfabeto[i] = tolower(alfabeto[i]); 
      else 
         alfabeto[i] = toupper(alfabeto[i]); 
   cout << alfabeto << endl; // Mostrar resultado 

   // Aplicamos el tercer procedimiento, pondremos los dos 
   // primeros caracteres directamente a may�sculas, y 
   // recorreremos el resto de la cadena, si el car�cter 
   // dos posiciones a la izquierda es may�scula cambiamos 
   // el car�cter actual a min�scula, y viceversa 
   alfabeto[0] = 'A'; 
   alfabeto[1] = 'B'; 
   for(i = 2; alfabeto[i]; i++) 
      if(isupper(alfabeto[i-2])) 
         alfabeto[i] = tolower(alfabeto[i]); 
      else 
         alfabeto[i] = toupper(alfabeto[i]); 
   // Mostrar resultado:
   cout << alfabeto << endl; 

   // El �ltimo procedimiento, es tan simple como aplicar 
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
