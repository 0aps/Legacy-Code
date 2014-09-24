#include <windows.h>

int main(int argc, char *argv[])
{
    int n = 999;
    DWORD pid;
    HANDLE process;
    HWND wnd;
    
wnd = FindWindow(0, "Buscaminas");
GetWindowThreadProcessId(wnd, &pid);
process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

WriteProcessMemory(process, (LPVOID)/*0x010057A4*/0x0100579C, &n, 8, 0);

CloseHandle(process);

return 0;

}

//8
// en esta parte hay que colocar el nuevo tamaño del valor que se escribe.
