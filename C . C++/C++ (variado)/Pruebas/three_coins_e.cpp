#include <iostream>
#include <cmath>
#include <iomanip>

#define ATM 3

using namespace std;

int main()
{
    int cc;
    long double radios[3], s, At,As,t, PI = 4*atan(1.0);
    
    cc = 0;
    while( cin >> t )
    {
           radios[cc++] = t/2;
           
           if( cc == ATM )
           {
               long double a = radios[0] + radios[1],
                   b = radios[1] + radios[2],
                   c = radios[2] + radios[0],
                   A,B,C;
               
               s   = (a+b+c)/2;
               At  = sqrt( s*(s-a)*(s-b)*(s-c) );
               
               A =  acos( ( -1*pow(a,2) + pow(b,2) + pow(c,2) )/ (2*b*c) );
               B =  acos( ( -1*pow(b,2) + pow(a,2) + pow(c,2) )/ (2*a*c) ) ;
               C =  acos( ( -1*pow(c,2) + pow(a,2) + pow(b,2) )/ (2*a*b) ) ;
               
               As = A*pow(radios[2],2)/2;
               At -= As;
               As = B*pow(radios[0],2)/2;
               At -= As;
               As = C*pow(radios[1],2)/2;
               At -= As;
               
               cout << setprecision(13) << fixed << At << endl;
               cc = 0;
           }          
    } 
    
    return 0;
}
       
