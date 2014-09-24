#include <conio.h>
#include <iostream>

int main()
{
    int i;
    while ( i != 27)
    {
    std::cout << (char)getch() << "\t";
    if(getch() == 27)
    i=27;
    //std::cin.get();
    }
return 0;
}

// while(getch() != 27) mas efectivo :toma:
