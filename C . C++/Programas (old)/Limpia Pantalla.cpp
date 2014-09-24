#include <windows.h>
#include <iostream>

using namespace std;

void ClearScreen();

int main(int argc, char *argv)
{
    cout << "\n\n\n\n\n\t\t\t Hi, hi, hi, hi : =) ";
    cin.get();
    ClearScreen();
    cin.get();
    cout << "\n\n\n\n\n\t\t\t Hi, hi, hi, hi : =) ";
    cin.get();
    return 0;
}


void ClearScreen ()
{
    HANDLE hOut = GetStdHandle ( STD_OUTPUT_HANDLE );
    COORD coord = { 0, 0 };
    DWORD dwcount;
    CONSOLE_SCREEN_BUFFER_INFO csb_i;
    GetConsoleScreenBufferInfo ( hOut, &csb_i );
    FillConsoleOutputCharacter ( hOut, '  ',
    csb_i.dwSize.X * csb_i.dwSize.Y, coord, &dwcount );

    SetConsoleCursorPosition ( hOut, coord );
   
}

