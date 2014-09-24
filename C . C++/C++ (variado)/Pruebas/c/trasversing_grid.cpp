#include <stdio.h>

int main()
{
    int t;
    unsigned long n,m;
    
    scanf("%d", &t);
    while(t--)
    {
              scanf("%d%d", &n,&m);
                            if(n>m)
                                   if( !(m%2) )
                                       printf("U\n");
                                   else
                                       printf("D\n");
                            else
                                if( n%2 )
                                         printf("R\n");
                                else
                                         printf("L\n");
    }
    return 0;
}
