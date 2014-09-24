#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float x,sum(0);
    
    for(int i=0; i < 12; i++)
            cin >> x, cin.ignore(), cin.clear(), sum+=x;
                
    cout << "$" << setprecision(2) << fixed << sum/12;
    
    cin.get();
    return 0;
}
