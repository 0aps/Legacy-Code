/***************************************************************************
Ejemplo6_1
(C) 2003 by Alberto Garcia Serrano
Programación de videojuegos con SDL
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "csprite.h"

#define MAXMAP 400
#define MAXBALAS 8


// Mapa de tiles
// cada tile tiene 64x64 píxeles
// una pantalla tiene 10x10 tiles

int mapa[401]= {0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,2,0,0,0,0,
                0,0,1,0,0,0,0,1,0,0,
                2,0,0,0,0,0,0,0,0,0,
                0,0,0,0,1,0,0,0,2,0,
                0,0,0,0,0,0,0,0,0,0,
                0,2,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,0,0,
                0,0,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,2,0,0,0,0,
                0,0,1,0,0,0,0,1,0,0,
                2,0,0,0,0,0,0,0,0,0,
                0,0,0,0,1,0,0,0,2,0,
                0,0,0,0,0,0,0,0,0,0,
                0,2,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,0,0,
                0,0,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,2,0,0,0,0,
                0,0,1,0,0,0,0,1,0,0,
                2,0,0,0,0,0,0,0,0,0,
                0,0,0,0,1,0,0,0,2,0,
                0,0,0,0,0,0,0,0,0,0,
                0,2,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,0,0,
                0,0,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,2,0,0,0,0,
                0,0,1,0,0,0,0,1,0,0,
                2,0,0,0,0,0,0,0,0,0,
                0,0,0,0,1,0,0,0,2,0,
                0,0,0,0,0,0,0,0,0,0,
                0,2,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,1,0,0,
                0,0,1,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0}; //401 mosaicos

SDL_Surface *screen;
CFrame fnave;
CFrame fmalo;
CFrame tile1;
CFrame tile2;
CFrame tile3;

CFrame labala;
CFrame ex1;
CFrame ex2;
CFrame ex3;
CFrame ex4;
CFrame ex5;
CFrame ex6;
CFrame ex7;

CSprite nave(1);
CSprite malo(1);
CSprite suelo[3];//*

CSprite mibala(1);
CSprite explode(8);

SDL_Rect rectangulo;
SDL_Joystick *joystick;
int joyx, joyy;
int done=0;

int indice;
int indice_in;

// estructura que contiene la información
// de nuestro avión

struct minave {
int x,y;
} jugador;

// Estructura que contiene información
// del avión enemigo

struct naveenemiga {
int x,y,estado;
} enemigo;

// Estructura que contine información
// de los disparos de nuestro avión
struct disparo {
int x,y;
} bala[MAXBALAS+1];


// Estructura que contiene información
// de la explosión
struct explosion {
int activo,x,y,nframe;
} exp;

void muevenave() {

// estado 1. Movimiento a la derecha.
if (enemigo.estado == 1) 
{
enemigo.x=enemigo.x+2;
if (enemigo.x>600) enemigo.estado=2;
}

// estado2. Movimiento a la izquierda.
if (enemigo.estado == 2) 
{
enemigo.x=enemigo.x-2;
if (enemigo.x<40) enemigo.estado=1;
}
                   }
                   
void muevebalas() 
{
int i;
    for (i=0 ; i<=MAXBALAS ; i++) 
    {

     // si la pos.X del desparo no es 0,
     // es una bala activa.
        if (bala[i].x != 0) 
        {
        bala[i].y=bala[i].y-5;

        // si el disparo sale de la pantalla la desactivamos
           if (bala[i].y < 0)
           {
           bala[i].x=0;
           }
        }

    }
}


// Dibuja los esprites en la pantalla
void DrawScene(SDL_Surface *screen)
{
int i,j,x,y,t;


// movimiento del scenario (scroll)
indice_in+=1; // velocidad en la que se mueve el mapa
if (indice_in>=64) {
indice_in=0;
indice-=10;
}


if (indice <= 0) {
indice=MAXMAP-100; // si llegamos al final, empezamos de nuevo.
indice_in=0;
}

//dibujar escenario
for (i=0 ; i<10 ; i++) 
{

    for (j=0 ; j<10 ; j++)
     {
        t=mapa[indice+(i*10+j)];

        // calculo de la posición del tile
        x=j*64;  //0 x 64 = 64
     //   y=(i-1)*64;  // 0 - 1 = 0; 0 x 64 = 0; 
                    //el primer mosaico se coloca en 64,0
        y=(i-1)*64+indice_in; //0-1 = 0; 0 x 64 = 0; 0+1 = 1; (64,1);

        // dibujamos el tile
        suelo[t].setx(x);
        suelo[t].sety(y);
        suelo[t].draw(screen);
     }
}

// dibuja avión
nave.setx(jugador.x);
nave.sety(jugador.y);
nave.draw(screen);

// Dibuja enemigo
malo.setx(enemigo.x);
malo.sety(enemigo.y);
malo.draw(screen);

// dibuja disparos
for (i=0 ; i<=MAXBALAS ; i++) 
{
     if (bala[i].x != 0) 
    {
    mibala.setx(bala[i].x);
    mibala.sety(bala[i].y);
    mibala.draw(screen);
    }
}

// dibujar explosion
   if (exp.activo==1) 
{
    explode.selframe(exp.nframe);
    explode.setx(exp.x);
    explode.sety(exp.y);
    explode.draw(screen);
    exp.nframe=exp.nframe+1;

    if (exp.nframe>=7) 
    {
     exp.activo=0;
     done=1;
     }
}

// ¿ha colisionado con la nave?
if (malo.colision(nave) == TRUE)
 {
done=1;
 }
 
 // ¿ha colisionado el disparo con la nave?
if (malo.colision(mibala) == TRUE) 
{

 enemigo.estado=0;
 exp.activo=1;
 exp.nframe=1;
 exp.x=enemigo.x;
 exp.y=enemigo.y;
}

// Mostramos todo el frame
SDL_Flip(screen);

}

void creadisparo() 
{

int libre=-1;

             // ¿Hay alguna bala libre?
        for (int i=0 ; i<=MAXBALAS ; i++) 
        {
          if (bala[i].x==0)
          libre=i;
        }

// Hay una bala
   if (libre>=0) 
   {
   bala[libre].x=nave.getx();
   bala[libre].y=nave.gety()-15;
   }

}

// Inicializamos estados
void inicializa() {
     int i,c;

jugador.x=300;
jugador.y=300;

enemigo.x=100;
enemigo.y=100;

explode.finalize();

indice=MAXMAP-100;
indice_in=0;

enemigo.estado=1;
exp.activo=0;

// Inicializamos el array de balas

for (i=0 ; i<=MAXBALAS ; i++) 
{
bala[i].x=0;
bala[i].y=0;
}

}

void finaliza() 
{
     
// finalizamos los sprites
nave.finalize();
malo.finalize();
mibala.finalize();

suelo[0].finalize();
suelo[1].finalize();
suelo[2].finalize();

// cerramos el joystick
if (SDL_JoystickOpened(0)) {
SDL_JoystickClose(joystick);
}

}

// Preparamos los esprites
int InitSprites() {

fnave.load("nave1.bmp");
nave.addframe(fnave);

fmalo.load("nave2.bmp");
malo.addframe(fmalo);

tile1.load("mapa1.bmp");
suelo[0].addframe(tile1);

tile2.load("mapa2.bmp");
suelo[1].addframe(tile2);

tile3.load("mapa3.bmp");
suelo[2].addframe(tile3);

labala.load("balas.bmp");
mibala.addframe(labala);

ex1.load("explode1.bmp");
explode.addframe(ex1);

ex2.load("explode2.bmp");
explode.addframe(ex2);

ex3.load("explode3.bmp");
explode.addframe(ex3);

ex4.load("explode4.bmp");
explode.addframe(ex4);

ex5.load("explode5.bmp");
explode.addframe(ex5);

ex6.load("explode6.bmp");
explode.addframe(ex6);

ex7.load("explode7.bmp");
explode.addframe(ex7);

return 0;

}

int main(int argc, char *argv[]) {

SDL_Event event;
Uint8 *keys;

if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK) < 0) {
printf("No se pudo iniciar SDL: %s\n",SDL_GetError());
return 1;
}

screen = SDL_SetVideoMode(640,480,24,SDL_HWSURFACE);
if (screen == NULL) {
printf("No se puede inicializar el modo gráfico: \n",SDL_GetError());
return 1;
}

atexit(SDL_Quit);

inicializa();
InitSprites();

while (done == 0) {
      
// movemos el avión enemiga
muevenave();

// movemos los disparos
muevebalas();

// dibujamos el frame
DrawScene(screen);

// consultamos el estado del teclado
keys=SDL_GetKeyState(NULL);

// consultamos el estado del joystick
SDL_JoystickUpdate();
joyx = SDL_JoystickGetAxis(joystick, 0);
joyy = SDL_JoystickGetAxis(joystick, 1);

if ((keys[SDLK_UP] || joyy < -10) && (jugador.y > 0)) {jugador.y=jugador.y-(1);}
if ((keys[SDLK_DOWN] || joyy > 10) && (jugador.y < 430)) {jugador.y=jugador.y+(1);}
if ((keys[SDLK_LEFT] || joyx < -10) && (jugador.x > 0)) {jugador.x=jugador.x-(1);}
if ((keys[SDLK_RIGHT] || joyx > 10) && (jugador.x < 560)) {jugador.x=jugador.x+(1);}
if (keys[SDLK_LSHIFT]) {creadisparo();}


while (SDL_PollEvent(&event)) {

if (event.type == SDL_QUIT) {done=1;}
if (event.type == SDL_KEYDOWN || event.type == SDL_JOYBUTTONDOWN) {
if (event.key.keysym.sym == SDLK_ESCAPE) {

done=1;

}
}
}
}

finaliza();
return 0;
}
