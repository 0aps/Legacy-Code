#include <windows.h>
using namespace std;

int main(int argc, char *argv)
{
    HWND hWnd;
    int i = 0;
  //  DWORD pid;
    
   // GetWindowThreadProcessId(hWnd, &pid);
    while(i  <= 5000)
    {
                  hWnd = FindWindow(NULL, "Sin título - Bloc de notas");
                  keybd_event(VK_SPACE, 0, KEYEVENTF_EXTENDEDKEY | 0, 0 );
                  i++;
                  
          if(hWnd)
         {
                      keybd_event( 
                      VK_SPACE,
                      0,
                      KEYEVENTF_KEYUP,
                      0); 
         } 
         
        if(i == 2000)  
        {
            WinExec("notepad.exe", SW_MAXIMIZE);
        }
                
    }
    
return 0;
}                                                                                                                                       
                                                                                                                                                                              
