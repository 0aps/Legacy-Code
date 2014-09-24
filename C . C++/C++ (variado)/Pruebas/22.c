#include <stdio.h>

int main()
{
    int *a=NULL;
    
    
    
    
    while( a && *a <= 10)
    {
           printf("%i", a);
           a=0;
    }
           
    getchar();
    return 0;
}
