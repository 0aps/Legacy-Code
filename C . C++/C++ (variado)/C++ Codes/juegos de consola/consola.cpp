#include<stdio.h>
#include<conio.h>
#include"vibora.h"
#include"carros.h"
#include"naves.h"
#include"carros color.h"
#include"numeros romanos.h"
#include"magia.h"
#include"sudoku nuevo.h"
#include"gato.h"
void main(void)
{
int a;
while(a!=0)
{
clrscr();
textcolor(9);
gotoxy(34,2);cprintf("ARCADE BRETALERA");
textcolor(13);
gotoxy(24,2);cprintf("----------");
gotoxy(50,2);cprintf("----------");
gotoxy(1,5);printf("Elige un juego de la lista:");
printf("\n\n1- vibora\n2- carros\n3- carros multicolor\n4- naves\n5- sudoku\n6- magia\n7- numeros romanos\n8- gato\n\n0- salir del programa");
printf("\n\nelige: ");
scanf("%i",&a);
switch (a)
	{
   case 1:vibora();break;
   case 2:carros();break;
   case 3:carroscolor();break;
   case 4:naves();break;
   case 5:sudoku();break;
   case 6:magia();break;
   case 7:numerosromanos();break;
   case 8:gato();break;
   default:
   printf("\n\ngracias por utilizar este programa\n\n");
   printf("hecho por tadeo gonzalez ^^\n\n");
   printf("pulsa cualquier tecla para salir");
   getch();
   }
}
}