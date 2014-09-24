#include <SDL/SDL.h>
#include <time.h>
 
void putpixel ( SDL_Surface *, int, int, Uint32 );
 
int main ( int argc, char *argv[] )
{
	int esquinas [3][2] = {
		100,	10,
		0,	190,
		200,	190
	};
 
	srand ( time ( NULL ) );
 
	SDL_Surface *pantalla;
	SDL_Event evento;
	int color, i, a=0, x=0, y=0;
 
	if ( SDL_Init ( SDL_INIT_VIDEO ) )
	{
		fprintf ( stderr, "No se pudo iniciar SDL\nCausa: %s\n\n", SDL_GetError() );
		return -1;
	}
 
	pantalla = SDL_SetVideoMode ( 200, 200, 16,  SDL_HWSURFACE | SDL_DOUBLEBUF );
	if(!pantalla)
	{
		fprintf( stderr, "No se puedo configurar la pantalla\nCausa: %s\n\n", SDL_GetError() );
		return -1;
	}
 
	SDL_PollEvent(&evento);
 
	color = SDL_MapRGB ( pantalla->format, 255, 0, 0 );
 
	while ( evento.key.keysym.sym != SDLK_ESCAPE )
	{
		/* Bloquear la pantalla para poner directamente los pixeles */
		if ( SDL_MUSTLOCK ( pantalla ) ) {
			if ( SDL_LockSurface ( pantalla ) < 0 ) {
				fprintf ( stderr, "No puedo bloquear la pantalla: %s\n", SDL_GetError() );
			}
		}
 
		a = 3.0 * rand() / ( RAND_MAX+0.0 );
		x = ( x + esquinas[a][0] ) / 2;
		y = ( y + esquinas[a][1] ) / 2;
 
		putpixel ( pantalla, x, y, color );
 
		/* Desbloquear pantalla */
		if ( SDL_MUSTLOCK ( ( pantalla ) ) )
			SDL_UnlockSurface ( pantalla );
 
		SDL_Flip ( pantalla );
		SDL_PollEvent ( &evento );
	}
	SDL_Quit();
	return 0;
}
 
/*
 * Funcion procedente de la documentación de la libreria
 * libsdl1.2-dev/docs/html/guidevideo.html#AEN93
 * NOTA: La superficie debe ser bloqueada antes de la llamada
 */
void putpixel ( SDL_Surface *surface, int x, int y, Uint32 pixel )
{
	int bpp = surface->format->BytesPerPixel;
	/* Aquí p is la direción en la que el pixel debe establecerse */
	Uint8 *p = ( Uint8 * ) surface->pixels + y * surface->pitch + x * bpp;
 
	switch ( bpp )
	{
		case 1:
			* p = pixel;
			break;
 
		case 2:
			* ( Uint16 * ) p = pixel;
        		break;
 
		case 3:
			if ( SDL_BYTEORDER == SDL_BIG_ENDIAN )
			{
				p[0] = ( pixel >> 16 ) & 0xff;
				p[1] = ( pixel >> 8 ) & 0xff;
				p[2] = pixel & 0xff;
			} else {
				p[0] = pixel & 0xff;
				p[1] = ( pixel >> 8 ) & 0xff;
				p[2] = ( pixel >> 16 ) & 0xff;
			}
			break;
 
		case 4:
			* ( Uint32 * ) p = pixel;
			break;
	}
}
