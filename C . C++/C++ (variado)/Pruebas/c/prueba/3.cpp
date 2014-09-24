#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    
    int x = atoi(str.c_str());
    
    while(x--){
               
               cout << (str.length()/2) << endl;
               getline(cin,str);
               }
    cin.get();
    return 0;
}
