#include <ddk/ntddk.h>

#define TRANSFER_METHOD_NEITHER 0
#define TRANSFER_METHOD_BUFFERED 1
#define TRANSFER_METHOD_X_DIRECT 2

//#define TRANSFER_METHOD TRANSFER_METHOD_NEITHER
#define TRANSFER_METHOD TRANSFER_METHOD_BUFFERED
//#define TRANSFER_METHOD TRANSFER_METHOD_X_DIRECT

//buffer data (only for test!)

#define BUFFERSIZE 2048
PBYTE pDriverBuffer=NULL;
DWORD nRefCount=0;
PWCHAR ucDriverName=L"\\Device\\Ejemplo";
PWCHAR ucDosDeviceName=L"\\DosDevices\\Ejemplo";






/**********************************************************************
 *  Example_Create
 *    Llamado cuando una instancia del driver es creada (CreateFile)
 **********************************************************************/
NTSTATUS DDKAPI Example_Create(PDEVICE_OBJECT DeviceObject, PIRP Irp){

  DbgPrint("Example_Create Called \r\n");

  //creamos un buffer que usaremos para ralizar nuestra tarea
  if(!pDriverBuffer){
    pDriverBuffer=(PBYTE)ExAllocatePoolWithTag(NonPagedPool,BUFFERSIZE,0);

    if(pDriverBuffer)
    DbgPrint("Memory Allocated OK \r\n");
  }

  //incrementamos el número de clientes en 1
  ++nRefCount;
  return STATUS_SUCCESS;
}

/**********************************************************************
 *  Example_Close
 *    Llamado cuando una instancia del driver es cerrada (CloseHandle)
 **********************************************************************/
NTSTATUS DDKAPI Example_Close(PDEVICE_OBJECT DeviceObject, PIRP Irp){

  DbgPrint("Example_Close Called \r\n");

  //decrementamos el número de clientes en 1 y si ya no hay liberamos memoria
  if( !--nRefCount && pDriverBuffer ){

    ExFreePoolWithTag(pDriverBuffer,0);
    DbgPrint("Memory Released OK \r\n");
    pDriverBuffer=NULL;

  }
  return STATUS_SUCCESS;
}

/**********************************************************************
 *  Example_Read
 *    Llamado cuando una instancia intenta leer de nuestro driver (ReadFile/ReadFileEx)

 **********************************************************************/
