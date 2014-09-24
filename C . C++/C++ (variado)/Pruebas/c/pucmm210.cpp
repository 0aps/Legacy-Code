#include <iostream>
//suma parcial de una sucesion aritmetica
//S = (a1 + an)n/2

using namespace std;

int rpow(unsigned long long b, unsigned long long e)
{
    return (e == 0)? 1 : b*rpow(b,e-1);
}

int main()
{
    int x;
    cin >> x;
    
    while (x--)
    {
          unsigned long long a,rest(0);
          cin >> a;
          
          for(unsigned long long aux(1),b=1; b<=a; b++)
          {
                   aux  = ((1+b)*b)/2;
                   aux  = rpow(aux,2);
                   rest += aux;
          }
          cout << fixed << rest << endl;
          
    }
    
    cin.get();
    return 0;
}
