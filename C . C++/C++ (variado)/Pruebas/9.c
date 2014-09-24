#include <stdio.h>
#include <windows.h>

int main()
{
  int x,z;
  
  char **bucle = (char **)malloc(3);
  for(x=0; x < 3; x++)
  {
  bucle[x] = (char*)malloc(10);
  ZeroMemory(bucle[x], 10);
  }
  
  strcpy(bucle[0], "annnnGellll");
  strcpy(bucle[1], "pamellaa"   );
  strcpy(bucle[2], "isssabeell" );
  
  for(x=0; x < 3; x++)
 {
  printf("%s\n", bucle[x]); 
 }
 
 for(z=0; z < 3; z++)
 {
 printf("\n\n");
 
 for(x=0; bucle[z][x]; x++)
 {
  printf("bucle[%d][%d] = %c\n", z,x, bucle[z][x]);
 }
 
 }
  
 getchar();
 return 0;
 }
