#include <winbgim.h>  // Provides the BGI graphics functions for Windows
#include <stdio.h>
#include <math.h>
 
#define RGB_COLOR(c) (c & 0xFFFFFF)
 
void lineas (float z);
void grafica (float x, float y, int z, int col);
int winx, winy,oldx,oldy;bool ini=false;
 
 
int main(void) {
 
settitlewindow("Dibuja Funciones");
setgraphmode(VGAMAX);//Pantalla completa
initwindow(640, 480);
winx=getmaxx();
winy=getmaxy();
char txt[256];
char op=13;
int mr = 1,zoom = 25,colorr = 12;
settextstyle(3, 0, 2);
while (1){
 
  switch (op){
    case 27:exit(0);break;
    case 43:if(zoom<100){zoom++;gprintf(winx-100, 10,"Zoom= %d",zoom);}break;
    case 45:if(zoom>1){zoom--;gprintf(winx-100, 10,"Zoom= %d",zoom);}break;
    case 13:
      cleardevice();
      lineas(zoom);
      int vo = 32124, rp = 20, rn = -20, av=0;
      double pres = .01;
      double y = 0, ox;ini=false;
 
 
      for(double x=rn;x<rp;x+=pres){
        if(x!=vo){
        //y = 2 * x - 1;
        //y = ((17*x+20)/(13+7*x));
        //y = sin(x)/3-cos(x)*2+3*tan(x);
        //y = pow(-1,int(x)) * pow(-x,int(x));
        //y = pow(-1,int(x)) / x;
        //y=cos(x);
        y=(100/(100+pow((x-M_PI/2),8))) * (2-sin(7*x)-cos(30*x)/2);
/*
        sqrt(as)     raiz
        pow (a,b)    potencia
        log (a)      logaritmo natural
        log10 (a)    logaritmo en base 10
        exp (a)      e ^ x 
        abs (a)      absoluto
        div (a,b)    div entera
        cos(a) - sin(a) - tan(a)       Trigonometricas(en rad)
        acos(a) - asin(a) - atan(a)    Inv Trigonometricas(en rad)
*/
        }
        grafica(x, y, zoom, colorr);       
        if ((int(y/.001) == 0)&&(av<7)&&(int(ox)!=int(x))) {
          gprintf(10 + av*140, winy-30,"Raiz: %.4g",x);av++;ox=x;
        }
        //sleep(10);
      }
    break;
  }  
  op=getch();
}
closegraph( );  
}
 
void grafica (float x, float y, int z, int col) {
 
if(((winy/2 - y * z)<=0)||((winy/2 - y * z)>=winy))
{ini=false;return;}
 
if(!ini){
oldx = int(winx/2 + x * z); oldy = int(winy/2 - y * z);
ini = true;return;
}
setcolor(col);
line(oldx,oldy,int(winx/2 + x * z),int(winy/2 - y * z));
oldx = int(winx/2 + x * z); oldy = int(winy/2 - y * z);
}
 
 
void lineas (float z) {
setcolor(7);
line(0,winy/2,winx,winy/2);
line(winx/2,0,winx/2,winy);
for( float i = winy/2;i < winy;i+=z){
line(winx/2-winx/300,int(i),winx/2+winx/300,int(i));
line(winx/2-winx/300,int(winy-i),winx/2+winx/300,int(winy-i));
}
for( float i = winx/2;i < winx;i+=z){
line(int(i),winy/2-winy/200,int(i),winy/2+winy/200);
line(int(winx-i),winy/2-winy/200,int(winx-i),winy/2+winy/200);
}
}
