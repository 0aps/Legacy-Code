#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void gato(void)
{
int a[3][3],x,y,i,b,d,u,g=0,f=0,l,t,w,c=1;
char h,e,m[10],n[10];
while(c==1)
{
u=2;
clrscr();
textcolor(12);
gotoxy(38,12);cprintf("GATO");
textcolor(9);
gotoxy(20,14);cprintf("-Presiona enter para comenzar el juego");
gotoxy(20,16);cprintf("-Presiona esc para salir del juego");
while(u==2)
	{
   h=getch();
   if(h==char(13))
   	{
      u=1;
      }
   if(h==char(27))
   	{
      u=3;c=2;
      }
   if(h!=char(13)&&h!=char(27))
   	{
      u=2;
      }
   }
if(u==1)
{
clrscr();
textcolor(12);
gotoxy(35,2);cprintf("INTRUCCIONES");
printf("\n\n1-Mueves el cursor con las flechas\n2-El jugador 1 tira con enter\n3-El jugador 2 tira con el backspace <-\n4-Gana el jugador que logre una tercia");
textcolor(9);
gotoxy(20,10);cprintf("-Presiona cualquier tecla para comenzar");
getch();
clrscr();
textcolor(12);
gotoxy(36,2);cprintf("JUGADORES");
textcolor(9);
gotoxy(1,6);cprintf("introduce el nombre de el jugador 1: ");
scanf("%s",&m);
textcolor(12);
gotoxy(1,8);cprintf("introduce el nombre de el jugador 2: ");
scanf("%s",&n);
textcolor(9);
gotoxy(20,10);cprintf("-Presiona cualquier tecla para comenzar");
g=0;f=0;
}
while(u==1)
{
clrscr();
textcolor(9);
gotoxy(1,2);cprintf("puntos de %s: %i",m,g);
textcolor(12);
gotoxy(1,4);cprintf("puntos de %s: %i",n,f);
d=1;
gotoxy(26,11);printf("-----------------------------");
gotoxy(26,16);printf("-----------------------------");
for(y=6;y<22;y++)
{
gotoxy(35,y);printf("|");
gotoxy(45,y);printf("|");
}
for(i=0;i<3;i++)
	{
   	for(b=0;b<3;b++)
      	{
         a[i][b]=0;
         }
   }
x=50;y=19;i=2;b=2;
textcolor(9);
gotoxy(3,12);cprintf("%c %s",254,m);
gotoxy(50,19);
while(d==1)
	{
		while(kbhit())
      	{
				h=getch();
					if(h==char(75))  //izquierda
					{
   					x-=10;b--;
   					gotoxy(x,y);
   				}
					if(h==char(77))  //derecha
					{
   					x+=10;b++;
   					gotoxy(x,y);
   				}
					if(h==char(72)) //arriba
					{
   					y-=5;i--;
   					gotoxy(x,y);
   				}
					if(h==char(80)) //abajo
					{
   					y+=5;i++;
   					gotoxy(x,y);
   				}
            	if(h==char(59))
               {
                d=2;
               }
            	if(h==char(60))
               {
               d=2;u=2;c=1;
               }
   		}
      while(!kbhit())
      	{
         e=getch();
            if(e==char(13))
            	{
               textcolor(9);
               a[i][b]=254;
               cprintf("%c",254);
					textcolor(12);
               gotoxy(3,12);cprintf("               ");
					gotoxy(3,12);cprintf("%c %s",4,n);
               gotoxy(x,y);
               }
            if(e==char(8))
            	{
               textcolor(12);
               a[i][b]=4,
               cprintf("%c",4);
               textcolor(9);
               gotoxy(3,12);cprintf("               ");
               gotoxy(3,12);cprintf("%c %s",254,m);
               gotoxy(x,y);
               }
            l=0;
           for (w=0;w<3;w++)
           	{
            	for(t=0;t<3;t++)
               	{
                  	if(a[w][t]==254||a[w][t]==4)
                     	{
                        l++;
                        }
                  }
            }
            if(l==9)
            	{
               gotoxy(39,23);printf("Gato");gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");d=2;
               }
            if(a[0][0]==254&&a[0][1]==254&&a[0][2]==254||a[0][0]==4&&a[0][1]==4&&a[0][2]==4)
   				{
            textcolor(10);
            gotoxy(30,9);cprintf("%c",a[0][0]);
            gotoxy(40,9);cprintf("%c",a[0][1]);
            gotoxy(50,9);cprintf("%c",a[0][2]);d=2;
            	if(e==char(13)){
               	gotoxy(34,22);printf("%s gana",m);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");g++;}
               if(e==char(8)){
               	gotoxy(34,22);printf("%s gana",n);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");f++;}
      			}
            if(a[1][0]==254&&a[1][1]==254&&a[1][2]==254||a[1][0]==4&&a[1][1]==4&&a[1][2]==4)
   				{
            textcolor(10);
            gotoxy(30,14);cprintf("%c",a[1][0]);
            gotoxy(40,14);cprintf("%c",a[1][1]);
            gotoxy(50,14);cprintf("%c",a[1][2]);d=2;
            	if(e==char(13)){
               	gotoxy(34,22);printf("%s gana",m);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");g++;}
               if(e==char(8)){
               	gotoxy(34,22);printf("%s gana",n);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");f++;}
      			}
            if(a[2][0]==254&&a[2][1]==254&&a[2][2]==254||a[2][0]==4&&a[2][1]==4&&a[2][2]==4)
   				{
      		textcolor(10);
            gotoxy(30,19);cprintf("%c",a[2][0]);
            gotoxy(40,19);cprintf("%c",a[2][1]);
            gotoxy(50,19);cprintf("%c",a[2][0]);d=2;
            	if(e==char(13)){
               	gotoxy(34,22);printf("%s gana",m);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");g++;}
               if(e==char(8)){
               	gotoxy(34,22);printf("%s gana",n);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");f++;}
      			}
            if(a[0][0]==254&&a[1][0]==254&&a[2][0]==254||a[0][0]==4&&a[1][0]==4&&a[2][0]==4)
   				{
            textcolor(10);
            gotoxy(30,9);cprintf("%c",a[0][0]);
            gotoxy(30,14);cprintf("%c",a[1][0]);
            gotoxy(30,19);cprintf("%c",a[2][0]);d=2;
            	if(e==char(13)){
               	gotoxy(34,22);printf("%s gana",m);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");g++;}
               if(e==char(8)){
               	gotoxy(34,22);printf("%s gana",n);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");f++;}
      			}
            if(a[0][1]==254&&a[1][1]==254&&a[2][1]==254||a[0][1]==4&&a[1][1]==4&&a[2][1]==4)
   				{
      		textcolor(10);
            gotoxy(40,9);cprintf("%c",a[0][1]);
            gotoxy(40,14);cprintf("%c",a[1][1]);
            gotoxy(40,19);cprintf("%c",a[2][1]);d=2;
            	if(e==char(13)){
               	gotoxy(34,22);printf("%s gana",m);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");g++;}
               if(e==char(8)){
               	gotoxy(34,22);printf("%s gana",n);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");f++;}
      			}
            if(a[0][2]==254&&a[1][2]==254&&a[2][2]==254||a[0][2]==4&&a[1][2]==4&&a[2][2]==4)
   				{
      		textcolor(10);
            gotoxy(50,9);cprintf("%c",a[0][2]);
            gotoxy(50,14);cprintf("%c",a[1][2]);
            gotoxy(50,19);cprintf("%c",a[2][2]);d=2;
            	if(e==char(13)){
               	gotoxy(34,22);printf("%s gana",m);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");g++;}
               if(e==char(8)){
               	gotoxy(34,22);printf("%s gana",n);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");f++;}
      			}
            if(a[0][0]==254&&a[1][1]==254&&a[2][2]==254||a[0][0]==4&&a[1][1]==4&&a[2][2]==4)
   			{
            textcolor(10);
            gotoxy(30,9);cprintf("%c",a[0][0]);
            gotoxy(40,14);cprintf("%c",a[1][1]);
            gotoxy(50,19);cprintf("%c",a[2][2]);d=2;
            	if(e==char(13)){
               	gotoxy(34,22);printf("%s gana",m);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");g++;}
               if(e==char(8)){
               	gotoxy(34,22);printf("%s gana",n);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");f++;}
      		}
            if(a[2][0]==254&&a[1][1]==254&&a[0][2]==254||a[2][0]==4&&a[1][1]==4&&a[0][2]==4)
   			{
      		textcolor(10);
            gotoxy(30,19);cprintf("%c",a[0][0]);
            gotoxy(40,14);cprintf("%c",a[1][1]);
            gotoxy(50,9);cprintf("%c",a[0][2]);d=2;
            	if(e==char(13)){
               	gotoxy(34,22);printf("%s gana",m);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");g++;}
               if(e==char(8)){
               	gotoxy(34,22);printf("%s gana",n);gotoxy(26,24);printf("Presiona f1 para volver a jugar");gotoxy(15,25);printf("Presiona dos veces f2 para regresar al menu principal");f++;}
      		}
         }
	}
}
}
}
