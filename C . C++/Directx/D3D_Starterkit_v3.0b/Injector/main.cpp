/***********************************************\
*	Program : Tatnium Injector					*
*	Author : Matthew L (Azorbix)				*
*	Date : December 22nd, 2003					*
*	Credits:	Y0DA, OGC guys, RetarT, Mstr	*
*				LanceVorgin, P47R!CK, VisPrfn	*
\***********************************************/
//you will need VC++ .net or VC++6.0 w/ service packs

#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <winbase.h>
#include "forcelib\forcelib.h"
#define WIN32_LEAN_AND_MEAN

#define APP_EXE "target_application.exe" //change this!!!

bool GetProcessOf(char exename[], PROCESSENTRY32 *process)
{
	HANDLE handle ;
	process->dwSize = sizeof(PROCESSENTRY32);
	handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if(Process32First(handle, process))
	{
		do
		{
			if(strcmpi(process->szExeFile, exename) == 0)
			{
				CloseHandle(handle);
				return true;
			}
		}while(Process32Next(handle, process));
	}

	CloseHandle(handle);
	return false;
}

bool GetThreadOf(DWORD ProcessID, THREADENTRY32 *thread)
{
	HANDLE handle;
	thread->dwSize = sizeof(THREADENTRY32);
	handle = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	if(Thread32First(handle, thread))
	{
		do
		{
			if(thread->th32OwnerProcessID == ProcessID)
			{
				CloseHandle(handle);
				return true;
			}
		}while(Thread32Next(handle, thread));
	}

	CloseHandle(handle);
	return false;
}
 
bool fileExists(const char filename[]) 
{
	WIN32_FIND_DATA finddata;
	HANDLE handle = FindFirstFile(filename,&finddata);
	return (handle!=INVALID_HANDLE_VALUE);
} 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{	
	PROCESSENTRY32 pe32;
	THREADENTRY32 te32;

	HANDLE handle = CreateMutex(NULL, true, "ttn5loader");
	if(GetLastError() != ERROR_SUCCESS)
	{
		MessageBox(0, "Process is already running", "Tatnium Warning", MB_ICONWARNING);
		return 0;
	}

	char dllname[MAX_PATH];
	GetModuleFileName(0, dllname, MAX_PATH);
	dllname[strlen(dllname)-3] = 0;
	strcat(dllname, "dll");

	if(!fileExists(dllname))
	{
		MessageBox(0, "Could not find dll", "Tatnium Error", MB_ICONERROR);
		return 0;
	}

	MessageBox(0, "\tTatnium Injector\n Press \'END\' to exit without injection ", "Tatnium Injector", 0);
	
	while(!GetProcessOf(APP_EXE, &pe32))
	{
		if(GetAsyncKeyState(VK_END))
			return 0;
		Sleep(10);
	}
	
	while(!GetThreadOf(pe32.th32ProcessID, &te32))
	{
		Sleep(2);
	}

	PROCESS_INFORMATION PI;
	PI.dwProcessId = pe32.th32ProcessID;
	PI.dwThreadId = te32.th32ThreadID;
	PI.hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pe32.th32ProcessID);

	if(!ForceLibrary(dllname, &PI))
	{
		TerminateProcess(PI.hProcess, 0);
		MessageBox(0, "Could not inject dll", "Tatnium Error", MB_ICONERROR);
	}

	CloseHandle(PI.hProcess);

	return 0;
}