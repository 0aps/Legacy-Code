/***************************************************************************
Ejemplo4_3
(C) 2003 by Alberto Garcia Serrano
Programaci�n de videojuegos con SDL
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

int main(int argc, char *argv[]) {
SDL_Surface *screen;
SDL_Event event;
Mix_Chunk *sonido;
int done = 0;
int canal;
atexit(SDL_Quit);
// Iniciar SDL
if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
printf("No se pudo iniciar SDL: %s\n",SDL_GetError());
exit(1);
}
// Activamos modo de video
screen = SDL_SetVideoMode(640,480,24,SDL_HWSURFACE);
if (screen == NULL) {
printf("No se puede inicializar el modo gr�fico: %s \n",SDL_GetError());
exit(1);
}
// Inicializamos SDL_mixer
if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096)) {
printf("No se puede inicializar SDL_mixer %s\n",Mix_GetError());
exit(1);
}
atexit(Mix_CloseAudio);
// Cargamos sonido
sonido = Mix_LoadWAV("explosion.wav");
if ( sonido == NULL ) {
printf("No pude cargar sonido: %s\n", Mix_GetError());
exit(1);
}
// Reproducci�n del sonido.
// Esta funci�n devuelve el canal por el que se reproduce el sonido
canal = Mix_PlayChannel(-1, sonido, 0);
// Esperamos la pulsaci�n de una tecla para salir
while(done == 0) {
while ( SDL_PollEvent(&event) ) {
if ( event.type == SDL_KEYDOWN )
done = 1;
}
}
// liberamos recursos
Mix_FreeChunk(sonido);
return 0;
}
