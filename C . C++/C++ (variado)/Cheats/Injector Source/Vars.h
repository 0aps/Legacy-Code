//Simple struct to organise all the Variables
struct Vars
{
	HANDLE RemoteThread;
	HANDLE Snapshot;

	LPTHREAD_START_ROUTINE ThreadRet;
	HMODULE KernelModule;
	LPVOID AllocatedMemory;
	HMODULE hInjector;
	PROCESSENTRY32 ProcessEntry32;

	BOOL DLL_Exists;
	BOOL DLL_Injected;

	int Stats;

	struct stat FileInfo;

	char Process_Name	[MAX_PATH];
	char DLL_Name		[MAX_PATH];
	char DLL_Path		[MAX_PATH];
	char Injector_Dir	[MAX_PATH];
};