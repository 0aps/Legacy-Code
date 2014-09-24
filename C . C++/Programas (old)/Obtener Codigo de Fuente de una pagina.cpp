#include <stdio.h>

#include <stdlib.h>

#include <winsock2.h>

 

int main(int argc, char *argv[])

{

   FILE *code;

   WSADATA wsa_Data;

   SOCKET mi_socket;

   struct sockaddr_in con;

   struct hostent *he;

   int i;

   char buffer[1024];  

   char *peticion1 = "GET / HTTP/1.1\r\nHost: ";

   char *peticion2 = argv[1];

   char *peticion3 = "\r\n\r\nConnection: close\r\n";

   char peticion[strlen(peticion1)+strlen(peticion2)+strlen(peticion3)+1];

   

   strcat(peticion,peticion1);

   strcat(peticion,peticion2);

   strcat(peticion,peticion3);

   

   WSAStartup(MAKEWORD(2,0),&wsa_Data);

   

   if (argc != 2)

   {

            fprintf(stderr,"uso: cliente.exe host_name\n");

           exit(1);

   }

       

   if ((he=gethostbyname(argv[1])) == NULL)

   {

           printf("error al obtener informacion de la maquina");            

            exit(1);

   }

 

   

   mi_socket=socket(AF_INET,SOCK_STREAM,0);

   if(mi_socket==-1)

   {

     printf("error al crear el socket\n");

      exit(1);

   }

   

   con.sin_family = AF_INET;

   con.sin_port = htons(80);  

   con.sin_addr = *((struct in_addr *)he->h_addr);

   memset(con.sin_zero,0,8);

   

   if (connect(mi_socket, (struct sockaddr *)&con,sizeof(struct sockaddr)) == -1)

   {

            printf("error al conectar el socket");

            exit(1);

   }  

   

   send(mi_socket, peticion, strlen(peticion), 0);

   

   code = fopen("code.txt","a+");

   do

    {

        i = recv(mi_socket, buffer, sizeof(buffer), 0);        

        fprintf(code,"%s",buffer);        

    } while (i != 0);  

    fclose(code);

   close(mi_socket);

   printf("\n");

   system("PAUSE");

   return 0;

}
