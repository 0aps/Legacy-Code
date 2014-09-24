#include <windows.h>
#include <stdio.h>

#define LIB_NAME "Project3.dll"

int main(int argc, char* argv[])
{
	DWORD dwCalculatorProcId;
	HANDLE hndCalculatorHandle;
	HWND hdCalculator;
	LPVOID lpLibNameSpace;
	LPVOID lpLoadLib;
	HANDLE hToken;
    TOKEN_PRIVILEGES tkp;
    
	while ((hdCalculator = FindWindow(NULL, "Untitled - Notepad")) == NULL)
	{
		Sleep(100);
	}
	GetWindowThreadProcessId(hdCalculator, &dwCalculatorProcId);
	if(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tkp.Privileges[0].Luid);
		tkp.PrivilegeCount = 1;
		tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(hToken, 0, &tkp, sizeof(tkp), NULL, NULL);
	}
	if ( (hndCalculatorHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwCalculatorProcId)) == NULL)
	{
		printf("Couldn't open process.\n");
		return -1;
	}
	if ( (lpLoadLib = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA") ) == NULL) 
	{
		printf("GetProcAddress() failed\n");
		return -1;
	}
	if ( (lpLibNameSpace = (LPVOID)VirtualAllocEx(hndCalculatorHandle, NULL, strlen(LIB_NAME), MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE) ) == NULL) {
		printf("VirtualAllocEx failed\n");
		return -1;
	}
	if ( (WriteProcessMemory(hndCalculatorHandle,(LPVOID)lpLibNameSpace, LIB_NAME, strlen(LIB_NAME), 0)) == 0) 
	{
		printf("Write failed\n");
		return -1;
	}
	CreateRemoteThread(hndCalculatorHandle, 0, 0, (LPTHREAD_START_ROUTINE)lpLoadLib, (LPVOID)lpLibNameSpace, 0, 0);
    
    printf("done\n");
		CloseHandle(hndCalculatorHandle);
	return 0;
}

