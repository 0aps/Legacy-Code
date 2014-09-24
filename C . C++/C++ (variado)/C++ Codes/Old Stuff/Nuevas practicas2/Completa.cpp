#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10;
    int b=90;
    int c=a+b;
    printf("La suma de %i, mas %i, es igual a: %i\n", a,b,c);
    system("pause>nul\n");
    
    int A=100;
    int B=200;
    printf("\nEl resusltado de tu operación es: %i\n", A+B);
    system("pause");
    
    int numero;
    int numero2;
    printf("\nEscriba el primer numero de su operacion: ");
    scanf("%i", &numero);
    printf("\nEscriba el Segundo numero de su operacion: ");
    scanf("%i",&numero2);
    printf("\nLa suma de sus valores es igual a %i.\n ", numero+numero2);
    system("pause");
    
    int variable;
    printf("\nDi un numero al Azar: ");
    scanf("%i", &variable);
    printf(" El numero dicho es %i\n", variable);
    system("pause");

    int Numero;
    printf("Ingrese un Numero al Azar: ");
    scanf("%i", &Numero);
    if(Numero>0)
    {
                printf("El numerno es positivo\n");
    }
    if(Numero<0)
{
    printf("El numero es negativo\n");
}
if(Numero==0)
{
             printf("El numero es neutro\n");
             }
             system("pause");
}
