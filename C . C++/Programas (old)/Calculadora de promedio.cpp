#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
int a,b,c,d,e,f,g;

printf("@********************************************************@\n");
printf(" @ *****    *    *     ***** *    *  *         *        @\n");
printf(" @ *       *-*   *     *     *    *  *        *-*       @\n");
printf(" @ *      *   *  *     *     *    *  *       *   *      @\n");
printf(" @ ***** *     * ***** ***** ******  ****** *     *     @\n");
printf("@********************************************************@\n");

printf("..................................\nCalcula tu Promedio\n..........0........................\n\n");
printf("Bienvenido\n\n");
printf("Que deceas hacer?\n\n");
printf("1.Calcular Tu promedio \n2.Salir\n\n");
scanf("%i", &a);
switch (a) {
    
case 1:
printf("\n Ingresa tu primera nota: ");
scanf("%i", &b);
printf("\n Ingresa tu segunda nota: ");
scanf("%i", &c);
printf("\n Ingresa tu tercera nota: ");
scanf("%i", &d);
printf("\n Ingresa tu cuarta  nota: ");
scanf("%i", &e);
g=b+c+d+e;
printf("\n\n Tu promedio es %i", g/4);
if(g>70)
printf("\n\nFelicidades pasaste");
else
printf("\nDeves estudiar mas");
system("pause>nul");
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

