#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
int operacion, suma, suma1, suma2, resta, resta1, resta2, multiplicacion, 
multiplicacion1, multiplicacion2, divicion, divicion1, divicion2;
// Si ya se que se puede simplificar, pero me da igual //
printf("@********************************************************@\n");
printf(" @ *****    *    *     ***** *    *  *         *        @\n");
printf(" @ *       *-*   *     *     *    *  *        *-*       @\n");
printf(" @ *      *   *  *     *     *    *  *       *   *      @\n");
printf(" @ ***** *     * ***** ***** ******  ****** *     *     @\n");
printf("@********************************************************@\n\n");

printf("Bienvenido a la calculadora\n\n\b ");
printf("Que operacion decea realizar?\n\n");
printf("1. Suma \n2. Resta \n3. Multiplicacion \n4. Divicion\n\n");
scanf("%i", &operacion);
switch (operacion){

case 1:
printf("\nDame el primer numero a sumar: ");
scanf("%i",&suma1);
printf("Dame el otro numero a sumar: ");
scanf("%i", &suma2);
suma=(suma1+suma2);
printf("El resultado es: %i", suma);
system("pause>nul");
break;

case 2:
printf("\nDame el primer numero a restar: ");
scanf("%i", &resta1);
printf("Dame el segundo numero a restar: ");
scanf("%i", &resta2);
resta=(resta1-resta2);
printf("El resultado es: %i", resta);
system("pause>nul");
break;

case 3:
printf("\nDame el primer numero a multiplicar: ");
scanf("%i", &multiplicacion1);
printf("Dame el segundo numero a multiplicar: ");
scanf("%i", &multiplicacion2);
multiplicacion=(multiplicacion1*multiplicacion2);
printf("El resultado es: %i", multiplicacion);
system("pause>nul");
break;

case 4:
printf("\nDame el primer numero a dividir: ");
scanf("%i", &divicion1);
printf("Dame el segundo numero a dividir: ");
scanf("%i", &divicion2);
divicion=(divicion1/divicion2);
printf("El resultado es: %i", divicion);
system("pause>nul");
break;
default:
printf("La opcion es incorrecta");
system("pause>nul");
break;
}
}
