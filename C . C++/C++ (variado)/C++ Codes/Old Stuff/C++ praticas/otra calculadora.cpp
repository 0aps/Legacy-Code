#include <stdio.h>//Declaramos la libreria stdio.h
#include <stdlib.h>//Declaramos la libreria stdlib.h
#include <windows.h>//Declaramos la libreria windows.h
#include <math.h>//Declaramos la libreria math.h
#define CLS printf ("\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f\f")//Haremos un CLS artesanal, xd

int main()
{
    int opcion, opcion1; //Declaramos variables
    char sino[4]; //Declaramos variables
    SetConsoleTitle("Programa multitareas"); //Cambiamos el titulo de la ventana sin usar el odioso system("title Mi ventana")
    printf("Escoje una opcion a elegir:\n\n1. Calculadora\n\n"); //Mostramos mensaje
    scanf("%i", &opcion); //Guardamos lo que escriba el usuario en una variable
    switch(opcion) 
    {
        case 1: CLS;
        printf("Escoje una opcion a elegir:\n\n1.Sumar\n2.Restar\n3.Multiplicar\n4.Dividir\n5.Potencias\n6.Raiz Cuadrada\n\n");
        scanf("%i", &opcion1);
        switch(opcion1)
        {
            case 1:
                CLS;
                float sum1, sum2;
                printf("Introduce el primer numero:\n\n");
                scanf("%f", &sum1);
                CLS;
                printf("Introduce el numero que le quieres sumas a %f:\n\n", sum1);
                scanf("%f", &sum2);
                CLS;
                printf("%f + %f = %f", sum1, sum2, sum1+sum2);
                system("pause>nul");
            break;
            case 2:
                CLS;
                float rest1, rest2;
                printf("Introduce el primer numero:\n\n");
                scanf("%f", &rest1);
                CLS;
                printf("Introduce el numero que le vas a restar a %f:\n\n", rest1);
                scanf("%f", &rest2);
                CLS;
                printf("%f - %f = %f", rest1, rest2, rest1-rest2);
                system("pause>nul");
            break;
            case 3:
                CLS;
                float mult1, mult2;
                printf("Introduce el primer numero:\n\n");
                scanf("%f", &mult1);
                CLS;
                printf("Introduce el numero al que le vas a multiplar a %f:\n\n", mult1);
                scanf("%f", &mult2);
                CLS;
                printf("%f x %f = %f", mult1, mult2, mult1*mult2);
                system("pause>nul");
            break;
            case 4:
                CLS;
                float divi1, divi2;
                printf("Introduce el primer numero:\n\n");
                scanf("%f", &divi1);
                CLS;
                printf("Introduce el numero por el que va a ser dividido %f:\n\n", divi1);
                scanf("%f", &divi2);
                CLS;
                printf("%f / %f = %f", divi1, divi2, divi1/divi2);
                system("pause>nul");
            break;
            case 5:
                CLS;
                float pote1, pote2, pote3;
                printf("Introduce la base:\n\n");
                scanf("%f", &pote1);
                CLS;
                printf("Introduce el exponente de %f:\n\n", pote1);
                scanf("%f", &pote2);
                CLS;
                pote3=pow(pote1, pote2);
                printf("%f ^ %f = %f", pote1, pote2, pote3);
                system("pause>nul");
                CLS;
            break;
            case 6:
                CLS;
                float raiz1;
                printf("Introduce el numero al que le vas a hacer la raiz cuadrada:\n\n");
                scanf("%f", &raiz1);
                printf("La raiz cuadrada de %f es %f", raiz1, sqrt(raiz1));
                system("pause>nul");
            break;
            default:
                CLS;
                printf("Error, has introducido %i, este numero no esta entre 1-6", opcion1);
                system("pause>nul");
            break;
                
        }
    }
}
