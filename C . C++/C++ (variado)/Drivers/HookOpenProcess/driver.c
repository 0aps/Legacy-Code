#include <ddk/ntddk.h>

typedef struct ServiceDescriptorEntry
{
        unsigned int *ServiceTableBase;
        unsigned int *ServiceCounterTableBase;
        unsigned int NumberOfServices;
        unsigned char *ParamTableBase;
} ServiceDescriptorTableEntry_t, *PServiceDescriptorTableEntry_t;
__declspec(dllimport)  ServiceDescriptorTableEntry_t KeServiceDescriptorTable;

#define SYSTEMSERVICE(_function)  KeServiceDescriptorTable.ServiceTableBase[ *(PULONG)((PUCHAR)_function+1)]

#define SYSCALL_INDEX(_Function) *(PULONG)((PUCHAR)_Function+1)

#define HOOK_SYSCALL(_Function, _Hook, _Orig )  \
       _Orig = (PVOID) InterlockedExchange( (PLONG) &MappedSystemCallTable[SYSCALL_INDEX(_Function)], (LONG) _Hook)

#define UNHOOK_SYSCALL(_Function, _Hook, _Orig )  \
       InterlockedExchange( (PLONG) &MappedSystemCallTable[SYSCALL_INDEX(_Function)], (LONG) _Hook)

typedef DWORD (ULONG);
PMDL  g_pmdlSystemCall;
PVOID *MappedSystemCallTable;

NTSTATUS NTAPI ZwOpenProcess (OUT PHANDLE ProcessHandle,IN ACCESS_MASK DesiredAccess,IN POBJECT_ATTRIBUTES ObjectAttributes,IN PCLIENT_ID ClientId OPTIONAL);


typedef NTSTATUS (*TypZwOpenProc)(OUT PHANDLE ProcessHandle,IN ACCESS_MASK DesiredAccess,IN POBJECT_ATTRIBUTES ObjectAttributes,IN PCLIENT_ID ClientId OPTIONAL);
TypZwOpenProc ZwOpenProcessIni;

NTSTATUS NewZwOpenProcess(OUT PHANDLE ProcessHandle,IN ACCESS_MASK DesiredAccess,IN POBJECT_ATTRIBUTES ObjectAttributes,IN PCLIENT_ID ClientId OPTIONAL)
{
   HANDLE PID;

    if(! (PID = ClientId->UniqueProcess) )
{
	DbgPrint("PID: 0x%x",PID);

	//Verificamos el pid
	if (PID == (HANDLE)3024) return STATUS_ACCESS_DENIED; //Retornamos acceso denegado
	else return ZwOpenProcessIni(ProcessHandle, DesiredAccess,ObjectAttributes, ClientId); //Llamamos a la API nativa y retornamos el resultado correcto

}
		return STATUS_INVALID_PARAMETER;
}

VOID OnUnload(IN PDRIVER_OBJECT DriverObject)
{
   DbgPrint("Descargando driver...");

   //Unhookeamos
   UNHOOK_SYSCALL( ZwOpenProcess, ZwOpenProcessIni, NewZwOpenProcess );

   //Eliminamos la MDL
   if(g_pmdlSystemCall)
   {
      MmUnmapLockedPages(MappedSystemCallTable, g_pmdlSystemCall);
      IoFreeMdl(g_pmdlSystemCall);
   }
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING theRegistryPath)
{
   DriverObject->DriverUnload  = OnUnload;

   DbgPrint("Driver cargado");
   ZwOpenProcessIni =(TypZwOpenProc)(SYSTEMSERVICE(ZwOpenProcess));

   //Creamos la MDL para deshabilitar la protección de memoria
   g_pmdlSystemCall = MmCreateMdl(NULL, KeServiceDescriptorTable.ServiceTableBase, KeServiceDescriptorTable.NumberOfServices*4);
   if(!g_pmdlSystemCall)
      return STATUS_UNSUCCESSFUL;

   MmBuildMdlForNonPagedPool(g_pmdlSystemCall);

   g_pmdlSystemCall->MdlFlags = g_pmdlSystemCall->MdlFlags | MDL_MAPPED_TO_SYSTEM_VA;

   MappedSystemCallTable = MmMapLockedPages(g_pmdlSystemCall, KernelMode);


   DbgPrint("Hookeando...");
   HOOK_SYSCALL( ZwOpenProcess, NewZwOpenProcess, ZwOpenProcessIni );

   return STATUS_SUCCESS;
}
