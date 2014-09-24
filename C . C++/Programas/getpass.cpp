#include <windows.h>
#include <stdio.h>

//el borrado es un problema
char *getpass(char *pass,unsigned int length){
  DWORD num,modo,i=0;
  HANDLE input=GetStdHandle(STD_INPUT_HANDLE);
  HANDLE output=GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleMode(input,&modo);
  SetConsoleMode(input,modo&~(ENABLE_ECHO_INPUT|ENABLE_LINE_INPUT));

  do{
    ReadConsole(input,&pass[i],1,&num,NULL);

     if(pass[i++]=='\r')break;

    WriteConsole(output,"*",1,&num,NULL);
    }while(i<length);

  pass[i]=0;
  WriteConsole(output,"\n",1,&num,NULL);
  SetConsoleMode(input,modo);
  return pass;
}

int main(void){
  char pass[32]={0};
  printf("in1grese clave: ");
  getpass(pass,sizeof(pass));
  puts(pass);
  return 0;
}

