#include <iostream> 
#include <windows.h> 
using namespace std;

bool IsWindowsNT()
{
   // checkea la versión de windows
   DWORD version = GetVersion();
   // parse return
   DWORD majorVersion = (DWORD)(LOBYTE(LOWORD(version)));
   DWORD minorVersion = (DWORD)(HIBYTE(LOWORD(version)));
   return (version < 0x80000000);
}


int main(int argc, char *argv)
{

IsWindowsNT();

cin.get();
}
