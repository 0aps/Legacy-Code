#include <SDL/SDL.h>

#include <windows.h>

#define ARRIBA          243
#define IZQUIERDA       120
#define DERECHA         360
#define ABAJO           2

int main ( int argc, char** argv )
{
    if (SDL_Init(SDL_INIT_VIDEO)<0)
    {
        return 1;
    }

    atexit(SDL_Quit);

    SDL_Surface * screen = SDL_SetVideoMode(640,480,16,SDL_HWSURFACE|SDL_DOUBLEBUF);

    SDL_Surface * MiNave = SDL_LoadBMP("P1.BMP");       // nuestro personaje
    SDL_Surface * Casa1 = SDL_LoadBMP("Casa1.BMP");     // Casa tipo 1

    SDL_Rect pMiNave;  // posicion de nuestro personaje
    pMiNave.x = 0;
    pMiNave.y = 0;

    SDL_Rect pCasa1;    // posicion de la casa
    pCasa1.x = 100;
    pCasa1.y = 0;

    SDL_SetColorKey(MiNave, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(MiNave->format,255,0,0));
    SDL_SetColorKey(Casa1, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(Casa1->format,255,0,0));

    SDL_BlitSurface(Casa1, 0, screen, &pCasa1);

    SDL_Flip(screen);

    int CicloPrincipal = 1;
    Uint8 * Teclas;
    SDL_Event event;
    SDL_Rect Trozo;

    int Izquierda = 0,Derecha = 0,Abajo = 0,Arriba = 0;
    int IO = 0,DO = 0,AO,ARO = 0;

    Trozo.x = 0;

    while(CicloPrincipal)
    {
        Teclas = SDL_GetKeyState(NULL);

        if (Teclas[SDLK_UP])
        {
            pMiNave.y-=2;

            IO = 0;
            DO = 0;
            AO = 0;
            ARO = 1;

            if (Arriba == 0)
            {
                Arriba++;
                Trozo.x = ARRIBA+40;
            }else if(Arriba == 1){
                Arriba--;
                Trozo.x = ARRIBA+80;
            }
            goto NoParado;
        }
        if (Teclas[SDLK_DOWN])
        {
            pMiNave.y+=2;

            IO = 0;
            DO = 0;
            AO = 1;
            ARO = 0;

            if (Abajo == 0)
            {
                Abajo++;
                Trozo.x = ABAJO+40;
            }else if(Abajo == 1){
                Abajo--;
                Trozo.x = ABAJO+80;
            }
            goto NoParado;

        }
        if (Teclas[SDLK_LEFT])
        {
            pMiNave.x-=2;

            IO = 1;
            DO = 0;
            AO = 0;
            ARO = 0;

            if (Izquierda == 0)
            {
                Izquierda++;
                Trozo.x = IZQUIERDA+40;
            }else if(Izquierda == 1){
                Izquierda--;
                Trozo.x = IZQUIERDA+80;
            }
            goto NoParado;
        }
        if (Teclas[SDLK_RIGHT])
        {
            pMiNave.x+=2;

            IO = 0;
            DO = 1;
            AO = 0;
            ARO = 0;

            if (Derecha == 0)
            {
                Derecha++;
                Trozo.x = DERECHA+40;
            }else if(Derecha == 1){
                Derecha--;
                Trozo.x = DERECHA+80;
            }
            goto NoParado;
        }

        if (IO == 1) {Trozo.x = IZQUIERDA ;}
        if (DO == 1) {Trozo.x = DERECHA;}
        if (AO == 1) {Trozo.x = ABAJO;}
        if (ARO == 1) {Trozo.x = ARRIBA;}

        NoParado:
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,240,100));


        Trozo.w = 40;
        Trozo.y = 0;
        Trozo.h = 60;


        SDL_BlitSurface(Casa1, 0, screen, &pCasa1);
        SDL_BlitSurface(MiNave, &Trozo, screen, &pMiNave);

        SDL_Flip(screen);

        if(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) { CicloPrincipal = 0; } // Boton salir.
        }
    }

    return 0;
}
