#include <windows.h>
#include <stdio.h>

/* ____________________________________________
   |Programa codeado 100% By Mr.Blo0D de CPH. |
   |Para www.Yeah-Hack.es.kz                  |
   _____________________________________________
*/

int main()
{

HWND hwnd; /* Declaramos la variable hwnd del tipo HWND de window's */
char NN[50]; /*declaramos NN(Nobre Nuevo) y NV(Nombre Viejo)*/
char NV[50];
for(;;)
{

printf("Introduzca el nombre actual de la ventana(maximo 50 caracteres) : "); /* Pedimos el nombre de la ventana */
scanf("%s", &NV);

hwnd = FindWindow(NULL, NV);/* Usamos esta API para conseguir el Handle de la ventana, a traves del nombre que tiene actualmente. */

if (hwnd == 0) /* Comprobamos que la ventana existe. Si no existe, se cierra el programa. */
{
exit(0);
}

printf("Introduzca el nuevo nombre de la ventana(maximo 50 caracteres) : "); /* Pedimos el nombre a dar a la ventana */
scanf("%s", &NN);

SetWindowText(hwnd, NN); /* Usamos esta API para darle ese nombre a la ventana */
}
return 0;
}

