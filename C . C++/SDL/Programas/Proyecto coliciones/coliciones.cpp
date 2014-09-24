/***************************************************************************
Ejemplo5_1
(C) 2003 by Alberto Garcia Serrano
Programación de videojuegos con SDL
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_IMAGE.h>
#include "csprite.h"

SDL_Surface *screen;

CFrame fnave;
CFrame fmalo;

CSprite nave(1);
CSprite malo(1);

SDL_Rect rectangulo;
SDL_Joystick *joystick;

int joyx, joyy;
int done=0;

// estructura que contiene la información
// de nuestro avión
struct minave {
int x,y;
} jugador;

// Estructura que contiene información
// del avión enemigo
struct naveenemiga {
int x,y;
} enemigo;

// Dibuja los esprites en la pantalla
void DrawScene(SDL_Surface *screen) {

// borramos el avión dibujado
// en el frame anterior
rectangulo.x=nave.getx();
rectangulo.y=nave.gety();
rectangulo.w=nave.getw();
rectangulo.h=nave.geth();
SDL_FillRect(screen,&rectangulo,SDL_MapRGB(screen->format,0,0,0));

// dibuja avión
nave.setx(jugador.x);
nave.sety(jugador.y);
nave.draw(screen);

// Dibuja enemigo
malo.setx(enemigo.x);
malo.sety(enemigo.y);
malo.draw(screen);

// ¿ha colisionado con la nave?
if (malo.colision(nave) == TRUE) {
done=1;
}

// Mostramos todo el frame
SDL_Flip(screen);
}

// Inicializamos estados
void inicializa() {
jugador.x=300;
jugador.y=300;

enemigo.x=100;
enemigo.y=100;
}

void finaliza() {
// finalizamos los sprites
nave.finalize();
malo.finalize();

// cerramos el joystick
if (SDL_JoystickOpened(0)) {
SDL_JoystickClose(joystick);
}

}

// Preparamos los esprites
int InitSprites() {

fnave.load("ima.bmp");
nave.addframe(fnave);

fmalo.load("ima.png");
malo.addframe(fmalo);
return 0;
}

int main(int argc, char *argv[])
 {

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

// dibujamos el frame
DrawScene(screen);

// consultamos el estado del teclado
keys=SDL_GetKeyState(NULL);

// consultamos el estado del joystick
SDL_JoystickUpdate();
joyx = SDL_JoystickGetAxis(joystick, 0);
joyy = SDL_JoystickGetAxis(joystick, 1);

if ((keys[SDLK_UP] || joyy < -10) && (jugador.y > 0)) {jugador.y=jugador.y-(2);}
if ((keys[SDLK_DOWN] || joyy > 10) && (jugador.y < 380)) {jugador.y=jugador.y+(2);}
if ((keys[SDLK_LEFT] || joyx < -10) && (jugador.x > 0)) {jugador.x=jugador.x-(2);}
if ((keys[SDLK_RIGHT] || joyx > 10) && (jugador.x < 500)) {jugador.x=jugador.x+(2);}

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
