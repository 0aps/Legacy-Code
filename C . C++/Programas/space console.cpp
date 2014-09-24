#include <iostream>
#include <windows.h>

#define A -32767

using namespace std;

void goxy(int x, int y)
{
COORD coord;
coord.X = x; coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{

    int x=14;
    int y=8;

    for(int i=0; i<30; i++)
    cout << "#";
    for(int i=0; i<20; i++)
    cout << "\n#\t\t\t     #";
    cout << endl;
    for(int i=0; i<30; i++)
    cout << "#";

    goxy(14,8);

    while(1)
    {

    if(GetAsyncKeyState(VK_UP) == A) // arriba
        {goxy(x,y); y--;}
    if(GetAsyncKeyState(VK_DOWN) == A)//abajo
        {goxy(x,y); y++;}
    if(GetAsyncKeyState(VK_LEFT) == A)//izquierda
        {goxy(x,y); x--;}
    if(GetAsyncKeyState(VK_RIGHT) == A)//derecha
        {goxy(x,y); x++;}


    if( x == 29) x--;
    if (x == 0 ) x++;
    if (y == 20) y--;
    if (y == 0)  y++;

}

 cin.get();
 return 0;
}
