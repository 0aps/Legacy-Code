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

#ifndef _NIVEL_H
#define _NIVEL_H

#include <SDL/SDL.h>

/*!
 * \brief Un bloque o tile del mapeado
 */
struct bloque
{
	/// numero de grafico
	int grafico;
	/// es un suelo
	bool solido;
	/// se debe imprimir
	bool visible;
};


/*!
 * \brief Imprime y almacena todos los bloques del nivel
 *
 * \author Hugo Ruscitti
 */
class nivel
{
	public:
		~nivel();
		int iniciar (void);
		void imprimir (SDL_Surface *screen);
		int get_dist_suelo (int x, int y, int rango);
		int get_dist_pared (int x, int y, int rango);
		
	private:
		SDL_Surface *ima;
		struct bloque tiles[15][20];

		int cargar_imagen (void);
		bool es_solido (int x, int y);
		bool es_suelo (int x, int y);
		bool es_pared (int x, int y);
		void cargar_bloques (FILE *archivo);
		void imprimir_tile (SDL_Surface *screen, int fil, int col);
};

#endif
