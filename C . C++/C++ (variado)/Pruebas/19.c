#include <stdio.h>

void foo(int** a)
{
   int *hola = (int *)malloc(sizeof(int));
   *hola = 15;     
    *(*a) = 80  ;
    }

int main()
{
    int *b = (int*)malloc(sizeof(int));
    *b = 10;
    foo(&b);
    printf("%d", *b);
    getchar();
    return 0;
}    

