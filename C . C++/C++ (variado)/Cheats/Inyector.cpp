#include <windows.h>
#include <iostream>
#include <fstream> 
#define ventana "Buscaminas"
#define DLL "Project1.dll"

using namespace std;

HANDLE proceso;
HWND hwnd;
DWORD tid ;

void Inyectar(char*);

int main(int argv, char *argc)
{
    do
    {   
    cout << "Esperando a que aparesca la ventana "; 
    cout << ". "; Sleep(100); cout << ". "; Sleep(100); cout << "."; Sleep(100);
    system("cls");
    }
    while(!(hwnd = FindWindow(NULL, ventana)));
    
    cout << "Se encontro la ventana! ";
    
    tid = GetWindowThreadProcessId(hwnd, &tid);
    proceso = OpenProcess(PROCESS_ALL_ACCESS, false, tid);
    ofstream filecheck;
    filecheck.open(DLL,ios::in);
    if(!filecheck.is_open()) cout <<"\n\n\t\tError!\n\t No se encontro " << DLL;
    else { 
         Inyectar(DLL);
         cout<<"\nSe inyecto "<< DLL<<" en el proceso! "<<endl;
         }
    
    cin.get();
    
}

void Inyectar(char *Dll)
{
   LPVOID VirAcess = VirtualAllocEx(proceso, NULL, sizeof(&Dll), MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
    WriteProcessMemory(proceso, (LPVOID)VirAcess, (LPCVOID)&Dll, sizeof(&Dll), NULL);
    
    CreateRemoteThread(
    proceso, NULL, NULL, 
    (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA"), VirAcess, 0, NULL);
                        
}
    
