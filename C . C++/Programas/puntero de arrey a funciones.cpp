#include <stdio.h>

int multi(int x,int y){
	
	return x*y;
}
int restar(int x,int y){

	return x-y;
}
int sumar(int x,int y){

	return x+y;
}

int main(){

	int (*ptr[])(int,int) = {multi,restar,sumar};
	int x=0,y=0;
	printf("ingrese x e y: ");
	scanf("%d,",&y);
	scanf("%d",&x);
	for(int i=0;i<3;i++){
		printf("\nvalor de x %d,valor de y %d,valores de la funcion %d",x,y,ptr[i](x,y));
	}
	
	setbuf(stdin, NULL);
	getchar();
	return 0;
}


