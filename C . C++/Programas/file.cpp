#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    while(1)
    {
  if(GetAsyncKeyState(VK_UP) == -32767)
   cout << "hola"; 
   
   Sleep(35);
}
 cin.get();
 return 0;
}
