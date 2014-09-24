#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
 
#define Limpiar(pantalla) SDL_FillRect(pantalla, NULL, SDL_MapRGB(pantalla->format, 0, 0, 0))
#define DERECHA 0
#define IZQUIERDA 1
#define ARRIBA 2
#define ABAJO 3
 
int main(int argc, char *argv[])
{
    srand(time(NULL));
    SDL_Surface *pantalla, *matriz;
    SDL_Event evento;
    SDL_Rect grilla[4], recta={0, 0, 100, 100};
    int i, op=rand()%4;
 
    if(SDL_Init(SDL_INIT_VIDEO)) return -1;
    pantalla=SDL_SetVideoMode(500, 200, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(!pantalla) return -2;
    matriz=SDL_LoadBMP("matriz.bmp");
    if(!matriz) return -3;
    for(i=0; i<4; i++)
    {
        grilla[i].w=100;
        grilla[i].h=100;
    }
    grilla[0].x=1;
    grilla[0].y=1;
    grilla[1].x=103;
    grilla[1].y=1;
    grilla[2].x=1;
    grilla[2].y=103;
    grilla[3].x=103;
    grilla[3].y=103;
    SDL_SetColorKey(matriz, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(matriz->format, 255, 0, 255));
    SDL_BlitSurface(matriz, &grilla[op], pantalla, &recta);
    SDL_Flip(pantalla);
    SDL_PollEvent(&evento);
 
    while(evento.type!=SDL_QUIT)
    {
        if(evento.type==SDL_KEYDOWN)
        {
            switch(evento.key.keysym.sym)
            {
                case SDLK_UP:
                    if(op!=ARRIBA) op=ARRIBA;
                    recta.y-=3;
                break;
                case SDLK_DOWN:
                    if(op!=ABAJO) op=ABAJO;
                    recta.y+=3;
                break;
                case SDLK_RIGHT:
                    if(op!=DERECHA) op=DERECHA;
                    recta.x+=3;
                break;
                case SDLK_LEFT:
                    if(op!=IZQUIERDA) op=IZQUIERDA;
                    recta.x-=3;
                break;
                default:
                break;
            }
            SDL_Delay(10);
        }
        Limpiar(pantalla);
        SDL_BlitSurface(matriz, &grilla[op], pantalla, &recta);
        SDL_Flip(pantalla);
        SDL_PollEvent(&evento);
        SDL_Delay(10);
    }
    SDL_FreeSurface(matriz);
    SDL_Quit();
    return 0;
}
