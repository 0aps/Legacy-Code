#include <iostream>
#include <iomanip>
#define PI 3.141592653

using namespace std;

int main()
{
    float num;
    
    while ( cin >> num)
    {
    cout << fixed << setprecision(4) << num*num - (8*(num*num) + 48*(PI/2)*(num/3)*(num/3))/24 << endl;
    }
    
    return 0;
}
