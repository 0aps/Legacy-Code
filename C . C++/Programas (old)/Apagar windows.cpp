#include <cstdlib>
#include <iostream>
#include <windows.h>
 
using namespace std;
 
BOOL ApagarWindows()
{
   HANDLE Token; 
   TOKEN_PRIVILEGES tkpriv; 
 
   if (!OpenProcessToken(GetCurrentProcess(), 
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &Token)) // obtiene un token para el proceso
      return( FALSE ); 
 
 
 
   LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,    
        &tkpriv.Privileges[0].Luid);               // obtiene el LUID para el privilegio de apagar
 
   tkpriv.PrivilegeCount = 1;                      // pone privilegio a 1    
   tkpriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 
 
 
 
   AdjustTokenPrivileges(Token, FALSE, &tkpriv, 0, 
        (PTOKEN_PRIVILEGES)NULL, 0);              // obtiene el privilegio para apagar el proceso
 
   if (GetLastError() != ERROR_SUCCESS) 
      return FALSE; 
 
 
 
   if (!ExitWindowsEx(EWX_POWEROFF | EWX_FORCE, 0x00020000 | 0x00000003 | 0x80000000 )) 
      return FALSE;                            // apaga el sistema y forza a todas las aplicaciones a cerrar       
 
          //la aplicacion termina con exito
   return TRUE;
}
 
int main()
{
    char tecla;
    cout<<"Desea apagar windows? Si=[S]  No=[N]"<<endl;
    cin >> tecla;
 if (tecla == 'S' | tecla =='s'){
 
   ApagarWindows();
}
else
{   
    system("cls");
    cout<<"adios";
    Sleep(1000);
    exit(0);
    }
    return 0;
    }
 
