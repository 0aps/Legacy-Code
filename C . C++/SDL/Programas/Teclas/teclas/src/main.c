/*
 * Mini ejemplo : teclas
 * Copyright (C) 2005 Hugo Ruscitti
 *
 * Este programa es software libre. Puede redistribuirlo y/o 
 * modificarlo bajo los términos de la Licencia Pública General	de 
 * GNU según es publicada por la Free Software Foundation, bien de 
 * la versión 2 de dicha Licencia o bien (según su elección) de 
 * cualquier versión posterior.
 * 
 * Este programa se distribuye con la esperanza de que sea útil, pero
 * SIN NINGUNA GARANTÍA, incluso sin la garantía MERCANTIL implícita 
 * o sin garantizar la CONVENIENCIA PARA UN PROPÓSITO PARTICULAR. 
 * Véase la Licencia Pública General de GNU para más detalles.
 * 
 * Debería haber recibido una copia de la Licencia Pública General 
 * junto con este programa. Si no ha sido así, escriba a la Free 
 * Software Foundation, Inc., en 675 Mass Ave, Cambridge, 
 * MA 02139, EEUU.
 */

#include <SDL/SDL.h>
#include <stdio.h>
#include <ctype.h>

int iniciar (SDL_Surface **screen);
void info (void);
int leer_teclado (char *cadena, int limite, SDL_Surface *screen);
void agregar(char *cadena, int lim, char letra, SDL_Surface *screen);
void imprimir(char letra, int x, int y, SDL_Surface *screen);
void put_pixel(SDL_Surface *_ima, int x, int y, Uint32 pixel);
void borrar(int lim, SDL_Surface *screen);
void limpiar(SDL_Surface *screen, int x, int y, int w, int h);
int es_letra (SDLKey letra);


#ifdef WIN32
#include <windows.h>
int WINAPI WinMain(HINSTANCE x1, HINSTANCE x2, LPSTR x3, int x4)
#else
/**
 * \brief programa principal
 */
int main (void)
#endif
{
	SDL_Surface *screen;
	char cadena[25];
	int retorno;

	info ();

	if (iniciar(&screen))
		return 1;

	limpiar(screen, 0, 0, screen->w, screen->h);

	retorno = leer_teclado (cadena, 25, screen);

	if (retorno == 0)
		printf("La cadena escrita es : '%s'\n", cadena);
	else
		printf("en 'main()', leer_teclado fué cancelada\n"); 
	
	SDL_Quit();
	return 0;
}


/**
 * \brief imprime la información inicial del programa
 */
void info (void)
{
	printf("Mini ejemplo: teclas\n");
	printf("Licencia: GPL\n");
	printf("Autor: Hugo Ruscitti\n");
	printf("Web: www.losersjuegos.com.ar\n");
	printf("\n");
}


/**
 * \brief inicializa la biblioteca SDL
 * 
 * \return 1 en caso de error
 */
int iniciar (SDL_Surface **screen)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1) 
	{
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}

	*screen = SDL_SetVideoMode(320, 240, 16, SDL_SWSURFACE);
	
	if (screen == NULL) 
	{
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}
	
	SDL_WM_SetCaption("Lectura de teclado", NULL);
	
	return 0;
}


/**
 * \brief detiene el programa para que el usuario ingrese un texto en 'cadena'
 *
 * \param cadena puntero al primer elemento del vector de 'char'
 * \param limite_real cantidad de posiciones del vector cadena
 * \param screen pantalla destino, para imprimir los caracteres
 * 
 * \return 1 si no obtiene una cadena (por cancelar o cerrar la ventana)
 */
int leer_teclado (char *cadena, int limite_real, SDL_Surface *screen)
{
	SDL_Event event;
	int lim = 0; // cantidad de caracteres útiles en la cadena
	SDLKey tecla;

	
	// espera por un evento
	while (SDL_WaitEvent(&event))
	{
		
		// si cierran la ventana
		if (event.type == SDL_QUIT)
		{
			printf("Cancelaron el ingreso de datos\n");
			return 1;
		}
		
		
		// si pulsan una tecla
		if (event.type == SDL_KEYDOWN)		
		{
			tecla = event.key.keysym.sym;
			
			switch (tecla)
			{
				
				case SDLK_ESCAPE:
					printf("Pulsó ESC, cancelando\n");
					return 1;
					break;
					
					
				case SDLK_RETURN:
					cadena[lim] = '\0'; // fin de cadena
					printf("Pulsó ENTER, terminado\n");
					return 0;
					break;
	
					
				case SDLK_BACKSPACE:
					if (lim > 0)
					{
						printf("Quitando:  '%c'\n", cadena[lim-1]);
						borrar(lim - 1, screen);
						lim --;
					}
					else
					{
						printf("Cadena vacia\n");
					}
					break;

					
				case SDLK_SPACE:
				
					if (lim < limite_real - 1)
					{
						agregar(cadena, lim, ' ', screen);
						lim ++;
					}
					else
					{
						printf("Llegó al limite\n");
					}

					break;
					
				default:

					if (lim < limite_real - 1)
					{
						if (es_letra(tecla))
						{
							agregar(cadena, lim, tecla - SDLK_a + 'a', screen);
							lim ++;
						}
						else
						{
							printf("Solo se admiten letras ('a' - 'z')\n");
						}
					}
					else
					{
						printf("Llegó al limite\n");
					}
					
					break;
			}
		}
	}
	
	return 1;
}



