
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void goxy(int x, int y)
{
COORD coord;
coord.X = x; coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	int KeyPress=0;
	int CharX; int CharY; int xt; int yt;
	int x; int y; int i;
	int Tabla[25][15];

	for (x=0; x<25; x++) {
		for (y=0; y<15; y++) {
			Tabla[x][y]=1;
		}
	}

	//Dibujamo una linea superior horizontal
	for (i=0; i<25; i++) {
		Tabla[i][0]=2;
	}
	//Dibujamo una linea inferior horizontal
	for (i=0; i<25; i++) {
		Tabla[i][14]=2;
	}
	//Dibujamo una linea superior vertical
	for (i=0; i<15; i++) {
		Tabla[0][i]=2;
	}
	//Dibujamo una linea inferior vertical
	for (i=0; i<15; i++) {
		Tabla[24][i]=2;
	}

	//Dibujamo una linea inferior horizontal en medio de la consola
	for (i=5; i<19; i++) {
		Tabla[i][7]=2;
	}

	//Definimos la posición inicial de la "x"
	Tabla[4][3]=3;
	CharX=4;
	CharY=3;

	printf("Press Key...");
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		KeyPress = getch();
		goxy(0,0); //si quitamos esta linea nos damos cuenta que la consola se redibuja
		if (GetAsyncKeyState(VK_UP)) { //Arriba
			yt = CharY - 1;
			if (Tabla[CharX][yt]==1) { //si la anterior esta libre
				Tabla[CharX][CharY]=1; //pongo en la que estoy libre
				CharY=yt;
				Tabla[CharX][yt]=3;
			}
		}
		if (GetAsyncKeyState(VK_DOWN)) { //Abajo
			yt = CharY + 1;
			if (Tabla[CharX][yt]==1) {
				Tabla[CharX][CharY]=1;
				CharY=yt;
				Tabla[CharX][yt]=3;
			}
		}
		if (GetAsyncKeyState(VK_LEFT)) { //Izquierda
			xt = CharX - 1;
			if (Tabla[xt][CharY]==1) {
				Tabla[CharX][CharY]=1;
				CharX=xt;
				Tabla[xt][CharY]=3;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT)) { //Derecha
			xt = CharX + 1;
			if (Tabla[xt][CharY]==1) {
				Tabla[CharX][CharY]=1;
				CharX=xt;
				Tabla[xt][CharY]=3;
			}
		}
		for (y=0; y<15; y++) {
			for (x=0; x<25; x++) {
				if (Tabla[x][y]==1) {
					printf(" ");
				} else if (Tabla[x][y]==2) {
					printf("#");
				} else if (Tabla[x][y]==3) {
					printf("x");
				}
			}
			printf("\n");

		}
	}
}
