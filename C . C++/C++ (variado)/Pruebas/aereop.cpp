#include <iostream>
#include <windows.h>

using namespace std;

void limpiar();

int main()
{
    string aux;
    int he, hs, hp;
    
    while(1)
    {
            limpiar();
            cout <<"Hora de entrada: ";  getline(cin, aux);
            he = atoi(aux.c_str()); 
            cout <<"Hora de salida: ";  getline(cin, aux);
            hs = atoi(aux.c_str());
               
            cout << hs << endl << he << endl;
            if( he >= 0 && he <= 23 
                        &&
                hs >= 0 && hs <= 23
                        &&
                      he <= hs      )
            {
                    hp = 500 + ((hs-he))*250;
                    cout << "Duraste: " << (hs-he)+1 << " horas."
                         << endl
                         << "Tienes que pagar: " << hp << " pesos." << endl;
            }
            else
                 cout << "Formato invalido, solo formato de 24 horas objetivo. ";
                 
            setbuf(stdin, NULL); cin.get();
    }
    
    return 0;
}

void limpiar ()
{
    HANDLE hOut = GetStdHandle ( STD_OUTPUT_HANDLE );
    COORD coord = { 0, 0 };
    DWORD dwcount;
    CONSOLE_SCREEN_BUFFER_INFO csb_i;
    GetConsoleScreenBufferInfo ( hOut, &csb_i );
    FillConsoleOutputCharacter ( hOut, ' ',
        csb_i.dwSize.X * csb_i.dwSize.Y, coord, &dwcount );
    SetConsoleCursorPosition ( hOut, coord );
   
}  
