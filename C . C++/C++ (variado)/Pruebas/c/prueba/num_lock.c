
   #include <windows.h>

   void SetNumLock( char x )
   {
      BYTE keyState[256];

     // GetKeyboardState((LPBYTE)&keyState);
     // if( (bState && !(keyState[VK_NUMLOCK] & 1)) ||
     //     (!bState && (keyState[VK_NUMLOCK] & 1)) )
     // {
      // Simulate a key press
         keybd_event( VkKeyScan(x),
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | 0,
                      0 );

      // Simulate a key release
         keybd_event( VkKeyScan(x),
                      0x45,
                      KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                      0);
     // }
     
   }

   void main()
   {
        int x;
        char p = 'A';
      /*for( x=0; x<100; x++)
      {  
         SetNumLock( p );
         Sleep(100);
      }*/
      while(p!='Z')
      {
                   SetNumLock(p);
                   Sleep(100);
                   p++;
      }
   }
   
