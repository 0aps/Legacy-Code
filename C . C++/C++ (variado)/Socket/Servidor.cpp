#include <winsock2.h> //la cabezera para usar las funciones de winsock
#include <stdio.h>
/*linkamos a la libreria del winsock, también puedes hacerlo desde
  project->settings->link si usas ms visual c++ */
#pragma comment(lib,"ws2_32.lib")
int main()
{
   WSADATA wsa;
   SOCKET sock;
   struct sockaddr_in local;
   int len=0;
   char Buffer[1024];
   //Inicializamos
   WSAStartup(MAKEWORD(2,0),&wsa);
   
   //Creamos el socket
   sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   
   //defnimos dirección por defecto, ipv4 y el puerto 9999
   local.sin_family = AF_INET;
   local.sin_addr.s_addr = INADDR_ANY;
   local.sin_port = htons(9999);
   //asociamos el socket al puerto
   if (bind(sock, (SOCKADDR*) &local, sizeof(local))==-1)
   {
      printf("error en el bind\n");
      return -1;
   }
   //ponemos el socket a la escucha
   if (listen(sock,1)==-1)
   {
      printf("error en el listen\n");
      return -1;
   }
   
   len=sizeof(struct sockaddr);
   
    //hay una conexión entrante y la aceptamos
   sock=accept(sock,(sockaddr*)&local,&len);
   printf("[SERVIDOR MiniXat para tutorial de sockets MazarDZone Foro]\n");
   printf("[Cuando se vaya recibiendo texto aparecera en pantalla    ]\n");
   while (len!=0) //mientras estemos conectados con el otro pc
   {
      len=recv(sock,Buffer,1023,0); //recibimos los datos que envie
      if (len>0)  //si seguimos conectados
      {
         Buffer[len]=0; //le ponemos el final de cadena
         printf("Texto recibido:%s",Buffer); //imprimimos la cadena recibida
      }
   }
   
   return 0;
}
