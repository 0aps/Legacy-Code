#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main()

{
    system("color 2");
    int i;
    do
    {
cout << "Û" << "Û\t";
Sleep(5);
i++;
}
while (i<=1000);
system("msg * Carga completa");

system("pause>nul");
return 0;
}
