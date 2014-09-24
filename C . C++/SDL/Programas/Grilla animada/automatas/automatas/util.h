/*!
 * \file util.h
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

#ifndef _UTIL_H
#define _UTIL_H

#include "actor.h"

int iniciar (SDL_Surface ** screen);
int procesar_eventos (void);
void imprimir_rectangulo (SDL_Surface *screen, SDL_Rect * rect);
void limpiar_pantalla (SDL_Surface *screen);
void imprimir_titulo_ventana (enum estado estado);

#endif
