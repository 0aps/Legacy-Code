//nota: los numeros romanos que son en minuscula, es su valor mas 3 ceros
//I=1, i=1,000
//V=5, v=5,000
//X=10, x=10,000
//L=50, l=50,000
//C=100, c=100,000
//D=500, d=500,000
//M=1,000, m=1,000,000
#include<stdio.h>
#include<conio.h>
int ciclo(void)
{
char s;
int d,c;
s=getch();
d=1;
	while(d==1)
   	{
      if(s==char(13))
      	{
         c=1;
         d=2;
         }
      if(s==char(27))
      	{
         d=2;
         c=2;
         }
      if(s!=char(13)&&s!=char(27))
      	{
         d=1;
         }
      }
   return (c);
}
void decimas(int a, int b)
{
switch (b)
{
case 1:
printf("X");
break;
	case 2:
	printf("XX");
	break;
		case 3:
		printf("XXX");
		break;
			case 4:
			printf("XL");
			break;
				case 5:
				printf("L");
				break;
					case 6:
   				printf("LX");
   				break;
   					case 7:
      				printf("LXX");
      				break;
      					case 8:
         				printf("LXXX");
         				break;
								case 9:
								printf("XC");
								break;
}
switch (a)
{
case 1:
printf("I");
break;
	case 2:
	printf("II");
	break;
		case 3:
		printf("III");
		break;
			case 4:
			printf("IV");
			break;
				case 5:
				printf("V");
				break;
					case 6:
					printf("VI");
					break;
						case 7:
                  printf("VII");
						break;
							case 8:
							printf("VIII");
							break;
								case 9:
								printf("IX");
								break;
}
}
void centenas(int b)
{
switch (b)
{
case 1:
printf("C");
break;
	case 2:
	printf("CC");
	break;
		case 3:
      printf("CCC");
		break;
			case 4:
			printf("CD");
			break;
				case 5:
				printf("D");
				break;
            	case 6:
               printf("DC");
               break;
               	case 7:
                  printf("DCC");
                  break;
                  	case 8:
                     printf("DCCC");
                     break;
                     	case 9:
                        printf("CM");
                        break;
}
}
void millares(int b)
{
switch (b)
{
case 1:
printf("M");
break;
	case 2:
   printf("MM");
   break;
		case 3:
   	printf("MMM");
   	break;
      	case 4:
         printf("iv");
         break;
         	case 5:
            printf("v");
            break;
            	case 6:
               printf("vi");
               break;
               	case 7:
                  printf("vii");
                  break;
                  	case 8:
                     printf("viii");
                     break;
								case 9:
                        printf("ix");
                        break;
}
}
void dmillares(int b)
{
switch (b)
{
case 1:
printf("x");
break;
	case 2:
   printf("xx");
   break;
   	case 3:
      printf("xxx");
      break;
      	case 4:
         printf("xl");
         break;
         	case 5:
            printf("l");
            break;
            	case 6:
               printf("lx");
               break;
               	case 7:
                  printf("lxx");
                  break;
                  	case 8:
                     printf("lxxx");
                     break;
                     	case 9:
                        printf("xc");
                        break;
}
}
void ddmillares(int b)
{
switch (b)
{
case 1:
printf("c");
break;
	case 2:
   printf("cc");
   break;
   	case 3:
      printf("ccc");
      break;
      	case 4:
         printf("cd");
         break;
         	case 5:
            printf("d");
            break;
            	case 6:
               printf("dc");
               break;
               	case 7:
                  printf("dcc");
                  break;
                  	case 8:
                     printf("dccc");
                     break;
                     	case 9:
                        printf("cm");
                        break;
}
}
void numerosromanos(void)
{
char s;
int a,b,c=1,d;
clrscr();
textcolor(12);
gotoxy(34,11);cprintf("NUMEROS ROMANOS");
textcolor(9);
gotoxy(22,13);cprintf("presiona cualquier tecla para comenzar");
getch();
clrscr();
while(c==1)
{
clrscr();
printf("\n\nNOTA: los numeros romanos que son minuscula, es su valor mas 3 ceros");
printf("\n\nI=1, i=1,000\nV=5, v=5,000\nX=10, x=10,000\nL=50, l=50,000\nC=100, c=100,000\nD=500, d=500,000\nM=1,000, m=1,000,000");
printf("\n\ninserta un numero del 1 al 1,000,000: ");
scanf("%i",&a);
if(a>=1&&a<=99)
{
textcolor(9);
cprintf("\nNUMERO RONAMO: ");
b=a/10;
a=a%10;
decimas(a,b);
printf("\n\nsi quieres introducir otra cantidad presiona enter\nsi quieres salir presiona esc");
c=ciclo();
}
if(a>=100&&a<=999)
{
textcolor(9);
cprintf("\nNUMERO RONAMO: ");
b=a/100;
a=a%100;
centenas(b);
b=a/10;
a=a%10;
decimas(a,b);
printf("\n\nsi quieres introducir otra cantidad presiona enter\nsi quieres salir presiona esc");
c=ciclo();
}
if(a>=1000&&a<=9999)
{
textcolor(9);
cprintf("\nNUMERO RONAMO: ");
b=a/1000;
a=a%1000;
millares(b);
b=a/100;
a=a%100;
centenas(b);
b=a/10;
a=a%10;
decimas(a,b);
printf("\n\nsi quieres introducir otra cantidad presiona enter\nsi quieres salir presiona esc");
c=ciclo();
}
if(a>=10000&&a<=99999)
{
textcolor(9);
cprintf("\nNUMERO RONAMO: ");
b=a/10000;
a=a%10000;
dmillares(b);
b=a/1000;
a=a%1000;
millares(b);
b=a/100;
a=a%100;
centenas(b);
b=a/10;
a=a%10;
decimas(a,b);
printf("\n\nsi quieres introducir otra cantidad presiona enter\nsi quieres salir presiona esc");
c=ciclo();
}
if(a>=100000&&a<=999999)
{
textcolor(9);
cprintf("\nNUMERO RONAMO: ");
b=a/100000;
a=a%100000;
ddmillares(b);
b=a/10000;
a=a%10000;
dmillares(b);
b=a/1000;
a=a%1000;
millares(b);
b=a/100;
a=a%100;
centenas(b);
b=a/10;
a=a%10;
decimas(a,b);
printf("\n\nsi quieres introducir otra cantidad presiona enter\nsi quieres salir presiona esc");
c=ciclo();
}
if(a==1000000)
{
textcolor(9);
cprintf("\nNUMERO RONAMO: m");
printf("\n\nsi quieres introducir otra cantidad presiona enter\nsi quieres salir presiona esc");
c=ciclo();
}
if(a<0||a>=1000001)
{
c=1;
}
}
}
