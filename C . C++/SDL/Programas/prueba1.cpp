#include <stdio.h>
#include <SDL/SDL.h>
 
void imprimir_rectangulo (SDL_Surface *screen, int x, int y);
 
int main(int argc, char *argv[])
{
        SDL_Surface *screen;
        SDL_Event event;
 
        if (SDL_Init(SDL_INIT_VIDEO) == -1)
        {
                printf("Error: %s\n", SDL_GetError());
                return 1;
        }
 
        screen = SDL_SetVideoMode(320, 240, 16, SDL_SWSURFACE);
 
        if (screen == NULL)
        {
                printf("Error: %s\n", SDL_GetError());
                return 1;
        }
 
        SDL_WM_SetCaption("Ejemplo básico", NULL);
 
        imprimir_rectangulo(screen, 20, 30);
 
        while (SDL_WaitEvent(&event))
        {
                if (event.type == SDL_QUIT)
                        break;
        }
 
        SDL_Quit();
        return 0;
}
 
void imprimir_rectangulo (SDL_Surface *screen, int x, int y)
{
        SDL_Rect rect = {x, y, 50, 50};
        Uint32 a = SDL_MapRGB(screen->format, 255, 200, 100);
 
        SDL_FillRect(screen, &rect, a);
        //SDL_Flip (screen);
        SDL_UpdateRect(screen, rect.x, rect.y, rect.w, rect.h);
}
