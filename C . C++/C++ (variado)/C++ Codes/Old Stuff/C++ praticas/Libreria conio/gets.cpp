#include <stdio.h>
#include <string.h>
int main()
{
 
char letra1[]="AAAAA";
char letra2[]="BBBBB";
char letra3[]="CCCCC";
 
printf("A: %s\nB: %s\nC: %s\n\n",letra1,letra2,letra3);
 
printf("Ingrese la letra D, 5 veces: ");
fgets(letra2, 10, stdin);
if (letra2[strlen(letra2)-1] == '\n')//string.h para strlen(); 
letra2[strlen(letra2)-1] = '\0';

printf("\nA: %s\nB: %s\nC: %s\n\n",letra1,letra2,letra3);
 
getchar();
}
