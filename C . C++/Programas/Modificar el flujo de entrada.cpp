#include <iostream>
#include <windows.h>

using namespace std;

char *tomar(char *);
void input();

int main()
{
    char cad[10];
     
    tomar(cad);
    
    if(cad[0] != 0)
    {
     input();
    }
            
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}

char *tomar(char *cad)
{
    DWORD num, modo = 0;
    HANDLE input    = GetStdHandle(STD_INPUT_HANDLE);    
    GetConsoleMode(input,&modo);
    SetConsoleMode(input,modo&~(ENABLE_ECHO_INPUT|ENABLE_LINE_INPUT));
    
    ReadConsole(input,&cad[0],1, &num, NULL);
    SetConsoleMode(input,modo);
  
    return cad; 
}

void input()
{
    keybd_event(VK_SPACE, 0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
                  
}
