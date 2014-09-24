#include <iostream>

int main()
{
    short int t;
    std::string num;
    
    std::cin >> t;
    std::cin.ignore();
    std::cin.clear();
    
    while(t--)
    {
              std::getline(std::cin, num);
              
              if(num.at(num.length()-1) == '0' || num.at(num.length()-1) == '5' )
                                      std::cout << "YES" << std::endl;
              else
                                      std::cout << "NO" << std::endl;
    }
    
    std::cin.get();
    return 0;
}
