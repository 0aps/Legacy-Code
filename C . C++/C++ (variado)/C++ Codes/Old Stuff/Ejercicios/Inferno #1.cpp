// Ejercicio # 1:
// 
// Condiciones
// 
// Condiciones sencillas
// 
// El maestro de la clase de Matemáticas quiere determinar cual es la
// calificación más alta de su grupo, forma grupos de tres calificaciones y las
// captura. Desarrollar un programa en C++, el cual determine el mayor de las
// tres calificaciones, el programa debe mostrar en pantalla la calificación mayor.

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    signed short int a[3],i;
    
    for(i=1; i<=3; i++)
    {
        cout << "Nota " << i << ": ";
        cin >> a[i];
    }
    cout << endl;
    
    for(i=1; i<=3; i++)
    {
        cout << a[i] << "\t";
        if(i==3)
        { cout << "\n\n"; }
    }
    
    if(a[1]>a[2] && a[1]>a[3]){ cout << a[1];}
    if(a[2]>a[1] && a[2]>a[3]){ cout << a[2];}
    if(a[3]>a[1] && a[3]>a[2]){ cout << a[3];}
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}

