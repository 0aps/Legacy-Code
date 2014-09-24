#include <stdio.h>

void arrey(char arrey[])
{
     char *hola = (char *)malloc(sizeof(char*));
     strncpy(hola, "pedro", strlen("pedro"));
     *pedro = 'a';
     pedro = hola;
}
void puntero(char *pedro)
{
     char *hola = (char *)malloc(sizeof(char*));
     strncpy(hola, "pedro", strlen("pedro"));
     *pedro = 'a';
     pedro = hola;
}

int main()
{
    char eso[] = "maria";
    arrey(eso);
    printf("%s", eso);
    puntero(eso);
    printf("%s", eso);
    
    getchar();
    return 0;
}
