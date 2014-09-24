# include <stdio.h>
# include <stdlib.h>
int main()
{
    int opcion;
    do
    {
     printf("teclea 1, 2 o 3\n\n");
     scanf("%i", &opcion);
    }
    while ((opcion<1)||(opcion>3));
    printf("numero correcto\n");
    system("pause");
}
