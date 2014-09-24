#include <stdio.h>

int factorial (int n)
{
    long long factorial = 1;
    while(n >= 1)
    factorial*=n--;
    return factorial;
}
int main()
{
    int n=1;
    scanf("%i",&n);
    printf("%i", factorial(n));
    setbuf(stdin, NULL);
    getchar();
    return 0;
}    
