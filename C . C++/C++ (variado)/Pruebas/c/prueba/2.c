#include <stdio.h>
#include <string.h>

int main()
{
    
 char test[300];
 char test2[300];
 
      short x = 10;  //1010
      short p = ~x;   //0101
      
      itoa (x,test,2); 
      itoa (p,test2,2); 
  long long a = 2;
          printf("%lld",a>>1);    
//      printf("%i -> %s, %i -> %s", x, test, p, test2);
 
    setbuf(stdin, NULL); 
    getchar();
    return 0;
}
