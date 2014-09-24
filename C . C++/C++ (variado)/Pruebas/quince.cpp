#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    argv[0] = "pedro maria y jose";
    char *buf = new char[250];
    strcpy(buf, argv[0]);
    
    cout << buf << endl;
    
    *buf = 'a';
    cout << buf << endl;
    
    buf+=2;
    *buf = 'Z';
    
    cout << buf << endl;
       
    cin.get(); 
    return 0;
}
