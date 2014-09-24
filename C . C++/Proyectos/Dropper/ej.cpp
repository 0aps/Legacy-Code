#include <windows.h>

int main()
{

 WinExec("calc.exe", SW_HIDE);
 WinExec("file.exe", SW_SHOWNORMAL);

}
