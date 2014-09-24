#include <iostream>

using namespace std;

class numeros{
      
      int a,b;
      numeros(){ a=0; b=0; };
      
      public:     
      int mayor();
      int leer(int );
};

int numeros::mayor()
{
    return (a>b)? a : b;
}

int numeros::leer(int a)
{
    cin >> a;
    if( x ) x = a;
    else this->a = a; 
}

int main()
{
   numeros num;
   int a,b;
   cout << "Primer numero: ";
        num.leer(a);
   cout << "Segundo numero: ";
        num.leer(b);
   
   cout << "Mayor: ";
        num.mayor(a,b);
   
   setbuf(stdin, NULL);
   cin.get();
   return 0;
}  
