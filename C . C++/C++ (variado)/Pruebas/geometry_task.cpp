#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a,b,r;
    double PI =  atan(1.0)*4;
    string line;
    cin >> line;
    if( line == "circle")
        cin >> r, cout << setprecision(2) << fixed << (PI)*pow(r,2);
    if( line == "rhombus")
        cin >> a >> b, cout << setprecision(2) << fixed <<(a*b)/2;
    if(line == "triangle")
    {
    /*
     double c,s;
     cin >> b >> a;
     c = pow(b,2) + pow(a,2);
     c = sqrt(c);
     s = (a+b+c)/2;
     s = s*(s-a)*(s-b)*(s-c);
     s = sqrt(s);
     cout << setprecision(2) << fixed << s;
     *//*   double c;
        cin >> b >> a;
        c = pow(a,2) - pow(b/2,2);
        c = sqrt(c);
        cout << setprecision(2) << fixed << (b*c)/2;
        */
    cin >> b >> a;
    cout << setprecision(2) << fixed << (b*a)/2;
    
    }
    cin.ignore();
    
    cin.clear();
    cin.get();
    return 0;
}
