/*!
 * \file actor.c
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
#include <SDL/SDL_Image.h>
#include <SDL/SDL.h>
#include "actor.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"


/*!
 * \brief inicializa los recursos utilizados por el arctor
 * \return 1 en caso de error
 */
int actor_iniciar (struct actor * obj)
{                         
                          //nueve fila, 5 columna
	if (cargar_grilla (&obj->grilla, 9, 5))
		return 1;
		
	obj->paso = 0;       //el proximo cuadro a seleccionar en la grilla
	obj->estado = INICIA; 
	obj->cuadro = 0;     //el cuadro actual

	obj->x = 50;
	obj->y = 150;
                                             //# de cada cuadro de la grilla
	actor_cargar_animacion (obj, INICIA, "37,37,37,37,37,38,39,40,41,42");
	actor_cargar_animacion (obj, PARADO, "0, 1, 2, 3, 4");
	actor_cargar_animacion (obj, CAMINA, "5, 6, 7, 8, 9");
	actor_cargar_animacion (obj, AGACHADO, "25");
	actor_cargar_animacion (obj, GOLPEA_AGACHADO, "26, 27, 27, 26");
	actor_cargar_animacion (obj, PATEA_AGACHADO, "29, 30, 30");
	actor_cargar_animacion (obj, GOLPEA, "18, 19, 19, 18");
	actor_cargar_animacion (obj, PATEA, "21, 22, 23, 23, 24");
	actor_cargar_animacion (obj, SALTA, "10, 11, 12");
	actor_cargar_animacion (obj, SALTA_ADELANTE, "13, 14, 15, 16, 17");
	actor_cargar_animacion (obj, SALTA_ATRAS, "17, 16, 15, 14, 13");
	actor_cargar_animacion (obj, GOLPEA_SALTANDO, "31");
	actor_cargar_animacion (obj, GOLPEA_SALTANDO_ADELANTE, "31");
	actor_cargar_animacion (obj, GOLPEA_SALTANDO_ATRAS, "31");
	actor_cargar_animacion (obj, PATEA_SALTANDO, "34");
	actor_cargar_animacion (obj, PATEA_SALTANDO_ADELANTE, "34");
	actor_cargar_animacion (obj, PATEA_SALTANDO_ATRAS, "34");

	return 0;
}


/*!
 * \brief inicializa la estructura con los gráficos del actor
 * \return 1 en caso de error
 */
int cargar_grilla (struct grilla * obj, int filas, int columnas)
{
	Uint32 key;
	SDL_Surface *tmp, *tmp2;

	tmp = IMG_Load ("ima.bmp");

	if (tmp == NULL)
	{
		printf("Error: %s\n", SDL_GetError ());
		return 1;
	}
    //para que el blidding no haya que hacer la conversion de formato de la imagen
    // ahorra recuersos
	tmp2 = SDL_DisplayFormat (tmp);
	
	SDL_FreeSurface (tmp);

	if (tmp2 == NULL)
	{
		printf("Error: %s\n", SDL_GetError ());
		return 1;
	}

	key = SDL_MapRGB (tmp2->format, 247, 178, 214); 
			
	SDL_SetColorKey (tmp2, SDL_SRCCOLORKEY | SDL_RLEACCEL, key);

	obj->ima = tmp2;
	obj->filas = filas;
	obj->columnas = columnas;
    
    //Forma de obtener el las dimensiones de cada cauadro de la grilla	
	obj->w = obj->ima->w / columnas; //60
	obj->h = obj->ima->h / filas;    //65 

	return 0;
}


/*!
 * \brief almacena los cuadros de animacion en actor
 */
void actor_cargar_animacion (struct actor * obj, enum estado estado, char * cuadros)
{
	char buffer[1024];
	char * p;
	int i = 0;
	
	strcpy (buffer, cuadros);
	
	p = (char *) strtok (buffer, " ,");
	
	while (p)
	{
		obj->animaciones[estado][i] = atoi (p);
		p = (char *) strtok (NULL, " ,");
		i ++;
	}

	obj->animaciones[estado][i] = FIN_DE_ANIMACION;
}

/*!
 * \brief imprime el actor sobre una superficie
 */
void actor_imprimir (struct actor * obj, SDL_Surface * screen, SDL_Rect * destino)
{
	SDL_Rect fuente;
	
	destino->x = obj->x;
	destino->y = obj->y;
		
	fuente.w = obj->grilla.w; //60 
	fuente.h = obj->grilla.h; //65
    
    //formula para posicionarse en cada cuadro
	fuente.x = (obj->cuadro % obj->grilla.columnas) * fuente.w;
	fuente.y = (obj->cuadro / obj->grilla.columnas) * fuente.h;
	
	SDL_BlitSurface(obj->grilla.ima, &fuente, screen, destino);
}


/*!
 * \brief selecciona la función a ejecutar sobre el actor en base a su estado
 */
