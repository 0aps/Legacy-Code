#include <stdio.h>
#include <windows.h>
 
int main()
{
    int num=500;
    SetConsoleTitle("Hackme");
    while(1)
    {
        printf("%i, %p", num, &num);
        getchar();
        num++;
    }
    return 0;
}
