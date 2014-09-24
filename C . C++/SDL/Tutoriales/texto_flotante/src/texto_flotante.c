/*
 * Mini ejemplo : texto flotante (basado en `fuentes_sol_3` del mismo autor)
 * Copyright (C) 2006 Hugo Ruscitti
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

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>


SDL_Surface * iniciar_sdl (const char * titulo)
{
	SDL_Surface * screen;

	if (SDL_Init (SDL_INIT_VIDEO))
	{
		printf ("error: %s\n", SDL_GetError ());
		return NULL;
	}

	screen = SDL_SetVideoMode (320, 240, 16, SDL_HWSURFACE);
	
	if (screen == NULL)
	{
		printf ("error: %s\n", SDL_GetError ());
		return NULL;
	}

	SDL_WM_SetCaption (titulo, NULL);

	return screen;
}


Uint32 get_pixel (SDL_Surface * ima, int x, int y)
{
	int bpp = ima->format->BytesPerPixel;
	Uint8 *p = (Uint8 *) ima->pixels + y * ima->pitch + x * bpp;

	switch (bpp)
	{
		case 1:
			return *p;
		
		case 2:
			return *(Uint16 *)p;

		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
				return p[0] << 16 | p[1] << 8 | p[2];
			else
				return p[0] | p[1] << 8 | p[2] << 16;

		case 4:
			return *(Uint32 *)p;

		default:
			return 0;
	}
}

/* 
 * Informa si la columna (parámetro 2) es una linea completa de pixeles
 * transparentes en la superficie ima (parámetro 1)
 *
 * Se asume que el color transparente es aquel que coincide con el pixel
 * situado en la posicion (0,0) de la superficie.
 */
int es_columna_vacia (SDL_Surface * ima, int columna)
{
	Uint32 pixel_transparente = get_pixel (ima, 0, 0);
	int fila;
	
	/* busca un pixel opaco */
	for (fila = 0; fila < ima->h; fila ++)
	{
		if (pixel_transparente != get_pixel (ima, columna, fila))
			return 0;
	}

	return 1;
}


/*
 * Define la dimensión del rectángulo rect (parámetro 1)
 */
void guardar_rect (SDL_Rect * rect, int x, int y, int w, int h)
{
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
}

/*
 * Analiza la superficie ima buscando letras para registrarlas en el 
 * vector de rectángulos fuentes (segundo parámetro)
 *
 * Para analizar, el programa recorre la imágen de izquierda a derecha
 * 'leyendo' barras verticales de píxeles. Así determina donde comienza
 * y termina cada letra (debe existir una separación de, al menos, un 
 * pixel entre cada caracter)
 */
void identificar_rects (SDL_Surface * ima, SDL_Rect * fuentes)
{
	int indice_letra = 0;
	int esta_recorriendo_letra = 0;
	int w = 0; /* ancho de la letra actual */
	int i;

	for (i = 0; i < ima->w; i ++)
	{
		if (es_columna_vacia (ima, i))
		{
			
			/* si estaba leyendo una letra entonces encontró 
			 * el ancho de la misma */
			if (esta_recorriendo_letra)
			{
				guardar_rect (fuentes + indice_letra, \
						i - w, 0, w, ima->h);
				esta_recorriendo_letra = 0;
				indice_letra ++;
			}
		}
		else
		{
			/* si está recorriendo una letra aumenta el contador
			 * de ancho, en caso contrario encontró donde comienza
			 * la siguiente letra
			 */
			if (esta_recorriendo_letra)
				w ++;
			else
			{
				w = 1;
				esta_recorriendo_letra = 1;
			}
		}
	}

	printf ("Econtré %d letras en el archivo de fuentes\n", indice_letra);
}


/*
 * Relaciona un caracter con un número entero
 */
int obtener_indice (char caracter)
{
	int i;
	static char letras [] = \
				"!\"#$%&'()*+,-./0123456789:;<=>?@"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"[\\]^_`"
				"abcdefghijklmnopqrstuvwxyz"
				"{|}~¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾"
				"¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäå"
				"æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
	
	if (caracter == ' ')
		return 1;

	for (i = 0; letras [i]; i ++)
	{
		if (caracter == letras [i])
			return i;
	}
	
	printf ("No se puede encontrar el índice de '%c'\n", caracter);
	return -1;
}


/*
 * imprime un caracter sobre la superficie dst (generalmente screen)
 */
int imprimir_letra (SDL_Surface * dst, SDL_Surface * ima, SDL_Rect * fuentes, \
		int x, int y, char letra)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect = {x, y, 0, 0};
	int indice = obtener_indice (letra);

	if (letra == ' ')
		return fuentes [0].w;

	
	if (indice != -1)
	{
		srcrect = fuentes [indice];
		SDL_BlitSurface(ima, &srcrect, dst, &dstrect);
	}
	return srcrect.w;
}

/*
 * imprime una cadena de textos completa sobre la superficie referenciada
 * por el primer parámetro
 */
void imprimir_palabra (SDL_Surface * screen, SDL_Surface * ima, \
		SDL_Rect * fuentes, int x, int y, char * cadena)
{
	int i;
	int dx = x;

	for (i = 0; cadena [i]; i ++)
		dx += imprimir_letra (screen, ima, fuentes, dx, y, cadena [i]);
}


int main (int argc, char * argv [])
{
	SDL_Surface * screen;
	SDL_Surface * ima;
	SDL_Event event;
	SDL_Rect fuentes [200];
	int salir = 0;
	float angulo = 0;
	
	screen = iniciar_sdl ("Texto Flotante");

	if (screen == NULL)
		return 1;
	
	ima = IMG_Load ("../ima/fuente_iso_8859_1.png");
	
	if (ima == NULL)
	{
		printf ("%s\n", SDL_GetError ());
		return 1;
	}
	
	identificar_rects (ima, fuentes);

	while (! salir)
	{
		while (SDL_PollEvent (& event))
		{
			if (event.type == SDL_QUIT)
				salir = 1;
		}

		angulo += 0.025;

		SDL_FillRect (screen, NULL, SDL_MapRGB (screen->format, 200,
					200, 200));
		
		imprimir_palabra (screen, ima, fuentes, 
				cos (angulo * 2.5) * 30 + 75,  
				sin (angulo) * 30 + 100, 
				"¡ Hola Mundo !");

		SDL_Flip (screen);
	}

	SDL_FreeSurface (ima);
	SDL_Quit ();
	return 0;
}