void actor_actualizar (struct actor * obj)
{
	Uint8 * key;

	key = SDL_GetKeyState (NULL);

	switch (obj->estado)
	{
		case INICIA:
			actor_estado_inicia (obj, key);
			break;

		case PARADO:
			actor_estado_parado (obj, key);
			break;

		case CAMINA:
			actor_estado_camina (obj, key);
			break;

		case AGACHADO:
			actor_estado_agachado (obj, key);
			break;

		case GOLPEA_AGACHADO:
			actor_estado_golpea_agachado (obj, key);
			break;

		case PATEA_AGACHADO:
			actor_estado_patea_agachado (obj, key);
			break;

		case GOLPEA:
			actor_estado_golpea (obj, key);
			break;

		case PATEA:
			actor_estado_patea (obj, key);
			break;

		case SALTA:
			actor_estado_salta (obj, key);
			break;

		case SALTA_ADELANTE:
			actor_estado_salta_adelante (obj, key);
			break;

		case SALTA_ATRAS:
			actor_estado_salta_atras (obj, key);
			break;

		case GOLPEA_SALTANDO:
			actor_estado_golpea_saltando (obj, key);
			break;

		case GOLPEA_SALTANDO_ADELANTE:
			actor_estado_golpea_saltando_adelante (obj, key);
			break;

		case GOLPEA_SALTANDO_ATRAS:
			actor_estado_golpea_saltando_atras (obj, key);
			break;

		case PATEA_SALTANDO:
			actor_estado_patea_saltando (obj, key);
			break;

		case PATEA_SALTANDO_ADELANTE:
			actor_estado_patea_saltando_adelante (obj, key);
			break;

		case PATEA_SALTANDO_ATRAS:
			actor_estado_patea_saltando_atras (obj, key);
			break;

		default:
			break;
	}
}

/*!
 * \brief avanza un cuadro de animación
 * \return 1 si terminó de reproducir la animación (la reinicia inmediatamente)
 */
int actor_avanzar_animacion (struct actor *obj)
{
	static int delay = 0;

	delay --;
	
	if (delay < 0)
	{
		obj->paso ++;                  //inicia     , 1   
		obj->cuadro = obj->animaciones [obj->estado][obj->paso]; //37

		delay = 10;

		if (obj->cuadro == FIN_DE_ANIMACION)
		{
			obj->paso = 0;
			obj->cuadro = obj->animaciones [obj->estado][0];
			return 1;
		}
	}

	return 0;
}


/*!
 * \brief muestra un cuadro en particular
 * \return 1 si terminó de reproducir la animación (la reinicia inmediatamente)
 */
void actor_animacion_ver_cuadro (struct actor *obj, int cuadro)
{
	obj->paso = cuadro;
	obj->cuadro = obj->animaciones [obj->estado][obj->paso];
}



/*!
 * \brief realiza un cambio de estado
 */
void actor_cambiar_estado (struct actor * obj, enum estado estado)
{
	obj->estado = estado;
	obj->paso = 0;
	obj->cuadro = obj->animaciones [obj->estado][0];
	
	imprimir_titulo_ventana (obj->estado);
}


/*!
 * \brief comportamiento en el estado INICIA
 */
void actor_estado_inicia (struct actor * obj, Uint8 * key)
{
	if (actor_avanzar_animacion(obj))
		actor_cambiar_estado (obj, PARADO);
}

/*!
 * \brief comportamiento en el estado PARADO
 */
void actor_estado_parado (struct actor * obj, Uint8 * key)
{
	actor_avanzar_animacion (obj);

	if (key [SDLK_UP])
	{
		obj->velocidad_salto = -5.0; // que tan alto salta
		actor_cambiar_estado (obj, SALTA);
	}

	if (key [SDLK_DOWN])
		actor_cambiar_estado (obj, AGACHADO);
	
	if (key [SDLK_z])
		actor_cambiar_estado (obj, PATEA);

	if (key [SDLK_x])
		actor_cambiar_estado (obj, GOLPEA);

	if (key [SDLK_LEFT] || key [SDLK_RIGHT])
		actor_cambiar_estado (obj, CAMINA);

}

/*!
 * \brief comportamiento en el estado CAMINA
 */
void actor_estado_camina (struct actor * obj, Uint8 * key)
{
	if (key[SDLK_LEFT])
		obj->x --;
	else
	{
		if (key [SDLK_RIGHT])
			obj->x ++;
		else
			actor_cambiar_estado (obj, PARADO);
	}

	if (key [SDLK_UP])
	{
		obj->velocidad_salto = -5.0;

		if (key [SDLK_LEFT])
			actor_cambiar_estado (obj, SALTA_ATRAS);
		else
			actor_cambiar_estado (obj, SALTA_ADELANTE);
	}

	actor_avanzar_animacion (obj);
}

/*!
 * \brief comportamiento en el estado AGACHADO
 */
