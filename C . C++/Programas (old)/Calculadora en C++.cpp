#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
system("title Calculadora v.2.0");
double X;
{
cout << "#Internetizad0s Blog\n#www.internetizados.wordpress.com\n#C0ded: KilerSys\n#Calculadora Avanzada\n\nElige la opcion que desea realizar:\n\n Funciones Matematicas\n1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n5. Raiz cuadrada\n6. Porcentaje\n7. Numero elevado a otro numero\n\n Funciones Trigonometricas\n8. Coseno del angulo\n9. Seno del angulo\n10. Tangente\n11. Arco tangente\n\n Funciones Logaritmicas\n12. Logaritmo natural\n13. Logaritmo decimal\n\n";
cin >> X;
if(X == 1){ //Sumar
double sum1, sum2;
cout << "\nEscribe el primer digito: ";
cin >> sum1;
cout << "Escribe el segundo digito: ";
cin >> sum2;
cout << "El resultado de la suma es " << sum1 + sum2 << "\n" << endl;
system("pause>nul");
}
if(X == 2){ //Restar
double res1, res2;
cout << "\nEscribe el primer digito: ";
cin >> res1;
cout << "Escribe el segundo digito: ";
cin >> res2;
cout << "El resultado de la resta es " << res1 - res2 << endl;
system("pause>nul");
}
if(X == 3) { //Multiplicar
double mul1, mul2;
cout << "\nEscribe el primer digito: ";
cin >> mul1;
cout << "Escribe el segundo digito: ";
cin >> mul2;
cout << "El resultado de la multiplicacion es " << mul1 * mul2 << endl;
system("pause>nul");
}
if(X == 4){ //Dividir
double div1, div2;
cout << "\nEscribe el primer digito: ";
cin >> div1;
cout << "Escribe el segundo digito: ";
cin >> div2;
cout << "El resultado de la división es " << div1 / div2 << endl;
system("pause>nul");
}
if(X == 5){ //Raiz cuadrada
double raiz;
cout << "\nEscribe el digito: ";
cin >> raiz;
cout << "La raiz cuadrada es " << sqrt(raiz) << endl;
system("pause>nul");
}
if(X == 6){ //Porcentaje
double por1, por2;
cout << "\nEscribe el digito: ";
cin >> por1;
cout << "Escribe el porcentaje: ";
cin >> por2;
cout << "El porcentaje es " << (por1 * por2)/100 << endl;
system("pause>nul");
}
if(X == 7){ //Elevar un número a otro exponente
double num1, num2;
cout << "\nEscribe el digito:";
cin >> num1;
cout << "Escribe digito elevado: ";
cin >> num2;
cout << "El resultado es " << pow(num1, num2) << endl;
system("pause>nul");
}
if(X == 8){ //Coseno
double c;
cout << "\nEscribe el digito: ";
cin >> c;
cout << "El coseno del angulo es " << cos(c) << endl;
system("pause>nul");
}
if(X == 9){ //Seno
double s;
cout << "\nEscribe el digito: ";
cin >> s;
cout << "El seno del angulo es " << sin(s) << endl;
system("pause>nul");
}
if(X == 10){ //Tangente
double t;
cout << "\nEscribe un digito: ";
cin >> t;
cout << "La tangente del angulo es " << tan(t) << endl;
system("pause>nul");
}
if(X == 12){ //Logaritmo natural
double l;
cout << "\nEscribe un digito: ";
cin >> l;
cout << "El logaritmo natural del argumento es " << log(l) << endl;
system("pause>nul");
}
if(X == 13){ //Logaritmo decimal
double l1;
cout << "\nEscribe un digito: ";
cin >> l1;
cout << "El logaritmo decimal del argumento es " << log10(l1) << endl;
system("pause>nul");
}
}
}