/**
 * \brief intenta añadir un nuevo caracter a 'cadena'
 *
 * \param cadena puntero al primer elemento del vector de chars
 * \param lim puntero al límite original de caracteres válidos en la cadena
 * \param screen pantalla destino
 */
void agregar(char *cadena, int lim, char letra, SDL_Surface *screen)
{
	imprimir(letra, 10 + (lim * 12), 100, screen);
	cadena[lim] = letra;
	printf("Agregando: '%c'\n", letra);
}

/**
 * \brief imprime un caracter sobre una superficie
 *
 * \param letra el caracter a imprimir
 * \param x coordenada x
 * \param y coordenada y
 * \param screen superficie destino
 */
void imprimir(char letra, int x, int y, SDL_Surface *screen)
{
	char mapa[6][150]={\
		{"AAAA BBBB CCCC DDDD EEEE FFFF GGGG HHHH IIIII JJJJ KKKK LLLL MMMMM NNNNN OOOO PPPP QQQQQ RRRR SSSSS TTTTT UUUU VVVVV WWWWW XXXX YYYYY ZZZZ"},\
		{" oo  ooo   ooo ooo  oooo oooo  ooo o  o   o    ooo o  o o    o   o o   o oooo ooo   ooo  ooo   ooo   ooo  o  o o   o o   o o  o o   o oooo"},\
		{"o  o o  o o    o  o o    o    o    o  o   o      o o o  o    oo oo oo  o o  o o  o o   o o  o o       o   o  o o   o o   o o  o o   o    o"},\
		{"oooo ooo  o    o  o oo   ooo  o oo oooo   o      o oo   o    o o o o o o o  o ooo  o o o ooo   ooo    o   o  o o   o o   o  oo   o o    o "},\
		{"o  o o  o o    o  o o    o    o  o o  o   o   o  o o o  o    o   o o  oo o  o o    o  oo o  o     o   o   o  o  o o  o o o o  o   o    o  "},\
		{"o  o ooo   ooo ooo  oooo o     ooo o  o   o    oo  o  o oooo o   o o   o oooo o     oooo o  o oooo    o   oooo   o    o o  o  o  o    oooo"}\
	};
	Uint32 color = SDL_MapRGB(screen->format, 255, 255, 255);
	int i;
	int col = 0;
	int fil;

	letra = toupper (letra);

	// busca su columna en 'mapa' y la guarda en 'i'
	for (i = 0; mapa[0][i] != letra; i ++)
		;

	// imprime la letra recorriendo filas y columnas
	for (; mapa[0][i] == letra; i++)
	{
		for (fil = 1; fil < 6; fil ++)
		{
			if (mapa[fil][i] != ' ')
				put_pixel(screen, x + col * 2 , y + fil * 2, color);
		}

		col ++;
	}

	SDL_UpdateRect(screen, x, y, col * 2 , fil * 2);
}


/**
 * \brief imprime un pixel de color en la pantalla (original de SDL)
 *
 * \param _ima superficie destino
 * \param x coordenada x
 * \param y coordenada y
 * \param pixel color
 */
void put_pixel(SDL_Surface *_ima, int x, int y, Uint32 pixel)
{
	int bpp = _ima->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)_ima->pixels + y * _ima->pitch + x*bpp;

	switch (bpp)
	{
		case 1:
			*p = pixel;
			break;
			
		case 2:
			*(Uint16 *)p = pixel;
			break;
			
		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			{
				p[0]=(pixel >> 16) & 0xff;
				p[1]=(pixel >> 8) & 0xff;
				p[2]=pixel & 0xff;
			}
			else
			{
				p[0]=pixel & 0xff;
				p[1]=(pixel >> 8) & 0xff;
				p[2]=(pixel >> 16) & 0xff;
			}
			break;
			
		case 4:
			*(Uint32 *) p = pixel;
			break;
	}
}


/**
 * \brief imprime un caracter en blanco
 */
void borrar(int lim, SDL_Surface *screen)
{
	limpiar(screen, 10 + (lim * 12), 100, 12, 50);
}


/**
 * \brief Informa si la tecla pulsada corresponde a una letra
 * 
 * \param tecla tecla pulsada
 * \return 1 es letra, 0 no lo es
 */
int es_letra (SDLKey letra)
{
	if (letra >= SDLK_a && letra <= SDLK_z)
		return 1;
	else
		return 0;
}


/**
 * \brief pinta y actualiza una superficie
 * 
 * \param screen superficie destino
 * \param x posicion inicial del rectágulo
 * \param y posicion inicial del rectángulo
 * \param w ancho del rectángulo
 * \param h alto del rectángulo
 */
void limpiar(SDL_Surface *screen, int x, int y, int w, int h)
{
	SDL_Rect rect = {x, y, w, h};

	SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 20, 100, 20));
	SDL_UpdateRect(screen, x, y, w, h);
}
