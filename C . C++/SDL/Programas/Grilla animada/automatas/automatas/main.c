/*!
 * \file main.c
 */

/*
 * Autómatas - ejemplo
 * Copyright (C) 2005 - Hugo Ruscitti
 *
 * Este programa es software libre. Puede redistribuirlo y/o modificarlo bajo 
 * los términos de la Licencia Pública General de GNU según es publicada por la 
 * Free Software Foundation, bien de la versión 2 de dicha Licencia o bien 
 * (según su elección) de cualquier versión posterior.
 *
 
 * Este programa se distribuye con la esperanza de que sea útil, pero SIN 
 * NINGUNA GARANTÍA, incluso sin la garantía MERCANTIL implícita o sin 
 * garantizar la CONVENIENCIA PARA UN PROPÓSITO PARTICULAR. Véase la Licencia 
 * Pública General de GNU para más detalles.
 * 
 * Debería haber recibido una copia de la Licencia Pública General junto con 
 * este programa. Si no ha sido así, escriba a la Free Software Foundation, 
 * Inc., en 675 Mass Ave, Cambridge, MA 02139, EEUU. 
 * 
 */

/*!
 * 
 * \mainpage Ejemplo Autómatas
 * \section intro Introducción
 *
 * Esta es la documentación del programa 'autómatas' que, generalmente, se 
 * distribuye junto con un artículo que explica su funcionamiento. Si quiere 
 * ver el artículo completo visite el sitio http://www.losersjuegos.com.ar.
 * 
 * Puede hacer uso de este programa sólo bajo los términos de la licencia
 * pública general GPL, vea los archivo COPYING o COPYING_ES para mas detalles.
 * 
 *
 * \section cred Creditos
 * 	\li \c Programación: Hugo Ruscitti
 */




#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "actor.h"


/*!
 * \brief función principal del programa
 * \return 1 en caso de error
 */
int main (int argc, char *argv[])
{
	SDL_Surface * screen;
	struct actor actor;
	SDL_Rect rect [2] = {0};

	if (iniciar (&screen))
		return 1;

	if (actor_iniciar (&actor))
		return 1;

	limpiar_pantalla (screen);
	
	while (procesar_eventos ())
	{
		actor_actualizar (&actor);
                                        //uso el segundo rect, sigt posicion de memoria ...
                                        //es equivalente ... &rect[1]
		actor_imprimir (&actor, screen, rect + 1);
		SDL_UpdateRects (screen, 2, rect);
		imprimir_rectangulo (screen, rect + 1);

		rect[0] = rect[1];
		SDL_Delay (10);
	}
	
	return 0;
}
