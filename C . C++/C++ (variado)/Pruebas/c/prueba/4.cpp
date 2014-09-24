#include <iostream>

int main()

{
    int nums;
    while(std::cin >> nums && nums != 0)
    {
                   std::cout << nums << std::endl;
                   std::cout << "yes" << std::endl;
    }
    std::cin.ignore();
    std::cin.clear();
    
    return 0;
}
                   
