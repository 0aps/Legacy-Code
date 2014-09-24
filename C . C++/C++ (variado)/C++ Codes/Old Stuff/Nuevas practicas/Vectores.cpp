# include <stdio.h>
# include <stdlib.h>
int main()
{
int notas[4];
printf("Ingresa todas tus notas acá.\n");
printf("\nPrimera nota: ");
scanf("%i", &notas[0]);
printf("\nSegunda nota: ");
scanf("%i", &notas[1]);
printf("\nTercera nota: ");
scanf("%i", &notas[2]);
printf("\nCuarta nota: ");
scanf("%i", &notas[3]);
printf("\n\nLas notas que ingresaste son %i, %i, ", notas[0], notas[1]);
printf("%i, %i, \n\n", notas [2], notas[3]);
system("pause");
}

