#include <iostream>
#include <conio.h>

using namespace std;

int main(int argc, char *argv)
{
    for(;;)                          // Se hace el bucle para que no salga del programa.
    {
    cout << getch() << "\t";         //getch obtine el numero ANSI de la letra presionada.
    }
}
/*
void main()
{
      int tec=0;
      while(tec!=27) // Mientras no se preciona escape no se sale!
      {
           tec=getch();
           printf("%i\n",tec);
      }
      return 0;
}
*/

