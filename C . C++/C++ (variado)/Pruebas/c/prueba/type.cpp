#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void key(char ch  )
   {
      // Simulate a key press      
         keybd_event( VkKeyScan(ch),
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | 0,
                      0 );

      // Simulate a key release
         keybd_event( VkKeyScan(ch),
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);
   }

int main() {
    
           ifstream     readStream;
                        readStream.open("test.txt");
           
           int i=0;
           string  text[20];
           
           if (readStream.is_open()) {
              while (!readStream.eof()) {
                            getline(readStream,text[i]);
                            i++; 
	                }
            }
            
            SetFocus(NULL);
            for(int i(0); i<20; i++)
                    {
                          char *cstr = new char[text[i].length() + 1];
                          strcpy(cstr, text[i].c_str());

                          for(; *cstr; cstr++)                          
                          {
                                              key(*cstr);
                                            Sleep(30);
                          }
                     }
                    
            return 0;
}
