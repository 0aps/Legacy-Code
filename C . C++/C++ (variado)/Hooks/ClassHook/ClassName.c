/*
  Copyright: InExInferis Inc.
  URL: http://www.inexinferis.co.nr
  Author: Karman
  Date: 26/10/05 13:27
*/

/******************* ClassName.c  **********************/

#include <stdio.h>
#include <windows.h>
#include "Classhook.h"

int main( void ){
  
printf("Class Names Hooks Returner Vr. 0.1\n");
printf("==========================================\n\n");

DLKStart();

printf("Presione una tecla Para Finalizar... .)\n\n");
getchar();

DLKExit();
return 0;
}

/******************* ClassName.c  **********************/

