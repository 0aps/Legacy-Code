#include <SDL/SDL.h>
#include <stdlib.h>
     
    int main ( int argc, char** argv )
    {
        if (SDL_Init(SDL_INIT_VIDEO)<0)
        {
            return 1;
        }
     
       SDL_Surface* screen = SDL_SetVideoMode(640,480,16,SDL_HWSURFACE|SDL_DOUBLEBUF);
        if ( !screen )
        {
            return 1;
        }
     
        SDL_Surface* MiNave = SDL_LoadBMP("nave.bmp");
        if (!MiNave)
        {
            return 1;
        }
     
        SDL_Rect pMiNave;
        pMiNave.x = 0;
        pMiNave.y = 0;
        
pMiNave.w = MiNave->w; //ancho de imagen
pMiNave.h = MiNave->h; //alto de imagen
     
        SDL_SetColorKey(MiNave, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(MiNave->format,255,0,0));
     
        int CicloPrincipal = 1;
        Uint8 * Teclas;
     
SDL_Event event;  //eventos
        while(CicloPrincipal)
        {
            
            SDL_FillRect(screen, 0, SDL_MapRGB(screen->format,0,255,0));
             
            Teclas = SDL_GetKeyState(NULL);
     
            if (Teclas[SDLK_UP]) {pMiNave.y-=2;}
            if (Teclas[SDLK_DOWN]) {pMiNave.y+=2;}
            if (Teclas[SDLK_LEFT]) {pMiNave.x-=2;}
            if (Teclas[SDLK_RIGHT]){pMiNave.x+=2;}
     
            SDL_BlitSurface(MiNave, 0, screen, &pMiNave);
            SDL_Flip(screen);
            
     // Comprobando teclas para opciones
while (SDL_PollEvent(&event)) 
{
// Cerrar la ventana
   if (event.type == SDL_QUIT) { CicloPrincipal = 0; }

}
            
    }

        return 0;
}
