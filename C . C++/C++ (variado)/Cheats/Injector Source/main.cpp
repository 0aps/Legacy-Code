//Project Includes
#include "Includes.h"
#include <sys/stat.h>


///////////////////////////////////////////////
//  Author:  ReUnioN						 //
//  Project: Injector V1.0					 //
//  Date:    20.08.2008						 //
//  Note:    This is a UC release but might  //
//           be linked						 //
//  Credits: MSDN, Code Project & UC Forum   //
//           where i found some threads      //
///////////////////////////////////////////////


//Namespace and Struct Declaration
using namespace std;
Vars Var = {0};


//Remove Thread
DWORD WINAPI RemoteThread (LPVOID)
{
	while(!GetModuleHandle(Var.DLL_Name))
	{
		LoadLibrary(Var.DLL_Path);
		Sleep(100);
	}
	return true;
}


//Check If the DLL Exist
bool CheckIfDLLExist (void)
{
	Var.DLL_Exists = false;
	Var.Stats = 0;	
	
	Var.Stats = stat(Var.DLL_Path,&Var.FileInfo);

	if(!Var.Stats)
		Var.DLL_Exists = true;

	return Var.DLL_Exists;
}


//Main Routine
void main (void)
{
	GetModuleFileName(Var.hInjector, Var.Injector_Dir, 512);					
	for(int i = strlen(Var.Injector_Dir); i > 0; i--) { if(Var.Injector_Dir[i] == '\\') { Var.Injector_Dir[i+1] = 0; break; } }
	strcpy(Var.DLL_Path,Var.Injector_Dir);

	cout<<"Project: Injector V1.0"						<<endl;
	cout<<"Author:  ReUnioN"							<<endl;
	cout<<"Note:    UC only Release"					<<endl;
	cout<<"\nEnter the DLL`s Name you wish to inject: "	<<endl;
	cin>>Var.DLL_Name;
	cout<<"\nEnter the Target Process: "				<<endl;
	cin>>Var.Process_Name;

	strcat(Var.DLL_Path,Var.DLL_Name);

	cout<<"\nInjector Dir:   \n"<<Var.Injector_Dir			<<endl;
	cout<<"\nDLL Path:       \n"<<Var.DLL_Path				<<endl;
	cout<<"\nDLL Name:       \n"<<Var.DLL_Name				<<endl;
	cout<<"\nTarget Process: \n"<<Var.Process_Name			<<endl;

	if(!CheckIfDLLExist())
	{
		cout<<"\nDLL does not exist in the Folder of the Injector.exe\n"<<endl;
		system("PAUSE");
	}
	else
	{
		cout<<"\nStart your Game now... DLL will auto Inject\n"	<<endl;

		while(1)
		{
			Var.DLL_Injected = false;
			Var.Snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
			Var.ProcessEntry32.dwSize = sizeof(PROCESSENTRY32);
			Process32First( Var.Snapshot, &Var.ProcessEntry32 );

			while( Process32Next( Var.Snapshot, &Var.ProcessEntry32 ) )
			{
				if( strcmp( Var.ProcessEntry32.szExeFile, Var.Process_Name ) == 0 )
				{
					cout<<"Found Process\n"<<endl;
					cout<<"15 Seconds till injection...\n"<<endl;
					Sleep(15000);

					Var.Snapshot = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Var.ProcessEntry32.th32ProcessID);

					Var.AllocatedMemory = VirtualAllocEx(Var.Snapshot,NULL,MAX_PATH,MEM_COMMIT,PAGE_READWRITE);
					if(!Var.AllocatedMemory)
						cout<<"\nCouldnt allocate Memory for the Injecting Process\n"<<endl;

					Var.KernelModule = GetModuleHandle("Kernel32.dll");
					if(!Var.KernelModule)
						cout<<"\nCouldnt get the Kernel32 Module Handle"<<endl;

					Var.ThreadRet = (LPTHREAD_START_ROUTINE)GetProcAddress(Var.KernelModule,"LoadLibraryA");
					if(!Var.ThreadRet)
						cout<<"\Couldnt get LoadLibrary\n"<<endl;

					if(!WriteProcessMemory(Var.Snapshot,Var.AllocatedMemory,(LPVOID)Var.DLL_Path,strlen(Var.DLL_Path),NULL))
						cout<<"\Couldnt Write the DLL Path in the Process Memspace\n"<<endl;

					Var.RemoteThread = CreateRemoteThread(Var.Snapshot,NULL,NULL,Var.ThreadRet,Var.AllocatedMemory,NULL,NULL);
					if(!Var.RemoteThread)
						cout<<"\nCouldnt load the DLL into the Process Memspace\n"<<endl;
					else
						cout<<"\nLoading Dll...\n"<<endl;
					
					WaitForSingleObject(Var.RemoteThread,INFINITE);

					ExitProcess(0);
				}
				Sleep(100);
			}
			Sleep(100);
		}
	}
}