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
    DWORD old;
    
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
    //00401000 00001000
    //00401353
    if (VirtualProtectEx(proceso,(void*)0x00401000, 0x00001000, PAGE_READONLY, &old))
         cout << "\nVirtual Protect succed. " << old;
         else cout << "\nVirtual Protec failed."<< old;;
         
    
    setbuf(stdin, NULL);
    cin.get();
    
    return 0;
}
