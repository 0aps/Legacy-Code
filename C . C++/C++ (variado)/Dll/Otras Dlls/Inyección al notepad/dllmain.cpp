#include <windows.h>
#define ZOutput 0x00401080

void main()
{
	char* t = "Hola";
	while(1)
	{
		//Para utilizar assembler en c++ ponemos __asm
		asm
		{"
			pushad //guardamos los valores de los registros para no intervenir con el progama
			push t//ponemos t en el stack
			mov eax, ZOutput//Muevo la direccion de la funcion a eax
			call eax//Llamo a eax (llamo a la funcion)
			add esp,4//Limpio el Stack modificando la ultima direccion introducida
			popad//reestablecemos los registros
		"}
		Sleep(1000);
	}	

}

//DllMain - No voy a entrar en detalles. Si el proceso es Attach (Si fue inyectada)
//Crea un Thread (main)
bool APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved){
if(dwReason == DLL_PROCESS_ATTACH){
DisableThreadLibraryCalls(hModule);
CreateThread(NULL, 0, (unsigned long(__stdcall*)(void*))main, NULL, 0, NULL);
}
return true;
}
