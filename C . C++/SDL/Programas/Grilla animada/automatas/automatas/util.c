/*!
 * \file util.c
 */

/*
 * Aut�matas - ejemplo
 * Copyright (C) 2005 - Hugo Ruscitti
 *
 * Este programa es software libre. Puede redistribuirlo y/o modificarlo bajo 
 * los t�rminos de la Licencia P�blica General de GNU seg�n es publicada por la 
 * Free Software Foundation, bien de la versi�n 2 de dicha Licencia o bien 
 * (seg�n su elecci�n) de cualquier versi�n posterior.
 *
 * Este programa se distribuye con la esperanza de que sea �til, pero SIN 
 * NINGUNA GARANT�A, incluso sin la garant�a MERCANTIL impl�cita o sin 
 * garantizar la CONVENIENCIA PARA UN PROP�SITO PARTICULAR. V�ase la Licencia 
 * P�blica General de GNU para m�s detalles.
 * 
 * Deber�a haber recibido una copia de la Licencia P�blica General junto con 
 * este programa. Si no ha sido as�, escriba a la Free Software Foundation, 
 * Inc., en 675 Mass Ave, Cambridge, MA 02139, EEUU. 
 * 
 */

#include <SDL/SDL.h>
#include "util.h"
#include <string.h>

/*!
 * \brief inicializa la biblioteca y genera la ventana
 * \return 1 en caso de error
 */
int iniciar (SDL_Surface ** screen)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1) 
	{
		printf("Error en SDL_Init: %s\n", SDL_GetError());
		return 1;
	}

	*screen = SDL_SetVideoMode(320, 240, 16, SDL_DOUBLEBUF | SDL_HWSURFACE);
	
	if (*screen == NULL) 
	{
		printf("Error en SDL_SetVideoMode: %s\n", SDL_GetError());
		return 1;
	}

	SDL_WM_SetCaption("Automatas", NULL);
	
	return 0;
}


/*!
 * \brief actualiza la cola de eventos
 * \return 0 si el programa debe terminar
 */
int procesar_eventos (void)
{
	static SDL_Event event;

	while (SDL_PollEvent(&event)) 
	{
		if (event.type == SDL_QUIT)
			return 0;

		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_q || \
					event.key.keysym.sym == SDLK_ESCAPE)
				return 0;
		}
	}

	return 1;
}


/*!
 * \brief imprime un rect�nglo de color sobre la superficie
 */
void imprimir_rectangulo (SDL_Surface *screen, SDL_Rect * rect)
{
	Uint32 color = SDL_MapRGB (screen->format, 200, 200, 200);
	SDL_FillRect (screen, rect, color);
}


/*!
 * \brief pinta toda la superficie de un color uniforme
 */
void limpiar_pantalla (SDL_Surface *screen)
{
	SDL_Rect rec = {0, 0, screen->w, screen->h};

	imprimir_rectangulo (screen, &rec);
	SDL_Flip (screen);
}

/*!
 * \brief informa el estado actual del automata
 */
void imprimir_titulo_ventana (enum estado estado)
{
	char titulo [60] = {"Automata: "};
	char string_estado [][30] = {\
		{"INICIA"},\
		{"PARADO"},\
		{"GOLPEA"},\
		{"PATEA"},\
		{"SALTA"},\
		{"SALTA_ADELANTE"},\
		{"SALTA_ATRAS"},\
		{"GOLPEA_SALTANDO"},\
		{"GOLPEA_SALTANDO_ADELANTE"},\
		{"GOLPEA_SALTANDO_ATRAS"},\
		{"PATEA_SALTANDO"},\
		{"PATEA_SALTANDO_ADELANTE"},\
		{"PATEA_SALTANDO_ATRAS"},\
		{"CAMINA"},\
		{"AGACHADO"},\
		{"GOLPEA_AGACHADO"},\
		{"PATEA_AGACHADO"}};

	strcat (titulo, string_estado [estado]);
	SDL_WM_SetCaption (titulo, NULL);
}
