#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

bool player1[3][3]={false}, player2[3][3]={false};
char game[3][3]={0};
unsigned short turno;
unsigned short checked=0;

void refreshwindow()
{
      system("cls");
      printf("\n\n\n\n\n\n\n");
      printf("          \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
      printf("          \xdb %c \xdb %c \xdb %c \xdb\n", game[0][0], game[0][1], game[0][2]);
      printf("          \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
      printf("          \xdb %c \xdb %c \xdb %c \xdb\n", game[1][0], game[1][1], game[1][2]);
      printf("          \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
      printf("          \xdb %c \xdb %c \xdb %c \xdb\n", game[2][0], game[2][1], game[2][2]);
      printf("          \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
      printf("\n\n");
      if(!checked)printf("Es el turno del jugador %i", turno);
      else if(checked==1 || checked==2)printf("El jugador %i ha ganado",checked);
      else printf("La ronda ha terminado en empate");
}

unsigned short check()
{
      if(player1[0][0])if(player1[1][0])if(player1[2][0]) return 1;
      if(player1[0][1])if(player1[1][1])if(player1[2][1]) return 1;
      if(player1[0][2])if(player1[1][2])if(player1[2][2]) return 1;
      if(player1[0][0])if(player1[0][1])if(player1[0][2]) return 1;
      if(player1[1][0])if(player1[1][1])if(player1[1][2]) return 1;
      if(player1[2][0])if(player1[2][1])if(player1[2][2]) return 1;
      if(player1[0][0])if(player1[1][1])if(player1[2][2]) return 1;
      if(player1[2][0])if(player1[1][1])if(player1[0][2]) return 1;
      
      if(player2[0][0])if(player2[1][0])if(player2[2][0]) return 2;
      if(player2[0][1])if(player2[1][1])if(player2[2][1]) return 2;
      if(player2[0][2])if(player2[1][2])if(player2[2][2]) return 2;
      if(player2[0][0])if(player2[0][1])if(player2[0][2]) return 2;
      if(player2[1][0])if(player2[1][1])if(player2[1][2]) return 2;
      if(player2[2][0])if(player2[2][1])if(player2[2][2]) return 2;
      if(player2[0][0])if(player2[1][1])if(player2[2][2]) return 2;
      if(player2[2][0])if(player2[1][1])if(player2[0][2]) return 2;
      
      if(game[0][0])if(game[0][1])if(game[0][2])if(game[1][0])if(game[1][1])if(game[1][2])if(game[2][0])if(game[2][1])if(game[2][2]) return 3;
      
      return 0;
}

void juego()
{
      bool sale=false;
      short tecla=0;
      for(;;)
      {
      while(!(tecla>=49 && tecla<=57))
      {
            tecla=getch();
      }
      if((tecla==49) && (game[2][0]==0))
      {
            if(turno==1)
            {
                  game[2][0]='O';
                  player1[2][0]=true;
            }
            else if(turno==2)
            {
                  game[2][0]='X';
                  player2[2][0]=true;
            }
      return;
      }
      
      if((tecla==50) && (game[2][1]==0))
      {
            if(turno==1)
            {
                  game[2][1]='O';
                  player1[2][1]=true;
            }
            else if(turno==2)
            {
                  game[2][1]='X';
                  player2[2][1]=true;
            }
      return;
      }
      
      if((tecla==51) && (game[2][2]==0))
      {
            if(turno==1)
            {
                  game[2][2]='O';
                  player1[2][2]=true;
            }
            else if(turno==2)
            {
                  game[2][2]='X';
                  player2[2][2]=true;
            }
      return;
      }
      
      if((tecla==52) && (game[1][0]==0))
      {
            if(turno==1)
            {
                  game[1][0]='O';
                  player1[1][0]=true;
            }
            else if(turno==2)
            {
                  game[1][0]='X';
                  player2[1][0]=true;
            }
      return;
      }
      
      if((tecla==53) && (game[1][1]==0))
      {
            if(turno==1)
            {
                  game[1][1]='O';
                  player1[1][1]=true;
            }
            else if(turno==2)
            {
                  game[1][1]='X';
                  player2[1][1]=true;
            }
      return;
      }
      
      if((tecla==54) && (game[1][2]==0))
      {
            if(turno==1)
            {
                  game[1][2]='O';
                  player1[1][2]=true;
            }
            else if(turno==2)
            {
                  game[1][2]='X';
                  player2[1][2]=true;
            }
      return;
      }
      
      if((tecla==55) && (game[0][0]==0))
      {
            if(turno==1)
            {
                  game[0][0]='O';
                  player1[0][0]=true;
            }
            else if(turno==2)
            {
                  game[0][0]='X';
                  player2[0][0]=true;
            }
      return;
      }
      
      if((tecla==56) && (game[0][1]==0))
      {
            if(turno==1)
            {
                  game[0][1]='O';
                  player1[0][1]=true;
            }
            else if(turno==2)
            {
                  game[0][1]='X';
                  player2[0][1]=true;
            }
      return;
      }
      
      if((tecla==57) && (game[0][2]==0))
      {
            if(turno==1)
            {
                  game[0][2]='O';
                  player1[0][2]=true;
            }
            else if(turno==2)
            {
                  game[0][2]='X';
                  player2[0][2]=true;
            }
      return;
      }
      tecla=0;
      }

}


main()
{
      bool termina=false;
      srand(time(NULL));
      system("title The Void's TaTeTi");
      turno=(rand()%2)+1;
      while(!termina)
      {
            refreshwindow();
            juego();
            checked=check();
            if(checked==1 || checked==2 || checked==3) termina=true;
            if(turno==1)turno=2;
            else if(turno==2)turno=1;
      }
      refreshwindow();
      if(checked==1)system("color a");
      if(checked==2)system("color c");
      if(checked==3)system("color b");
      getch();
}
