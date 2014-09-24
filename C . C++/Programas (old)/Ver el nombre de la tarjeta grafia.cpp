#include <stdio.h>
#include <windows.h>
 
int main()
{
    int i=0;
    DISPLAY_DEVICE grafica;
    grafica.cb=sizeof(DISPLAY_DEVICE);
 
    while(EnumDisplayDevices(0, i, &grafica, 3))
    {
        printf("El nombre de la grafica es %s\nEl nombre interno es %s\n\n", grafica.DeviceString, grafica.DeviceName);
        i++;
    }
    getchar();
    return 0;
}
