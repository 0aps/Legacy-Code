#include <iostream>

using namespace std;

int rpow(long long b, long long e)
{
    return (e == 0)? 1 : b*rpow(b,e-1);
}

long long modexpo(long long a,long long b,long long n)
{
    long long d=1;
    while(b)
    {
        if(b%2)
            d=(d*a)%n;
        b>>=1;
        a=(a*a)%n;
    }
    return d;
}

int main()
{
    int x;
    cin >> x;
    
    while (x--)
    {
          long long a, b, rest;
          
          cin >> a >> b;
          
          //rest = rpow(a,b);    
          //rest = rest%10;
          cout << modexpo(a,b,1000000000)  << endl;
    }
    
    cin.get();
    return 0;
}
