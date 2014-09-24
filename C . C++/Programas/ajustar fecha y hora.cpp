//For finding the format of date and time with different form,then we can use the following code:

#include<Windows.h>
#include<iostream>
using namespace std;

int main()
{
	SYSTEMTIME tiempo;
	
	do {
    GetSystemTime(&tiempo) ;
    cout << "Fecha: " << tiempo.wDay  << "/" << tiempo.wMonth  << "/"   << tiempo.wYear   << endl
 	     << "Hora: "  << tiempo.wHour << ":" << tiempo.wMinute << " con " << tiempo.wSecond << " segundos. ";
         system("cls");
         //Sleep(15);
    }while(true);
 	//modificas los miembros de la estructura tiempo
 	// ej: tiempo.wDay = 28;
 	// SetSystemTime(&tiempo);
 	//saludos...
 	
 	cin.get();
 	return 0;

}
