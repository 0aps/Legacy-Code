#include <stdio.h>

void Cobro();

struct cliente
{
       char nombre[50];
       int  
       


int main()
{
    signed short opcion = 0;
    
    do
    {
    system("cls");
    printf("Bienvenido al sistema contable\n\n");
    printf("Elija una opcion:\n\n1) Cobro\n2) Salir\n\n:");
    fscanf(stdin, "%i", &opcion);
    }while( opcion == 0 || opcion > 2);
    
    if(opcion == '1')
       Cobro();
        
    printf("\n\nSaliendo . . . \n Gracias por preferirnos.");
    setbuf(stdin, NULL);
    getchar();
    return 0;
}

void Cobro()
{
     
     
     
     system("cls");
     printf("Nombre del cliente: "
}
