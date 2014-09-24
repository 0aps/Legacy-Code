/*

WARNING! This exlample has not been tested and MAY crash your system!!!

*/

#include <ddk/ntddk.h>
#include "dll.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath)
{
    NTSTATUS status;
    PDEVICE_OBJECT pDeviceObject;
    UNICODE_STRING usDriverName, usDosDeviceName;

    //Initializing device name strings
    RtlInitUnicodeString(&usDriverName, L"\\Device\\Example");
    RtlInitUnicodeString(&usDosDeviceName, L"\\DosDevices\\Example"); 

    //Device object creation
    if(STATUS_SUCCESS != (status = IoCreateDevice(pDriverObject, 0, &usDriverName, FILE_DEVICE_UNKNOWN,
        FILE_DEVICE_SECURE_OPEN, FALSE, &pDeviceObject)))
    {
        return status;
    }

    //Setting Dummy Service
    int i;
    for(i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; i++)
         pDriverObject->MajorFunction[i] = Dummy;

    //Setting unload function
    pDriverObject->DriverUnload =  my_unload;
    
    if(STATUS_SUCCESS != (status = IoCreateSymbolicLink(&usDosDeviceName, &usDriverName)))
    {
        return status;
    }    

    return STATUS_SUCCESS;
}

VOID my_unload(PDRIVER_OBJECT  DriverObject)
{    
    UNICODE_STRING usDosDeviceName;
    
    RtlInitUnicodeString(&usDosDeviceName, L"\\DosDevices\\Example");
    IoDeleteSymbolicLink(&usDosDeviceName);

    IoDeleteDevice(DriverObject->DeviceObject);
}

NTSTATUS Dummy(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp)
{
    return STATUS_NOT_IMPLEMENTED;
}

