#include <SDL/SDL.h>

// Colores: ( R, G, B)
// Rojo: (255, 0, 0)
// Naranja: (255, 168, 0)
// Verde: ( 0, 255, 0)

/*
  Name: Semaforo
  Copyright: GPL    
  Author: @aps
  Date: 07/08/11 13:13
  Description: First app in SDL :) 
*/


void semaforo(SDL_Surface *, SDL_Rect);

    SDL_Event evento;
    SDL_Surface *pantalla;
    SDL_Rect rect;
    bool aparecer[3] = {false,false,false};

int main(int argc, char *argv[])
{
    
    
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
    
    SDL_WM_SetCaption("Semaforo", NULL);
    
     
// Mientras se capture el evento y no se precione la X
while ( evento.type != SDL_QUIT )
{
      SDL_PollEvent(&evento); 
      
       if(evento.type==SDL_KEYDOWN)
      {
        if(evento.key.keysym.sym == SDLK_r) //rojo
        { 
          if(aparecer[0] != true)
             {
                         aparecer[0] = true;
             }else aparecer[0] = false;
        }
             
        
        if(evento.key.keysym.sym == SDLK_v) // verde
        {
          if(aparecer[1] != true)
             {
                         aparecer[1] = true;
             }else aparecer[1] = false;
        }
         
                     
        if(evento.key.keysym.sym == SDLK_n) // naranja
        {
            if(aparecer[2] != true)
             {
                         aparecer[2] = true;
             }else aparecer[2] = false;
        } 
        
        
      }
      
      
      semaforo(pantalla, rect);
      SDL_Flip (pantalla);
      SDL_Delay(60); // deley para que no se actualice tan rapido 
      
}
                
//liberamos
SDL_FreeSurface(pantalla);
SDL_Quit();


return 0;
}    


void semaforo(SDL_Surface *pantalla, SDL_Rect rect)
{
     
    //fondo
    SDL_FillRect(pantalla ,
                 NULL     ,
                 SDL_MapRGB(pantalla->format, 255, 255, 255) ); //pinto un rectangulo
    
   
    //cubo
    rect.x = 250;
    rect.y = 90;
    rect.w = 100;
    rect.h = 145;
    
    SDL_FillRect(pantalla ,
                 &rect    ,
                 SDL_MapRGB(pantalla->format,255, 220, 0) ); //pinto un rectangulo
        
   //linea
   
    rect.y = 90;
    rect.h = 10;     
  
    SDL_FillRect(pantalla ,
                 &rect    ,
                 SDL_MapRGB(pantalla->format,0, 0, 0) ); //pinto un rectangulo
  
  
    //rojo
    if(aparecer[0] == true)
    {
    rect.y = 100;
    rect.h = 35;     
  
    SDL_FillRect(pantalla ,
                 &rect    ,
                 SDL_MapRGB(pantalla->format,255, 0, 0) ); //pinto un rectangulo
    
    }  
   
   //linea
   
    rect.y = 135;
    rect.h = 10;     
  
    SDL_FillRect(pantalla ,
                 &rect    ,
                 SDL_MapRGB(pantalla->format,0, 0, 0) ); //pinto un rectangulo
   
   
   
   //verde
    if(aparecer[1] == true)
    {
    rect.y = 145;
    rect.h = 35;     
  
    SDL_FillRect(pantalla ,
                 &rect    ,
                 SDL_MapRGB(pantalla->format, 0, 255, 0 ) ); //pinto un rectangulo
    }
    
   //linea
    rect.y = 180;
    rect.h = 10;     
  
    SDL_FillRect(pantalla ,
                 &rect    ,
                 SDL_MapRGB(pantalla->format,0, 0, 0) ); //pinto un rectangulo
   
   
    //naranja
    if(aparecer[2] == true)
    {
    rect.y = 190;
    rect.h = 35;     
    
    
     SDL_FillRect(pantalla ,
                 &rect    ,
                 SDL_MapRGB(pantalla->format, 255, 168, 0) ); //pinto un rectangulo
    }
    
      //linea
   
    rect.y = 225;
    rect.h = 10;     
    
     SDL_FillRect(pantalla ,
                 &rect    ,
                 SDL_MapRGB(pantalla->format,0, 0, 0) ); //pinto un rectangulo
   
  
}
