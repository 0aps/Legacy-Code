#include <windows.h>
#include <stdio.h>
#include <iostream> //optional: puede reforzar el tamaño de archivo.
#include <fstream> // optional: hay alternativas.
#define GAME "Sin título - Bloc de notas"
#define DLL "Project1.dll"

using namespace std; //

HWND hWnd;
DWORD pId;

void Inject(HWND hWnd, char* strDll ) {
  GetWindowThreadProcessId(hWnd, &pId);
  HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);
  LPVOID lpRemoteAddress = VirtualAllocEx(hProcess, NULL, strlen(strDll), MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
  WriteProcessMemory(hProcess, lpRemoteAddress, (LPVOID)strDll, strlen(strDll), NULL);
  CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA"), lpRemoteAddress, 0, NULL);
}


int main() {
  cout<<"Waiting for window to appear... ";
  while(!(hWnd = FindWindow(0,GAME))) Sleep(1000);
  cout<<"Found Window!"<<endl;
  ofstream filecheck;
  filecheck.open(DLL,ios::in);
  if(!filecheck.is_open()) printf("Error: Unable to find %s.n",DLL);
  else { Inject(hWnd,DLL); cout<<"Injected "<<DLL<<" into process!"<<endl;}
  filecheck.close();
  system("PAUSE");
  return 0;
}
