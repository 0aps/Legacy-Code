#include <stdio.h>
#include <stdlib.h>

int main()
{
    
FILE *ptr;
ptr = fopen("libro.txt","rb");

if(!ptr)
return -1;

fseek(ptr, 0, SEEK_END); // Se posiciona al final del archivo
int size = ftell(ptr); // posición actual del archivo (en bytes)
fseek(ptr, 0, SEEK_SET);

char *var = (char*)malloc( size );


while(!feof(ptr))
{
fgets(var,size,ptr);/*Aqui leemos desde un archivo de texto*/
puts(var);
}



free (ptr);
setbuf(stdin, NULL);
getchar();

return 0;
}
