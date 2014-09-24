#include <iostream> // << >>
#include <windows.h>
using namespace std;

int main(int argc, char *argv)
{
    for(int i=99;i>=1; i--)
    {
        cout << i << " Bottles of beer on the wall, " << i << " bottles of beer." << endl;
        cout << "Take one down and pass it around, " << i << " bottles of beer on the wall." << endl << endl;
    Sleep(50);
    }
cout << "\n\nNo more bottles of beer on the wall, mo more bottles of beer \n"
     << "Go to the store and buy some more 99 bottles of beer on the wall";
cin.get();
return 0;
}

