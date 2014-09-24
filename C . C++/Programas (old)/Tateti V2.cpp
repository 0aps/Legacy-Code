#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

bool player1[3][3]={false}, player2[3][3]={false};
char game[3][3]={0};
unsigned short turno=1, bgturno=1;
unsigned short checked=0;
bool out=false;
unsigned short p1=0, p2=0, pe=0;
bool ai=false;


short inteligente()
{
      char x,y;
      _sleep(100);
      if(player2[0][0])if(player2[1][0])if(!game[2][0]) return 49;
      if(player2[0][1])if(player2[1][1])if(!game[2][1]) return 50;
      if(player2[0][2])if(player2[1][2])if(!game[2][2]) return 51;
      if(player2[0][0])if(player2[0][1])if(!game[0][2]) return 57;
      if(player2[1][0])if(player2[1][1])if(!game[1][2]) return 54;
      if(player2[2][0])if(player2[2][1])if(!game[2][2]) return 51;
      if(player2[0][0])if(player2[1][1])if(!game[2][2]) return 51;
      if(player2[2][0])if(player2[1][1])if(!game[0][2]) return 57;
      
      if(player2[0][0])if(!game[1][0])if(player2[2][0]) return 52;
      if(player2[0][1])if(!game[1][1])if(player2[2][1]) return 53;
      if(player2[0][2])if(!game[1][2])if(player2[2][2]) return 54;
      if(player2[0][0])if(!game[0][1])if(player2[0][2]) return 56;
      if(player2[1][0])if(!game[1][1])if(player2[1][2]) return 53;
      if(player2[2][0])if(!game[2][1])if(player2[2][2]) return 50;
      if(player2[0][0])if(!game[1][1])if(player2[2][2]) return 53;
      if(player2[2][0])if(!game[1][1])if(player2[0][2]) return 53;
      
      if(!game[0][0])if(player2[1][0])if(player2[2][0]) return 55;
      if(!game[0][1])if(player2[1][1])if(player2[2][1]) return 56;
      if(!game[0][2])if(player2[1][2])if(player2[2][2]) return 57;
      if(!game[0][0])if(player2[0][1])if(player2[0][2]) return 55;
      if(!game[1][0])if(player2[1][1])if(player2[1][2]) return 52;
      if(!game[2][0])if(player2[2][1])if(player2[2][2]) return 49;
      if(!game[0][0])if(player2[1][1])if(player2[2][2]) return 55;
      if(!game[2][0])if(player2[1][1])if(player2[0][2]) return 49;
      
      
      if(player1[0][0])if(player1[1][0])if(!game[2][0]) return 49;
      if(player1[0][1])if(player1[1][1])if(!game[2][1]) return 50;
      if(player1[0][2])if(player1[1][2])if(!game[2][2]) return 51;
      if(player1[0][0])if(player1[0][1])if(!game[0][2]) return 57;
      if(player1[1][0])if(player1[1][1])if(!game[1][2]) return 54;
      if(player1[2][0])if(player1[2][1])if(!game[2][2]) return 51;
      if(player1[0][0])if(player1[1][1])if(!game[2][2]) return 51;
      if(player1[2][0])if(player1[1][1])if(!game[0][2]) return 57;
      
      if(player1[0][0])if(!game[1][0])if(player1[2][0]) return 52;
      if(player1[0][1])if(!game[1][1])if(player1[2][1]) return 53;
      if(player1[0][2])if(!game[1][2])if(player1[2][2]) return 54;
      if(player1[0][0])if(!game[0][1])if(player1[0][2]) return 56;
      if(player1[1][0])if(!game[1][1])if(player1[1][2]) return 53;
      if(player1[2][0])if(!game[2][1])if(player1[2][2]) return 50;
      if(player1[0][0])if(!game[1][1])if(player1[2][2]) return 53;
      if(player1[2][0])if(!game[1][1])if(player1[0][2]) return 53;
      
      if(!game[0][0])if(player1[1][0])if(player1[2][0]) return 55;
      if(!game[0][1])if(player1[1][1])if(player1[2][1]) return 56;
      if(!game[0][2])if(player1[1][2])if(player1[2][2]) return 57;
      if(!game[0][0])if(player1[0][1])if(player1[0][2]) return 55;
      if(!game[1][0])if(player1[1][1])if(player1[1][2]) return 52;
      if(!game[2][0])if(player1[2][1])if(player1[2][2]) return 49;
      if(!game[0][0])if(player1[1][1])if(player1[2][2]) return 55;
      if(!game[2][0])if(player1[1][1])if(player1[0][2]) return 49;
      for(;;)
      {
            x=(rand()%3);
            y=(rand()%3);
            if(!game[y][x])
            {
                  if(y==0 && x==0)if(!game[0][0])return 55;
                  if(y==1 && x==0)if(!game[1][0])return 52;
                  if(y==2 && x==0)if(!game[2][0])return 49;
                  if(y==0 && x==1)if(!game[0][1])return 56;
                  if(y==1 && x==1)if(!game[1][1])return 53;
                  if(y==2 && x==1)if(!game[2][1])return 50;
                  if(y==0 && x==2)if(!game[0][2])return 57;
                  if(y==1 && x==2)if(!game[1][2])return 54;
                  if(y==2 && x==2)if(!game[2][2])return 51;
            }
      }
}

