#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <winable.h> // Necesaria para blockinput();
 
 
using namespace std;
 
int main(int argc, char *argv[])
{
    if(BlockInput(true)==1)
     {
    cout<<"Teclado y mouse bloqueado, consiga un martillo para desbloquearlo";
    Sleep(5000);
    BlockInput(false);
    }
    system("CLS");
    cout<<"se desbloqueo el mouse y el teclado, guarde su martillo";
    getchar();
    return EXIT_SUCCESS;
}
