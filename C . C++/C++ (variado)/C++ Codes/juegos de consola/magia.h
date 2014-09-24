#include<stdio.h>
#include<conio.h>
int ciclo1(void)
{
char s;
int d,n;
s=getch();
d=1;
while(d==1)
{
	if(s==char(13))
   {
   	n=1;
      d=2;
   }
   if(s==char(27))
   {
		n=2;
      d=2;
	}
	if(s!=char(13)&&s!=char(27))
	{
   	d=1;
   }
}
return (n);
}
void magia(void)
{
int a[18],b=1,i,y,v,w,x,z[18],t,n=1,q,d;
clrscr();
textcolor(12);
gotoxy(38,11);cprintf("MAGIA");
textcolor(9);
gotoxy(24,13);cprintf("presiona una tecla para comenzar");
getch();
clrscr();
for(i=0;i<18;i++)
	{
   a[i]=b;
   b++;
   }
while(n==1)
{
clrscr();
q=1;
printf("Elige un numero entre estas columnas y memorizalo");
gotoxy(22,3);printf("columna 1");
y=4;
for(i=0;i<6;i++)
	{
   gotoxy(25,y);printf("%i",a[i]);
   y++;
   }
gotoxy(37,3);printf("columna 2");
y=4;
for(i=6;i<12;i++)
	{
   gotoxy(40,y);printf("%i",a[i]);
   y++;
   }
gotoxy(52,3);printf("columna 3");
y=4;
for(i=12;i<18;i++)
	{
   gotoxy(55,y);printf("%i",a[i]);
   y++;
   }
while(q==1)
{
printf("\n\nEn que columna esta tu numero???      elige entre columna 1,2 o 3: ");
scanf("%i",&v);
if(v<1||v>3)
	{
   	printf("\nTe dije que solo la columna 1,2 o 3, orale hazlo de nuevo\n");
      q=1;
   }
else
	{
   	q=2;
   }
}
clrscr();
i=0;
printf("Busca tu numero");
gotoxy(22,3);printf("columna 1");
y=4;
while(i<14)
	{
   gotoxy(25,y);printf("%i",a[i]);
   i=i+6;
   y++;
   if(i==18)
   {
   i=1;
   }
	}
i=2;
gotoxy(37,3);printf("columna 2");
y=4;
while(i<16)
	{
   gotoxy(40,y);printf("%i",a[i]);
   i=i+6;
   y++;
   if(i==20)
   {
   i=3;
   }
	}
i=4;
gotoxy(52,3);printf("columna 3");
y=4;
while(i<18)
	{
   gotoxy(55,y);printf("%i",a[i]);
   i=i+6;
   y++;
   if(i==22)
   {
   i=5;
   }
	}
while(q==2)
{
printf("\n\nAhora en que columna esta tu numero???    elige entre columna 1,2 o 3: ");
scanf("%i",&w);
if(w<1||w>3)
	{
   	printf("\nTe dije que solo la columna 1,2 o 3, orale hazlo de nuevo\n");
      q=2;
   }
else
	{
	q=1;
   }
}
switch(v)
	{
		case 1:
			switch (w)
   			{
   				case 1:
               t=0;
               for(i=0;i<6;i++)
               	{
                  	for(b=0;b<20;b=b+6)
                  		{
                        if(b==18)
   								{
  										 b=1;
   								}
                           if(b==19)
   								{
  										 break;
   								}
                        if(a[i]==a[b])
                        	{
                              z[t]=a[i];

                              t++;
                        	}
                     	}
                  }
             break;
             case 2:
             t=0;
               for(i=0;i<6;i++)
               	{
                  	for(b=2;b<22;b=b+6)
                  		{
                        if(b==20)
   								{
  										 b=3;
   								}
                        if(b==21)
                        	{
                           	break;
                           }
                        if(a[i]==a[b])
                        	{
                              z[t]=a[i];
                              t++;
                           }
                     	}
                  }
             break;
             case 3:
             t=0;
             	for(i=0;i<6;i++)
               	{
                  	for(b=4;b<23;b=b+6)
                     	{
                        if(b==22)
                        	{
                           b=5;
                           }
                        if(a[i]==a[b])
                        	{
                           z[t]=a[b];
                           t++;
                           }
                        }
                  }
             break;
				}
         break;
		case 2:
      	switch (w)
            {
         	case 1:
            t=0;
               for(i=6;i<12;i++)
               	{
                  	for(b=0;b<20;b=b+6)
                  		{
                        if(b==18)
   								{
  										 b=1;
   								}
                        if(b==19)
   								{
  										 break;
   								}
                        if(a[i]==a[b])
                        	{
                              z[t]=a[i];
                              t++;
                        	}
                     	}
                  }
             break;
             case 2:
             t=0;
               for(i=6;i<12;i++)
               	{
                  	for(b=2;b<22;b=b+6)
                  		{
                        if(b==20)
   								{
  										 b=3;
   								}
                        if(b==21)
                        	{
                           	break;
                           }
                        if(a[i]==a[b])
                        	{
                              z[t]=a[i];
                              t++;
                           }
                     	}
                  }
             break;
             case 3:
             t=0;
             	for(i=6;i<12;i++)
               	{
                  	for(b=4;b<23;b=b+6)
                     	{
                        if(b==22)
                        	{
                           b=5;
                           }
                        if(a[i]==a[b])
                        	{
                           z[t]=a[b];
                           t++;
                           }
                        }
                  }
             break;
             }
            break;
		case 3:
      	switch (w)
         	{
         	case 1:
            t=0;
               for(i=12;i<18;i++)
               	{
                  	for(b=0;b<20;b=b+6)
                  		{
                        if(b==18)
   								{
  										 b=1;
   								}
                        if(b==19)
   								{
  										 break;
   								}
                        if(a[i]==a[b])
                        	{
                              z[t]=a[i];
                              t++;
                        	}
                     	}
                  }
             break;
             case 2:
             t=0;
               for(i=12;i<18;i++)
               	{
                  	for(b=2;b<22;b=b+6)
                  		{
                        if(b==20)
   								{
  										 b=3;
   								}
                        if(b==21)
                        	{
                           	break;
                           }
                        if(a[i]==a[b])
                        	{
                              z[t]=a[i];
                              t++;
                           }
                     	}
                  }
             break;
             case 3:
             t=0;
             	for(i=12;i<18;i++)
               	{
                  	for(b=4;b<23;b=b+6)
                     	{
                        if(b==22)
                        	{
                           b=5;
                           }
                        if(a[i]==a[b])
                        	{
                           z[t]=a[b];
                           t++;
                           }
                        }
                  }
             break;
           }
           break;
   }
clrscr();
i=0;
y=4;
printf("Busca tu numero");
gotoxy(22,3);printf("columna 1");
while(i<16)
	{
   gotoxy(25,y);printf("%i",a[i]);
   i=i+3;
   y++;
	}
i=1;
y=4;
gotoxy(37,3);printf("columna 2");
while(i<17)
	{
   gotoxy(40,y);printf("%i",a[i]);
   i=i+3;
   y++;
	}
i=2;
y=4;
gotoxy(52,3);printf("columna 3");
while(i<18)
	{
   gotoxy(55,y);printf("%i",a[i]);
   i=i+3;
   y++;
	}
while(q==1)
{
printf("\n\nY por ultima vez en que columna esta tu numero?  elige entre columna 1,2 o 3: ");
scanf("%i",&x);
if(x<1||x>3)
	{
   	printf("\nTe dije que solo la columna 1,2 o 3, orale hazlo de nuevo\n");
      q=1;
   }
else
	{
	q=2;
   }
}
switch(x)
	{
   case 1:
	for(t=0;t<2;t++)
   	{
         for(b=0;b<16;b=b+3)
         	{
            if(z[t]==a[b])
            	{
               textcolor(9);
               cprintf("\n\nEL NUMERO QUE MEMORIZASTE ES: %i",z[t]);
               printf("\n\n-Si quieres que te adivine otro numero presiona enter");
               printf("\n\n-Si quieres salir de el programa presiona esc");
               n=ciclo1();
               }
            }
      }
    break;
    case 2:
    	for(t=0;t<2;t++)
      	{
         for(b=1;b<17;b=b+3)
         	{
            if(z[t]==a[b])
            	{
               textcolor(9);
               cprintf("\n\nEL NUMERO QUE MEMORIZASTE ES: %i",z[t]);
               printf("\n\n-Si quieres que te adivine otro numero presiona enter");
               printf("\n\n-Si quieres salir de el programa presiona esc");
               n=ciclo1();
               }
            }
         }
      break;
      case 3:
    	for(t=0;t<2;t++)
      	{
         for(b=2;b<18;b=b+3)
         	{
            if(z[t]==a[b])
            	{
               textcolor(9);
               cprintf("\n\nEL NUMERO QUE MEMORIZASTE ES: %i",z[t]);
               printf("\n\n-Si quieres que te adivine otro numero presiona enter");
               printf("\n\n-Si quieres salir de el programa presiona esc");
               n=ciclo1();
               }
            }
         }
      break;
    }
}
}
