#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
        
SDL_Event event;  //eventos
SDL_Surface *screen; //superficies
SDL_Surface *imagen;
Uint8 *keystate; // variable que recoge el valor de la tecla pulsada


//cuadro para colocar la imagen
SDL_Rect rect;
int done = 0;

//resolucion, 16 bytes x pixel, superficie, doble buffer (para que mientras trabaja con una
//imagen no muestre la otra // SDL_FULLSCREEN
screen = SDL_SetVideoMode(640,350,16, SDL_SWSURFACE | SDL_DOUBLEBUF );
if(!screen)
{
printf("No se pudo iniciar la pantalla: %s\n", SDL_GetError());
SDL_Quit();
return 1;
}

//nombre de la ventana
//nombre, icono
SDL_WM_SetCaption("Formato", NULL);

//cambiamos icono
//SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL);

//minimizar la aplicacion, devuelve 1 si salio bien
//int iconify = SDL_WM_IconifyWindow();



//cargo la imagen
imagen = IMG_Load ("ima.bmp");
rect.x = 0;
rect.y = 0;
rect.w = imagen->w; //ancho de imagen
rect.h = imagen->h; //alto de imagen


//elimina o anyade trasparencia a una IMAGEN
//superficie, permite volver trasparente el color indicado en el tercer parametro | acelera
//el blitting(pintado de imagen), y color que sera trasparente.
SDL_SetColorKey(imagen, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(imagen->format,0,0,0));

//bucle para pintar muchas veces
//for(int i=0; i<100; i++)
//{

//anyade trasparencia, parametros iguales que setcolorkey.
//nota: no funciona con imagenes .png        
//SDL_SetAlpha(imagen,SDL_SRCALPHA|SDL_RLEACCEL,rand() % 255); 

//SDL_FillRect(screen,&rect,SDL_MapRGB(screen->format,255,0,0)); //pinto un rectangulo
                                                               //format - color indicado [rojo];
//rect.x = rand() % 640;
//rect.y = rand() % 480;
//rect.w = imagen->w;
//rect.h = imagen->h;
                                    
                    //imagen a copiar
                    //parte de la img a copiar // si es null se dibuja toda la img
                    //surface donde se copia la imagen
                    //coordenadas a copiar                             
//SDL_BlitSurface(imagen, NULL, screen, &rect); //pinto la imagen
//}
SDL_Rect scre;
scre.x = 0;
scre.y = 0;
scre.w = screen->w; //ancho de imagen
scre.h = screen->h; //alto de imagen

//bucle
while (done == 0) {
      
//limpio la pantalla
SDL_FillRect(screen,&scre,SDL_MapRGB(screen->format,0,480,0));

//obtengo la letra pulsada
keystate = SDL_GetKeyState(NULL);

//patron 
if ( keystate[SDLK_UP]) {rect.y-=2;};
if ( keystate[SDLK_DOWN]) { if(rect.y < 250) rect.y+=2; } //solo llega hasta la cord.y 390 de la pantalla
if ( keystate[SDLK_LEFT]) { rect.x-=2;}
if ( keystate[SDLK_RIGHT]){ if(rect.x < 600) rect.x+=2; } //solo llega hasta la cord.x 600 de la pantalla

SDL_BlitSurface(imagen, 0, screen, &rect);

//Se actualiza la ventana, osea se muestra la superficie
SDL_Flip (screen);

// Comprobando teclas para opciones
//La función devuelve 1 si hay un evento pendiente de lo contrario 
//devuelve 0 (sale del bucle)
while (SDL_PollEvent(&event)) 
{
// Cerrar la ventana
   if (event.type == SDL_QUIT) { done = 1; }
// Pulsando una tecla

  // if (event.type == SDL_KEYUP)  //cualquier letra pulsada 
  // {
  //  done = 1;
  //  }
}

                  }
//liberamos
SDL_FreeSurface(imagen);
SDL_FreeSurface(screen);
SDL_Quit();

printf("\nTodo ha salido bien.\n");
return 0;
}