NTSTATUS DDKAPI Example_Read(PDEVICE_OBJECT DeviceObject,PIRP Irp){

  PIO_STACK_LOCATION  pIoStackIrp     =NULL;
  NTSTATUS            NtStatus        =STATUS_UNSUCCESSFUL;
  PCHAR               pReadDataBuffer;
  DWORD               dwDataReaded    =0;

  DbgPrint("Example_Read Called \r\n");

  //obtenemos la dirección de la pila del IRP
  pIoStackIrp=IoGetCurrentIrpStackLocation(Irp);

  if(pDriverBuffer&&pIoStackIrp){

#if (TRANSFER_METHOD == TRANSFER_METHOD_NEITHER)

    //hay que tener cuidado con este método ya que el acceso es directo!
    pReadDataBuffer=(PCHAR)Irp->UserBuffer;

    if(pReadDataBuffer){

      if(pIoStackIrp->Parameters.Read.Length < BUFFERSIZE)
        dwDataReaded=pIoStackIrp->Parameters.Read.Length;
      else
       dwDataReaded=BUFFERSIZE;

      RtlCopyMemory(pReadDataBuffer,pDriverBuffer,dwDataReaded);

      DbgPrint("METHOD_NEITHER -> Readed %d Bytes \r\n",dwDataReaded);
      NtStatus = STATUS_SUCCESS;
    }

#else
  #if (TRANSFER_METHOD == TRANSFER_METHOD_BUFFERED)

    pReadDataBuffer=(PCHAR)Irp->AssociatedIrp.SystemBuffer;
    if(pReadDataBuffer){

      if(pIoStackIrp->Parameters.Read.Length < BUFFERSIZE)
        dwDataReaded=pIoStackIrp->Parameters.Read.Length;

      else
        dwDataReaded=BUFFERSIZE;

      RtlCopyMemory(pReadDataBuffer,pDriverBuffer,dwDataReaded);

      DbgPrint("METHOD_BUFFERED -> Readed %d Bytes \r\n",dwDataReaded);
      NtStatus=STATUS_SUCCESS;
    }

  #else
    #if (TRANSFER_METHOD == TRANSFER_METHOD_X_DIRECT)

    if(Irp->MdlAddress){

      pReadDataBuffer=MmGetSystemAddressForMdlSafe(Irp->MdlAddress, NormalPagePriority);

      if(pReadDataBuffer){

        if(pIoStackIrp->Parameters.Read.Length < BUFFERSIZE)
          dwDataReaded=pIoStackIrp->Parameters.Read.Length;

        else
          dwDataReaded=BUFFERSIZE;

        RtlCopyMemory(pReadDataBuffer,pDriverBuffer,dwDataReaded);
        DbgPrint("METHOD_X_DIRECT -> Readed %d Bytes \r\n",dwDataReaded);

        NtStatus=STATUS_SUCCESS;
      }
    }

    #endif
  #endif
#endif
  }

  //informamos al SO como terminó nuestra ejecución
  Irp->IoStatus.Status=NtStatus;

  //informamos la cantidad de bytes correctamente copiados
  Irp->IoStatus.Information=dwDataReaded;

  //con esto le deciemos al SO que no le dé más prioridad al thread que nos llama,
  //y que se reactive cuando él lo crea necesario
  IoCompleteRequest(Irp,IO_NO_INCREMENT);
  return NtStatus;
}

/**********************************************************************
 *  Example_Write
 *    Llamado cuando una instancia intenta escribir en nuestro driver (WriteFile/WriteFileEx)
 **********************************************************************/

