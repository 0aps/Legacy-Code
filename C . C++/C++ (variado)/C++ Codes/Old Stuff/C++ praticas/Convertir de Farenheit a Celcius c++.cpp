#include <iostream>
using namespace std;
// Farenheit  to Celcius.

int main(int argc, char *argv[])
{
    int f;
    cout << "Farenheit: ";
    cin >> f;
    float c=32-f; 
    float t=c/9*5;
    cout << "Celcius is equal to: " << t;
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
