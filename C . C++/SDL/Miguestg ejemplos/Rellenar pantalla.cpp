#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
 
#ifdef WIN32
 #include <windows.h>
#endif
 
int GetX()
{
    #ifdef WIN32
     return GetSystemMetrics(SM_CXSCREEN);
    #else
     return 0;
    #endif
}
 
int GetY()
{
    #ifdef WIN32
     return GetSystemMetrics(SM_CYSCREEN);
    #else
     return 0;
    #endif
}
 
int main(int argc, char *argv[])
{
    SDL_Surface *pantalla;
    SDL_Event evento;
    SDL_Rect aux;
    int color;
 
    srand(time(NULL));
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "No se pudo iniciar SDL\nCausa: %s\n\n", SDL_GetError());
        return -1;
    }
    pantalla=SDL_SetVideoMode(GetX(), GetY(), 16, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
    if(!pantalla)
    {
        fprintf(stderr, "No se puedo configurar la pantalla\nCausa: %s\n\n", SDL_GetError());
        return -2;
    }
    SDL_PollEvent(&evento);
    printf("Ha tardado %i milisegundos en empezar el bucle\n\n", SDL_GetTicks());
 
    while(evento.type!=SDL_MOUSEBUTTONDOWN&&evento.type!=SDL_KEYDOWN)
    {
        aux.x=rand()%pantalla->w;
        aux.y=rand()%pantalla->h;
        aux.w=150;
        aux.h=150;
        color=SDL_MapRGB(pantalla->format, rand()%256, rand()%256, rand()%256);
        SDL_FillRect(pantalla, &aux, color);
        SDL_Flip(pantalla);
        SDL_PollEvent(&evento);
        SDL_Delay(100);
    }
    SDL_Quit();
    return 0;
}

