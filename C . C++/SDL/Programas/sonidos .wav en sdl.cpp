/*****************************************
Ejemplo3_4
(C) 2003 by Alberto Garcia Serrano
Programación de videojuegos con SDL
*****************************************/
#include <stdlib.h>
#include <SDL/sdl.h>

SDL_Surface* superficie;
SDL_Event event;
SDL_AudioSpec* deseado;
SDL_AudioSpec* obtenido;
int done;

// declaración de la función de retrollamada
void retrollamada(void* userdata,Uint8* buffer,int len);

int main(int argc, char* argv[]) {

// Inicializamos SDL
if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0) {
printf("No se pudo inicializar SDL.\n");
exit(1);
}
// Inicializamos modo de video
// (en Windows es necesario para que funcione el audio)
if ( (superficie = SDL_SetVideoMode(640,480,0,SDL_ANYFORMAT)) == NULL) {
printf("No se pudo inicializar la ventana.\n");
exit(1);
}
// Alojamos espacio para almacenar las estructuras
deseado=new SDL_AudioSpec;
obtenido=new SDL_AudioSpec;

// especificaciones deseadas
deseado->freq=11025;
deseado->format=AUDIO_S16SYS;
deseado->channels=1;
deseado->samples=4096;
deseado->callback=retrollamada;
deseado->userdata=NULL;

// abrimos el dispositivo de audio
//audio deseado, audio final si se pudo obtener
if(SDL_OpenAudio(deseado,obtenido)<0) {
printf("No puedo abrir el dispositivo\n");
delete deseado;
delete obtenido;
exit(1);
}
atexit (SDL_CloseAudio);
delete deseado;

// Empieza a sonar...
SDL_PauseAudio(0);
// esperamos a que cierren la aplicación
done = 0;

while (!done) {
if(SDL_PollEvent(&event)==0)
if(event.type==SDL_QUIT) done=1;
}

delete deseado;
return(0);
}


// Función de retrollamada
// Simplemente llena el buffer con información aleatoria.
void retrollamada(void* userdata,Uint8* buffer,int len) {
int i;
for(i=0 ; i<len ; i++)
buffer[i]=rand()%256;
}
