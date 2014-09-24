#include <cstdlib>
#include <stdio.h>
#include <wininet.h>
using namespace std;
/*
/* Ejemplo Subir / Descargar archivos via FTP C++
/* By Octalh [octalh@gmail.com]
/* www.aztekmindz.org
*/

int SubirFTP(char *servidor, char *usuario, char *password,
int puerto, char *ALocal, char *ARemoto){
    HINTERNET Peticion;
    Peticion =InternetOpen("Internet Explorer",0,NULL,NULL,0);
    if(Peticion==NULL){
         return 1;
    }else {
       HINTERNET Conectar;
       Conectar = InternetConnect(Peticion,servidor,puerto,
       usuario,password,INTERNET_SERVICE_FTP,0,0);
       if(Conectar==NULL){
            InternetCloseHandle(Conectar);
            return 1;
       }else{
          if(FtpPutFile(Conectar,ALocal,ARemoto,FTP_TRANSFER_TYPE_BINARY,0)==FALSE){
             return 1;
          }

          return 0;
          InternetCloseHandle(Peticion);
          InternetCloseHandle(Conectar);

       }

    }

}

int BajarFTP(){
}

int main(int argc, char *argv[])
{
    if (SubirFTP("Servidorftp.com", "usuario","password",21,"local.txt","remoto.txt")==0){
        printf("\n Archivo Subido Con Exito. \n\n");
        }else{
        printf("\n Error al Subir el Archivo. \n\n");
        }
    system("PAUSE");
    return EXIT_SUCCESS;
}
