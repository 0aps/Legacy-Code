/*
 * Copyright (C) 2006 Hugo Ruscitti
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

SDL_Surface * iniciar_sdl (int w, int h, char * titulo);
void reemplazar_color (SDL_Surface * src, Uint32 remover, Uint32 reemplazo);
void put_pixel(SDL_Surface *_ima, int x, int y, Uint32 pixel);
Uint32 get_pixel(SDL_Surface *surface, int x, int y);

int main (void)
{
	SDL_Event event;
	SDL_Surface * ima;
	SDL_Surface * screen;
	SDL_Rect tmp;

	screen = iniciar_sdl (320, 240, "Reemplazar un color");

	if (! screen)
		exit (1);

	ima = IMG_Load ("../data/imagen.png");

	if (! ima)
	{
		printf ("%s\n", SDL_GetError ());
		exit (1);
	}

	/* Imprime la superficie sin cambios */
	tmp.x = 70;
	tmp.y = 100;
	SDL_BlitSurface (ima, NULL, screen, & tmp);

	/* reemplaza los colores del pantalon: de azul a verde */
	reemplazar_color (ima, SDL_MapRGB (ima->format, 72, 88, 140), 
			SDL_MapRGB (ima->format, 80, 156, 100));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 100, 120, 168), 
			SDL_MapRGB (ima->format, 112, 174, 125));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 56, 68, 112), 
			SDL_MapRGB (ima->format, 65, 131, 84));

	/* reeemplaza los colores de la remera: de verde a rojo */
	reemplazar_color (ima, SDL_MapRGB (ima->format, 0, 160, 0), 
			SDL_MapRGB (ima->format, 213, 72, 23));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 0, 136, 0), 
			SDL_MapRGB (ima->format, 197, 67, 21));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 0, 128, 0), 
			SDL_MapRGB (ima->format, 189, 64, 21));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 0, 96, 0), 
			SDL_MapRGB (ima->format, 168, 57, 18));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 0, 88, 0), 
			SDL_MapRGB (ima->format, 162, 55, 18));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 0, 64, 0), 
			SDL_MapRGB (ima->format, 144, 49, 16));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 0, 44, 0), 
			SDL_MapRGB (ima->format, 132, 45, 14));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 32, 64, 12), 
			SDL_MapRGB (ima->format, 131, 39, 50));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 108, 116, 52), 
			SDL_MapRGB (ima->format, 132, 61, 89));
	reemplazar_color (ima, SDL_MapRGB (ima->format, 52, 116, 24), 
			SDL_MapRGB (ima->format, 168, 52, 57));

	/* Imprime la superficie luego de los cambios */
	tmp.x = 200;
	tmp.y = 100;
	SDL_BlitSurface (ima, NULL, screen, & tmp);

	/* termina la impresión */
	SDL_FreeSurface (ima);
	SDL_Flip (screen);

	/* espera el cierre de la aplicación */	
	while (SDL_WaitEvent (& event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit (1);
				break;

			default:
				break;
		}
	}

	return 0;
}


SDL_Surface * iniciar_sdl (int w, int h, char * titulo)
{
	int flags = SDL_SWSURFACE;
	SDL_Surface * screen;

	if (SDL_Init (SDL_INIT_VIDEO) == -1)
	{
		printf ("%s\n", SDL_GetError ());
		return NULL;
	}

	atexit (SDL_Quit);

	SDL_WM_SetCaption (titulo, NULL);
	
	screen = SDL_SetVideoMode (w, h, 16, flags);
	
	if (! screen)
	{
		printf ("%s\n", SDL_GetError ());
		return NULL;
	}

	SDL_FillRect (screen, NULL, SDL_MapRGB (screen->format, 200, 200, 200));
	
	return screen;
}



void reemplazar_color (SDL_Surface * src, Uint32 remover, Uint32 reemplazo)
{
	int x;
	int y;
	
	if (SDL_MUSTLOCK (src))
	{
		if (SDL_LockSurface (src) < 0)
			return;
	}

	for (x = 0; x < src->w; x ++)
	{
		for (y = 0; y < src->h; y ++)
		{
			if (get_pixel (src, x, y) == remover)
				put_pixel (src, x, y, reemplazo);
		}
	}

	if (SDL_MUSTLOCK (src))
		SDL_UnlockSurface (src);
}

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


Uint32 get_pixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	
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
