#include <windows.h>
#include <winsock.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    
   int sockfd,cn;
   struct sockaddr_in cliente;   // Guardará la dirección de destino     struct
   hostent *host;
   char *aux = "Host: apsq.dom.do";
   
WSADATA wsaData;

if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)
{
   cerr << "WSAStartup fallo";        
    exit(1);
}


if ( (host=gethostbyname(argv[1])) == NULL) {  // Obtener información del host
perror ("No se ha podido usar el DNS");
exit(1);
}

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

if (sockfd < 0)
{
   perror ("No se ha podido conseguir un socket");
}


  cliente.sin_family = AF_INET;
  cliente.sin_port = htons(80);
  cliente.sin_addr = *( (in_addr *)host->h_addr);

memset(&(cliente.sin_zero), '\0', 
        sizeof(cliente.sin_zero) );  // Poner a cero el resto de la estructura
        
if (connect (sockfd, (struct sockaddr *)&cliente,  sizeof(struct sockaddr)) == -1)
{
   perror("error en connect");
   exit(1);
}else cout << "conectado . . . ";

 
  for(cn=0; cn < atoi(argv[2]); cn++)
  {
    connect( sockfd, (struct sockaddr *)&cliente, sizeof(struct sockaddr) );
    
    if( send(sockfd, "GET / HTTP/1.1\n", sizeof("GET / HTTP/1.1\n"), 0) == -1)
     
       perror("send");
       else cout << "\nGet enviado.";
       
   if( send(sockfd, aux, sizeof(host), 0) == -1)
       
       perror("send");
       else cout << "\nHosting enviado.";
  }
}
 