NTSTATUS DDKAPI Example_Write(PDEVICE_OBJECT DeviceObject,PIRP Irp){

  PIO_STACK_LOCATION pIoStackIrp=NULL;
  NTSTATUS NtStatus=STATUS_UNSUCCESSFUL;
  PCHAR pWriteDataBuffer;DWORD dwDataWritten=0;

  DbgPrint("Example_Write Called \r\n");

  //obtenemos la dirección de la pila del IRP
  pIoStackIrp = IoGetCurrentIrpStackLocation(Irp);
  if(pDriverBuffer&&pIoStackIrp){

#if (TRANSFER_METHOD == TRANSFER_METHOD_NEITHER)

    //hay que tener cuidado con este método ya que el acceso es directo!
    pWriteDataBuffer=(PCHAR)Irp->UserBuffer;
    if(pWriteDataBuffer){
      if(pIoStackIrp->Parameters.Write.Length < BUFFERSIZE)
        dwDataWritten=pIoStackIrp->Parameters.Write.Length;
      else
        dwDataWritten=BUFFERSIZE;
      RtlCopyMemory(pDriverBuffer,pWriteDataBuffer,dwDataWritten);
      DbgPrint("METHOD_NEITHER -> Writenn %d Bytes \r\n",dwDataWritten);
      NtStatus=STATUS_SUCCESS;
    }

#else
  #if (TRANSFER_METHOD == TRANSFER_METHOD_BUFFERED)

    pWriteDataBuffer=(PCHAR)Irp->AssociatedIrp.SystemBuffer;
    if(pWriteDataBuffer){
      if(pIoStackIrp->Parameters.Write.Length < BUFFERSIZE)
        dwDataWritten=pIoStackIrp->Parameters.Write.Length;
      else
        dwDataWritten=BUFFERSIZE;
      RtlCopyMemory(pDriverBuffer,pWriteDataBuffer,dwDataWritten);
      DbgPrint("METHOD_BUFFERED -> Writenn %d Bytes \r\n",dwDataWritten);
      NtStatus=STATUS_SUCCESS;
    }

  #else
    #if (TRANSFER_METHOD == TRANSFER_METHOD_X_DIRECT)

    if(Irp->MdlAddress){
      pWriteDataBuffer=MmGetSystemAddressForMdlSafe(Irp->MdlAddress,NormalPagePriority);
      if(pWriteDataBuffer){
        if(pIoStackIrp->Parameters.Write.Length < BUFFERSIZE)
          dwDataWritten=pIoStackIrp->Parameters.Write.Length;
        else
          dwDataWritten=BUFFERSIZE;
        RtlCopyMemory(pDriverBuffer,pWriteDataBuffer,dwDataWritten);
        DbgPrint("METHOD_X_DIRECT -> Writenn %d Bytes \r\n",dwDataWritten);
        NtStatus=STATUS_SUCCESS;
      }
    }

    #endif
  #endif
#endif

  }

  //informamos al SO como terminó nuestra ejecución
  Irp->IoStatus.Status=NtStatus;
  //informamos la cantidad de bytes correctamente copiados
  Irp->IoStatus.Information=dwDataWritten;
  //con esto le deciemos al SO que no le dé más prioridad al thread que nos llama,
  //y que se reactive cuando él lo crea necesario
  IoCompleteRequest(Irp,IO_NO_INCREMENT);
  return NtStatus;
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
 *  Example_UnSupportedFunction
 *    Esta función es llamada cuando la operación solicitada no está soportada.
 **********************************************************************/
NTSTATUS DDKAPI Example_UnSupportedFunction(PDEVICE_OBJECT DeviceObject, PIRP Irp){
  DbgPrint("Example_UnSupportedFunction Called \r\n");
  return STATUS_NOT_SUPPORTED;
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
 *  DriverEntry
 *    Punto de inicio de nuestro driver.
 **********************************************************************/
__declspec (dllexport) NTSTATUS DDKAPI DriverEntry(IN PDRIVER_OBJECT pDriverObject,IN PUNICODE_STRING RegistryPath){

  NTSTATUS       NtStatus            =   STATUS_SUCCESS;
  UINT           uiIndex             =   0;
  PDEVICE_OBJECT pDeviceObject       =   NULL;

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

   // pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL]=Example_IoControl;
    pDriverObject->MajorFunction[IRP_MJ_CREATE]        =Example_Create;
    pDriverObject->MajorFunction[IRP_MJ_CLOSE]         =Example_Close;
    pDriverObject->MajorFunction[IRP_MJ_READ]          =Example_Read;
    pDriverObject->MajorFunction[IRP_MJ_WRITE]         =Example_Write;

    //creamos el nombre simbólico
    NtStatus=IoCreateSymbolicLink(&usDosDeviceName,&usDriverName);

    if(NtStatus==STATUS_SUCCESS){

      //seteamos flags
#if (TRANSFER_METHOD == TRANSFER_METHOD_NEITHER)
      pDeviceObject->Flags|=0;

#else
  #if (TRANSFER_METHOD == TRANSFER_METHOD_BUFFERED)
      pDeviceObject->Flags|=DO_BUFFERED_IO;

#else
 #if (TRANSFER_METHOD == TRANSFER_METHOD_X_DIRECT)
      pDeviceObject->Flags|=DO_DIRECT_IO;

    #endif
  #endif
#endif

    }else{
      //algo falló, eliminamos el dispositivo
      DbgPrint("Couldn't Create SymbolicLink [%X]\r\n",NtStatus);
      IoDeleteDevice(pDeviceObject);
         }

  }
  else//algo falló, retornamos el código de error
    DbgPrint("Couldn't Create Device [%X]\r\n",NtStatus);

  return NtStatus;

}
