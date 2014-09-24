/*!
 * \file actor.h
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

#ifndef _ACTOR_H
#define _ACTOR_H

#define FIN_DE_ANIMACION -1

/// estados del actor
enum estado { \
	INICIA,\
	PARADO,\
	GOLPEA,\
	PATEA,\
	SALTA,\
	SALTA_ADELANTE,\
	SALTA_ATRAS,\
	GOLPEA_SALTANDO,\
	GOLPEA_SALTANDO_ADELANTE,\
	GOLPEA_SALTANDO_ATRAS,\
	PATEA_SALTANDO,\
	PATEA_SALTANDO_ADELANTE,\
	PATEA_SALTANDO_ATRAS,\
	CAMINA,\
	AGACHADO,\
	GOLPEA_AGACHADO,\
	PATEA_AGACHADO,\
	_CANTIDAD_ESTADOS
};

/// grilla de gráficos
struct grilla
{
	SDL_Surface * ima;
	int filas;
	int columnas;
	int w;
	int h;
};


/// propiedades del personaje
struct actor
{
	struct grilla grilla;
	enum estado estado;
	int x;
	int y;
	float velocidad_salto;
	int cuadro;
	int paso;
	int animaciones [_CANTIDAD_ESTADOS] [30];
};

/* Inicializadores */
int actor_iniciar (struct actor * obj);
int cargar_grilla (struct grilla * obj, int filas, int columnas);
void actor_cargar_animacion (struct actor * obj, enum estado, char * cuadros);

/* Gráfica */
void actor_imprimir (struct actor * obj, SDL_Surface * screen, SDL_Rect * destino);

/* Lógica */
void actor_actualizar (struct actor * obj);
int actor_avanzar_animacion (struct actor * obj);
void actor_animacion_ver_cuadro (struct actor * obj, int cuadro);
void actor_cambiar_estado (struct actor * obj, enum estado estado);
void actor_aplicar_salto (struct actor * obj, Uint8 *key);

/* Gestión de estados */
void actor_estado_inicia (struct actor
 * obj, Uint8 * key);
void actor_estado_parado (struct actor * obj, Uint8 * key);
void actor_estado_camina (struct actor * obj, Uint8 * key);
void actor_estado_agachado (struct actor * obj, Uint8 * key);
void actor_estado_golpea_agachado (struct actor * obj, Uint8 * key);
void actor_estado_patea_agachado (struct actor * obj, Uint8 * key);
void actor_estado_golpea (struct actor * obj, Uint8 * key);
void actor_estado_patea (struct actor * obj, Uint8 * key);
void actor_estado_salta (struct actor * obj, Uint8 * key);
void actor_estado_salta_adelante (struct actor * obj, Uint8 * key);
void actor_estado_salta_atras (struct actor * obj, Uint8 * key);
void actor_estado_golpea_saltando (struct actor * obj, Uint8 * key);
void actor_estado_golpea_saltando_adelante (struct actor*obj, Uint8*key);
void actor_estado_golpea_saltando_atras (struct actor * obj, Uint8 * key);
void actor_estado_patea_saltando (struct actor * obj, Uint8 * key);
void actor_estado_patea_saltando_adelante (struct actor*obj, Uint8*key);
void actor_estado_patea_saltando_atras (struct actor * obj, Uint8 * key);

#endif
