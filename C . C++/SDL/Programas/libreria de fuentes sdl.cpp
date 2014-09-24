/***************************************************************************
Ejemplo4_1
(C) 2003 by Alberto Garcia Serrano
Programación de videojuegos con SDL
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

int main(int argc, char *argv[]) {

SDL_Color bgcolor,fgcolor;
SDL_Rect rectangulo;
SDL_Surface *screen,*ttext;
TTF_Font *fuente;

const char texto[14]="Hola Mundo...";
char msg[14];
SDL_Event event;
int done = 0;

// Inicializamos SDL
if (SDL_Init(SDL_INIT_VIDEO) < 0) {
printf("No se pudo iniciar SDL: %s\n",SDL_GetError());
return 1;
}
// Inicializamos modo de video
screen = SDL_SetVideoMode(640,480,24,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen == NULL) {
printf("No se puede inicializar el modo gráfico: \n",SDL_GetError());
return 1;
}
atexit(SDL_Quit);

// Inicializamos SDL_ttf
if (TTF_Init() < 0) {
printf("No se pudo iniciar SDL_ttf: %s\n",SDL_GetError());
return 1;
}
atexit(TTF_Quit);

// carga la funte de letra
fuente = TTF_OpenFont("ariblk.ttf",20);

// inicializa colores para el texto
fgcolor.r=200;
fgcolor.g=200;
fgcolor.b=10;
bgcolor.r=255;
bgcolor.g=0;
bgcolor.b=0;
sprintf(msg,"%s",texto);
ttext = TTF_RenderText_Shaded(fuente,msg,fgcolor,bgcolor);
rectangulo.y=100;
rectangulo.x=100;
rectangulo.w=ttext->w;
rectangulo.h=ttext->h;

// Usamos color rojo para la transparencia del fondo
SDL_SetColorKey(ttext,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(ttext->format,255,0,0));

// Volcamos la superficie a la pantalla
SDL_BlitSurface(ttext,NULL,screen,&rectangulo);

// destruimos la fuente de letra
TTF_CloseFont(fuente);


// liberar superficie
SDL_FreeSurface(ttext);

// Esperamos la pulsación de una tecla para salir
while(done == 0) {

while ( SDL_PollEvent(&event) ) {
if ( event.type == SDL_KEYDOWN )
done = 1;
}
}
return 0;
}
