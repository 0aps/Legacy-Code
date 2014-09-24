#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX 255
#define max 20

void correComando ( char comando [max], char linea [MAX] )
{
	if ( ! strcmp ( comando, "echo" ) )
	{
		puts( linea );
	} 
	else if ( ! strcmp ( comando, "clear" ) )
	{
		#if defined ( __unix__ ) || defined ( __VMS )
			system ( "clear" );
		#else
			system ( "cls" );
		#endif
	}
	else if ( ! strcmp ( comando, "ls" ) )
	{
		struct dirent * dirent = NULL;
		DIR *dir = NULL;
		if ( ! strcmp ( linea, "" ) )
			strcpy ( linea, "." );
		dir = opendir( linea );
		if ( dir == NULL )
		{
			puts ("falló opendir()");
			return;
		}
		while ( ( dirent = readdir ( dir ) ) != NULL )
			printf ( "%s\n", dirent->d_name );
		closedir(dir);
	}
	else if ( ! strcmp ( comando, "mkdir" ) )
	{
		char comando [100];
		sprintf( comando, "md4 %s", linea );
		system ( comando );
	}
	else if ( ! strcmp ( comando, "rmdir" ) )
	{
	}
	else if ( ! strcmp ( comando, "cd" ) )
	{
	}
	else if ( ! strcmp ( comando, "exit" ) )
	{
		exit (0);
	}
	else
		printf ("Comando no encontrado ...\n");
}


int main (void)
{
        char comando[max], linea[MAX], tmp[MAX];
        int i, d;

	puts ( "\t\t********************\n\t*CPH shell comander*\n\t********************" );
	puts ( "\n\"exit\" sin comillas para salir ...\n\n" );
        while ( 1 )
        {
                printf ( "Sh3ll  > " );
                fgets ( linea, MAX,stdin );
                if ( linea [ strlen ( linea ) -1 ] == '\n' )
                        linea [ strlen ( linea ) -1 ] = '\0';
                sscanf ( linea, "%s", comando );
                d=0;
                strcpy ( tmp, "" );
                for ( i = strlen ( comando ) + 1; i < strlen ( linea ) ; i++ )
                {
                        tmp [d] = linea [i];
                        d++;
                        if ( i == strlen ( linea ) - 1 )
                                tmp [d] = '\0';
                }
                strcpy ( linea, tmp );
                correComando ( comando, linea );
}
        // aqui nunca se va a llegar.
        return 0;
}
