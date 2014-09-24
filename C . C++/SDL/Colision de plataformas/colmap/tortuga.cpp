/*
 * Copyright (c) 2005 Hugo Ruscitti
 * 
 * Este programa es Software Libre, puede redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General de GNU publicada por la
 * Free Software Fundation, bien de la versión 2 de dicha Licencia o bien 
 * (según su elección) de cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil, pero SIN 
 * NINGUNA GARANTÍA. Véase la Licencia Pública General de GNU para más detalles.
 *
 * Debería haber recibido una copia de la Licencia Pública General junto con 
 * este programa. Si no ha sido así, escriba a la Free Software Foundation, 
 * Inc., en 675 Mass Ave, Cambridge, MA 02139, EEUU. 
 * 
 */

#include "tortuga.h"

/*!
 * \brief Constructor
 */
tortuga :: tortuga ()
{
	x = 20;
	y = 50;
	grafico = 0;
	salto = 0;
	flip = 1;
	paso = 0;
	pausa_animacion = 0;
	
	cargar_animaciones();
}



/*!
 * \brief Destructor
 */
tortuga :: ~tortuga ()
{
	if (ima == NULL)
		SDL_FreeSurface(ima);
}


/*!
 * \brief Carga las imágenes y define la posición inicial
 *
 * \return 1 en caso de error
 */
int tortuga :: iniciar (class nivel *nivel)
{
	this->nivel = nivel;

	if (cargar_imagen())
		return 1;

	caer();
	
	return 0;
}


/*!
 * \brief carga las imágenes del personaje
 *
 * \return 1 en caso de error
 */
int tortuga :: cargar_imagen (void)
{
	Uint32 color;
	
	ima = SDL_LoadBMP("ima/tortuga.bmp");

	if (ima == NULL)
	{
		printf("Error al cargar la imágen: %s\n", SDL_GetError());
		return 1;
	}

	color = SDL_MapRGB(ima->format, 255, 0, 255);

	SDL_SetColorKey(ima, SDL_SRCCOLORKEY, color);

	return 0;
}


/*!
 * \brief Actualiza la posición del personaje
 */
void tortuga :: actualizar (void)
{
	key = SDL_GetKeyState(NULL);

	procesar_animacion();

	switch (estado)
	{
		case PARADO:
			if (key[SDLK_UP])
				saltar();

			if (key[SDLK_LEFT] || key[SDLK_RIGHT])
				caminar();
			
			break;

		case CAMINA:

			x += get_dist_pared(flip);

			if (flip == 1 && ! key[SDLK_RIGHT])
				estado = PARADO;

			if (flip == -1 && ! key[SDLK_LEFT])
				estado = PARADO;
			
			if (key[SDLK_UP])
				saltar();

			if (! pisa_el_suelo())
				caer();
			
			break;

		case SALTA:
	
			if (key[SDLK_LEFT])
			{
				flip = -1;
				x += get_dist_pared(flip);
			}

			if (key[SDLK_RIGHT])
			{
				flip = 1;
				x += get_dist_pared(flip);
			}

			salto += 0.08;

			// está bajando
			if (salto > 0)
			{
				y += get_dist_suelo((int) salto);

				if (pisa_el_suelo())
					estado = PARADO;
			}
			else
				y += (int) salto;

			break;
	}
				
}

/*!
 * \brief Lo imprime sobre una superficie
 */
void tortuga :: imprimir (SDL_Surface *screen)
{
	SDL_Rect srcrect;
	SDL_Rect dstrect;
	int x_dst = x - (ima->w/4)/2;
	int y_dst = y - ima->h;
	
	dstrect.x = x_dst;
	dstrect.y = y_dst;

	srcrect.w = ima->w / 4;
	srcrect.h = ima->h;
	srcrect.x = grafico * (ima->w / 4);
	srcrect.y = 0;

	if (flip == 1)
		SDL_BlitSurface(ima, &srcrect, screen, &dstrect);
	else
	{
		SDL_Rect read_rect = {srcrect.x, 0, 1, srcrect.h};
		SDL_Rect write_rect = {srcrect.w + x_dst, y_dst, 1, srcrect.h};

		for (int i = 0; i < srcrect.w; i++)
		{
			SDL_BlitSurface(ima, &read_rect, screen, &write_rect);
			write_rect.x --;
			read_rect.x ++;
			write_rect.y = y_dst;
		}
	}
}

/*!
 * \brief indica si la tortuga está sobre una plataforma
 */
bool tortuga :: pisa_el_suelo (void)
{
	if (nivel->get_dist_suelo(x, y, 1) == 0)
		return true;
	else
		return false;
}


/*!
 * \brief obtiene la distancia al suelo
 *
 * \brief distancia al suelo o 'rango' si el suelo no está presente
 */
int tortuga :: get_dist_suelo (int rango)
{
	return nivel->get_dist_suelo(x, y, rango);
}

/*!
 * \brief obtiene la distancia a una pared
 */
int tortuga :: get_dist_pared (int rango)
{
	return nivel->get_dist_pared(x, y, rango);
}

/*!
 * \brief comienza a caer
 */
void tortuga :: caer (void)
{
	salto = 0;
	estado = SALTA;
}


/*!
 * \brief comienza a saltar
 */
void tortuga :: saltar (void)
{
	salto = -3.5;
	estado = SALTA;
}


/*!
 * \brief comienza a caminar
 */
void tortuga :: caminar (void)
{
	if (key[SDLK_LEFT])
		flip = -1;
	else
		flip = 1;

	estado = CAMINA;
}

/*!
 * \brief avanza los cuadros de animación
 */
void tortuga :: procesar_animacion (void)
{
	if (pausa_animacion == 0)
	{
		pausa_animacion = 10;
		paso ++;

		// detecta el fin de la animación
		if (animacion[estado][paso] == -1)
			paso = 0;
	}
	else
		pausa_animacion --;
	

	// se alteró el estado
	if (estado != estado_anterior)
	{
		paso = 0;
		estado_anterior = estado;
	}

	
	grafico = animacion[estado][paso];
}


/*!
 * \brief carga las secuencias de animación
 */
void tortuga :: cargar_animaciones (void)
{
	animacion[PARADO][0] = 1;
	animacion[PARADO][1] = -1;

	animacion[CAMINA][0] = 2;
	animacion[CAMINA][1] = 1;
	animacion[CAMINA][2] = 3;
	animacion[CAMINA][3] = 1;
	animacion[CAMINA][4] = -1;

	animacion[SALTA][0] = 0;
	animacion[SALTA][1] = -1;
}
