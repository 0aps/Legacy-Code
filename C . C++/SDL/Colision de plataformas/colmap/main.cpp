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

#include <stdio.h>
#include "juego.h"



void imprimir_creditos (void);

/*!
 * \brief programa principal
 */
int main (void)
{
	class juego juego;

	imprimir_creditos();
	
	if (juego.iniciar())
		return 1;

	juego.main_loop();

	juego.terminar();

	printf("Programa terminado con normalidad\n");
	return 0;
}


/*!
 * \brief muestra la infomación general del programa
 */
void imprimir_creditos (void)
{
	printf("\n");
	printf("Colisión de Plataformas ver 0.1\n");
	printf(" Licencia: GPL (vea el archivo COPYING o COPYING_ES)\n");
	printf(" Programación: Hugo Ruscitti\n");
	printf(" Gráficos: Walter Velazquez\n");
	printf(" Web: www.losersjuegos.com.ar\n");
	printf("\n");
}
