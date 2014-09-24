#include <iostream>

using namespace std;

int Astrlen(char []);
void Astrcopy(char [], char []);
void Astreverse(char [], char []);
void Astreverse1(char []);

int main() {
    
    char a[100],b[100];
    cout << "A: ";
    cin.getline(a, 100);
    //cout << "B: ";
    //cin.getline(b, 100);
    cout << endl << endl << "Antes: " << endl;
    cout << "A: " << a << endl << "B: " << b;
    //Astreverse1(a);
    Astreverse1(a);
    cout << endl << "Despues ";
    cout << endl << "A: " << a << endl << "B: " << b;
    

    cin.get();
    return 0;
}

void Astrcopy(char a[], char b[])
{ 
 int i(0);
 
     while(b[i])
     {
     a[i] = b[i];
     i++;
     if(a[i]){ a[i] = '\0';}
     }
     return;
}  
/*

     0=h
     1=o
     2=l
     3=a
     4=\0
*/    

void Astreverse(char a[], char b[])
{
     int i,j(0);                 // Variables para indicar fin y principio de las cadenas
     i = Astrlen(a)-1;            // Ubico el numero de caracteres y le resto 1 para no estar en la posicion de final de cadena
     while(a[j])                 // Mientras no este en final de cadena
     {           
                b[j] = a[i];    //El primer elemento de b sera el ultimo de a
                i--; j++;       //descremento a i para que valla bajando los elementos del arrey y aumento a j para b
     
     if(i == -1)            // Si i es igual a -1 significa que ya llego al principio del arrey                
     {
     b[j] = '\0';        // cierro la cadena para evitar basura
     break;          // salgo del bucle
     }
     }
      return;
}           

void Astreverse1(char a[])
{
     int i,j(0);                 // Variables para indicar fin y principio de las cadenas
     char *b;
     i = Astrlen(a)-1;            // Ubico el numero de caracteres y le resto 1 para no estar en la posicion de final de cadena
     while(a[j])                 // Mientras no este en final de cadena
     {           
                b[j] = a[i];    //El primer elemento de b sera el ultimo de a
                i--; j++;       //descremento a i para que valla bajando los elementos del arrey y aumento a j para b
     
     if(i == -1)            // Si i es igual a -1 significa que ya llego al principio del arrey                
     {
     b[j] = '\0';        // cierro la cadena para evitar basura
     Astrcopy(a,b);
     break;          // salgo del bucle
     }
     }
      return;
}

int Astrlen(char a[])
{
    int i(0);
    while(a[i]) i++;
    
    return i;
}
