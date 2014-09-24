#include <iostream>
#include <time.h>

//En matemática, la sucesión de Fibonacci es la siguiente sucesión infinita de números naturales:
//   1,1,2,3,5,8,13,21,34,55,89,144 ... 
//La sucesión inicia con 0 y 1, y a partir de ahí cada elemento es la suma de los dos anteriores.

/*
    int main(){
         
    int a(0),b(1),aux(a+b),;   
    
    while(aux<3) // while true.
    {
                cout << a << "," << b << "," << aux << ",";
    a=b+aux;
    b=aux+a;
    aux = a+b;
    }
    
     }
     */
//0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,



using namespace std;
int fiboacci(int);

   int main(){
         
    int a(0),b(1),aux(a+b),;   
    
    while(aux<1000000000) // while true.
    {
                cout << a << "," << b << "," << aux << ",";
    a=b+aux;
    b=aux+a;
    aux = a+b;
    }
    

/*
int main() 
{
//el programa tiene que mosstar todos los numeros menores a n
//que no pertenescan a la serie fiboacci
//@aps
// july 31, 2011

int n(0);
clock_t tStart = clock(); 

cout << ":";
cin >> n;


while(n <= 30000 && n != -1) 
{

if(fiboacci(n)); // si esta en la no hacer nada.
else
cout << endl << n;

n--;
};

    
    cout << "\nTiempo tomado: " << (double)(clock() - tStart)/CLOCKS_PER_SEC;
*/    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}

int fiboacci(int n)
{
int serie[] = { 0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,'\0'};

for(int i(0); i < sizeof(serie)/4; i++)
{
        if( n == serie[i])
           {
              return 1;
           }
}
return 0;
}

