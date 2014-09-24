#include <iostream>
using namespace std;

//Uso de la función while y do while

int main(){
    int a;
    do{
    cout << "A vale 0, dale valor entre el 1 al 10: ";
    cin >> a;
    }
    while ((a > 10) || (a<1));
    cout << "A vale " << a; 
    system("pause>nul");
    return 1;
}
