#include <cstdlib>
#include <iostream>
#include <deque>
 
using namespace std;
 
int main(int argc, char *argv[])
{
    deque<char> v;
    int x; 
 
    // Metemos en la cola v valores desde la 'A' hasta la 'Z'
    // mediante el método push_back.
    for (x = 'A'; x <= 'Z'; x++) v.push_back(x);
 
    // Metemos en la cola v valores desde la '0' hasta la '9'
    // mediante el método push_front.
    for (x = 0; x <= 9; x++) v.push_front(x);
 
    // despliegue de los elementos de la cola
    // mediante el operador [].
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
 
    // despliegue de los elementos del vector v
    // mediante el método at().
    for(int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
 
    cout << endl;        
 
    cin.get();
    return EXIT_SUCCESS;
}

