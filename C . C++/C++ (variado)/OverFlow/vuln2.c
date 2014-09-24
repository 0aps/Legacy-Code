#include <stdio.h>

void funcion(int a, int b, int c)
{
     char buffer1[5];
     char buffer[10];
     int *ret;
     
     ret = buffer1 + 13;
     (*ret) += 8;
}

void main()
{
int x;
 
 x = 0;
 funcion(1,2,3);
 x = 1;
 
 printf("%d\n",x);
}     
