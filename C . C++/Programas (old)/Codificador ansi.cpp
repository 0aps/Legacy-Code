/* Codificador ASCII     
      By myguestp   */
 
#include <stdio.h>
#include <string.h>
 
 
int main()
{
    char buff[200];
    char ruta[]="ola.txt";
    scanf("%s", buff);
    FILE *arc;
    arc=fopen(ruta, "a");
    if(!arc)
    {
        return 1;
    }
    for(int i=0; i<strlen(buff); i++)
    {
        fprintf(arc, "%i ", (int)buff[i]);
    }
    printf("Escrito con exito");
    setbuf(stdin, NULL); getchar();
    fclose(arc);
    return 0;
}
