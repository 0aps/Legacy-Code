#include <SDL/SDL.h>
#include <SDL/SDL_Image.h>

int  init ( SDL_Surface ** );
void procesar_eventos ( int *, int * );
void imprimir ( SDL_Surface *, SDL_Surface *, int, int, int );
int  posFondoX, cargar_imagen ( SDL_Surface **, SDL_Surface ** );
void pinta_fondo ( SDL_Surface *, SDL_Surface * );

int main ( int argc, char * argv[] )
{
  // Inicializa unas cuantas variables

  SDL_Surface * pantalla, * imagen, * fondo;
  int salir = 0, cuadro = 0, columna = 13, fila = 38;
  posFondoX = 0;

  // Inicializo las SDL
  if ( init ( &pantalla ) )
    return 1;
    
  // Carga de las dos imagenes que se utilizarán
  if ( cargar_imagen ( &imagen, &fondo ) )
    return 1;


  // Inicia un bucle de pintado
  while ( ! salir ) {

    pinta_fondo ( pantalla, fondo );

    cuadro ++;

    if ( cuadro > 13*38 )
      cuadro = 2;

    imprimir ( pantalla, imagen, cuadro, fila, columna );

    SDL_Flip ( pantalla );

    SDL_Delay ( 150 );

    // Al procesar los eventos, nos desplazarmos por la
    // la cuadrícula del sprite con cuadro

    procesar_eventos ( &salir, &cuadro );

  }

  // Finalizando
  SDL_Quit ();

  return 0;
}

// Inicializa la biblioteca SDL y genera la pantalla principal
int init ( SDL_Surface **pantalla )
{

  if ( SDL_Init ( SDL_INIT_VIDEO ) == -1 )
    return 1;

  *pantalla = SDL_SetVideoMode ( 370, 145, 16, SDL_DOUBLEBUF | SDL_HWSURFACE );

  if ( pantalla == NULL )

    return 1;

  SDL_WM_SetCaption ( "Ejemplo con las Firmas", NULL );

  return 0;
}

// Informa si el programa debe terminar
void procesar_eventos ( int * salir, int * cuadro )
{
  SDL_Event event;

  while ( SDL_PollEvent ( &event ) ) {

    if ( event.type == SDL_QUIT )
      * salir = 1;

    if ( event.type == SDL_KEYDOWN )

      switch ( event.key.keysym.sym ) {

        case SDLK_q:
        case SDLK_ESCAPE:
          * salir = 1;
          break;

        case SDLK_p:
          if ( * cuadro > 0)
            ( * cuadro ) --;
          break;

        case SDLK_o:
          if ( * cuadro < 17 )
            ( * cuadro ) ++;
                      break;
        default:
          break;
      }
  }
}

// Pinta el fondo en la pantalla
void pinta_fondo ( SDL_Surface * pantalla, SDL_Surface * fondo )
{
  SDL_Rect destino;
  int i;
  if ( posFondoX <= -370 ) posFondoX = -6; else posFondoX -= 3;
  for( i=0; i<=1; i++ ){
      destino = ( SDL_Rect ) { 370 * i + posFondoX, 0, 0, 0 };
      SDL_BlitSurface ( fondo, NULL, pantalla, &destino );
  }
}

// Cargamos las imagenes
int cargar_imagen ( SDL_Surface ** imagen, SDL_Surface ** fondo )
{
  * imagen = IMG_Load( "KyubiNaruto.png" );
  if ( * imagen == NULL )
    return 1;
    
    //verde
  SDL_SetColorKey ( * imagen, SDL_SRCCOLORKEY, SDL_MapRGB ( ( * imagen ) -> format, 0, 128, 0 ) );
  * fondo = IMG_Load ( "laFirma.bmp" );
  
  if ( * fondo == NULL )
    return 1;
  return 0;
}

// función que calcula el cuadro a mostrar de la animación
// y dibuja el que corresponde en la pantalla
void imprimir ( SDL_Surface * dst, SDL_Surface * imagen, int cuadro, int fila, int columna )
{
  SDL_Rect srcrect;
  SDL_Rect dstrect = { 70, 25, 0, 0 };
  //x,y,h,w
  
  if ( cuadro > fila * columna || cuadro < 0 )
    return;
  
  srcrect.w = imagen -> w / columna;
  srcrect.h = imagen -> h / fila;
  srcrect.x = (cuadro % columna) * srcrect.w;
  srcrect.y = (cuadro / columna) * srcrect.h;
  
  SDL_BlitSurface ( imagen, &srcrect, dst, &dstrect );
}
