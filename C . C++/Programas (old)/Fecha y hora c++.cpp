#include <cstdlib>
#include <time.h>
#include <iostream>
 
 using namespace std;
 
int main(int argc, char *argv[])
{
 
 
              tm * fecha_hora; /* tm es un tipo estructurado definido en <time.h> 
                                   //que contiene cada campo de fecha y hora */
	time_t segundos; 
 
    segundos = time(NULL); /* obtiene los segundos desde 1-1-1970 */
    fecha_hora=localtime(&segundos); /* convierte los 'segundos' en la hora local */
 
system("color E");
cout<<"\n\t\t       hora   minutos   segundos";
cout<<"\n\t\t\t"<<fecha_hora->tm_hour<< "   :   "<<fecha_hora->tm_min<<"    :   "<<fecha_hora->tm_sec<<endl;
cout<<"\n\t\t       Dia       Mes     Anyo"; 
cout<<"\n\t\t\t"<<fecha_hora->tm_mday<<"    /   "<<fecha_hora->tm_mon+1<< "   /   "<<fecha_hora->tm_year+1900;
 
    getchar();
    return EXIT_SUCCESS;
}
 
