#include <stdio.h>

int main()
{
 unsigned short x,i,y,z;
 printf("# d lineas: ");
 scanf("%d", &x);
 
 if( x <= 9)
{
     
 for(y = 1; y <= x; y++)
 {
   for(z = 1; z <= x-y; z++)
   { 
         printf(" ");
   }
 
   for(i = 1; i <= 1*y-1; i++)
    {
         printf("**");
    }
      printf("\n");
   
 }

}else printf("El num max d lineas es 9.");
    
 setbuf(stdin, NULL);
 getchar();
 return 0;
}

