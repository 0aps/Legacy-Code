#include <iostream>

using namespace std;
/*
int espacio(char *cadena)
{
    int i;
    while(strlen(cadena) == ' ')
    {
      i++;
    }
    return i;
    
}
*/

/*contaje de blancos*/



int main(int argc, char *argv[])
{
long nb=0;
char c;

printf("\n Introduce un texto acabado en CTRL+Z :\n");
while ((c=getchar())!=EOF)
{
if(c=' ')
nb++;
}

printf("\n\n\n El numero de blancos del texto es: %ld \n",nb);
setbuf(stdin, NULL);
cin.get();
return 0;
}
    
    
