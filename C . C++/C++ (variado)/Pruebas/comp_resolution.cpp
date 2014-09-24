#include <iostream>
#include <cstdlib>

using namespace std;
//la función erase está sobrecargada, erase(1,1), erase(str.begin(), str.end())
//str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

int main()
{
    string input;
    float w,h,c;
    
    while ( getline(cin, input) )
    {
          w = atoi(input.c_str());
          input = input.substr(input.find("x")+1, input.length() );    
          h = atoi(input.c_str());
          c = (4/3.0)/(w/h);
    
          if( c > 1 ) 
                  cout << "Horizontally." << endl;
          else if( c < 1)
                   cout << "Vertically." << endl;
          else cout << "Fill the screen." << endl;
              
    }
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
