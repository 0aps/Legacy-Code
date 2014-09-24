#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);
VOID my_unload(PDRIVER_OBJECT  DriverObject);
NTSTATUS Dummy(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);

#endif /* _DLL_H_ */

