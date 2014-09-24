/*!
 * \file util.h
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

#ifndef _UTIL_H
#define _UTIL_H

#include "actor.h"

int iniciar (SDL_Surface ** screen);
int procesar_eventos (void);
void imprimir_rectangulo (SDL_Surface *screen, SDL_Rect * rect);
void limpiar_pantalla (SDL_Surface *screen);
void imprimir_titulo_ventana (enum estado estado);

#endif
