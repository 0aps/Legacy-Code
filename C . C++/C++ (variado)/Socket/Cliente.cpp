#include <winsock2.h> //la cabezera para usar las funciones de winsock
#include <stdio.h>
/*linkamos a la libreria del winsock, también puedes hacerlo desde
  project->settings->link si usas ms visual c++ */
#pragma comment(lib,"ws2_32.lib")

int main()
{
   WSADATA wsa;
   SOCKET sock;
   struct hostent *host;
   struct sockaddr_in direc;
   int conex;
   char Buffer[1024];
   int len;
   //Inicializamos
   WSAStartup(MAKEWORD(2,2),&wsa);
   //resolvemos el nombre de dominio localhost, esto se resolverá a 127.0.0.1
   host=gethostbyname("localhost");
   //creamos el socket
   sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   if (sock==-1)
   {
      printf("Error al crear el socket");
      return -1;
   }
   
   //Definimos la dirección a conectar que hemos recibido desde el gethostbyname
   //y decimos que el puerto al que deberá conectar es el 9999 con el protocolo ipv4
   direc.sin_family=AF_INET;
   direc.sin_port=htons(9999);
   direc.sin_addr = *((struct in_addr *)host->h_addr);
   memset(direc.sin_zero,0,8);
   //Intentamos establecer la conexión
   conex=connect(sock,(sockaddr *)&direc, sizeof(sockaddr));
   if (conex==-1)  //si no se ha podido conectar porque no se ha encontrado el host o no
                  //está el puerto abierto
   {
      printf("No se ha podido conectar\n");
      return -1;
   }
   printf("[MiniXat para tutorial de sockets MazarDZone Foro]\n");
   printf("[escribe el texto a enviar o 'salir' para salir  ]\n");
   
     while (len!=-1 && strcmp(Buffer,"salir")!=0) //mientras el socket no se haya 
                                               //y no se escriba salir
   {
      printf("Texto a enviar:");
      fgets(Buffer,1023,stdin);  //pedir texto a enviar por pantalla
      len=send(sock,Buffer,strlen(Buffer),0); //enviar el texto que se ha introducido
   }
   return 0;
}
