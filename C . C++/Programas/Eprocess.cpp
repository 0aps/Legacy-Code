#include <iostream>
#include <windows.h>

using namespace std;

unsigned long BuscaEPROCESSPid(unsigned int Pid)
{
	unsigned long eproc,aux,proceso,ret;
	PLIST_ENTRY lista;
	unsigned int idProceso=0;
 
	eproc=(unsigned long)PsGetCurrentProcess();//estamos en "System"
	lista=(LIST_ENTRY*)(eproc+0x88);//tenemos los punteros al siguiente y al anterior
	aux=(unsigned long)lista->Blink;
	proceso=(unsigned long)lista;
	idProceso=*((int *)(proceso+0x84));
 
	while(aux!=proceso && Pid!=idProceso)//recorremos la lista
	{
		proceso-=0x88;
		ret=proceso;
 
		idProceso=*((int *)(proceso+0x84));
		//avanzamos
		lista=lista->Flink;
		proceso=(unsigned long)lista;
	}
 
	if(Pid!=idProceso)
	ret=0;
 
	return ret;
}

int main()
{
    
PLIST_ENTRY plist_active_procs;
unsigned long eproc=0;
 
if ( (eproc = BuscaEPROCESSPid(1234) ) )
{
cout << "La Eprocess esta en la direccion " << eproc << endl;

plist_active_procs = (LIST_ENTRY *)(eproc+0x88);
plist_active_procs->Blink->Flink=plist_active_procs->Flink;
plist_active_procs->Flink->Blink=plist_active_procs->Blink;
}else cout << "No se encontro la eProcess del proceso";


setbuf(stdin, NULL);
cin.get();

return 0;

}
