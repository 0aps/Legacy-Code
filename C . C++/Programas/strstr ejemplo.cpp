/* strstr example */
#include <stdio.h>
#include <string.h>

//This example searches for the "simple" substring in str and replaces that word for "sample".

int main ()
{
        
  char str[] ="This is a simple string";
  char * pch;
  
  //retorna un puntero a la cadena encontrada
  pch = strstr (str,"simple");
  
  strncpy (pch,"sample",6);
  puts (str);
  
  getchar();
  return 0;
}
