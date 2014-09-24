#include <SDL/SDL.h>
#include <SDL.h>
#include <windows.h>

#include "ListaMapas.h"

void DibujarMapa(); // Dibuja el mapa enfocado y como corresponde en el mapa virtual
void BloqueoSN();   // comprueba si el lugar donde nos situaremos se puede pisar.
void EntrarSN();   // Funcion que determina si el oobjeto donde vamos a pisar es una puerta

struct Personaje   // posicion en la pantalla
{
    int bx;
    int by;
    int ax;
    int ay;
};

struct pPersonaje  // posicion sobre el mapa
{
    int x;
    int y;
};

Personaje Yo;
pPersonaje mPosicion;

SDL_Rect PorcionMapa;
SDL_Rect pMapa;

SDL_Surface* bmp;     // ID de la imagen que contiene los Tiles
SDL_Surface* screen;  // ID de la ventana

int EjeX=0,EjeY=0;  // Para situal el mapa en la posicion donde nos encontramos (Realizar el scroll)
int TI,TD,TA,TAB;   // Tecla activada porsi nos encontramos lugares por donde no podamos pasar

int main (int argc,char** argv)
{
    mPosicion.x = 10;  // Posicion en coordenadas donde comenzamos
    mPosicion.y = 10;  // ...

    Yo.bx = 20;         // Coordenada centrada de la vista del muñeco
    Yo.by = 20;
    Yo.ax = 20;
    Yo.ay = 19;

    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    screen = SDL_SetVideoMode(20*15, 20*15, 16,SDL_HWSURFACE|SDL_DOUBLEBUF);

    bmp = SDL_LoadBMP("Tiles.BMP");

    pMapa.x = 0;  // Coordenadas de la pantalla
    pMapa.y = 0;

    PorcionMapa.x = 0;  //  porcion donde se encontrara el tile
    PorcionMapa.y = 0;  // ...
    PorcionMapa.w = 15; // Tamaño del Tile
    PorcionMapa.h = 15; // ...

    Uint8 * Teclas;
    SDL_Event event;

    while (true)
    {
        Teclas = SDL_GetKeyState(NULL);

        if(SDL_PollEvent(&event)){if (event.type == SDL_QUIT) {break;}} // Boton salir

        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 0, 255));

        DibujarMapa();  // Dibujamos el mapa enfocado

        if (Teclas[SDLK_UP])
        {
            if (EjeY!=0)
            {
                TA = 1;
                TAB = 0;
                TD = 0;
                TI = 0;

                EjeY-=1;
                mPosicion.y -=1;
            }
        }
        if (Teclas[SDLK_DOWN])
        {
           if (EjeY<30)
            {
                TA = 0;
                TAB = 1;
                TD = 0;
                TI = 0;

                EjeY+=1;
                mPosicion.y +=1;
            }
        }
        if (Teclas[SDLK_LEFT])
        {
            if (EjeX!=0)
            {
                TA = 0;
                TAB = 0;
                TD = 0;
                TI = 1;

                EjeX-=1;
                mPosicion.x -=1;
            }
        }
        if (Teclas[SDLK_RIGHT])
        {
                if (EjeX<30)
                {
                   TA = 0;
                   TAB = 0;
                   TD = 1;
                   TI = 0;

                   EjeX+=1;
                   mPosicion.x +=1;
                }
        }

        BloqueoSN(); // comprovamos si nuestro proximo movimiento esta bloqueado, si lo esta no se movera.

        pMapa.x = Yo.bx*7.5;   // Calculamos donde caera la parte baja de nuestro jugador
        pMapa.y = Yo.by*7.5;

        PorcionMapa.x = TIERRAX;
        PorcionMapa.y = TIERRAY;

        SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);    // Nos situamos en la posicion.

        pMapa.x = Yo.ax*7.5;   // Calculamos donde caera la parte alta de nuestro jugador
        pMapa.y = Yo.ay*7.2;

        PorcionMapa.x = TIERRAX;
        PorcionMapa.y = TIERRAY;

        SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);    // Nos situamos en la posicion.

        pMapa.x = 0;
        pMapa.y = 0;

        EntrarSN(); // comprovamos si estamos en una puerta

        SDL_Flip(screen);
        SDL_Delay(100);
    }

    SDL_FreeSurface(bmp);
    return 0;
}

