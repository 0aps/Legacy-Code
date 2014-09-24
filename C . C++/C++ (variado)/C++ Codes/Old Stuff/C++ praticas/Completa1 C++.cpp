//Completa uno en C++  
#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    a=80;
    b=20;
    c=a+b;
cout << "La suma de " << a;
cout << " mas " << b;
cout << " es igual a " << c << endl;
system("pause>nul");

int A=100;
int B=200;
cout << "\nEl resultado de tu operacinn es igual a: " << A+B;
system("pause>nul");

int d,e;
cout << "\n\nEscriba el primer numero: ";
cin >> d;
cout << "Escriba el segundo numero: ";
cin >> e;
cout << "La suma de los dos numeros es igual a " << d+e;
system("pause>nul");

int NumeroAlAzar;
cout << "\n\nEscribe un numero al azar: ";
cin >> NumeroAlAzar;
cout << "El numero escrito es: " << NumeroAlAzar;
system("pause>nul");

int n;
cout << "\n\nEscribe un numero: ";
cin >> n;

if (n>0)
{
cout << "El numero es: ";
cout << n; 
cout << " Y es positivo";
 }
 
 else if (n<0)
 {
        cout << "El numero es: ";
        cout << n; 
        cout << " Y es negativo";
 }
  else (n==0);
{
    cout << "El numero es: "; 
    cout << n;
    cout << " Y es neutro";
}
system("pause>nul");
return 1;
}
