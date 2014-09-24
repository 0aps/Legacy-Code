#include <iostream>
#include <windows.h>
#include <stdexcept>
#include <string>

using namespace std;

void comprobarClave ( string& );

#define printw(a) ( cout << (a) )
char getchc ();
int getch();

int main ( void )
{
	string laClave = "qwerty"; // La clave correcta
	string clave; // la clave entrada por el usuario

	printw ( "Escribe la clave: ");
	comprobarClave ( clave );

	if ( clave == laClave )
		printw("\nClave correcta!\n");
	else
		printw("\nAcceso no valido!\n");

	printw("Pulsa alguna tecla para finalizar ...");
	getch();

	return 0;
}

int getch ()
{
	char c=0;
	INPUT_RECORD irInputRecord;
    DWORD dwEventsRead;

	DWORD modo, contador;
	HANDLE ih = GetStdHandle( STD_INPUT_HANDLE );

	if ( !GetConsoleMode ( ih, &modo ) )
		throw runtime_error( "Desbes estar en la consola para esta aplicación!\n" );

	// Desactivamos escritura en terminal
	SetConsoleMode ( ih, modo & ~( ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT ) );

    ReadConsoleInputA (ih, &irInputRecord, 1, &dwEventsRead);
    ReadConsoleInputA (ih, &irInputRecord , 1, &dwEventsRead);
	//ReadConsoleA ( ih, &c, 1, &contador, NULL );

	SetConsoleMode ( ih, modo ); // Devolvemos control normal

	return irInputRecord.Event.KeyEvent.wVirtualKeyCode;
}


// Como en windows no tenemos la función getch vamos a creanos una

char getchc ()
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
