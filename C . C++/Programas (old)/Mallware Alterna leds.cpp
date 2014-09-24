#include <windows.h>
#define STOP Sleep(100)

//Funcion para hacer el efecto de presionar una tecla(sacada de codemakers)
void SimulateKey(BYTE bvk, BYTE bScanCode)
{
     keybd_event(bvk, bScanCode, 0, 0);
     keybd_event(bvk, bScanCode, KEYEVENTF_KEYUP, 0);
}

int main()
{
    int i=0;
    while(true){
     SimulateKey(VK_LBUTTON, 0x45); //No te deja arrastrar texto
     SimulateKey(VK_NUMLOCK, 0x45);//Esta
     STOP;                         //Función
     SimulateKey(VK_CAPITAL, 0x3A);//Hace que se
     STOP;                         //alternen los
     SimulateKey(VK_SCROLL, 0x91); //leds del teclado
     STOP;
     SimulateKey(VK_SPACE, 0x45);  //Esta hace que se pulse el espacio
     STOP;
     i++;
     if(i==40)
     {
      WinExec("C:/WINDOWS/NOTEPAD.EXE", SW_MAXIMIZE);
      Sleep(2000);
      SimulateKey(0x4D, 0x45);
      Sleep(500);
      SimulateKey(0x49, 0x45);
      Sleep(500);
      SimulateKey(0x47, 0x45);
      Sleep(500);
      SimulateKey(0x55, 0x45);
      Sleep(500);                          
      SimulateKey(0x45, 0x45);
      i++;
      }                    
     }
    return 0;
}
