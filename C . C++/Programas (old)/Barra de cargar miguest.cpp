#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void pause()
{
    setbuf(stdin, NULL);
    getchar();
}

int main()
{
    int num1, num2, i;
    printf("Introduce 2 numeros separados por 1 espacio: ");
    scanf("%i %i", &num1, &num2);

    //Para cambiar el tamaño de la ventana sin recurrir a system
    HANDLE hOut;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT DisplayArea = {0, 0, 0, 0};
    DisplayArea.Bottom = 1;
    DisplayArea.Right = 50;

    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);

    //Barra de cargar
    for(i=0;i<=20;i++)
    {
        printf("Û");
        Sleep(250);
    }
    system("cls");

    //Cambia el alto
    DisplayArea.Bottom=10;
    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);

    //Imprime resultado
    printf("%i + %i = %i", num1, num2, num1+num2);
    pause();
    return 0;
}
