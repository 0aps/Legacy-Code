
   #include <windows.h>

   void SetNumLock( BOOL bState )
   {
      BYTE keyState[256];

     // GetKeyboardState((LPBYTE)&keyState);
     // if( (bState && !(keyState[VK_NUMLOCK] & 1)) ||
     //     (!bState && (keyState[VK_NUMLOCK] & 1)) )
     // {
      // Simulate a key press
      
         keybd_event( 0x41,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | 0,
                      0 );

      // Simulate a key release
         keybd_event( 0x41,
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);
     // }
   }

   int main()
   {
        int x;
      for( x=0; x<100; x++)
      {  
         SetNumLock( TRUE );
         Sleep(100);
      }
      
   }
