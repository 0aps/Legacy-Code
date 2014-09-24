#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, i;
    printf("Ingrese un Numero: ");
    scanf("%i", &numero);
    for(i=0; i<1000000000; i++)
    {
       printf("el numero que ingresaste es %i\n", numero);
    }
    system("pause");
}
