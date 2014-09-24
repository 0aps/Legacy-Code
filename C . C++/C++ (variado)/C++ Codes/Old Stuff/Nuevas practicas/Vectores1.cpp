# include <stdio.h>
# include <stdlib.h>
int main()
{
int notas[10];
int i;
printf("Ingresa todas tus notas aca. \n\n");
for (i=0; i<10; i++)
{
printf("Notas %i: ", i+1);
scanf("%i", &notas[i]);
}
printf("\nLas notas que ingresate son: ");
bool terminado = false ;
terminado = i == 10 ;
for (i=0; i<10; i++)
{
printf("%i", notas[i]);
if(terminado) printf("."); else printf(",");
}
printf("\n\n");
system("pause");
}