void actor_estado_agachado (struct actor * obj, Uint8 * key)
{
	if (! key [SDLK_DOWN])
		actor_cambiar_estado (obj, PARADO);

	if (key [SDLK_z])
		actor_cambiar_estado (obj, PATEA_AGACHADO);

	if (key [SDLK_x])
		actor_cambiar_estado (obj, GOLPEA_AGACHADO);
}

/*!
 * \brief comportamiento en el estado GOLPEA_AGACHADO
 */
void actor_estado_golpea_agachado (struct actor * obj, Uint8 * key)
{
	if (actor_avanzar_animacion (obj))
		actor_cambiar_estado (obj, AGACHADO);
}

/*!
 * \brief comportamiento en el estado PATEA_AGACHADO
 */
void actor_estado_patea_agachado (struct actor * obj, Uint8 * key)
{
	if (actor_avanzar_animacion (obj))
		actor_cambiar_estado (obj, AGACHADO);
}

/*!
 * \brief comportamiento en el estado GOLPEA
 */
void actor_estado_golpea (struct actor * obj, Uint8 * key)
{
	if (actor_avanzar_animacion (obj))
		actor_cambiar_estado (obj, PARADO);
}

/*!
 * \brief comportamiento en el estado PATEA
 */
void actor_estado_patea (struct actor * obj, Uint8 * key)
{
	if (actor_avanzar_animacion (obj))
		actor_cambiar_estado (obj, PARADO);
}

/*!
 * \brief comportamiento en el estado SALTA
 */
void actor_estado_salta (struct actor * obj, Uint8 * key)
{
	if (obj->velocidad_salto < -2.0) // está subiendo
		actor_animacion_ver_cuadro (obj, 0);
	else
	{
		if (obj->velocidad_salto > 2.0)
			actor_animacion_ver_cuadro (obj, 2); // baja
		else
			actor_animacion_ver_cuadro (obj, 1); // altura máxima
	}

	actor_aplicar_salto (obj, key);

	if (key [SDLK_x])
		actor_cambiar_estado (obj, GOLPEA_SALTANDO);

	if (key [SDLK_z])
		actor_cambiar_estado (obj, PATEA_SALTANDO);
}

/*!
 * \brief comportamiento en el estado SALTA_ADELANTE
 */
void actor_estado_salta_adelante (struct actor * obj, Uint8 * key)
{
	obj->x ++;
	actor_aplicar_salto (obj, key);
	actor_avanzar_animacion (obj);
	
	if (key [SDLK_x])
		actor_cambiar_estado (obj, GOLPEA_SALTANDO_ADELANTE);

	if (key [SDLK_z])
		actor_cambiar_estado (obj, PATEA_SALTANDO_ADELANTE);
}

/*!
 * \brief comportamiento en el estado SALTA_ATRAS
 */
void actor_estado_salta_atras (struct actor * obj, Uint8 * key)
{
	obj->x --;
	actor_aplicar_salto (obj, key);
	actor_avanzar_animacion (obj);

	if (key [SDLK_x])
		actor_cambiar_estado (obj, GOLPEA_SALTANDO_ATRAS);

	if (key [SDLK_z])
		actor_cambiar_estado (obj, PATEA_SALTANDO_ATRAS);
}


/*!
 * \brief aplica la distancia al suelo en base a la gravedad
 */
void actor_aplicar_salto (struct actor * obj, Uint8 *key)
{
	obj->y += (int) obj->velocidad_salto;
	obj->velocidad_salto += 0.1;

	if (obj->y > 150)
	{
		obj->y = 150;
		actor_cambiar_estado (obj, PARADO);
	}
}


/*!
 * \brief comportamiento en el estado GOLPEA_SALTANDO
 */
void actor_estado_golpea_saltando (struct actor * obj, Uint8 * key)
{
	actor_aplicar_salto (obj, key);
}

/*!
 * \brief comportamiento en el estado GOLPEA_SALTANDO_ADELANTE
 */
void actor_estado_golpea_saltando_adelante (struct actor * obj, Uint8 * key)
{
	obj->x ++;
	actor_aplicar_salto (obj, key);
}

/*!
 * \brief comportamiento en el estado GOLPEA_SALTANDO_ATRAS
 */
void actor_estado_golpea_saltando_atras (struct actor * obj, Uint8 * key)
{
	obj->x --;
	actor_aplicar_salto (obj, key);
}

/*!
 * \brief comportamiento en el estado PATEA_SALTANDO
 */
void actor_estado_patea_saltando (struct actor * obj, Uint8 * key)
{
	actor_aplicar_salto (obj, key);
}

/*!
 * \brief comportamiento en el estado PATEA_SALTANDO_ADELANTE
 */
void actor_estado_patea_saltando_adelante (struct actor * obj, Uint8 * key)
{
	obj->x ++;
	actor_aplicar_salto (obj, key);
}

/*!
 * \brief comportamiento en el estado PATEA_SALTANDO_ATRAS
 */
void actor_estado_patea_saltando_atras (struct actor * obj, Uint8 * key)
{
	obj->x --;
	actor_aplicar_salto (obj, key);
}
