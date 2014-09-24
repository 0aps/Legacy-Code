#include <stdio.h>
#include <process.h>

unsigned hilo;
unsigned hilo2;
//Creamos una estructura con 3 elementos/variables/objetos xDD
struct parametros
{
int p1;
char *p2;
int p3;
};

void empezarhilo(void *valor){
//Creamos un puntero del tipo de la estructura parametros
struct parametros *nuevos;
//convertimos valor a tipo * estructura parametros
//(recordemos que valor contiene la estructura par)
//Entonces nuevo es igual a la estructura valor (par)
//Jeje lo que hicimos nomas fue recuperar la estructura :PP 
nuevos=(struct parametros *)valor;
//Imprimimos todos los parametros
	printf("\nParametro 1: %d\n",nuevos->p1);
	printf("\nParametro 2: %s\n",nuevos->p2);
	printf("\nParametro 3: %d\n",nuevos->p3);

printf("\nEste es el primer hilo...Continuo aunque el programa principal haya llegado al final");
printf("\n\nseguro que acabo despues de que acabe el programa principal");
printf("\n\nHilo creado por Dark Hero");

	_endthread();

}
void empezarotrohilo(void *valor)
{
	printf("\n\ny aqui hay otro hilo...\n");
printf("\ntamaño del segundo elemento del segundo hilo = %d\n",sizeof(valor));
	_endthread();
 
}

int main(){
	hilo = 0; 
	hilo2= 0;
	//int valor =20; quitamos tu parametro xDD
	//Indicamos que par sera tipo struct parametros
	//por lo tanto podremos acceder a cada elemento de la estructura parametros
	//mediante par
	struct parametros par;
	//Le damos algunos valores a las variables
	//de la estructura para usar en el ejemplo
	par.p1=5;
	par.p2="linkgl";
	par.p3=10;
	//comenzamos el hilo y enviamos el contenido de par
	hilo = _beginthread(empezarhilo,0,&par);
	if(!hilo){
		printf("el hilo no se ha creado\n");
	}
	hilo2 = _beginthread(empezarotrohilo,0,&par);
	
		printf("proceso principal terminado\n");
	
		getchar();
		return 0;
}
