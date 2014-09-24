// Compile: cl key.cpp
#pragma comment( lib, "user32.lib" ) 
#include <windows.h>
#include <WinAble.h> // Required for the SendInput function
int main(void)
{
   INPUT Input;                 // Se declara una estructura tipo IMPUT;
   static unsigned long X,Y;    // Variables para las cordenadas X,Y
   
             /* while(1)                        
               {
                       Input.type = INPUT_MOUSE;  //Tipo del imput : INPUT_MOUSE, INPUT_KEYBOARD, INPUT_HARDWARE
                       Input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE; // Movimientos del mouse : MOUSEEVENTF_LEFTDOWN,  MOUSEEVENTF_LEFTUP
                       Input.mi.dx = (GetSystemMetrics(SM_CXSCREEN) -1);// Posición X
                       Input.mi.dy = (GetSystemMetrics(SM_CYSCREEN) -1);// Posición Y
                       SendInput(true, &Input, sizeof(Input)); //Se envia el Input
                       if(GetAsyncKeyState(VK_INSERT)&1)
                       break;
               }*/
                keybd_event
               
               
               
return 0;
}


/*
Input.type = INPUT_KEYBOARD;
Input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
Input.ki.wVk = VK_SNAPSHOT;
SendInput(true, &Input, sizeof(Input));
*/
