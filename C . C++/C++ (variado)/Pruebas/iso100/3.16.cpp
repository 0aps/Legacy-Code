#include <iostream>

using namespace std;

int main()
{
    string articulo;
    int pArticulo,cuantos;
    float pb;
    
    cout << "Cual articulo quieres?" << endl;
    getline(cin, articulo);
    cout << "Cuanto cuesta? " << endl;
    cin >> pArticulo;
    cout << "Cuantas unidades quieres de " << articulo << "? " << endl;
    cin >> cuantos;
    
    pb = ( (pArticulo*cuantos) * 0.15);
    if( pb > 50000) pb *=  0.5;
    
    cout << "Compraste " << cuantos << " " << articulo << " en: "
         << pb << endl;
         
    
    setbuf(stdin, NULL);
    cin.get();
    
    return 0;
}
    
