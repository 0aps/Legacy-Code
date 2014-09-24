#include <iostream> // 
using namespace std;

int main(int argc, char *argv)
{
    system("color 02");
    int i(1),j;
     
    for(; i <= 20; i++ )
    {
     
     for(j=1; j <= i; j++)
     cout << j << " ";
     
     cout  <<  endl;
   }

setbuf(stdin, NULL);
cin.get();
return 0;
}
