#include <stdio.h>
#include <conio.h>

void main(){
int op;
float lado1,lado2,radio,res;
const float pi=3.1416;

printf("Menu Areas");
printf("\n\n1. Cuadrado \n2. Rectangulo \n3. Triangulo \n4. Circulo");
printf("\n Elige la opcion deseada");
scanf("%d",&op);
switch (op){

case 1:
printf("Dame la medida del lado");
scanf("%f",&lado1);
res=(lado1*lado1);
printf("El resultado es: %f",res);
break;

case 2:
printf("Dame la medida del lado");
scanf("%f",&lado1);
printf("Dame la medida del segundo lado");
scanf("%f",&lado2);
res=(lado1*lado2);
printf("El resultado es: %f",res);
break;

case 3:
printf("Dame la medida del primer lado");
scanf("%f",&lado1);
printf("Dame la medida del segundo lado");
scanf("%f",&lado2);
res=(lado1*lado2)/2;
printf("El resultado es:%f",res);
break;

case 4:
printf("Dame la medida del radio");
scanf("%f",&radio);
res=(radio*radio)*pi;
printf("El resultado es: %f",res);
break;
}
getch();
return;}


