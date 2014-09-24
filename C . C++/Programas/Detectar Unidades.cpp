#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

/***************************************************
Coder : ØnLy ***************************************
Lenguage : C ***************************************
Webs: -http://www.indetectables.net*****************
      -http://www.corp-51.net***********************
      -http://www.onlydevelopments.blogspot.com/****
Fecha : 06/01/2010**********************************
****************************************************/

int main()
{
   char drive[MAX_PATH];
   char *puntero;
   char unidad[256]={'\0'}; //Limpiamos la memoria de nuestro buffercito
   int i;

   GetLogicalDriveStrings(MAX_PATH , drive);

   printf("Unidades Conectadas: \n");
   puntero = drive; //Apuntmos "Puntero" al Buffer....
while(1)
{
   while ( *puntero != '\0') //Mientras el Puntero no termine.......
   {
      for ( i=0 ; *puntero != '\0' ; i++)
      {
         unidad[i] = *puntero; //unidad[i] , sera igaul al caracter al que apunta el puntero ,mientras este no termine.....
         *puntero++; //Aumentamos el Puntero para guardar el siguiente caracter , hasta llegar al punto muerto....
      }

        switch( GetDriveType(unidad) ) //Ya Tenemo la unidad actual encontrada...
        {
            //Comparamos con los diferentes Tipos.....
            case DRIVE_FIXED:
             printf("%s : Disco Duro/Disco Rigido" , unidad);
            break;

            case DRIVE_CDROM:
              printf("%s : CD-ROM", unidad);
            break;

            case DRIVE_REMOVABLE:
              printf("%s : Dispositivo Extraible" , unidad);
            break ;

            case DRIVE_UNKNOWN:
              printf("%s : Dispositivo Desconocido" , unidad);
            break;

            case DRIVE_RAMDISK:
              printf("%s : Memoria RAM" , unidad);
            break;
        }

      putchar('\n'); //Hacemos un ENTER
      puntero++; //Aumentamos el puntero de nuevo , para acceder a la proxima cadena con la Unidad Conectada!
   }
}
getchar();
return 0;
}
