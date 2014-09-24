#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Ingrese un Numero: ");
    scanf("%i", &numero);
    if(numero>0)
    {
       printf("el numero es positivo\n");
    }
    else if(numero>0)
         {
             printf("el numero es negativo\n");
         }
         else
             {
                 printf("el numero es neutro\n");
             }
    system("pause");
}
