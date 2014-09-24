/***************************************************************************
Ejemplo4_4
(C) 2003 by Alberto Garcia Serrano
Programación de videojuegos con SDL
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
int main(int argc, char *argv[]) {
SDL_Surface *screen;
SDL_Event event;
Mix_Music *musica;
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
printf("No se puede inicializar el modo gráfico: %s \n",SDL_GetError());
exit(1);
}
// Inicializamos SDL_mixer
if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096)) {
printf("No se puede inicializar SDL_mixer %s\n",Mix_GetError());
exit(1);
}
atexit(Mix_CloseAudio);
// Cargamos la música
musica = Mix_LoadMUS("C:/Documents and Settings/Owner/Desktop/Musica/Rose - La liste.mp3");
if ( musica == NULL ) {
printf("No pude cargar musica: %s\n", Mix_GetError());
exit(1);
}
// Reproducción la música.
// Esta función devuelve el canal por el que se reproduce la música
canal = Mix_PlayMusic(musica, -1);
// Esperamos la pulsación de una tecla para salir
while(done == 0) {
while ( SDL_PollEvent(&event) ) {
if ( event.type == SDL_KEYDOWN )
done = 1;
}
}
// paramos la música
Mix_HaltMusic();
// liberamos recursos
Mix_FreeMusic(musica);
return 0;
}
