#include <windows.h>
#include <stdio.h>
//Author:
//P4|3L0 : The person who doesn't must be called
//Thanks xassiz for being the victim of the Bomber
//27, Sept, 2009 13:50
 
 
void BufferRand0m( char* Res, int longitud )
{
    char* caracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890,.-??`+";
 
    for( int b = 0; b < longitud; b++ )
        Res[ b ] = caracteres[ rand( ) % strlen( caracteres ) ];
 
    Res[ longitud ] = 0;
};
 
void funcionkey( char* cadena )
{
    int longitud = strlen( cadena );
    bool ShiftDown = false;
 
    for( int b = 0; b < longitud; b++ )
    {
        short tecla = VkKeyScan( cadena[ b ] );
        //VkKeyScan, traduce el caracter ingresado como parametro a un tecla virtual.
        //una tecla virtual es por ej. VK_return.
        
        if( ( tecla >> 8 ) & 1 )
        {
            keybd_event( VK_LSHIFT, 0, 0, 0 );
            ShiftDown = true;
        }
 
        keybd_event( (unsigned char)tecla, 0, 0, 0 );
 
        if( ShiftDown )
        {
            keybd_event( VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0 );
            ShiftDown = false;
        }
    }
};
 
void funcionspam( void )
{
    char Res[ 512 ], Met[ 32 ], Lon[ 8 ], Tiempo[ 8 ];
     unsigned long EmpiezaContar;
    bool Comp32 = false;
 
    int b, sended = 0;
 
    while( true )
    {
        printf( "Para ayuda /? - For Help /?\n" );
        printf( "shell> " );
 
        scanf( "%s", Met );
 
        if( !strcmp( Met, "/?" ) )
        {
            system("Cls");
            printf( "      AYUDA  \n");
            printf( "1 - Aleatorio - Randomiz3\n" );
            printf( "2 - Tu mensaje - Your text\n" );
            printf( "3 - Emoticon0s\n" );
            printf( "4 - Ayuda - Help\n" );
            printf( "5 - Salir - Exit\n" );
 
            Comp32 = true;
        }
 
        switch( atoi( Met ) )
        {
        case 1:
            printf( "Longitud de la cadena aleatoria - Length of each random string\n" );
            printf( "shell> " );
 
            scanf( "%s", Lon );
            printf( "Tiempo de Spam - Time for Spam\n" );
            printf( "shell> " );
            scanf( "%s", Tiempo );
            printf( "Espera 3 segund0s - Wait 3 sec0nds\n" );
            Sleep( 3000 );
 
            EmpiezaContar = GetTickCount( );
 
            while( ( ( GetTickCount( ) - EmpiezaContar ) / 1000 ) < (unsigned)atoi( Tiempo ) )
            {
                BufferRand0m( Res, atoi( Lon ) );
 
                funcionkey( Res );
                keybd_event( VK_RETURN, 0, 0, 0 );
 
                sended++;
            }
 
            printf( "Mensajes mandados %d Sended messages\n", sended );
 
            break;
        case 2:
            printf( "Introduce tu texto (- : espacio) - Enter your text (- : Space)\n" );
            printf( "shell> " );
 
            scanf( "%s", Res );
 
           printf( "Tiempo de Spam - Time for Spam\n" );
 
            printf( "shell> " );
 
            scanf( "%s", Tiempo );
 
            for( b = 0; b < (signed)strlen( Res ); b++ )
            {
                if( Res[ b ] == '-' )
                    Res[ b ] = 0x20; // espacio
            }
 
            printf( "Espera 3 segund0s - Wait 3 sec0nds\n" );
            Sleep( 3000 );
 
            EmpiezaContar = GetTickCount( );
 
            while( ( ( GetTickCount( ) - EmpiezaContar ) / 1000 ) < (unsigned)atoi( Tiempo ) )
            {
                funcionkey( Res );
                keybd_event( VK_RETURN, 0, 0, 0 ); //vk_return = enter
 
                sended++;
            }
 
            printf( "Mensajes mandados %d Sended messages\n", sended );
 
            break;
        case 3:
            printf( "\nEsta es la parte del floodeo de em0tic0n0s. Pon el tiempo de spam y disfruta..\n" );
            printf( "\nThis is the part of flood of em0tic0ns. Put your time spam and enjoy ..\n" );
            printf( "shell> " );
 
            scanf( "%s", Tiempo );
 
            ZeroMemory( Res, sizeof( Res ) );
 
            for( b = 0; b < 32; b++ )
                strcat( Res, ":'(:D:):(:S(a)(6)(co)" );
 
            printf( "Espera 3 segund0s - Wait 3 sec0nds\n" );
            Sleep( 3000 );
 
            EmpiezaContar = GetTickCount( );
           //gettickcount = retorna el tiempo desde que el sistema se inicio.
            while( ( ( GetTickCount( ) - EmpiezaContar ) / 1000 ) < (unsigned)atoi( Tiempo ) )
            {
                funcionkey( Res );
                keybd_event( VK_RETURN ,0, 0, 0 );
 
                sended++;
            }
 
            printf( "Mensajes mandados %d Sended messages\n", sended );
 
            break;
 
        case 4:
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_RED | FOREGROUND_INTENSITY );
        printf("\n Este programa tiene un uso muy simple, solo tienes que poner una opcion de \n las 3 posibles.  Pones la opcion y decides el tiempo que se va a estar mandando\n y cuando te ponga que esperes 3 segundos te diriges a la conversacion y\n aprietas en el cuadro de conversacion\n " );
        printf("\n This program is very simple to use, just to put a choice of the 3 possible. \n You must put the choice and decide how long it's going to be sending, and when\n the programs puts you to wait 3 seconds you're going to click into \n the conversation and the conversation box \n");
        Sleep(3000);
 
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN | FOREGROUND_INTENSITY );
 
        break;
        case 5:
            printf( "Adi0s - By3\n" );
            Sleep( 500 );
 
            ExitProcess( 0 );
            break;
        default:
            if( !Comp32 )
                printf( "Pero que mierdas pones? - What the fuck, you writes?\n" );
 
            break;
        }
 
        printf( "\n\n" );
        EmpiezaContar = 0;
        sended = 0;
    }
};
 
int main( )
{
    SetConsoleTitle( "Cruel Spamming by The person who doesn't must be called" );
 
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    printf( "\tCruel Spamming by The person who doesn't must be called\n" );
    funcionspam( );
 
    return 0;
};


