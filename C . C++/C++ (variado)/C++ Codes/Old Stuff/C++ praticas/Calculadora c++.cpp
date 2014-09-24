#include <iostream>
#include <windows.h>      // <>
using namespace std;
//Calculadora [suma, resta, multiplica y divide]
int main(){
    int s1,s2,r1,r2,d1,d2,m1,m2;
    int op,op2;
    int l, t, t2, i;
    while(1){
    system("cls");
    system("color f2");
cout << "@********************************************************@\n";
cout << " @ *****    *    *     ***** *    *  *         *        @\n";
cout << " @ *       *-*   *     *     *    *  *        *-*       @\n";
cout << " @ *      *   *  *     *     *    *  *       *   *      @\n";
cout << " @ ***** *     * ***** ***** ******  ****** *     *     @\n";
cout << "@********************************************************@\n";

cout << "\nBienvenido!\n\n";
cout << "Que desea hacer?";
cout << "\n\n 1.Sumar\n 2.Restar\n 3.Multiplicar\n 4.Dividir\n 5.Salir\n:";
cin >> op;
switch (op){
    
case 1:
    for(i=0; i<=25; i++)
{
    Sleep(100);
cout << "Û";
}
    cout << "\n\nIngrese el primer numero a sumar: ";
    cin >> s1;
    cout << "Ingrese el segundo numero a sumar: ";
    cin >> s2;
    cout << "La suma de los dos numeros es: " << s1+s2;
    system("pause>nul");
    
    break;
    
case 2: 
    cout << "Ingrese el primer numero a restar: ";
    cin >> r1;
    cout << "Ingrese el segundo numero a restar: ";
    cin >> r2;
    cout << "La resta de los dos numeros es: " << r1-r2;
    system("pause>nul");
    
    break;
    
case 3:   
    system("cls");
    cout << "Que deceas hacer ?\n\n";
    cout << "1. Multiplicar dos numeros?\n2. Usar la tabla\n\n:";
    cin >> op2;
    switch(op2){
/////////////////////////////////////////////////////////////////////////
case 1:
    cout << "Ingrese el primer numero a multiplicar: ";
    cin >> m1;
    cout << "Ingrese el segundo numero a multiplicar: ";
    cin >> m2;
    cout << "La multiplicacion de los dos numeros es: " << m1*m2;
    system("pause>nul");
    break;
/////////////////////////////////////////////////////////////////////////
case 2:
    
cout << "Ingrese la tabla: ";
cin >> t;
cout << "Ingrese el limite: ";
cin >> l;
cout << "\n";
for(i=0; i<=l; i++){
    t2=t*i;
cout << t << " x " << i << " = " <<  t2 << endl;
}
system("pause>nul");
break;
}
    system("pause>nul");
    break;
/////////////////////////////////////////////////////////////////////////
case 4:
    cout << "Ingrese el primer numero a dividir: ";
    cin >> d1;
    cout << "Ingrese el segundo numero a dividir: ";
    cin >> d2;
    cout << "La divicion de los dos numeros es: " << d1/d2;
    system("pause>nul");
   
    break;

case 5:
exit(1);

    default:
    cout << "Opcion incorrecta";
    system("pause>nul");  }
}
}
