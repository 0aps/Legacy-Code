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
