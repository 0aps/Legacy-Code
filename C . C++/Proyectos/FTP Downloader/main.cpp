#include <iostream>
#include <stdexcept>
#include <wininet.h>

#define printw(a) ( cout << (a) )

using namespace std;

int SubirFTP(char*, char*, char*, int, char*, char*);
int BajarFTP(char*, char*, char*, int, char*, char*);
void comprobarClave( string&);
char getch(void);

struct {
               char servidor[100], usuario[100], password[100], aLocal[100], aRemoto[100];
               int puerto;
               string pass;  
       }FTP;
           

int main(int argc, char *argv[])
{
       
    char opcion[10];
 
 while(1)
 {   
     system("cls");
    cout << "\t\t \\\\Subir Y Bajar por FTP//";
 
    cout << endl << endl << "Servidor: ";
    cin.getline(FTP.servidor, 100);
    
    cout << "Usuario: ";
    cin.getline(FTP.usuario, 100);
    
    cout << "Password: ";
    comprobarClave(FTP.pass);
    
    cout << endl << "Ruta del archivo local: ";
    cin.getline(FTP.aLocal, 100);
   
    cout << "Ruta o nombre de como subera el archivo: ";
    cin.getline(FTP.aRemoto, 100);
   
    cout << "Puerto: ";
    cin >> FTP.puerto;

setbuf(stdin, NULL);

        cout << endl << "Subir o Bajar? ";
        cin.getline(opcion, 10);

            if(strcmp(opcion, "Subir") == 0)
        {   
                if (SubirFTP(FTP.servidor, FTP.usuario, FTP.password, FTP.puerto, FTP.aLocal, FTP.aRemoto) == 0)
             {
                cout << "\n Archivo subido con exito.\n\n";
             }
      else
               {
                cout << "\nError al subir el archivo. \n\n";
               }
}           

    else
   {
           if(BajarFTP(FTP.servidor, FTP.usuario, FTP.password, FTP.puerto, FTP.aLocal, FTP.aRemoto) == 0)   
          {
                  cout << "\n Archivo descargado con exito.\n\n";
          }
               else 
             {
              cout << "\nError al descargar el archivo. \n\n";
             }
   }   

   
            while(1)
         {
             cout << endl << endl << "Desea salir del gestor? [Si] o [No]: ";
             cin.getline(opcion, 10);
        
          if(!strcmp(opcion, "Si"))
                   exit(0);
               else
                   break;
         }
     
}                        
 
     setbuf(stdout, NULL);        
     return EXIT_SUCCESS;
}


int SubirFTP(char *servidor, char *usuario, char *password,
             int puerto, char *aLocal, char *aRemoto)
{ 
    
                             // alocal puntero a una variable de tipo char [es el nombre del archivo a subir que esta en nuestro pc.]
    HINTERNET Peticion;      // aRemoto puntero a una variable de tipo char [ es el nombre de como llegara e archivo al servidor]
    
    Peticion = InternetOpen("Mozilla Firefox",0,NULL,NULL,0);
    if(Peticion == NULL)
    {
         return 1;
    } else 
    {
       HINTERNET Conectar;
       Conectar = InternetConnect(Peticion,servidor,puerto,
                                  usuario,password,INTERNET_SERVICE_FTP,0,0);
    
       if(Conectar == NULL)
       {
          InternetCloseHandle(Conectar);
          return 1;
       } else
       {
          if(FtpPutFile(Conectar,aLocal,aRemoto,FTP_TRANSFER_TYPE_BINARY,0) == FALSE)
          {
             return 1;
          }

          return 0;
          InternetCloseHandle(Peticion);
          InternetCloseHandle(Conectar);

       }

    }

}

int BajarFTP(char *servidor, char *usuario, char *password, 
             int puerto,     char *aRemoto, char *aLocal )
{
    
                             // Alocal puntero a una variable de tipo char [es el nombre del archivo a subir que esta en nuestro pc.]
    HINTERNET Peticion;      // ARemoto puntero a una variable de tipo char [ es el nombre de como llegara e archivo al servidor]
    
    Peticion = InternetOpen("Mozilla Firefox",0,NULL,NULL,0);
    if(Peticion == NULL)
    {
         return 1;
    } else 
    {
       HINTERNET Conectar;
       
       Conectar = InternetConnect(Peticion,servidor,puerto,
                                  usuario,password,INTERNET_SERVICE_FTP,0,0);
    
       if(Conectar == NULL)
       {
          InternetCloseHandle(Conectar);
          return 1;
       } 
       else
       {
          if(FtpGetFile(Conectar,aLocal,aRemoto,FTP_TRANSFER_TYPE_BINARY,0,0,0) == FALSE)
//     FtpGetFileA(HINTERNET,LPCSTR,LPCSTR,BOOL,DWORD,DWORD,DWORD);
          {
             return 1;
          }

          return 0;
       
          InternetCloseHandle(Peticion);
          InternetCloseHandle(Conectar);

        }

    }

}

char getch ()
{
	char c=0;
	DWORD modo, contador;
	HANDLE ih = GetStdHandle( STD_INPUT_HANDLE );
 
	if ( !GetConsoleMode ( ih, &modo ) )
		throw runtime_error( "Desbes estar en la consola para esta aplicación!\n" );
 
	// Desactivamos escritura en terminal
	SetConsoleMode ( ih, modo & ~( ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT ) );
 
	ReadConsoleA ( ih, &c, 1, &contador, NULL );
 
	SetConsoleMode ( ih, modo ); // Devolvemos control normal
 
	return c;
}

 
 
void comprobarClave ( string& clave )
{
		const int ENTER = 13;
 
	const int BACKSPACE = 8;
	int ch;
 
	while ( ( ch=getch()) != ENTER ) // Entramos en el bucle hasta que se pulse ENTER
	{
		if ( ch == BACKSPACE )
		{
			if ( clave.empty() ) // No hay caracter que borrar
				continue;
 
			printw ("\b \b" );
			clave.resize ( clave.length() - 1 ); // borramos el último caracter de la cadena
		}
		else if( ch > 0x19 && ch < 0x7F ) // sólo permitimos caracteres visibles
		{
			printw("*"); // imprimimos un asterisco para que se vea que se pulso una tecla
			clave.push_back(ch); // añadimos el caracter a la cadena.
		}
	}

}
