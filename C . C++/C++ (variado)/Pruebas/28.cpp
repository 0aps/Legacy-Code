#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int a = GetTickCount( );

    cout << GetTickCount( ) << endl;
    Sleep(1000);
    cout << (GetTickCount( ) - a)/1000 << endl; //un segundo

    return 0;
}
