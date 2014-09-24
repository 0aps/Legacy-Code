#include <iostream>

int main()
{
    int suma(0);
    for(int i(2); i<= 20; i+=2) suma+=i;
    
    std::cout << suma;
    std::cin.get();
    return 0;
}
