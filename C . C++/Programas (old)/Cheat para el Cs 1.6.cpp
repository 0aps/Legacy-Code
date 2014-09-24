#include <windows.h>
#include <stdio.h>

HWND wnd;
DWORD pid;
HANDLE process;

void VidaInfinita();
void DineroInfinito();

int main()
{
    FreeConsole();

    MessageBox(0, "F12 = Cerrar CS_MONEY\n F5 = Encontrar ventana de CS 1.6\n F9 = Activar Cheat de Dinero y Vida Infinita\n F10 = Desactivar Cheat\n :::By: GodSys:::", "CS_MONEY&LIFE | By: GodSys", MB_OK);
    while(!GetAsyncKeyState(VK_F12))
    {
        if(GetAsyncKeyState(VK_F5))
        {
            wnd = FindWindow(0, "Counter-Strike");
            GetWindowThreadProcessId(wnd, &pid);
            process = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
        }
        if(GetAsyncKeyState(VK_F9))
        {
            while(!GetAsyncKeyState(VK_F10))
            {
                VidaInfinita();
                DineroInfinito();
                Sleep(50);
            }
        }

   Sleep(100);
    }
        MessageBox(0, "CS_MONEY Finalizado!", "CS_MONEY | By: GodSys", MB_OK);
        return 0;
}


void VidaInfinita()
{
    long flvl;
    long faddy;
    long slvl;
    long daddy;
    short poffset = 0x04;
    short soffset = 0x160;
    const long valuev = 0x461C3C00;

    ReadProcessMemory(process, (LPVOID)0x03C2FBF8, &flvl, sizeof(flvl), NULL);
    faddy = flvl + poffset;
    ReadProcessMemory(process, (LPVOID)faddy, &slvl, sizeof(slvl), NULL);
    daddy = slvl + soffset;
    WriteProcessMemory(process, (LPVOID)daddy, &valuev, sizeof(valuev), NULL);
}

void DineroInfinito()
{
    long maddy;
   long saddy;
   short offset = 0x1cc;
   const long valued = 16000;
    ReadProcessMemory(process, (LPVOID)0x3C2FBF8, &maddy, sizeof(maddy), NULL);
    saddy = maddy + offset;
    WriteProcessMemory(process, (LPVOID)saddy, &valued, sizeof(valued), NULL);
    WriteProcessMemory(process, (LPVOID)0x019E5F1C, &valued, sizeof(valued), NULL);
}
