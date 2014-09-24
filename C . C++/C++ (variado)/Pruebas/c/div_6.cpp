#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int t,sum(0),even;
    string num;
    stringstream ss;
    
    cin >> t;
    cin.ignore();
    cin.clear();
    while(t--)
    {
              getline(cin, num);
              ss.clear();
              for(int i(0),aux; i < num.length(); i++,ss.clear())
              {
                      ss << num.at(i);
                      ss >> aux;
                      sum+=aux;
              }
    ss << num.at(num.length()-1);
    ss >> even;
    
     if( !(even%2) && !(sum%3) )
                   cout << "YES" << endl;
     else
                   cout << "NO" << endl;
     sum=0;
     }
     
     cin.get();
     return 0;
}
    
              
              
