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

#ifndef _TORTUGA_H
#define _TORTUGA_H

#include "SDL/SDL.h"
#include "nivel.h"

/// diferentes acciones que puede realizar el jugador
enum estado {PARADO, CAMINA, SALTA};


/*!
 * \brief Personaje protagonista
 *
 * \author Hugo Ruscitti
 */
class tortuga
{
	public:
		tortuga();
		~tortuga();
		int iniciar (class nivel *nivel);
		void actualizar (void);
		void imprimir (SDL_Surface *screen);
		
	private:
		class nivel *nivel;
		SDL_Surface *ima;
		Uint8 *key;
		int x;
		int y;
		int grafico;
		float salto;
		enum estado estado;
		enum estado estado_anterior;
		int flip;
		int paso;
		int pausa_animacion;
		int animacion[3][10];

		bool pisa_el_suelo (void);
		int get_dist_suelo (int rango);
		int get_dist_pared (int rango);
		int cargar_imagen (void);
		void cargar_animaciones (void);
	
		void procesar_animacion (void);
		void caer (void);
		void saltar (void);
		void caminar (void);
};


#endif
