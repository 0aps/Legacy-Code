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

#ifndef _JUEGO_H
#define _JUEGO_H

#include <SDL/SDL.h>
#include "nivel.h"
#include "tortuga.h"

/*!
 * \brief Contiene todos los recursos del juego
 *
 * \author Hugo Ruscitti
 */
class juego
{
	public:
		int iniciar (void);
		void main_loop (void);
		void terminar (void);
		
	private:
		SDL_Surface *screen;
		SDL_Event event;
		class nivel nivel;
		class tortuga tortuga;

		int procesar_eventos (void);
};

#endif
