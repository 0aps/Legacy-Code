#include <SDL/SDL.h>
#include <stdio.h>

int init (SDL_Surface **screen);
void procesar_eventos (int *salir, int *cuadro);
void imprimir(SDL_Surface *dst, SDL_Surface *ima, int cuadro, int fil, int col);
int cargar_imagen(SDL_Surface **ima);
void limpiar(SDL_Surface *screen);


int main (int argc, char **argv)
{
	SDL_Surface *screen;
	SDL_Surface *ima;
	int salir = 0;
	int cuadro = 0;
	int col = 9;
	int fil = 2;
	
	if (init(&screen))
		return 1;

	if (cargar_imagen(&ima))
		return 1;
	
	while (! salir) {
		limpiar(screen);

		cuadro ++;

		if (cuadro > 16)
			cuadro = 2;

		imprimir(screen, ima, cuadro, fil, col);
		SDL_Flip(screen);
		SDL_Delay(50);
		procesar_eventos(&salir, &cuadro);
	}
	
	
	SDL_Quit();
	return 0;
}


/*
 * Inicializa la biblioteca SDL y genera la pantalla principal
 */
int init (SDL_Surface **screen)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}

	*screen = SDL_SetVideoMode(320, 200, 16, SDL_DOUBLEBUF | SDL_HWSURFACE);
	
	if (screen == NULL) {
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}
	
	SDL_WM_SetCaption("Grillas de sprites y animación (I)", NULL);
	
	return 0;
}


/*
 * Informa si el programa debe terminar
 */
void procesar_eventos (int *salir, int *cuadro)
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		
		if (event.type == SDL_QUIT)
			*salir = 1;

		if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym) {
				case SDLK_q:
				case SDLK_ESCAPE:
					*salir = 1;
					break;

				case SDLK_3:
					if (*cuadro > 0)
						(*cuadro)--;
					break;

				case SDLK_4:
					if (*cuadro < 17)
						(*cuadro)++;
					break;
					
				default:
					break;
			}
	}
}

/*
 * Pinta toda la pantalla
 */
void limpiar (SDL_Surface *screen)
{
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 150, 150, 150));
}



/*
 * Carga y optimiza un fichero grafico
 */
int cargar_imagen (SDL_Surface **ima)
{
	*ima = SDL_LoadBMP("ima.bmp");

	if (*ima == NULL)
		return 1;

	SDL_SetColorKey(*ima, SDL_SRCCOLORKEY, \
			SDL_MapRGB((*ima)->format, 255, 0, 255));
	
	return 0;
}



void imprimir(SDL_Surface *dst, SDL_Surface *ima, int cuadro, int fil, int col)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect = {100, 50, 0, 0};

	if (cuadro > fil * col || cuadro < 0) {
		printf("error, no se puede acceder al cuadro %d\n", cuadro);
		return;
	}

	srcrect.w = ima->w / col;
	srcrect.h = ima->h / fil;
	srcrect.x = (cuadro % col) * srcrect.w;
	srcrect.y = (cuadro / col) * srcrect.h;

	/* se evita imprimir la linea que divide cada cuadro */
	srcrect.x ++;
	srcrect.y ++;
	srcrect.w --;
	srcrect.h --;
	
	SDL_BlitSurface(ima, &srcrect, dst, &dstrect);
}
