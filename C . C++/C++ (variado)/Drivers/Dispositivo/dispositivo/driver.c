#include <ddk/ntddk.h>

PWCHAR ucDriverName    =    L"\\Device\\Ejemplo";
PWCHAR ucDosDeviceName =    L"\\DosDevices\\Ejemplo";

/**********************************************************************
 *  Example_Create
 *    Llamado cuando una instancia del driver es creada (CreateFile)
 **********************************************************************/
NTSTATUS DDKAPI Example_Create(PDEVICE_OBJECT DeviceObject, PIRP Irp){
  DbgPrint("Example_Create Called \r\n");
  return STATUS_SUCCESS;
}

/**********************************************************************
 *  Example_Close
 *    Llamado cuando una instancia del driver es cerrada (CloseHandle)
 **********************************************************************/
NTSTATUS DDKAPI Example_Close(PDEVICE_OBJECT DeviceObject, PIRP Irp){
  DbgPrint("Example_Close Called \r\n");
  return STATUS_SUCCESS;
}

/**********************************************************************
 *  Example_IoControl
 *    Llamado cuando una instancia envía un mensaje IOCTL (DeviceIoControl)
 **********************************************************************/
NTSTATUS DDKAPI Example_IoControl(PDEVICE_OBJECT DeviceObject, PIRP Irp){
  DbgPrint("Example_IoControl Called \r\n");
  return STATUS_SUCCESS;
}

/**********************************************************************
 *  Example_Read
 *    Llamado cuando una instancia intenta leer de nuestro driver (ReadFile/ReadFileEx)
 **********************************************************************/
NTSTATUS DDKAPI Example_Read(PDEVICE_OBJECT DeviceObject,PIRP Irp){
  DbgPrint("Example_Read Called \r\n");
  return STATUS_SUCCESS;
}

/**********************************************************************
 *  Example_Write
 *    Llamado cuando una instancia intenta escribir en nuestro driver (WriteFile/WriteFileEx)
 **********************************************************************/
NTSTATUS DDKAPI Example_Write(PDEVICE_OBJECT DeviceObject,PIRP Irp){
  DbgPrint("Example_Write Called \r\n");
  return STATUS_SUCCESS;
}

/**********************************************************************
 *  Example_UnSupportedFunction
 *    Esta función es llamada cuando la operación solicitada no está soportada.
 **********************************************************************/
NTSTATUS DDKAPI Example_UnSupportedFunction(PDEVICE_OBJECT DeviceObject, PIRP Irp){
  DbgPrint("Example_UnSupportedFunction Called \r\n");
  return STATUS_NOT_SUPPORTED;
}

/**********************************************************************
 *  DriverUnload
 *    Función de descarga de nuestro driver.
 **********************************************************************/
VOID DDKAPI DriverUnload(IN PDRIVER_OBJECT DriverObject){
  NTSTATUS NtStatus=STATUS_SUCCESS;
  UNICODE_STRING usDosDeviceName;
  DbgPrint("Hello Kernel! -> DriverUnload() !\n");

  //eliminamos nombre simbólico
  RtlInitUnicodeString(&usDosDeviceName,ucDosDeviceName);
  NtStatus=IoDeleteSymbolicLink(&usDosDeviceName);

  if(NtStatus!=STATUS_SUCCESS)
    DbgPrint("Couldn't Delete SymbolicLink [%X]\r\n",NtStatus);

  //eliminamos dispositivo
  IoDeleteDevice(DriverObject->DeviceObject);
  return;
}

/**********************************************************************
 *  DriverEntry
 *    Punto de inicio de nuestro driver.
 **********************************************************************/

__declspec (dllexport) NTSTATUS DDKAPI DriverEntry(IN PDRIVER_OBJECT pDriverObject,IN PUNICODE_STRING RegistryPath){

  NTSTATUS NtStatus=STATUS_SUCCESS;
  UINT uiIndex=0;
  PDEVICE_OBJECT pDeviceObject=NULL;
  UNICODE_STRING usDriverName,usDosDeviceName;

  DbgPrint("Hello Kernel! -> DriverEntry() !\n");

  //rutina de descarga!
  pDriverObject->DriverUnload=DriverUnload;

  //Iniciamos nombres
  RtlInitUnicodeString(&usDriverName,ucDriverName);
  RtlInitUnicodeString(&usDosDeviceName,ucDosDeviceName);

  //creamos el dispositivo
  NtStatus=IoCreateDevice(pDriverObject,0,&usDriverName,FILE_DEVICE_UNKNOWN,FILE_DEVICE_SECURE_OPEN,FALSE,&pDeviceObject);

  if(NtStatus==STATUS_SUCCESS){

    //seteamos lista de funciones
    for(uiIndex=0;uiIndex<IRP_MJ_MAXIMUM_FUNCTION;uiIndex++)
       pDriverObject->MajorFunction[uiIndex]=Example_UnSupportedFunction;

    pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL]=Example_IoControl;
    pDriverObject->MajorFunction[IRP_MJ_CREATE]=Example_Create;
    pDriverObject->MajorFunction[IRP_MJ_CLOSE]=Example_Close;
    pDriverObject->MajorFunction[IRP_MJ_READ]=Example_Read;
    pDriverObject->MajorFunction[IRP_MJ_WRITE]=Example_Write;

    //creamos el nombre simbólico
    NtStatus=IoCreateSymbolicLink(&usDosDeviceName,&usDriverName);

    if(NtStatus==STATUS_SUCCESS){
      //seteamos flags
      pDeviceObject->Flags|=0;
      pDeviceObject->Flags&=(~DO_DEVICE_INITIALIZING);
    }else{
      //algo falló, eliminamos el dispositivo
      DbgPrint("Couldn't Create SymbolicLink [%X]\r\n",NtStatus);
      IoDeleteDevice(pDeviceObject);
    }
  }else//algo falló, retornamos el código de error
    DbgPrint("Couldn't Create Device [%X]\r\n",NtStatus);
  return NtStatus;
}
