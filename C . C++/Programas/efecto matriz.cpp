#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{

keybd_event(VK_MENU, 0x038, 0, 0);
keybd_event(VK_RETURN, 0x01c, 0, 0);
keybd_event(VK_RETURN, 0X1c, KEYEVENTF_KEYUP, 0);
keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);

int binary, count;
HWND CurrentWin;
CurrentWin = GetForegroundWindow();
HANDLE consol;
consol = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(consol,FOREGROUND_BLUE);
SetConsoleTitle("Matrix");
while(1)
{
binary = rand();
cout << binary;

SetForegroundWindow(CurrentWin);
count = rand()%200;
if(count<51)
{
cout << " ";
}
}
return 0;
}
