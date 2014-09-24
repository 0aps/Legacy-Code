#include <windows.h>
#include <winioctl.h>
#include <stdio.h>

#define IOCTL_EJEMPLO_DIRECT_IN_IO    \
  CTL_CODE(FILE_DEVICE_UNKNOWN,0x800,METHOD_IN_DIRECT,FILE_ANY_ACCESS)

#define IOCTL_EJEMPLO_DIRECT_OUT_IO   \
  CTL_CODE(FILE_DEVICE_UNKNOWN,0x801,METHOD_OUT_DIRECT,FILE_ANY_ACCESS)

#define IOCTL_EJEMPLO_BUFFERED_IO     \
  CTL_CODE(FILE_DEVICE_UNKNOWN,0x802,METHOD_BUFFERED,FILE_ANY_ACCESS)

#define IOCTL_EJEMPLO_NEITHER_IO      \
  CTL_CODE(FILE_DEVICE_UNKNOWN,0x803,METHOD_NEITHER,FILE_ANY_ACCESS)

void communication(){

  HANDLE hFile;
  DWORD dwReturn;
  CHAR buffer[512],*msg="Este es un mensaje para el kernel!";;

  hFile=CreateFile("\\\\.\\Ejemplo",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);

  if(hFile){

    printf("Escribiendo en el driver: \"%s\"\n",msg);
    WriteFile(hFile,msg,strlen(msg)+1,&dwReturn,NULL);

    printf("Leyendo del driver!\n");
    ReadFile(hFile,buffer,sizeof(buffer),&dwReturn,NULL);
    printf("Mensaje Leido: \"%s\"\n",msg);

    strcpy(buffer,"Mensaje IOCTL de Prueba!");
    DeviceIoControl(hFile,IOCTL_EJEMPLO_DIRECT_IN_IO,
      "** Hello from User Mode Direct IN I/O",
      sizeof("** Hello from User Mode Direct IN I/O"),
      buffer,strlen(buffer)+1,&dwReturn,NULL);
    printf("Respuesta IOCTL_EJEMPLO_DIRECT_IN_IO: %s\n",buffer);

    ZeroMemory(buffer, sizeof(buffer));
    DeviceIoControl(hFile,IOCTL_EJEMPLO_DIRECT_OUT_IO,
      "** Hello from User Mode Direct OUT I/O",
      sizeof("** Hello from User Mode Direct OUT I/O"),
      buffer,sizeof(buffer),&dwReturn,NULL);
    printf("Respuesta IOCTL_EJEMPLO_DIRECT_OUT_IO: %s\n",buffer);

    ZeroMemory(buffer, sizeof(buffer));
    DeviceIoControl(hFile,IOCTL_EJEMPLO_BUFFERED_IO,
      "** Hello from User Mode Buffered I/O",
      sizeof("** Hello from User Mode Buffered I/O"),
      buffer,sizeof(buffer),&dwReturn,NULL);
    printf("Respuesta IOCTL_EJEMPLO_BUFFERED_IO: %s\n",buffer);

    ZeroMemory(buffer, sizeof(buffer));
    DeviceIoControl(hFile,IOCTL_EJEMPLO_NEITHER_IO,
      "** Hello from User Mode Neither I/O",
      sizeof("** Hello from User Mode Neither I/O"),
      buffer,sizeof(buffer),&dwReturn,NULL);
    printf("Respuesta IOCTL_EJEMPLO_NEITHER_IO: %s\n",buffer);

    CloseHandle(hFile);
  }
}

char *getfilepath(char *path){
  int i,len=strlen(path);

  for(i=len;i>0;i--)
    if(path[i]=='\\'){
      path[i+1]=0;
      break;
    }
  return path;
}

int main(){

  HANDLE hSCManager;
  HANDLE hService;
  SERVICE_STATUS ss;
  CHAR path[MAX_PATH];
  hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
  puts("Loading Driver");

  if(hSCManager){

    GetModuleFileName(0,path,MAX_PATH);
    getfilepath(path);
    strcat(path,"IOCTL.sys");

    printf("Creating Service %s\n",path);

      hService=CreateService(hSCManager,"Ejemplo","Driver de Ejemplo",
      SERVICE_START|DELETE|SERVICE_STOP,SERVICE_KERNEL_DRIVER,SERVICE_DEMAND_START,
      SERVICE_ERROR_IGNORE,path,NULL,NULL,NULL,NULL,NULL);

    if(!hService)
      hService=OpenService(hSCManager,"Ejemplo",SERVICE_START|DELETE|SERVICE_STOP);

    if(hService){
      puts("Service Started");

      if(StartService(hService, 0, NULL)){

        puts("Press Enter to Start Comunication");
        getchar();
        communication();

        puts("Press Enter to Finish");
        getchar();

        ControlService(hService,SERVICE_CONTROL_STOP,&ss);
        puts("Service Stoped");
      }else
        puts("Can't Start Service");
      DeleteService(hService);
      puts("Service Deleted");
      CloseServiceHandle(hService);
    }else
      puts("Can't Create Service");
    CloseServiceHandle(hSCManager);
  }else
    puts("Can't Open SC Manager");

  puts("Press Enter to Exit...");
  getchar();
  return 0;
}
