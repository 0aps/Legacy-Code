#include <windows.h>
#include <Tlhelp32.h>

int main()
{
    HANDLE CProc;   //Para crear la captura de la lista de procesos
    HANDLE pProceso;    //Para guardar el manejador del proceso a cerrar
    PROCESSENTRY32 Proceso;    //Necesario para realizar la captura de procesos
    unsigned int PidArray[500];    //Para almacenar todos los pids de los procesos
    unsigned int cont=0;    //Para contar los procesos
    unsigned int num;    //Para la entrada

	CProc=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);   //Con esto creamos una captura de la lista de procesos y la guardamos en CProc
	Process32First(CProc,&Proceso);    //Leemos el primer proceso

	while(Process32Next(CProc,&Proceso))   //Mientras haya procesos para leer leemos el siguiente
	{
		printf("%i. %s, %i\n", cont, Proceso.szExeFile, Proceso.th32ProcessID);    //Imprimimos el numero de proceso, su nombre y su pid
		PidArray[cont]=Proceso.th32ProcessID;    //Guardamos su pid en el array
		cont++;    //Incrementamos en 1 el contador
	}

	CloseHandle(CProc);    //Cerramos el manejador de la lista de procesos, no la necesitamos

	printf("\nHay un total de: %i procesos abiertos.\n\n", cont);    //Imprimimos el numero de procesos abiertos

	printf("Introduce el proceso a cerrar: ");    //Mensaje introductorio a la entrada
	scanf("%i", &num);    //Recogemos el numero de proceso que el usuario quiere cerrar

	pProceso=OpenProcess(PROCESS_TERMINATE, 0, PidArray[num]);    //Abrimos el proceso con permisos para cerrarlo
	//PROCESS_ALL_ACCESS engloba PROCESS_TERMIANTE  
    if(!pProceso)    //Si no se pudo abrir...
	{
	    printf("\nNo se pudo abrir el proceso con permiso para cerrarlo\n");    //Imprimimos mensaje de error
	    return -1;    //Retornamos -1 para decirle al SO que salio mal
	}
	TerminateProcess(pProceso, 0);   //Cerramos el proceso
	CloseHandle(pProceso);    //Cerramos el manejador del proceso, ya no lo necesitamos

	return 0;    //Retornamos 0 diciendo que salio bien
}
