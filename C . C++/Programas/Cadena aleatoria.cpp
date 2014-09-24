#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int largo_vector=25;

char *aleatorio(int largo)
{
    int i;
    char *cadena_aleatoria;
    
    srand(time(NULL));
    cadena_aleatoria=new char[largo+1];
    for(i=0;i<largo;i++)
    {
        cadena_aleatoria[i]=rand()%57+65;
    }
    cadena_aleatoria[largo]='\0';
    
    return cadena_aleatoria;
}


int main()
{
    printf("%s", aleatorio(10));
    getchar();
    return 0;
}
