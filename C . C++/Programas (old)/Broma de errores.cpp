#include<windows.h>


void error(int num)
{
	switch(num)
	{
	case 0:
		system("msg * ERROR");
		break;
	case 1:
		system("msg * No se pudo encontrar el archivo de sistema");
		break;
	case 2:
		system("msg * El disco duro no se puede ´read´");
		break;
	case 3:
		system("msg * No se puede ´write´");
		break;
	case 4:
		system("msg * ERROR FATAL");
		break;
	case 5:
		system("msg * Riesgo de virus, apague la PC");
		break;
	case 6:
		system("msg * No se pudo encontrar el puerto USB");
		break;
	case 7:
		system("msg * No se pudo encontrar el puerto PLT");
		break;
	case 8:
		system("msg * Error de transferencia de datos");
		break;
	case 9:
		system("msg * No se puede encontrar el archivo ´win.ini´");
		break;
	case 10:
		system("msg * Error de Windows");
		break;
	case 11:
		system("msg * Memoria virtual insuficiente");
		break;
	case 12:
		system("msg * Error de memoria RAM");
		break;
	case 13:
		system("msg * No se puede crear el archivo Autoexec.bat");
		break;
	case 14:
		system("msg * Error del sistema");
		break;
	case 15:
		system("msg * Error del Procesador");
		break;
	case 16:
		system("msg * No se pudo terminar el proceso");
		break;
	case 17:
		system("msg * Error del lector de CD");
		break;
	case 18:
		system("msg * Error de lectura");
		break;
	case 19:
		system("msg * Error de escritura");
		break;


	}
}

int main()
{
	FreeConsole();
	for(;;)
	{
		Sleep((rand()%100)*3000);
		error(rand()%20);
	}

}
