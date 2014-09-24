#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    char c;
    std::fstream file("numeros.txt", std::ios::in);
    std::stringstream ss;
    std::string hi;
        
    while( 1 ) ss << file.rdbuf(), ss >> hi, std::cout << hi << std::endl,std::cin.get();
    
    setbuf(stdin, NULL);
    std::cin.get();
    return 0;
}
    
