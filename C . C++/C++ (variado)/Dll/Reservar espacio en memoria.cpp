#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    POINT p; // para el obtener el cursor
    HWND hwnd; //manejador de la ventana
    char titulo[1024]; ///titulo de la ventana
    char cname[1024]; // clase de la ventana
    DWORD pid; // pid de la ventana
    HANDLE proceso; //proceso 
    LPVOID mReservada; //memoria reservada
    DWORD offset = 0xFFFFFBF8;
    DWORD mEscrita;
    
    char valor[100];
    
    
       if( GetCursorPos(&p) != 0)
       cout << "GetCursorPos succed.";
       else cout << "GetCursorPos failed.";
       
    
       hwnd = WindowFromPoint( p );
       if(hwnd != NULL)
       cout << "\nWindowsFromPoint succed.";
       else cout << "\nWindowsFromPoint failed.";
    
   if( GetWindowText(hwnd,titulo,255) == 0)
       cout << "\nGetWindowText failed.";
       else cout << "\nGetWindows Text succed.";
       
   cout << "\nCadena : " << titulo
        << endl;
        
    if( GetClassName(hwnd,cname, 1024 ) == 0)
       cout << "\nGetClassName failed.";
       else cout << "\nGetWindowName succed.";
    
    cout << "\nCadena : " << cname
        << endl;
    
    GetWindowThreadProcessId(hwnd, &pid);
    
    proceso = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
    if(proceso == NULL)
    cout << "\nOpenProcess failed.";
    else cout << "\nOpenProcess succed."; 
    
    mReservada = (LPVOID)VirtualAllocEx(proceso,NULL,1024,
                         MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);
    
    if(mReservada == NULL)
    cout << "\nVirtualAllocEx failed.";
    else  cout << "\nVirtualAllocEx succed.";
    
    mEscrita = 0x003E3850 - offset;
    
    while(1)
    {
    
    
    cout << "\n\nIngresa el valor: ";
    cin.getline(valor, 100);
    
    mEscrita += offset;
    
    if ( WriteProcessMemory(proceso,LPVOID(mEscrita),LPCVOID(valor),strlen(valor),NULL) == 0 )
    cout << "\nWriteProcessMemory failed.";
    else cout << "\nWriteProcessMemory succed.";
    
    }
    //003E3850
    //003E3C58
    //003E4060
    //003E4468
    //0x77C657C0
    
    //FFFFFBF8
    setbuf(stdin, NULL);
    cin.get();
    
    return 0;
}
