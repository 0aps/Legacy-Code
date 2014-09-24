#include <iostream>
using namespace std;

void sumar(int a, int b);
void restar(int a, int b);
void multiplicar(int a, int b);
void dividir(int a, int b);
void ingresa_valores();
int a,b, resultado;

int main(int argc, char *argv)
{
    for(;;)
    {
    int resultado, op;
    system("cls");
ingresa_valores();

cout << "\n\n" 
     << "[1]- Sumar"
     << "\n[2]- Restar"
     << "\n[3]- Multiplicar"
     << "\n[4]- Dividir"
     << "\n\nSeleccione: ";
cin >>  op;
switch(op)
{
      case 1: sumar(a,b);
      break;
      case 2: restar(a,b);
      break;
      case 3: multiplicar(a,b);
      break;
      case 4: dividir(a,b);
      break;
      default: "\nOpción invalida. ";
      break;
}
cin.get();
cin.get();
}
return 0;
}

void ingresa_valores()
{
    cout << "Ingrese el primer valor: ";
    cin  >> a; 
    cout << "Ingrese el segundo valor: ";
    cin  >> b;
}
void sumar(int a, int b)
{
resultado=a+b;
cout << "El resultado es: " << resultado;
}
void restar(int a, int b)
{
    resultado = a-b;
cout << "El resultado es: " << resultado;
}
void multiplicar(int a, int b)
{
    resultado = a*b;
cout << "El resultado es: " << resultado;
}
void dividir(int a, int b)
{
    resultado=a/b;
    cout << "El resultado es: " << resultado;
}
