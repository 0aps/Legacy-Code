#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL.h>

#define Limpiar(pantalla) SDL_FillRect(pantalla, NULL, SDL_MapRGB(pantalla->format, 0, 0, 0))
#define DERECHA 0
#define IZQUIERDA 1
#define ARRIBA 2
#define ABAJO 3

inline double Medir(int, int, int, int);
inline bool ComprobarColision(SDL_Rect, SDL_Rect);
inline bool SDL_CollideBoundingBox(SDL_Rect, SDL_Rect);
inline void Acercar(SDL_Rect*, SDL_Rect, int*, int);

int main(int argc, char *argv[])
{
    srand(time(NULL));
    SDL_Surface *pantalla, *matriz, *colision;
    SDL_Event evento;
    SDL_Rect grilla[4], recta={0, 0, 100, 100}, recto;
    int i, op=rand()%4;
    bool dibujar=true, perseguir=false;
  
    if(SDL_Init(SDL_INIT_VIDEO)) return -1;
    pantalla=SDL_SetVideoMode(800, 500, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(!pantalla) return -2;
    SDL_WM_SetCaption("Testeando...", NULL);
    matriz=SDL_LoadBMP("matriz.bmp");
    colision=SDL_LoadBMP("mariano.bmp");
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
    recto.x=700, recto.y=430;
    recto.w=colision->w;
    recto.h=colision->h;
    SDL_SetColorKey(matriz, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(matriz->format, 255, 0, 255));
    SDL_SetColorKey(colision, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(colision->format, 255, 0, 255));
    SDL_BlitSurface(matriz, &grilla[op], pantalla, &recta);
    SDL_BlitSurface(colision, NULL, pantalla, &recto);
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
                case SDLK_a:
                    if(dibujar) dibujar=false;
                    else dibujar=true;
                    recto.x=rand()%800;
                    recto.y=rand()%500;
                    SDL_Delay(300);
                break;
                case SDLK_p:
                    if(perseguir) perseguir=false;
                    else perseguir=true;
                    SDL_Delay(300);
                break;
                default:
                break;
            }
            SDL_Delay(10);
        }
        Limpiar(pantalla);
        if(!dibujar) perseguir=false;
        if(dibujar&&perseguir)
        {
            Acercar(&recta, recto, &op, 8);
        }
        SDL_BlitSurface(matriz, &grilla[op], pantalla, &recta);
        if(dibujar) SDL_BlitSurface(colision, NULL, pantalla, &recto);
        if(ComprobarColision(recta, recto)&&dibujar)
        {
            dibujar=false;
            recta.x=0;
            recta.y=0;
            SDL_Delay(10);
        }
        SDL_Flip(pantalla);
        SDL_PollEvent(&evento);
        SDL_Delay(10);
    }
    SDL_FreeSurface(matriz);
    SDL_Quit();
    return 0;
}

inline double Medir(int x1, int y1, int x2, int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

inline bool ComprobarColision(SDL_Rect recta1, SDL_Rect recta2)
{
    int r1, r2;
    int x1=recta1.x+(recta1.w/2), x2=recta2.x+(recta2.w/2);
    int y1=recta1.y+(recta1.h/2), y2=recta2.y+(recta2.h/2);
    r1=((recta1.w+recta1.h)/2)/2;
    r2=((recta2.w+recta2.h)/2)/2;
    if(Medir(x1, y1, x2, y2)<(r1+r2)) return true;
    return false;
}

inline bool SDL_CollideBoundingBox(SDL_Rect recta1, SDL_Rect recta2)
{
if(recta2.x + recta2.w < recta1.x) return false;
if(recta2.x > recta1.x + recta1.w) return false;

if(recta2.y + recta2.h < recta1.y) return false;
if(recta2.y > recta1.y + recta1.h) return false;

return true;
}

inline void Acercar(SDL_Rect *recta, SDL_Rect recto, int *op, int num)
{
    int i;
    for(i=0; i<=num; i++)
    {
             //recta matriz
             
        if(recta->x>recto.x)
        {
            if(*op!=IZQUIERDA) *op=IZQUIERDA;
            recta->x--;
        }
        else if(recta->x<recto.x)
        {
            if(*op!=DERECHA) *op=DERECHA;
            recta->x++;
        }
        if(recta->y>recto.y)
        {
            if(*op!=ARRIBA) *op=ARRIBA;
            recta->y--;
        }
        else if(recta->y<recto.y)
        {
            if(*op!=ABAJO) *op=ABAJO;
            recta->y++;
        }
    }
    SDL_Delay(10);
} 
