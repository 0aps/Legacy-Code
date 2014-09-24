// Descomprimir numeros en sus factores primos
// 06/06/2011 Angel Ortega

#include <iostream> // biblioteca para uso de cout
using namespace std;

int DescomponerFactoresPrimos(int n); // declaracion de la funcion que descompone los numeros

int main() // funcion principal
{
    bool terminado = false; // variable para indicar si se terminó de utilizar el programa
    int i = 0; // numero que se va a descomponer
    char resp[32]; // respuesta a la pregunta final
    do { // bucle para la descomposicion de primos
        system("CLS"); // limpiar la pantalla
        cout<<"Introduzca el numero que desea descomponer en sus factores primos: ";
        cin>>i; // obtener el numero
        cout<<endl; // nueva linea
        DescomponerFactoresPrimos(i); // funcion para descomponer el numero obtenido
        cout<<"\n"<<"\n"<<"Desea continuar descomponiendo? (si/no): ";
        cin>>resp; // obtener respuesta
    } while((resp[0] == 's' || resp[0] == 'S')); // si la respuesta es si o por lo menos comienza con s continuar descomponiendo
    cout<<endl; // nueva linea
    
    system("PAUSE");
    return 0;
}

int DescomponerFactoresPrimos(int n)
{
    int x = 0; // exponente del factor primo
    
    if(n==2 || n==3 || n==5 || n==7) {cout<<"Numero primo"; return 0;} // numeros primos de una cifra

    for(int i = 2; i <= 9; i++)
    { // bucle para la division del numero en sus factores primos
        if(n%i == 0) 
        { // n divisible entre i
            if(x > 0) cout<<" * "; // separador entre los factores primos
            x = 1; // indicar el exponente del factor primo
            cout<<i; // mostrar el divisor
            n /= i; // dividir entre el factor primo
            while((n%i == 0)) 
            { // si n sigue siendo divisible entre i
                n /= i; // dividir entre el factor primo
                x++; // aumentar la exponente del factor primo
            }
            if(x>1) cout<<"^"<<x; // si hay exponente mostrarlo
        }
    }
    if(x > 0 && n > 9) {cout<<" * "<<n; return 1;} // si el ultimo factor primo es mayor a 9 colocar el multiplicador para separarlo
    if(x > 0 && n != 1) {cout<<n; return 1;} // si el numero final no es igual a 1 agregarlo
    if(x == 0) {cout<<"Numero primo"; return 0;} // si no hay factores primos indicar que el numero es primo
    
    return 0; // no hay factores primos (numero primo)
}
