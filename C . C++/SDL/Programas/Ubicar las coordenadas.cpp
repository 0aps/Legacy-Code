#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
   COORD coord; 
while(1)
{
   cout << "Introdusca la coordenada x: ";
   cin >> coord.X;
   cout << endl 
        << "Introdusca la coodenada y: ";
   cin  >> coord.Y;
   
   setbuf(stdin, NULL);
   system("cls");
   
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
   cin.get();
   
   coord.X = 0;
   coord.Y = 0;    
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
   
   
} 
    
    return 0;
}
