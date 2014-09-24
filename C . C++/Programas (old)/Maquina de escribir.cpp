#include <iostream>
#include <windows.h>
using namespace std;
/*int main(){
    char *name[]={"J","a","v","i","e","r"};
    for(int i=0;i<=5;i++){
        cout << name[i];
        Sleep(1200);
        }
    }*/
    /*
int main(int argc, char *argv)
{
    char *name[]={"A", "n", "G", "e", "L"}; 
    int i(0);
do
{   
cout << name[i];
Sleep(1200);
i++;

}

while(i<=5);

return 0;
}*/
#include <iostream>
#include <string>
 
#if defined ( __unix__ ) || defined ( __VMS )
	#include <unistd.h>
	#define Sleep(a) ( sleep ( a / 1000 ) )
#else
	#include <windows.h>
#endif
 
using namespace std;
 
void escribe ( string, string );
void borraLinea ( string );
 
int main ( void )
{
	int i; // para los bucles
 
	// Tenemos una cadena con la que trabajar:
	const string nombre = "JaAViEr";
 
	// Y otra temporal	
	string tmpStr;
 
	// que contendrá una misma cantidad en espacios que nombre
//	for ( int i=0; i< nombre.size(); i++ )
	//	tmpStr = tmpStr + " ";	
 
	cout << "Nos presenatamos, que no nos conocemos }:-)....\n\n\t\t\thola" << endl;
 
	// ahora eso
	escribe ( nombre, tmpStr );
 
	// y lo que tenemos ;-)
	//cout << nombre <<  endl;
 
 cin.get();
	return 0;
}
 
/* 
 * Funciones
 */
 
void escribe ( string linea, string temporal )
{
	for ( int i=0; i < linea.size(); i++ )
	{
        //aritmetica de strings
        // me ubico en el ultimo lugar de la cadena y voy bajando
		temporal += linea [ linea.size() - i - 1] + temporal;
		cout << temporal;
		
        fflush(stdout);
		Sleep (1200) ;		
		borraLinea ( temporal );
	}
}
 
void borraLinea ( string linea )
{
	for ( int i=0; i< linea.size(); i++ )
	{
		cout << "\b " << "\b";
		fflush(stdout);
	}
}


