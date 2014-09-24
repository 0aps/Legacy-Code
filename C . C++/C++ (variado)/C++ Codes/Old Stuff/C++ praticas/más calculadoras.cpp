#include <iostream> // <> 
using namespace std;

int main(){
    int suma[2], resta[2], mult[2], div[2];
    int i, op;
    while(1){
        system("cls");
cout << "Bienvenido\n" << endl;
cout << "Que deseas hacer:\n " << endl;
cout << "1.Sumar " << endl;
cout << "2.Restar "<< endl;
cout << "3.Multiplicar "<< endl;
cout << "4.Dividir "<< endl;
cout << "5.Salir "<< endl;
cin >> op;
switch (op){
case 1:
    cout << "Primer numero:  " ;
    cin >> suma[0];
    cout << "Segundo numero: " ;
    cin >> suma[1];
   cout << "El resultado es: " << suma[0]+suma[1] << endl;
   system("pause>nul");
   break;
case 2:
    cout << "Primer numero : " ;
    cin >> resta[0];
    cout << "Segundo numero: " ;
    cin >> resta[1];
    cout << "El resultado es: " << resta[0]-resta[1] << endl;
    system("pause>nul");
    break;
case 3: 
    cout << "Primer numero : " ;
    cin >> mult[0];
    cout << "Segundo numero: " ;
    cin >> mult[1];
    cout << "El resultado es: " << mult[0]*mult[1] << endl;
    system("pause>nul");
    break;
case 4:
    cout << "Primer numero : " ;
    cin >> div[0];
    cout << "Segundo numero: ";
    cin >> div[1];
    cout << "El resultado es: " << div[0]/div[1] << endl;
    system("pause>nul");
    break;
default:
    cout << "Opcion incorrecta " << endl;
    system("pause>nul");
case 5:
    exit(1);
    break;
    return 1;
}
}
}
    

 
