#include <Windows.h> 
#include <iostream> 
 
void printscreen(void){ 
 
   keybd_event(VK_SNAPSHOT, 0, 0, 0); 
    keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0); 
   //Normal Full Screenshot 
} 
 
void printscreenwindow(void){ 
 
   keybd_event(VK_SNAPSHOT, 1, 0, 0); 
   keybd_event(VK_SNAPSHOT, 1, KEYEVENTF_KEYUP, 0); 
   //Screenshots the active window only 
} 
 
void savePic(void){ 
 
   OpenClipboard(NULL); 
   HANDLE clipHandle = GetClipboardData(CF_BITMAP); 
   //Convert the clipboard data to a bmp and save it ?? 
   CloseClipboard(); 
} 
 
 
int main(){ 
 
 
 
   for(;;25){ 
 
      if(GetAsyncKeyState(VK_F1)&1){
        printscreen(); 
        savePic(); 
     } 
 
 
      if(GetAsyncKeyState(VK_F2)&1){
        printscreenwindow(); 
        savePic(); 
     } 
 
   } 
 
   return 0; 
}
