#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double PI = atan(1.0)*4, r,h, sum(0);
    short int t,n;
    
    cin >> t; 
    cin.ignore();
    cin.clear();
    
    while(t--)
    {
              cin >> n;
              while(n--)
              {
                        cin >> r >> h;
                        cin.ignore();
                        cin.clear();
                        sum += PI*pow(r,2)*h;
              }
              cout << setprecision(2) << fixed << sum << endl;
              sum = 0;
    }          
    
    return 0;
}
