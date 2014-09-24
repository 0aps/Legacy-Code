#include <iostream> 
#include <windows.h>
#include <ctime>

using namespace std;

int sRand(int);

int main(int argc, char *argv[])
{
    int numero, otro_numero;
    srand(time(NULL));
    otro_numero = rand()%10;

cout << "Introduc" << char(160) << " un n" << char(163) << "mero: ";
cin >> numero;

if (numero == otro_numero)
        cout << "Bien culero.  . ."; else cout << "Mal. . .\n\n\t" << "El numero era " << otro_numero;
        
       
       setbuf(stdin, NULL);
       cin.get();
       return 0;
    } 
/*
 #include<stdio.h>
#include<stdlib.h>
#define LARGO_ARRAY 5
#define FILA 2
#define COLUMNA 4
//definicion de contantes
void CargarArray(int a[LARGO_ARRAY]);
void MostrarArray(int *a);
int SumarArray(int a[]);
void MostrarMatriz(int m[FILA][COLUMNA]);
void CargarMatriz(int m[FILA][COLUMNA]);
//declaracion de funciones
void CargarArray(int a[LARGO_ARRAY])//pasar array como parametro
{
	int i=0;
	for(i=0;i<LARGO_ARRAY;i++)
	{
		a[i]=(rand()%37)+1;
	}
}
void MostrarArray(int *a)
{
	int i=0;
	for(i=0;i<LARGO_ARRAY;i++)
	{
		printf("%d\n",*(a+i));
	}
}
int SumarArray(int a[])
{
	int i=0,oResultado=0;
	for(i=0;i<LARGO_ARRAY;i++)
	{
		oResultado=oResultado+a[i];
	}
	return oResultado;
}
void MostrarMatriz(int m[FILA][COLUMNA])
{
	int i,j;
		for(i=0;i<FILA;i++)
		{
			for(j=0;j<COLUMNA;j++)
			{
				printf("%d\t",m[i][j]);
			}
			printf("\n");
		}
}
void CargarMatriz(int m[FILA][COLUMNA])
{
	int i,j,k;
		for(i=0;i<FILA;i++)
		{
			for(j=0;j<COLUMNA;j++)
			{
				m[i][j]=(rand()%37+1);
			}
			
		}
}
int main(int argc,char * argv[])
{
	int oAltura[LARGO_ARRAY];
	int oMatriz[FILA][COLUMNA];
	CargarArray(oAltura);
	MostrarArray(oAltura);
	printf("La suma = %d\n",SumarArray(oAltura));//hace la suma del array	
	MostrarMatriz(oMatriz);
	printf("Cantidad de argumentos %d\n",argc);// mustra un argumento por defecto
	printf("Valor argumento 0 %s\n\n",argv[0]);//mustra la ubicacion del ejecutable
	if(argc==2 && argv[1][0]=='?')
	{
		printf("\nAYUDA:\n\tCargarArray carga oAltura\n\tMostrarArray mustra oAltura\n\n");
	}
	system("pause");
	system("pause");
}   
   */ 
