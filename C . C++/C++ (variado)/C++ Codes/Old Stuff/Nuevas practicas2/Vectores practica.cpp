#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
int notas[4];
int i,a;

printf("@********************************************************@\n");
printf(" @ *****    *    *     ***** *    *  *         *        @\n");
printf(" @ *       *-*   *     *     *    *  *        *-*       @\n");
printf(" @ *      *   *  *     *     *    *  *       *   *      @\n");
printf(" @ ***** *     * ***** ***** ******  ****** *     *     @\n");
printf("@********************************************************@\n");

printf("..................................\nCalcula tu Promedio\n..................................\n\n");
printf("Bienvenido\n\n");
printf("Que deceas hacer?\n\n");
printf("1.Calcular Tu promedio \n2.Salir\n\n");
scanf("%i", &a);
switch (a) {
    
case 1:
for(i=0; i<4; i++)
{
printf("Nota %i: ", i+1);
scanf("%i", &notas[i]);
}
printf("Tu promedio es: %i\n\n", notas[i]);
system("pause");

break;

case 2:
system("pause");
system("exit");
break;

default:
    printf("Opcion incorrecta");
    printf("\nVuelva a elegir");
    system("pause>nul");

}
}

