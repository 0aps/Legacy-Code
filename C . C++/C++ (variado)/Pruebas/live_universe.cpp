#include <iostream>

int main()
{
    int x;
    
    while( std::cin >> x)
    {
           if(x == 42)break;
           else
           std::cout << x << std::endl;
    }
    
    std::cin.get();
    return 0;
}
