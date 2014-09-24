#include <iostream>

using namespace std;

int main()
{
    short t,nums[3],a,b;
    cin >> t;
    while(t--)
    {
              for(short i=0; i<4; i++)
                      cin >> nums[i];
                      
                      a = (nums[2]-nums[0]);
                      b = (nums[3]-nums[1]);
                      
                      if( a < 0 ) a*=-1;
                      if( b < 0 ) b*=-1;
                      
                      cout << a+b << endl;
    }
    
    setbuf(stdin, NULL);
    cin.get();
    
    return 0;
}
                      
