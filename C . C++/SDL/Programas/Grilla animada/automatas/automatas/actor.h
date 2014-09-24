/*!
 * \file actor.h
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

/// grilla de gr�ficos
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

/* Gr�fica */
void actor_imprimir (struct actor * obj, SDL_Surface * screen, SDL_Rect * destino);

/* L�gica */
void actor_actualizar (struct actor * obj);
int actor_avanzar_animacion (struct actor * obj);
void actor_animacion_ver_cuadro (struct actor * obj, int cuadro);
void actor_cambiar_estado (struct actor * obj, enum estado estado);
void actor_aplicar_salto (struct actor * obj, Uint8 *key);

/* Gesti�n de estados */
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
