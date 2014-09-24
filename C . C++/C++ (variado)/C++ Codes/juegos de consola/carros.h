#include<stdio.h>
#include<conio.h>
#include<stdlib>
#include<windows.h>
void instrucciones2(void)
{
clrscr();
textcolor(9);
gotoxy(35,3);cprintf("INSTRUCCIONES");
gotoxy(1,6);printf("1- El proposito de el juego es esquivar los carros enemigos y obtener la mayor   cantidad de puntos\n2- Te mueves con las flechas izquierda y derecha\n3- Cada 60 puntos aumenta un nivel\n4- Puedes poner pausa con la tecla enter y reaunda el juego con cualquier tecla\n5- Tienes 3 vidas\n6- Al chocar con un carro enemigo perderas una vida\n7- El juego acaba cuando chocas 3 veces");
textcolor(9);
gotoxy(19,17);cprintf("-Para comenzar el juego presiona cualquier tecla-");
getch();
clrscr();
}
void enemigoder(int y,int x,int z,int w,int e)
{
gotoxy(41,w);cprintf("*");
gotoxy(40,z);cprintf("***");
gotoxy(41,x);cprintf("*");
gotoxy(40,y);cprintf("***");
gotoxy(40,e);printf("   ");
}
void enemigoizq(int y,int x,int z,int w,int e)
{
gotoxy(35,w);cprintf("*");
gotoxy(34,z);cprintf("***");
gotoxy(35,x);cprintf("*");
gotoxy(34,y);cprintf("***");
gotoxy(34,e);printf("   ");
}
void carroizq(void)
{
textcolor(9);
gotoxy(35,21);cprintf("*");
gotoxy(34,22);cprintf("***");
gotoxy(35,23);cprintf("*");
gotoxy(34,24);cprintf("***");

gotoxy(41,21);printf(" ");
gotoxy(40,22);printf("   ");
gotoxy(41,23);printf(" ");
gotoxy(40,24);printf("   ");
}
void carroder(void)
{
textcolor(9);
gotoxy(41,21);cprintf("*");
gotoxy(40,22);cprintf("***");
gotoxy(41,23);cprintf("*");
gotoxy(40,24);cprintf("***");

gotoxy(35,21);printf(" ");
gotoxy(34,22);printf("   ");
gotoxy(35,23);printf(" ");
gotoxy(34,24);printf("   ");
}
void carros(void)
{
char a,s;
int b,y=-2,x=-1,z=0,w=1,e=-3,r,m=0,d,g,k,n=22,h=22,f=0,p=1,i,t=1,j[3],q=60,u=1,c=2;
j[0]=2;j[1]=3;j[2]=4;
randomize();
while(t==1)
{
while(p==1)
{
y=-2,x=-1,z=0,w=1,e=-3;
m=0;f=0;u=1;q=60;
clrscr();
textcolor(12);
gotoxy(38,12);cprintf("CARRITOS");
textcolor(9);
gotoxy(22,14);cprintf("- Presiona cualquier tecla para comenzar");
gotoxy(22,16);cprintf("- Para ver las instrucciones presiona esc");
s=getch();
if(s==char(27))
	{
   instrucciones2();
   }
clrscr();
textcolor(9);
gotoxy(33,2);cprintf("Elige dificultad");
gotoxy(1,5);printf("Muy facil presiona 1\n\nFacil presiona 2\n\nMedio presiona 3\n\nDificil presiona 4\n\nMuy dificil presiona 5\n\nExtremo presona 6\n\nElige: ");
scanf("%i",&g);
switch (g)
{
case 1:
d=45;
break;
case 2:
d=35;
break;
case 3:
d=25;
break;
case 4:
d=15;
break;
case 5:
d=8;
break;
case 6:
d=2;
break;
}
clrscr();
textcolor(13);
gotoxy(12,3);cprintf("nivel %i",u);
textcolor(11);
gotoxy(50,24);cprintf("puntaje: %i",m);
carroder();
gotoxy(2,10);printf("PRESIONA CUALQUIER TECLA");
gotoxy(5,12);printf("   PARA COMENZAR");
gotoxy(14,14);printf("Y");
gotoxy(7,16);printf("PRESIONA ENTER");
gotoxy(6,18);printf("PARA PONER PAUSA");
textcolor(12);
gotoxy(50,3);cprintf("%c",3);
gotoxy(50,4);cprintf("%c",3);
gotoxy(50,5);cprintf("%c",3);
while(j[0]<=24)
	{
   gotoxy(30,j[2]);printf("%c",254);
   gotoxy(30,j[1]);printf("%c",254);
   gotoxy(30,j[0]);printf(" ");
   gotoxy(46,j[2]);printf("%c",254);
   gotoxy(46,j[1]);printf("%c",254);
   gotoxy(46,j[0]);printf(" ");
   gotoxy(38,j[2]);printf("|");
   gotoxy(38,j[1]);printf("|");
   gotoxy(38,j[0]);printf(" ");
   j[0]=j[0]+3;
   j[1]=j[1]+3;
   j[2]=j[2]+3;
   }
textcolor(14);
switch(d)
{
case 45:
gotoxy(9,24);cprintf("Muy facil");
break;
case 35:
gotoxy(11,24);cprintf("Facil");
break;
case 25:
gotoxy(11,24);cprintf("Medio");
break;
case 15:
gotoxy(10,24);cprintf("Dificil");
break;
case 8:
gotoxy(9,24);cprintf("Muy dificil");
break;
case 2:
gotoxy(10,24);cprintf("Extremo");
break;
}
getch();
p=2;
i=1;
}
while(i==1)
{
while(j[0]<=24)
	{
   gotoxy(30,j[2]);printf("%c",254);
   gotoxy(30,j[1]);printf("%c",254);
   gotoxy(30,j[0]);printf(" ");
   gotoxy(46,j[2]);printf("%c",254);
   gotoxy(46,j[1]);printf("%c",254);
   gotoxy(46,j[0]);printf(" ");
   gotoxy(38,j[2]);printf("|");
   gotoxy(38,j[1]);printf("|");
   gotoxy(38,j[0]);printf(" ");
   j[0]=j[0]+3;
   j[1]=j[1]+3;
   j[2]=j[2]+3;
   }
p=2;
textcolor(11);
gotoxy(62,24);printf("esc para salir");
gotoxy(50,24);cprintf("puntaje: %i",m);
textcolor(13);
gotoxy(12,3);cprintf("nivel %i",u);
r=1;
while(r==1)
{
if(e==-3||e==25)
{
b=random(3);
}
if(b==0)
{
r=1;
}
else
{
r=0;
}
}
gotoxy(1,1);printf("                                                         ");
Sleep(d);
while(kbhit())
{
a=getch();
if(a==char(27))
	{
   f=p=i=t=4;
   }
if(a==char(75))
	{
   k=35;
   carroizq();
   }
if(a==char(77))
	{
   k=41;
   carroder();
   }
if(a==char(13))
	{
   textcolor(2);
   gotoxy(50,13);cprintf("PAUSA");
   getch();
   gotoxy(50,13);printf("     ");
   }
}
if(b==1)
	{
   textcolor(c);
  	enemigoizq(y,x,z,w,e);
   }
if(b==2)
	{
   textcolor(c);
   enemigoder(y,x,z,w,e);
   }
if(y<25)
	{
   y++;
   }
if(x<25)
	{
   x++;
   }
if(z<25)
	{
   z++;
	}
if(w<25)
	{
   w++;
   }
if(e<26)
	{
   e++;
   }
if(j[0]==26)
   {
   j[0]=3;
   j[1]=4;
   j[2]=2;
   }
   if(j[0]==27)
   {
   j[0]=4;
   j[1]=2;
   j[2]=3;
   }
   if(j[0]==25)
   {
   j[0]=2;
   j[1]=3;
   j[2]=4;
   }
if(e==26)
	{
   y=-2,x=-1,z=0,w=1,e=-3;
   m=m+3;
   if(m==q)
	{
   d--;
   q=q+60;
   u++;
   gotoxy(50,12);printf("pasaste de nivel");
   gotoxy(50,14);printf("presiona cualquier tecla");
   gotoxy(50,16);printf("para continuar");
   y=-2,x=-1,z=0,w=1,e=-3;d--;
   getch();
   getch();
   c++;
   gotoxy(50,12);printf("                 ");
   gotoxy(50,14);printf("                        ");
   gotoxy(50,16);printf("              ");
   }
   }
if(k==35&&b==1)
	{
   if(n==w)
   	{
      f++;
      if(f==3)
      {
      gotoxy(50,3);printf(" ");
      gotoxy(50,4);printf(" ");
		gotoxy(50,5);printf(" ");
      textcolor(12);
      gotoxy(55,8);cprintf("PERDISTE");
      textcolor(9);
      gotoxy(50,10);cprintf("-Presiona enter");
      gotoxy(50,12);cprintf("para volver a jugar");
      textcolor(10);
      gotoxy(50,14);cprintf("-Presiona esc");
      gotoxy(50,16);cprintf("para salir del juego");
      while(f==3)
      {
      s=getch();
      if(s==char(27))
      {
      f=4;
      p=4;
      i=4;
      t=4;
      }
      if(s==char(13))
      {
      p=1;
      i=2;
      f=4;
      }
      if(s!=char(13)&&s!=char(27))
      {
      f=3;
      }
      }
      }
      while(p==2)
      {
      p=3;
      gotoxy(50,12);printf("presiona la flecha derecha");
      gotoxy(50,14);printf("para usar otra vida");
      getch();
      getch();
      getch();
      gotoxy(50,12);printf("                          ");
      gotoxy(50,14);printf("                   ");

      if(f==1)
      {
		gotoxy(50,5);printf(" ");
      y=-2,x=-1,z=0,w=1,e=-3;
      }
      if(f==2)
      {
      gotoxy(50,4);printf(" ");
		gotoxy(50,5);printf(" ");
      y=-2,x=-1,z=0,w=1,e=-3;
      }
      gotoxy(34,20);printf("   ");
      gotoxy(34,19);printf("   ");
      gotoxy(34,18);printf("   ");
      }
      }
   }
if(k==41&&b==2)
	{
   if(h==w)
   	{
      f++;
      if(f==3)
      {
      gotoxy(50,3);printf(" ");
      gotoxy(50,4);printf(" ");
		gotoxy(50,5);printf(" ");
      textcolor(12);
      gotoxy(55,8);cprintf("PERDISTE");
      textcolor(9);
      gotoxy(50,10);cprintf("-Presiona enter");
      gotoxy(50,12);cprintf("para volver a jugar");
      textcolor(10);
      gotoxy(50,14);cprintf("-Presiona esc");
      gotoxy(50,16);cprintf("para salir del juego");
      while(f==3)
      {
      s=getch();
      if(s==char(27))
      {
      f=4;
      p=4;
      i=4;
      t=4;
      }
      if(s==char(13))
      {
      p=1;
      i=2;
      f=4;
      }
      if(s!=char(13)&&s!=char(27))
      {
      f=3;
      }
      }
      }
      while(p==2)
      {
      p=3;
      gotoxy(50,12);printf("presiona la flecha izquierda");
      gotoxy(50,14);printf("para usar otra vida");
      getch();
      getch();
      getch();
      gotoxy(50,12);printf("                            ");
      gotoxy(50,14);printf("                   ");
      if(f==1)
      {
		gotoxy(50,5);printf(" ");
      y=-2,x=-1,z=0,w=1,e=-3;
      }
      if(f==2)
      {
      gotoxy(50,4);printf(" ");
		gotoxy(50,5);printf(" ");
      y=-2,x=-1,z=0,w=1,e=-3;
      }
      gotoxy(40,20);printf("   ");
      gotoxy(40,19);printf("   ");
      gotoxy(40,18);printf("   ");
      }
      }
   }
gotoxy(30,25);printf("                     ");
}
}
}
