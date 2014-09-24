#include <stdio.h>

int main()
{
    int n,sum;
    scanf("%d", &n);
    if(n>0)
           {
                sum = ((1+n)*n)/2;
                printf("%d\n",  sum);
           }
    else   
           {
                n*=-1;
                sum = ((1+n)*n)/2;
                printf("%d\n",  ((sum)*-1)+1);      
           }         
    setbuf(stdin, NULL);
    getchar();
    return 0;
}    