void exitwindow()
{
      system("color e");
      system("cls");
      printf("\n\n\n\n\n\n\n");
      printf("          ESTADISTICAS\n\n");
      printf("El jugador 1 ha ganado %i veces\n", p1);
      printf("El jugador 2 ha ganado %i veces\n\n", p2);
      printf("El juego termino en empate %i veces", pe);
}

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

void load(char nombre[])
{
      char yc;
      short i,j;
      FILE* archivo;
      archivo = fopen(nombre,"r+b");
      fread(&p1,sizeof(unsigned short),1,archivo);
      fread(&p2,sizeof(unsigned short),1,archivo);
      fread(&pe,sizeof(unsigned short),1,archivo);
      fread(&turno,sizeof(unsigned short),1,archivo);
      fread(&bgturno,sizeof(unsigned short),1,archivo);
      fread(&checked,sizeof(unsigned short),1,archivo);
      fread(&yc,sizeof(char),1,archivo);
      fread(&game,sizeof(char)*9,1,archivo);
      fclose(archivo);
      
      for(i=0;i<3;i++)
      {
            for(j=0;j<3;j++)
            {
                  if(game[i][j]=='O')player1[i][j]=true;
                  else if(game[i][j]=='X')player2[i][j]=true;
                  
            }
      }
      if(yc)ai=true;
      system("cls");
      printf("Partida cargada");
      getch();
}

void save()
{
      char yb=0;
      if(ai)yb=1;
      FILE* archivo;
      archivo = fopen("Save.sav","wb");
      fwrite(&p1,sizeof(unsigned short),1,archivo);
      fwrite(&p2,sizeof(unsigned short),1,archivo);
      fwrite(&pe,sizeof(unsigned short),1,archivo);
      fwrite(&turno,sizeof(unsigned short),1,archivo);
      fwrite(&bgturno,sizeof(unsigned short),1,archivo);
      fwrite(&checked,sizeof(unsigned short),1,archivo);
      fwrite(&yb,sizeof(char),1,archivo);
      fwrite(&game,sizeof(char)*9,1,archivo);
      fclose(archivo);
      system("cls");
      printf("Partida guardada");
      getch();
      refreshwindow();
}

void juego()
{
      bool sale=false;
      short tecla=0;
      for(;;)
      {
      if(turno==2 && ai)tecla=inteligente();
      else
      {
            while(!(tecla>=49 && tecla<=57))
            {
                  tecla=getch();
                  if(tecla==27)
                  {
                        out=true;
                        return;
                  }
                  if(tecla==19 || tecla==7)save();
                  if(tecla==9 || tecla==1)srand(time(NULL));
                  if(tecla==9 || tecla==1)ai=true;
                  if(tecla==9 || tecla==1)if(turno==2)tecla=inteligente();
            }
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


int main(int argc, char *argv[])
{
      bool termina=false;
      int i,j;
      short t=0;
      system("title The Void's TaTeTi");
      if(argc==2) load(argv[1]);
      
      for(;;)
      {
            if(checked)termina=true;
            while(!termina)
            {
                  refreshwindow();
                  juego();
                  if(!out)
                  {
                        checked=check();
                        if(checked==1 || checked==2 || checked==3) termina=true;
                        if(turno==1)turno=2;
                        else if(turno==2)turno=1;
                  }
                  else termina=true;
            }
            refreshwindow();
            if(!out)
            {
                  if(checked==1)system("color a");
                  if(checked==2)system("color 9");
                  if(checked==3)system("color b");
                  while(t!=32)
                  {
                        t=getch();
                        if(t==27)
                        {
                              t=32;
                              out=true;
                        }
                        if(t==19 || t==7)save();
                        if(t==9 || t==1)srand(time(NULL));
                        if(t==9 || t==1)ai=true;
                  }
                  
            }
            if(checked==1)p1++;
            if(checked==2)p2++;
            if(checked==3)pe++;
            if(!out)
            {
                  system("color 7");
                  for(i=0;i<3;i++)
                  {
                        for(j=0;j<3;j++)
                        {
                              player1[i][j]=false;
                              player2[i][j]=false;
                              game[i][j]=0;
                        }
                  }
                  checked=0;
                  termina=false;
                  t=0;
                  if(bgturno==1)
                  {
                        turno=2;
                        bgturno=2;
                  }
                  else if(bgturno==2)
                  {
                        turno=1;
                        bgturno=1;
                  }
            }
            if(out)
            {
                  exitwindow();
                  t=0;
                  while(t!=32 && t!=27)
                  {
                        t=getch();
                  }
                  return 0;
            }
      }
}
