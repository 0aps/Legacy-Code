#include <iostream> //<< >>
#include <conio.h>
using namespace std;

int main(int argc, char *arvg[])
{
char a[100];
char b[100];


int ab;
cout << "Ingresa la primera cadena: ";
cin.get(a, 100);
cout << "El valor de la segunda cadena es: X ";
cin.get();
cout << "\n\nLa primera cadena  es: " << a;
strcpy(b,a);
cout << "\nLa segunda cadena es: " << b << endl;
ab=strlen(a);
cout << "\nLa primera cadena tiene " << ab << " caracteres." << endl;
strcat(a,b);
cout << "\nLas dos cadenas unidas serian : " << a;
ab=strlen(a);
cout << "\n\nLas cuale tendrian " << ab << " caracteres.";
setbuf(stdin, NULL);
cin.get();
return 0;
}
