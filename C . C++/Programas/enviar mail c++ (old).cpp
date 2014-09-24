#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef WIN32
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#else
#include <windows.h>
#include <winsock.h>
#include <iostream>
#endif

#define DEST_PORT    25
#define MAXDATASIZE    255 //Añadir en el proyecto la librería wsock32.lib void

using namespace std;

void MandaMail(char * ServidorSMTP);

#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
   MandaMail("smtp.gmail.com");
   return 1;
}
#else     
int main(int argc, char *argv[])
{
   MandaMail("smtp.gmail.com");
   return 1;
}
#endif

void MandaMail(char * ServidorSMTP)
{
   int sockfd;
   struct sockaddr_in dest_addr;   // Guardará la dirección de destino     struct
   hostent *hServSMTP;
   char buf[MAXDATASIZE];
   int numbytes;

/*/////////////////////////////////////////////////////
////            Inicio de la Conexión              ////
/////////////////////////////////////////////////////*/

#ifdef WIN32 
WSADATA wsaData;
if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)
{
   cerr << "WSAStartup fallo";        
    exit(1);
}
#endif     

if ( (hServSMTP=gethostbyname(ServidorSMTP)) == NULL) {  // Obtener información del host
perror ("No se ha podido usar el DNS");
exit(1);
}

sockfd = socket(AF_INET, SOCK_STREAM, 0);

if (sockfd < 0)
{
   perror ("No se ha podido conseguir un socket");
}

dest_addr.sin_family = AF_INET;          // Ordenación de máquina
dest_addr.sin_port = htons(DEST_PORT);   // short, Ordenación de la red
dest_addr.sin_addr = *( (struct in_addr *)hServSMTP->h_addr);

memset(&(dest_addr.sin_zero), '\0', sizeof(dest_addr.sin_zero) );  // Poner a cero el resto de la estructura
if (connect (sockfd, (struct sockaddr *)&dest_addr,  sizeof(struct sockaddr)) == -1)
{
   perror("connect");
   exit(1);
}else cout << "conectado . . . ";

/*/////////////////////////////////////////////////////
////         Envio en si mismo                     ////
/////////////////////////////////////////////////////*/

if ((numbytes=recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1)
{
   perror("recv");
   exit(1);
}
buf[numbytes] = '\0';
if (send(sockfd, "helo gmail.com\n", 15, 0) == -1)
   perror("send");
   else cout << "\nSaludo enviado";

numbytes=recv(sockfd, buf, MAXDATASIZE-1,0);
buf[numbytes] = '\0';

if ( send(sockfd, "mail from: hola@hotmail.com\n", 29, 0) == -1)
   perror("send");
   else cout << "\n mail from bien.";

numbytes=recv(sockfd, buf, MAXDATASIZE-1, 0);
buf[numbytes] = '\0';

if( send(sockfd, "rcpt to: aps--@hotmail.com\n", 31, 0) == -1)
   perror("send");
   else cout << "\n receptor bien";

numbytes=recv(sockfd, buf, MAXDATASIZE-1, 0);
buf[numbytes] = '\0';

if ( send(sockfd, "data\n", 5, 0) == -1) 
   perror("send");
   else cout << "\n data bien.";

numbytes=recv(sockfd, buf, MAXDATASIZE-1, 0);
buf[numbytes] = '\0';

if( send(sockfd, "mail from: hola@hotmail.com\n.\n", 31, 0) == -1)
   perror("send");
   else cout << "\n mail from final bien";

numbytes=recv(sockfd, buf, MAXDATASIZE-1, 0);
buf[numbytes] = '\0';

/*/////////////////////////////////////////////////////
////              Fin de la Conexion               ////
/////////////////////////////////////////////////////*/

setbuf(stdin,NULL);
cin.get();
shutdown(sockfd,2);

#ifdef WIN32
closesocket(sockfd);
WSACleanup();

#endif

}
