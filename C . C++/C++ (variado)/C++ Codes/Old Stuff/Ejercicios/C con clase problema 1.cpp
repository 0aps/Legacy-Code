//   1.  Hacer un programa que lea diez valores enteros en un array desde el teclado 
//   y calcule y muestre: la suma, el valor promedio, el mayor y el menor.
#include <iostream> // << >>

using namespace std;

int main(int argc, char *argv[])
{
    int arrey[10];
    int suma(0),promedio, mayor(0), menor(100000000);
    
    cout << "Ingrese 10 valores. " << endl;
    for(int i=1; i<=10; i++)
    {
    cout << "Valor " << i << ": ";
    cin >> arrey[i];
    suma+=arrey[i];
    if(arrey[i] > mayor)
    mayor = arrey[i];
    if(arrey[i] < menor)
    menor = arrey[i];
    }
    
    for(int a=1; a<=10; a++)
    {
        
    cout << arrey[a];
    if(a<9)
       cout << ",";
        else
       cout << ".";
    
    }
    
    cout << "\n----------------------------------\n";
    cout << "Suma: " << suma;
    cout << "\nPromedio: " << suma/10;
    cout << "\nMayor: " << mayor;
    cout << "\nMenor: " << menor;
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
