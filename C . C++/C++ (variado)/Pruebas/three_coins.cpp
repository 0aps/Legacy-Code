#include <iostream>
#include <cmath>
#define AMT 3

using namespace std;

int main(){
    
    int radios[4], s, At, angulo, As, Ae, t,cc;
    
    cc=0;
    while (cin >> t)
    {
          radios[cc++] = t/2; //radio
          if(cc == AMT)
          {
                    radios[ATM] = radios[0];
                    s = 0;
                    while( cc && cc--)
                    {
                           radios[cc] += radios[cc+1];
                           s += radios[cc];
                    }
                    cc = AMT, s/=2;
                    At = s;
                    
                    while( cc && cc--)
                    {
                           At *= (s-radios[cc]); 
                    }
                    At = sqrt(At);
                    
                    
                    
                    cin.get();
          }
          
    }
    setbuf(stdin, NULL);
    cin.get();
    
    return 0;
}
          
