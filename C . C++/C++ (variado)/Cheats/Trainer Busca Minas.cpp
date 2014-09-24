#include <iostream>
#include <windows.h>
#include <Tlhelp32.h>

using namespace std;

DWORD Buscar_Proceso();

/*
  Name: trainer buscaminas
  Author: @aps
  Date: 14/12/11 17:51
*/


HANDLE CProc;              
HANDLE hProc;           
PROCESSENTRY32 Proceso;    
DWORD   pid;

int main()
{
    
BYTE    *celda;
DWORD   mapa = 0x01005360;
DWORD   aux;

     if(Buscar_Proceso() != 0)
     {
                       cout << "Se encontro el proceso. " << endl;
                       cout << "El pid es : " << hex << pid << endl;
     }else cout << "No se encontro el proceso." ;  
     
     if( (hProc = OpenProcess(PROCESS_ALL_ACCESS, false, pid) ) == NULL)
                {    
                  cout << "No se pudo abrir el proceso. " << endl;
                }else cout << "Se abrio el proceso." << endl;
     
     
     if( (VirtualProtectEx(hProc ,(void *)mapa, 0x2FF, PAGE_EXECUTE_READWRITE, &aux)) == 0)
         {
           cout << "Error al cambiar los permisos de la zona " << mapa << endl;
         }else cout << "Se modificaron los permisos en " << mapa << endl;
         
         
     for(int x(0); (mapa+x) <= (mapa + 0x2ff ); x++ )
     {
             
             if ( ReadProcessMemory( hProc, (LPVOID)(mapa+x), celda, 1, NULL) == 0) 
             {
                        cout << "Error al leer en " <<  (mapa+x) << endl;
             }else cout << "Se leyo en " << (mapa+x) << " el valor " << celda << endl;          
             
             //8F = 143 en decimal
             if( *celda == 0x8f ) //da igual el sistema numerico en el q ponga el valor. 
             {
                 *celda = 0x41;
                 
                 if(  WriteProcessMemory(hProc, (void *)(mapa+x), celda,
                        1, NULL)  == 0 )
               {
                        cout << "Error al escribir en " << (mapa+x) << endl;
               }else{ cout << "Se modifico " << (mapa+x) << endl;}    
                     
               
             }
     }
                          
    
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}


DWORD Buscar_Proceso()
{
   
    //Con esto creamos una captura de la lista de procesos y la guardamos en CProc
    CProc          =   CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);   
	
    Proceso.dwSize =   sizeof(PROCESSENTRY32);
    
    Process32First(CProc,&Proceso);    //Leemos el primer proceso

    //Mientras haya procesos para leer leemos el siguiente
	while(Process32Next(CProc,&Proceso))   
	{
                                           
	  if(!strcmp(Proceso.szExeFile, "winmine.exe") )
         {
           return pid = Proceso.th32ProcessID;
                      
         }
    }         
    return  pid = 0; 
}



