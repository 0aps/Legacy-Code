#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
 
void limpiar (SDL_Surface *screen);
void imprimir(SDL_Surface *screen, SDL_Surface *ima, int x, int y);
void mover_objeto(int *x, int *y, int ancho, int alto);
 
 
int main(int argc, char *argv[])
{
        SDL_Surface *screen;
        SDL_Surface *ima;
        Mix_Music *cancion;
        SDL_Event event;
        int salir = 0;
        int x = 100;
        int y = 100;
 
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
        {
                printf("Error: %s\n", SDL_GetError());
                return 1;
        }
 
        screen = SDL_SetVideoMode(320, 240, 16, SDL_HWSURFACE);
 
        if (screen == NULL)
        {
                printf("Error: %s\n", SDL_GetError());
                return 1;
        }
 
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
        {
                printf("Error en Mix_OpenAudio: %s\n", Mix_GetError());
                return 1;
        }
 
        SDL_WM_SetCaption("Ejemplo 2", NULL);
 
        ima = IMG_Load("C:/Documents and Settings/Owner/Desktop/Programming/C ++/SDL/Programas/ima.png");
 
        if (ima == NULL)
        {
                printf("Error en IMG_Load= %s\n", SDL_GetError());
                return 1;
        }
 
        cancion = Mix_LoadMUS("C:/Documents and Settings/Owner/Desktop/Musica/Rose - La liste.mp3");
 
        if (!cancion)
                printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
 
        if (cancion)
        {
                if (Mix_PlayMusic(cancion, -1) == -1)
                        printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
        }
 
        while (! salir)
        {
                SDL_PollEvent(&event);
 
                if (event.type == SDL_QUIT)
                        salir = 1;
 
                mover_objeto(&x, &y, ima->w, ima->h);
 
                limpiar(screen);
                imprimir(screen, ima, x, y);
                SDL_Flip(screen);
                SDL_Delay(10);
        }
 
        if (cancion)
        {
                Mix_HaltMusic();
                Mix_FreeMusic(cancion);
        }
 
        Mix_CloseAudio();
        SDL_Quit();
        return 0;
}
 
void limpiar (SDL_Surface *screen)
{
        Uint32 a = SDL_MapRGB(screen->format, 200, 200, 200);
        SDL_FillRect(screen, NULL, a);
}
 
 
void imprimir(SDL_Surface *screen, SDL_Surface *ima, int x, int y)
{
        SDL_Rect rect = {x, y, 0, 0};
 
        SDL_BlitSurface(ima, NULL, screen, &rect);
}
 
 
void mover_objeto(int *x, int *y, int ancho, int alto)
{
        Uint8 *key = SDL_GetKeyState(NULL);
 
        if (key[SDLK_LEFT] && * x > 0)
                (*x) -= 5;
 
        if (key[SDLK_RIGHT] && (*x + ancho) < 320)
                (*x) += 5;
 
        if (key[SDLK_UP] && *y > 0)
 
                (*y) -= 5;
 
        if (key[SDLK_DOWN] && (*y + alto) < 240)
                (*y) += 5;
}

