#include <iostream>

using namespace std;

//@aps

int main()
{
  int *arrey = new int;
  int x(0), j(0);
  
  for(int x(1);  x < 1000; x++)
  {
          if( !(x%3) || !(x%5) )
          {
               arrey[j] =  x;
               j++;
          }
  }
  
  for(int i = 0; i < j; i++)
  {
          cout << "Los multiplos son: " << arrey[i] << endl;
          x += arrey[i] ;
  }
   
    cout << "El resultado total es: " << x << endl;  
        
    cin.get();
    
    delete arrey;
    return 0;
}
