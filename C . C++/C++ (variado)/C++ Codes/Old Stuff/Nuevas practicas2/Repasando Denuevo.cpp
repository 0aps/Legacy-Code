# include <stdio.h>
# include <stdlib.h>
int main()
{
int notas[4];
int i;
printf("Ingresa todas tus notas aca. \n\n");
for (i=o; i<4; i++)
{
printf("Notas %i: ", i+1);
scanf("%i", &notas[i]);
}
printf("\nLas notas que ingresate son: ");
for (i=0; i<4; i++)
{
printf("%i ", notas[i]);
}
printf("\n\n");
system("pause");
}