void DibujarMapa() // Dibuja el mapa enfocado y como corresponde en el mapa virtual
{
    int i,a;

    for (i=EjeY;i<50;i++)  // Eje Y
    {
        for (a=EjeX;a<50;a++)  // Eje X
        {
            if ((*Mapa)[i][a] == '0') // Cesped
            {
                PorcionMapa.y = 0;
                PorcionMapa.x = COLUMNA1;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == '1'){ // Cesped flor azul
                PorcionMapa.y = 0;
                PorcionMapa.x = CESPEDFLOR;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if((*Mapa)[i][a] == '2'){  // Tierra
                PorcionMapa.x = TIERRAX;
                PorcionMapa.y = TIERRAY;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == '3')   // flor roja
            {
                PorcionMapa.x = CESPEDFLORRX;
                PorcionMapa.y = CESPEDFLORRY;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'V'){   // Valla cesped horizontal
                PorcionMapa.x = VALLACESPED;
                PorcionMapa.y = CESPEDFLORRY;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'v'){   // Valla cesped vertical
                PorcionMapa.x = VALLACESPED2;
                PorcionMapa.y = CESPEDFLORRY;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'Q'){   // Casa arbol arriba izquierda
                PorcionMapa.x = C_AAIX ;
                PorcionMapa.y = COLUMNA1;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'W'){   // Casa arbol arriba centro
                PorcionMapa.x = C_AACX ;
                PorcionMapa.y = COLUMNA1;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'E'){   // Casa arbol arriba derecha
                PorcionMapa.x = C_AADX ;
                PorcionMapa.y = COLUMNA1;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'R'){
                PorcionMapa.x = C_AAIX ;
                PorcionMapa.y = COLUMNA2;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'T'){
                PorcionMapa.x = C_ACM ;
                PorcionMapa.y = COLUMNA2;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'Y'){
                PorcionMapa.x = C_ADM ;
                PorcionMapa.y = COLUMNA2;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'U'){
                PorcionMapa.x = C_ABI;
                PorcionMapa.y = COLUMNA3;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'I'){
                PorcionMapa.x = C_ABC ;
                PorcionMapa.y = COLUMNA3;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'O'){
                PorcionMapa.x = C_ABD ;
                PorcionMapa.y = COLUMNA3;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'A'){
                PorcionMapa.x = C_ASI ;
                PorcionMapa.y = COLUMNA4;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'S'){
                PorcionMapa.x = C_ASC ;
                PorcionMapa.y = COLUMNA4;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'D'){
                PorcionMapa.x = C_ASD ;
                PorcionMapa.y = COLUMNA4;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'G'){
                PorcionMapa.x = CARTEL1;
                PorcionMapa.y = COLUMNA3;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'b'){
                PorcionMapa.x = VALLACESPED3;
                PorcionMapa.y = COLUMNA3;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'H'){
                PorcionMapa.x = CAMINOVERTICAL;
                PorcionMapa.y = COLUMNA1;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'J'){
                PorcionMapa.x = CAMINOGD;
                PorcionMapa.y = COLUMNA3;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'K'){
                PorcionMapa.x = CAMINOHORIZONT;
                PorcionMapa.y = COLUMNA1;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'L'){
                PorcionMapa.x = A_AI;
                PorcionMapa.y = COLUMNA3;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'Ñ'){
                PorcionMapa.x = A_AD;
                PorcionMapa.y = COLUMNA3;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'Z'){
                PorcionMapa.x = A_MI;
                PorcionMapa.y = COLUMNA4;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'X'){
                PorcionMapa.x = A_MD;
                PorcionMapa.y = COLUMNA4;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'C'){
                PorcionMapa.x = A_AI;
                PorcionMapa.y = COLUMNA5;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }else if ((*Mapa)[i][a] == 'B'){
                PorcionMapa.x = A_AD;
                PorcionMapa.y = COLUMNA5;
                SDL_BlitSurface(bmp, &PorcionMapa, screen, &pMapa);
            }



            pMapa.x +=15;
        }
        pMapa.y+=15;
        pMapa.x = 0;
    }
    pMapa.x = 0;
    pMapa.y = 0;
}

void BloqueoSN() // comprueba si nuestra proxima posición esta bloquedada.
{
    if ((*EstadoObj)[mPosicion.y][mPosicion.x] == '1')
    {   // No podemos pasar por ahi!! :P
        if (TD == 1) {EjeX-=1;mPosicion.x -=1;}
        if (TI == 1) {EjeX+=1;mPosicion.x +=1;}
        if (TA == 1) {EjeY+=1;mPosicion.y +=1;}
        if (TAB == 1) {EjeY-=1;mPosicion.y -=1;}
    }
}

void EntrarSN() // determina si es una puerta y algo por el estilo
{
    if ((*EstadoObj)[mPosicion.y][mPosicion.x] == '2')
    {   // Tenemos que pasar!
        MessageBoxA(0,"Ahora pasaríamos por la puerta",0,0);
    }
}

