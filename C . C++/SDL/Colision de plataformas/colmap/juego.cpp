/*
 * Copyright (c) 2005 Hugo Ruscitti
 * 
 * Este programa es Software Libre, puede redistribuirlo y/o modificarlo
 * bajo los t�rminos de la Licencia P�blica General de GNU publicada por la
 * Free Software Fundation, bien de la versi�n 2 de dicha Licencia o bien 
 * (seg�n su elecci�n) de cualquier versi�n posterior.
 *
 * Este programa se distribuye con la esperanza de que sea �til, pero SIN 
 * NINGUNA GARANT�A. V�ase la Licencia P�blica General de GNU para m�s detalles.
 *
 * Deber�a haber recibido una copia de la Licencia P�blica General junto con 
 * este programa. Si no ha sido as�, escriba a la Free Software Foundation, 
 * Inc., en 675 Mass Ave, Cambridge, MA 02139, EEUU. 
 * 
 */

#include "juego.h"

/*! 
 * Inicializa la biblioteca y los recursos base del juego
 *
 * \return 1 en caso de error
 */
int juego :: iniciar (void)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1) 
	{
		printf("Error al ejecutar SDL_Init: %s\n", SDL_GetError());
		return 1;
	}
	
	screen = SDL_SetVideoMode(320, 240, 16, SDL_DOUBLEBUF | SDL_HWSURFACE);

	if ( screen == NULL )
	{
		printf("Error al ejecutar SDL_SetVideoMode: %s\n", \
				SDL_GetError());
		return 1;
	}
	
	SDL_WM_SetCaption("Colisi�n de plataformas ver 0.1", NULL);
	
	if (nivel.iniciar())
		return 1;

	nivel.imprimir(screen);
	SDL_Flip(screen);

	if (tortuga.iniciar(&nivel))
		return 1;
	
	return 0;
}

/*!
 * \brief B�cle principal, controla la velocidad constante
 */
void juego :: main_loop (void)
{
	int t, tl, tg;
	int repeticion_logica;
	int i;

	#define DELAY (1000/100)
	
	t = tl = tg = SDL_GetTicks();
	
	while (procesar_eventos() == 0)
	{
		t = SDL_GetTicks();

		if (t - tl >= DELAY) 
		{
			repeticion_logica = (t - tl) / DELAY;
			
			for (i = 0; i < repeticion_logica; i++)
				tortuga.actualizar();
			
			
			nivel.imprimir(screen);
			tortuga.imprimir(screen);
			SDL_Flip(screen);
			
			tl += DELAY * repeticion_logica;
		}
		else
			SDL_Delay(DELAY - (t - tl));
	}
}


/*!
 * \brief Termina la ejecuci�n del programa
 */
void juego :: terminar (void)
{
	SDL_Quit();
}

/*!
 * \brief Captura los eventos de la ventana
 *
 * \return 1 si debe terminar
 */
int juego :: procesar_eventos (void)
{
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return 1;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_q:
					case SDLK_ESCAPE:
						return 1;
						break;

					default:
						break;
				}

			default:
				break;
		}
	}

	return 0;
}
