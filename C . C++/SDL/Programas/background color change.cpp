#include <SDL/SDL.h>

/*
  Name: Bg Color change
  Copyright: GPL
  Author: @aps
  Date: 07/08/11 13:56
  Description: Troling around with SLD 
*/


int main(int argc, char *argv[])
{
    SDL_Surface *pantalla;
    SDL_Event evento;
    int r(0),g(0),b(0);
    
    
    if( SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
    printf("No se pudo iniciar SDL: %s\n", SDL_GetError());
    return 1;
    }

    pantalla = SDL_SetVideoMode(640,350,16, SDL_SWSURFACE | SDL_DOUBLEBUF ); 
    
    if(!pantalla)
    {
    printf("No se pudo iniciar la pantalla: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
    }
    
    SDL_WM_SetCaption("Background Color", NULL);
    
  
// Mientras se capture el evento y no se precione la X
while ( evento.type != SDL_QUIT )
{
            SDL_FillRect(
                         pantalla ,
                         NULL     , // pinto la pantalla entera.
                         SDL_MapRGB(pantalla->format, r, g, b) ); //pinto un rectangulo
   
            SDL_Flip(pantalla);
    
      
      SDL_PollEvent(&evento); 
      
       if(evento.type == SDL_KEYDOWN)
       {
                                   if(evento.key.keysym.sym == SDLK_UP)
                                      g++; //green
                                   if(evento.key.keysym.sym == SDLK_LEFT)
                                      r++; //red
                                   if(evento.key.keysym.sym == SDLK_RIGHT)
                                      b++; //blue
       }
        
         if(r == 256 || g == 256 || b == 256)
         r = g = b = 0;
       
       
    
       
       
}
                
//liberamos
SDL_FreeSurface(pantalla);
SDL_Quit();


return 0;
}    
