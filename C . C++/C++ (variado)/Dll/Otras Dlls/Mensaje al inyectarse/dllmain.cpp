#include <windows.h>
#define ZOutput 0x00401080

char* t = "Hola";

int main()
{
	
	MessageBox(0, t, "loader", MB_OK);

}

//DllMain - No voy a entrar en detalles. Si el proceso es Attach (Si fue inyectada)
//Crea un Thread (main)
bool APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved){
if(dwReason == DLL_PROCESS_ATTACH){
MessageBox(0, t, "loader", MB_OK);
CreateThread(NULL, 0, (unsigned long(__stdcall*)(void*))main, NULL, 0, NULL);
}
return true;
}
