/*
 * Copyright (c) 2005 Hugo Ruscitti
 * 
 * Este programa es Software Libre, puede redistribuirlo y/o modificarlo
 * bajo los t�rminos de la Licencia P�blica General de GNU publicada por la
 * Free Software Fundation, bien de la versi�n 2 de dicha Licencia o bien 
 * (seg�n su elecci�n) de cualquier versi�n posterior.
 *
 * Este programa se distribuye con la esperanza de que sea �til, pero SIN 
 * NINGUNA GARANT�A. V�ase la Licencia P�blica General de GNU para m�s detalles.
 *
 * Deber�a haber recibido una copia de la Licencia P�blica General junto con 
 * este programa. Si no ha sido as�, escriba a la Free Software Foundation, 
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
 * \brief muestra la infomaci�n general del programa
 */
void imprimir_creditos (void)
{
	printf("\n");
	printf("Colisi�n de Plataformas ver 0.1\n");
	printf(" Licencia: GPL (vea el archivo COPYING o COPYING_ES)\n");
	printf(" Programaci�n: Hugo Ruscitti\n");
	printf(" Gr�ficos: Walter Velazquez\n");
	printf(" Web: www.losersjuegos.com.ar\n");
	printf("\n");
}
