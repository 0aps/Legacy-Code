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

#include <stdio.h>
#include "nivel.h"

/*!
 * \brief Destructor
 */
nivel :: ~nivel()
{
	if (ima != NULL)
		SDL_FreeSurface(ima);
}

/*!
 * \brief Carga el archivo de nivel y sus graficos
 */
int nivel :: iniciar (void)
{
	FILE *archivo;

	archivo = fopen("nivel/tiles.dat", "rt");

	if (archivo == NULL)
	{
		printf("No se puede abrir 'nivel/tiles.dat'\n");
		return 1;
	}

	cargar_bloques (archivo);

	fclose(archivo);
	
	if (cargar_imagen())
		return 1;
		
	return 0;
}

/*!
 * \brief Imprime el nivel
 */
void nivel :: imprimir (SDL_Surface *screen)
{
	int i;
	int j;

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 150, 150, 150));
	
	for (i = 0; i < 15; i ++)
	{
		for (j = 0; j < 20; j++)
		{
			if (tiles[i][j].visible)
				imprimir_tile(screen, i, j);
		}
	}
}


/*!
 * \brief Imprime un bloque del tile
 */
void nivel :: imprimir_tile (SDL_Surface *screen, int fil, int col)
{
	SDL_Rect srcrect = {0, 0, 16, 16};
	SDL_Rect dstrect = {col*16, fil*16, 16, 16};
	int indice = tiles[fil][col].grafico;
	
	if (indice > 3*4 || indice < 0) 
	{
		printf("error, no se puede acceder al cuadro %d\n", indice);
		return;
	}

	srcrect.x = (indice % 4) * 16;
	srcrect.y = (indice / 4) * 16;

	SDL_BlitSurface(ima, &srcrect, screen, &dstrect);
}


/*!
 * \brief retorna la cantida de pixeles hasta el suelo
 *
 * \return distancia al suelo o 'rango' si no hay suelo
 */
int nivel :: get_dist_suelo (int x, int y, int rango)
{
	int cont;
	
	if (y > 240)
		return 0;

	for (cont = 0; cont < rango; cont ++)
	{
		if (es_suelo(x, y + cont))
			return cont;
	}

	return cont;
}


/*!
 * \brief determina la distancia hasta una pared
 */
int nivel :: get_dist_pared (int x, int y, int rango)
{
	int cont;
	int inc;
	int w;
	
	if (rango > 0)
	{
		inc = 1;
		w = 10;
	}
	else
	{
		inc = -1;
		w = -10;
	}

	
	// verifica pixel a pixel en busca de la pared
	for (cont = 0; cont != rango; cont += inc)
	{
		if (x + w + cont > 310 || x + w + cont < 10)
			return cont;
		
		if (es_pared(x + w + cont, y - 1))
			return cont;
	}

	return rango;
}


/*!
 * \brief determina si un bloque es sólido
 */
bool nivel :: es_solido (int x, int y)
{
	return tiles[y / 16][x / 16].solido;
}

/*!
 * \brief determina si un bloque es pared
 */
bool nivel :: es_pared (int x, int y)
{
	if (tiles[y / 16][x / 16].grafico == 3)
		return true;
	else
		return false;
}

/*!
 * \brief determina si el bloque es un suelo
 */
bool nivel :: es_suelo (int x, int y)
{
	// el suelo sólo es colisionable en su parte
	// superior, mediante el resto de la división (%) 
	// verificamos este caso

	
	if (y % 16 == 0 && es_solido(x, y))
		return true;
	else
		return false;
}


/*!
 * \brief carga las imágenes de los bloques
 */
int nivel :: cargar_imagen (void)
{
	ima = SDL_LoadBMP("ima/tiles.bmp");

	if (ima == NULL)
	{
		printf("Error al cargar la imágen: %s\n", SDL_GetError());
		return 1;
	}

	SDL_SetColorKey(ima, SDL_SRCCOLORKEY, \
			SDL_MapRGB(ima->format, 255, 0, 255));

	return 0;
}


/*!
 * \brief Completa la matriz 'tiles' con los datos del archivo
 */
void nivel :: cargar_bloques (FILE *archivo)
{
	int j;
	int fila = 0;
	char buffer[100];

	while (fgets(buffer, 100, archivo))
	{
		for (j = 0; j < 20; j ++)
		{
			switch (buffer[j])
			{
				case '-':
					tiles[fila][j].visible = false;
					tiles[fila][j].solido = false;
					break;

				case '0':
				case '1':
				case '2':
				case '3':
					tiles[fila][j].visible = true;
					tiles[fila][j].solido = true;
					tiles[fila][j].grafico = buffer[j]-'0';
					break;

				default:
					tiles[fila][j].visible = true;
					tiles[fila][j].solido = false;
					tiles[fila][j].grafico = buffer[j]-'0';
					break;
			}
		}
		
		fila ++;
	}
}
