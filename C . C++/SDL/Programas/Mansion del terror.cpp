// La mansi�n del terror
// Programaci�n de videojuegos con SDL
// (c) Alberto Garc�a Serrano
#include <stdio.h>
#include <string.h>
/***
Declaraci�n de estructuras de datos
***/
#define HUESO 1
#define LLAVE 2
#define ESCALERA 3
#define PERRO 4
// Estructuras de datos para los objetos
struct objeto {
int estado; // Estado del objeto
char desc1[80]; // Descripci�n para estado 1
char desc2[80]; // Descripci�n para estado 2
int hab; // Habitaci�n en la que se encuentra
int lotengo; // Indica si tengo este objeto en mi inventario
} objetos[5];
// Estructura de datos para las habitaci�nes
struct habitacion {
char desc[255];
int norte;
int sur;
int este;
int oeste;
} habitaciones[10];
int main() {
/***
Inicializaci�n de estructuras de datos
***/
// Inicializaci�n de objetos
// hueso
objetos[HUESO].estado=1;
strcpy(objetos[HUESO].desc1,"un hueso");
strcpy(objetos[HUESO].desc2,"un hueso");
objetos[HUESO].hab=2;
objetos[HUESO].lotengo=0;
// llave
objetos[LLAVE].estado=1;
strcpy(objetos[LLAVE].desc1,"una llave sobre la lampara");
strcpy(objetos[LLAVE].desc2,"una llave sobre la lampara");
objetos[LLAVE].hab=3;
objetos[LLAVE].lotengo=0;
// escalera
objetos[ESCALERA].estado=1;
strcpy(objetos[ESCALERA].desc1,"una escalera");
strcpy(objetos[ESCALERA].desc2,"una escalera");
objetos[ESCALERA].hab=9;
objetos[ESCALERA].lotengo=0;
// perro
objetos[PERRO].estado=1;
strcpy(objetos[PERRO].desc1,"un perro rabioso");
strcpy(objetos[PERRO].desc2,"un perro comiendose un hueso");
objetos[PERRO].hab=9;
objetos[PERRO].lotengo=0;
// Datos del mapa

// Habitaci�n 1
strcpy(habitaciones[1].desc,"Estas en una peque�a habitaci�n pintada de blanco. Junto a ti puedes ver una cama y una mesita de noche.");
habitaciones[1].norte=0;
habitaciones[1].sur=4;
habitaciones[1].este=0;
habitaciones[1].oeste=0;
// Habitaci�n 2
strcpy(habitaciones[2].desc,"Estas en una habitaci�n pintada de verde. Junto a ti puedes ver una cama y una mesita de noche.");
habitaciones[2].norte=0;
habitaciones[2].sur=5;
habitaciones[2].este=0;
habitaciones[2].oeste=0;
// Habitaci�n 3
strcpy(habitaciones[3].desc,"Estas en el sal�n de la casa. Puedes ver una gran mesa rodeada de sillas.");
habitaciones[3].norte=0;
habitaciones[3].sur=6;
habitaciones[3].este=0;
habitaciones[3].oeste=0;
// Habitaci�n 4
strcpy(habitaciones[4].desc,"Estas en el pasillo.");
habitaciones[4].norte=1;
habitaciones[4].sur=7;
habitaciones[4].este=5;
habitaciones[4].oeste=0;
// Habitaci�n 5
strcpy(habitaciones[5].desc,"Estas en el pasillo.");
habitaciones[5].norte=2;
habitaciones[5].sur=8;
habitaciones[5].este=6;
habitaciones[5].oeste=4;
// Habitaci�n 6
strcpy(habitaciones[6].desc,"Estas en el pasillo.");
habitaciones[6].norte=3;
habitaciones[6].sur=9;
habitaciones[6].este=0;
habitaciones[6].oeste=5;
// Habitaci�n 7
strcpy(habitaciones[7].desc,"Estas en el t�pico servicio, con sus t�picas piezas.");
habitaciones[7].norte=4;
habitaciones[7].sur=0;
habitaciones[7].este=0;
habitaciones[7].oeste=0;
// Habitaci�n 8
strcpy(habitaciones[8].desc,"Estas en la entrada de la casa. Puedes ver la puerta cerrada.");
habitaciones[8].norte=5;
habitaciones[8].sur=0;
habitaciones[8].este=0;
habitaciones[8].oeste=0;
// Habitaci�n 9
strcpy(habitaciones[9].desc,"Estas en la cocina.");
habitaciones[9].norte=6;
habitaciones[9].sur=0;
habitaciones[9].este=0;
habitaciones[9].oeste=0;
/***
Inicializaci�n del estado de juego.
***/
// variable que indica la habitaci�n en la que estamos
int habitacionActual = 1;
// variable que indica cuantos objetos hay
int nobjetos = 4;

/***
game loop
***/
char verbo[30], nombre[30];
int i, accion;
int done = 0;
while (!done) {
// Mostramos informaci�n de la habitaci�n.
// Descripci�n
printf("\n\n%s",habitaciones[habitacionActual].desc);
// Mostramos si hay algun objeto
for (i=1 ; i<=nobjetos ; i++) {
if (objetos[i].hab == habitacionActual) {
printf("\nTambien puedes ver ");
// mostramos la descripci�n del objeto seg�n su estado
if (objetos[i].estado == 1) {
printf("%s",objetos[i].desc1);
} else {
printf("%s",objetos[i].desc2);
}
}
}
// Mostramos las posibles salidas
printf("\nPuedes ir direcci�n ");
if (habitaciones[habitacionActual].norte != 0)
printf ("Norte ");
if (habitaciones[habitacionActual].sur != 0)
printf ("Sur ");
if (habitaciones[habitacionActual].este != 0)
printf ("Este ");
if (habitaciones[habitacionActual].oeste != 0)
printf ("Oeste ");
// Leemos la entrada del jugador
printf("\n>>> ");
scanf("%s%s",verbo,nombre);
// Procesamos la entrada del jugador
// coger
if (!strcmp(verbo,"coger")) {
accion = 0;
// Hueso
if (!strcmp(nombre,"hueso") && objetos[HUESO].hab == habitacionActual) {
accion = 1;
objetos[HUESO].hab=0;
objetos[HUESO].lotengo=1;
printf("\nHas cogido el hueso.");
}
// Llave
if (!strcmp(nombre,"llave") && objetos[LLAVE].hab == habitacionActual) {
accion = 1;
// para coger la llave necesitamos la escalera
if (objetos[ESCALERA].lotengo == 1) {
objetos[LLAVE].hab=0;
objetos[LLAVE].lotengo=1;
printf("\nTras subirte a la escalera, alcanzas la llave.");
} else {
printf("\nNo alcanzo la llave. Est� demasiado alta.");
}
}
// Escaleras
if (!strcmp(nombre,"escalera") && objetos[ESCALERA].hab == habitacionActual) {
accion = 1;
if (objetos[PERRO].estado == 2) {
                          
                          objetos[ESCALERA].hab=0;
objetos[ESCALERA].lotengo=1;
printf("\nHas cogido las escaleras.");
} else {
printf("\nEl perro gru�e y ladra y no te deja cogerlo.");
}
}
if (accion == 0)
printf("\nNo puedes hacer eso.");
}
// dar
if (!strcmp(verbo,"dar")) {
accion = 0;
// Hueso
if (!strcmp(nombre,"hueso") && objetos[HUESO].lotengo == 1 && objetos[PERRO].hab ==
habitacionActual) {
accion = 1;
objetos[HUESO].lotengo=0;
objetos[PERRO].estado=2;
printf("\nEl perro coge el hueso y se retira a comerselo tranquilamente.");
}
if (accion == 0)
printf("\nNo puedes hacer eso.");
}
// usar
if (!strcmp(verbo,"usar")) {
accion = 0;
// Hueso
if (!strcmp(nombre,"llave") && objetos[LLAVE].lotengo == 1 && habitacionActual == 8) {
accion = 1;
printf("\nENHORABUENA!!! Has escapado de la mansi�n del terror.");
done = 1;
}
if (accion == 0)
printf("\nNo puedes hacer eso.");
}
// ir
if (!strcmp(verbo,"ir")) {
accion = 0;
// norte
if (!strcmp(nombre,"norte") && habitaciones[habitacionActual].norte != 0) {
accion = 1;
habitacionActual=habitaciones[habitacionActual].norte;
}
// sur
if (!strcmp(nombre,"sur") && habitaciones[habitacionActual].sur != 0) {
accion = 1;
habitacionActual=habitaciones[habitacionActual].sur;
}
// este
if (!strcmp(nombre,"este") && habitaciones[habitacionActual].este != 0) {
accion = 1;
habitacionActual=habitaciones[habitacionActual].este;
}
// oeste
if (!strcmp(nombre,"oeste") && habitaciones[habitacionActual].oeste != 0) {
accion = 1;
habitacionActual=habitaciones[habitacionActual].oeste;
}

if (accion == 0)
printf("\nNo puedes hacer eso.");
}
}
}
