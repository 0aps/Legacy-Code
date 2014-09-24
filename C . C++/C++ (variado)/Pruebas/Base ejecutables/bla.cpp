#include <stdio.h>

int rpow(int b, int e)
{
    return (!e)? 1 : b*rpow(b, e-1);
}

int main()
{
    int c;
    c = 1230456789%rpow(10,10-3);
    
    printf("%.d", c);
    getchar();
    return 0;
}
