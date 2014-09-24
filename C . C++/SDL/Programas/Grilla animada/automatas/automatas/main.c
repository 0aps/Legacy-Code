/*!
 * \file main.c
 */

/*
 * Aut�matas - ejemplo
 * Copyright (C) 2005 - Hugo Ruscitti
 *
 * Este programa es software libre. Puede redistribuirlo y/o modificarlo bajo 
 * los t�rminos de la Licencia P�blica General de GNU seg�n es publicada por la 
 * Free Software Foundation, bien de la versi�n 2 de dicha Licencia o bien 
 * (seg�n su elecci�n) de cualquier versi�n posterior.
 *
 
 * Este programa se distribuye con la esperanza de que sea �til, pero SIN 
 * NINGUNA GARANT�A, incluso sin la garant�a MERCANTIL impl�cita o sin 
 * garantizar la CONVENIENCIA PARA UN PROP�SITO PARTICULAR. V�ase la Licencia 
 * P�blica General de GNU para m�s detalles.
 * 
 * Deber�a haber recibido una copia de la Licencia P�blica General junto con 
 * este programa. Si no ha sido as�, escriba a la Free Software Foundation, 
 * Inc., en 675 Mass Ave, Cambridge, MA 02139, EEUU. 
 * 
 */

/*!
 * 
 * \mainpage Ejemplo Aut�matas
 * \section intro Introducci�n
 *
 * Esta es la documentaci�n del programa 'aut�matas' que, generalmente, se 
 * distribuye junto con un art�culo que explica su funcionamiento. Si quiere 
 * ver el art�culo completo visite el sitio http://www.losersjuegos.com.ar.
 * 
 * Puede hacer uso de este programa s�lo bajo los t�rminos de la licencia
 * p�blica general GPL, vea los archivo COPYING o COPYING_ES para mas detalles.
 * 
 *
 * \section cred Creditos
 * 	\li \c Programaci�n: Hugo Ruscitti
 */




#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "actor.h"


/*!
 * \brief funci�n principal del programa
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
