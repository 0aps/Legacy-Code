#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main()
{
    int x,aux;   
    string num;
    
    cin >> x;
    cin.ignore();
    cin.clear();
    while(x--)
    { 
      getline(cin, num);
      stringstream ss;
    
      if(num.length() == 1)
                        ss << num;
      else
      {
            num = num.substr(num.length()-2,num.length());
            ss << num;
      }
      
      ss >> aux;
      if(!(aux%4))
              cout << "YES" << endl;
      else
              cout << "NO" << endl;
    }
    
    return 0;
}
    
