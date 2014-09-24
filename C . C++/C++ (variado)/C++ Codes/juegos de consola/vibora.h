#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
void viborita(int x,int y)
{
int c;
c=254;
textcolor(9);
gotoxy(x,y);cprintf("%c",c);
}
int segundonivel(int x,int y,int b)
{
int m,n,i;
m=31;n=5;
for(i=0;i<20;i++)
	{
   	if(x==m&&y==n)
      	{
   		x=100;
         }
   gotoxy(m,n);printf("#");
   m++;
   }
m=31;
for(i=0;i<20;i++)
	{
   n=20;
   	if(x==m&&y==n)
      	{
   		x=100;
         }
   gotoxy(m,n);printf("#");
   m++;
   	if(b>=20)
      	{
          n=12;
          if(x==m&&y==n)
      	{
   		x=100;
         }
          gotoxy(m,n);printf("#");
         }
   }
return (x);
}
int primernivel(int x, int y,int b)
{
int m,n,i;
n=7;
for(i=0;i<10;i++)
	{
   m=20;
   if(x==m&&y==n)
   	{
      x=100;
      }
   gotoxy(m,n);printf("#");
   n++;
   if(b>=15)
   	{
      m=10;
      if(x==m&&y==n)
      	{
   		x=100;
         }
      gotoxy(m,n);printf("#");
      }
   }
n=7;
for(i=0;i<10;i++)
	{
   m=60;
   if(x==m&&y==n)
   	{
      x=100;
      }
   gotoxy(m,n);printf("#");
   n++;
   if(b>=15)
   	{
      m=70;
      if(x==m&&y==n)
      	{
   		x=100;
         }
      gotoxy(m,n);printf("#");
      }
   }
   return (x);
}
void instrucciones1(void)
{
char a;
clrscr();
textcolor(9);
gotoxy(34,3);cprintf("INSTRUCCIONES\n\n");
printf("1- El proposito de el juego es obtener la mayor cantidad de caritas\n2- Utiliza las flechas para mover la viborita\n3- Al tocar el limite de la pantalla se acaba el juego\n4- Puedes pausar el juego utilizando la tecla enter y presiona cualquier flecha para reanudar el juego\n5- cada 5 puntos sube 1 nivel\n");
gotoxy(21,14);cprintf("-Presiona enter para comenzar el juego");
a=getch();
if(a==char(13))
	clrscr();
}
int dificultad(void)
{
	int l;
	clrscr();
   textcolor(9);
   gotoxy(33,3);cprintf("Elige dificultad\n\n");
   printf("\nmuy facil: presiona 1\n\nfacil: presiona 2\n\nmedio: presiona 3\n\ndificil: presiona 4\n\nmuy dificil presiona 5\n\nextremo: presiona 6\n\n");
   printf("elige: ");
   scanf("%i",&l);
   switch (l)
   	{
      	case 1:
         l=180;
         break;
         case 2:
         l=130;
         break;
         case 3:
         l=90;
         break;
         case 4:
         l=40;
         break;
         case 5:
         l=20;
         break;
         case 6:
         l=7;
         break;
      }
   return (l);
}
void vibora(void)
{
char a,c,z;
int b,d,m,n,x,y,l,h,t,r;
x=40;d=1;y=12;m=30;n=10;r=3;
while(d==1)
{
r=3;
clrscr();
textcolor(12);
gotoxy(36,12);cprintf("VIBORITA");
textcolor(9);
gotoxy(21,14);cprintf("-Presiona enter para comenzar el juego");
gotoxy(20,16);cprintf("-Para leer las instrucciones presiona esc");
z=getch();
if(z==char(27))
	instrucciones1();
if(z==char(13))
	clrscr();
b=0;
l=dificultad();
clrscr();
while(x>=1&&y>=1&&x<=80&&y<=24)
{
textcolor(11);
gotoxy(49,25);printf("esc para salir");
gotoxy(65,25);cprintf("puntaje: %i",b);
textcolor(14);
switch (l)
   	{
      	case 180:
         gotoxy(3,25);cprintf("dificultad: muy facil");
         break;
         case 130:
         gotoxy(3,25);cprintf("dificultad: facil");
         break;
         case 90:
         gotoxy(3,25);cprintf("dificultad: normal");
         break;
         case 40:
         gotoxy(3,25);cprintf("dificultad: dificil");
         break;
         case 20:
         gotoxy(3,25);cprintf("dificultad: muy dificil");
         break;
         case 7:
         gotoxy(3,25);cprintf("dificultad: extremo");
         break;
      }
textcolor(13);
if(b>=0&&b<=4)
	{
   gotoxy(38,25);cprintf("nivel 1");
   }
if(b>=5&&b<=9)
	{
   gotoxy(38,25);cprintf("nivel 2");
   }
if(b>=10&&b<=14)
	{
   gotoxy(38,25);cprintf("nivel 3");
   }
if(b>=15&&b<=19)
	{
   gotoxy(38,25);cprintf("nivel 4");
   }
if(b>=20)
	{
   gotoxy(38,25);cprintf("nivel 5");
   }
if(b>=5)
	{
   x=primernivel(x,y,b);
   }
if(b>=10)
	{
   x=segundonivel(x,y,b);
   }
gotoxy(m,n);printf("%c",2);
viborita(x,y);
Sleep(l);
while(kbhit())
{
a=getch();
switch(a)
	{
   case char(80):
   clrscr();
   break;
   case char(72):
   clrscr();
   break;
   case char(75):
   clrscr();
   break;
   case char(77):
   clrscr();
   break;
   }
}
switch (a)
	{
   case char(27):
   x=100;d=2;
	case char(80):    //abajo
   y++;
   t=y;
   t=t-r;
   if(x==m&&y==n)
   	{
      r++;
      }
   gotoxy(x,t);printf(" ");
   break;
	case char(72):   //arriba
   y--;
   t=y;
   t=t+r;
   if(x==m&&y==n)
   	{
      r++;
      }
      if(t>=25)
   	{
      t=24;
      }
   gotoxy(x,t);printf(" ");
   break;
	case char(75):   //izquierda
   x--;
   t=x;
   t=t+r;
   if(x==m&&y==n)
   	{
      r++;
      }
   gotoxy(t,y);printf(" ");
   break;
	case char(77):   //derecha
   x++;
   t=x;
   t=t-r;
   if(x==m&&y==n)
   	{
      r++;
      }
   gotoxy(t,y);printf(" ");
   break;
   }
if(x==m&&y==n)
	{
   b++;
   randomize();
	m=random(80);
	n=random(25);
   }
if(m==0||n==0)
   	{
      m=random(80);
		n=random(25);
      }
if(m==0||n==0)
   	{
      m=random(80);
		n=random(24);
      }
if(b>=5)
	{
   	if(m==20||m==60)
      	{
         m=random(80);
			n=random(24);
         }
   }
if(b>=20)
	{
   	if(n==5||n==23)
      	{
         m=random(80);
			n=random(24);
         }
   }
if(b>=30)
	{
   	if(m==10||m==70)
      	{
         m=random(80);
			n=random(24);
         }
   }
if(b>=40)
	{
   	if(n==12)
      	{
         m=random(80);
			n=random(24);
         }
   }
}
clrscr();
gotoxy(19,12);printf("presiona una tecla para ver tu puntaje");
getch();
clrscr();
gotoxy(19,12);printf("presiona otra tecla para ver tu puntaje");
getch();
clrscr();
gotoxy(32,12);printf("TU PUNTAJE ES: %i\n",b);
gotoxy(17,14);printf("-Si quieres volver al menu principal presiona enter\n");
gotoxy(17,16);printf("-Si quieres salir presiona cualquier otra tecla\n");
a=getch();
if(a==char(13))
	{
   	x=40;
      y=12;
      d=1;
   }
else
	{
   x=100;
   d=2;
   }
}
}
