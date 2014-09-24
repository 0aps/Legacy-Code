// Ejercicio # 2:
// 
// Condiciones
// 
// Condiciones sencillas
// 
// Un cliente ordena cierta cantidad de brochas de cerda, rodillos y
// sellador; las brochas de cerda tienen un 20% de descuento y los rodillos un
// 15% de descuento. Los datos que se tienen por cada tipo de artículo son: la
// cantidad pedida y el precio unitario. Además, si se paga de contado todo
// tiene un descuento del 7%. Elaborar un programa en C++ que calcule y muestre
// en pantalla el costo total de la orden, tanto para el pago de contado como
// para el caso de pago de crédito.

#include <iostream>
#include <windows.h>

using namespace std;

void ClearScreen ()
{
    HANDLE hOut = GetStdHandle ( STD_OUTPUT_HANDLE );
    COORD coord = { 0, 0 };
    DWORD dwcount;
    CONSOLE_SCREEN_BUFFER_INFO csb_i;
    GetConsoleScreenBufferInfo ( hOut, &csb_i );
    FillConsoleOutputCharacter ( hOut, '  ',
        csb_i.dwSize.X * csb_i.dwSize.Y, coord, &dwcount );
    SetConsoleCursorPosition ( hOut, coord );
   
}  

int main(int argc, char *argv[])
{   
    int cerda(100), rodillo(200), sellador(300), opcion;
    string salir;
    
    while(1)
    {
    cout << "\t\t Bienvenido! \n\n";
    cout << "\tComo va a hacer su pago ?";
    cout << "\n\n1.Tarjeta o \tEfectivo\n:";
    cin >> opcion;
    switch(opcion)
    {
        case 1: 
            {
                cerda    =  (20 * cerda   ) /100;
                cerda    -= 100;
                rodillo  =  (15 * rodillo ) /100;
                rodillo  -= 200;
                sellador =  (7  * sellador) /100;
                sellador -= 300;
                
                cout << "\n\nSe eligio el " << opcion << "er pago. "<< endl << endl;
                cout << "Rodillo  (Descuento de 20%) = " << rodillo  << endl;
                cout << "Cerda    (Descuento de 15%) = " << cerda    << endl;
                cout << "Sellador (Descuento de 7% ) = " << sellador << endl;
                cout << "Desea salir del programa: ?\n\n";
                while(1)
                {
                  cout << "Teclee S (si) o N (no):";
                  cin >> salir;
                   
                     if(salir == "n" || "N" || "no" || "No" || "NO" || "nO")
                   {
                     cout << "\n\n\tTecle una tecla para volver.";
                     setbuf(stdin, NULL);
                     cin.get();
                     ClearScreen();
                     break;
                    
                   }
                   
                     if(salir == "s" || "S" || "si" || "Si" || "SI" || "sI" )
                   {
                     cout << "\n\n\t\tGracias por su compra!";
                     setbuf(stdin, NULL);
                     cin.get();
                     exit(0);
                   }
                   
                }
                
            }      
                
        case 2:           
        {                        
                cerda    = ( (7 * cerda    ) /100) - 100;
                rodillo  = ( (7 * rodillo  ) /100) - 200;
                sellador = ( (7  * sellador) /100) - 300;
               
                cout << "\n\nSe eligio el " << opcion << "do pago. "<< endl;
                cout << "Rodillo  (Descuento de 7%) = " << rodillo  << endl;
                cout << "Cerda    (Descuento de 7%) = " << cerda    << endl;
                cout << "Sellador (Descuento de 7%) = " << sellador << endl;
                cout << "Desea salir del programa: ?\n\n";
                while(1)
                {
                  cout << "Teclee S (si) o N (no):";
                  cin >> salir;
                   
                     if(salir == "s" || "S" || "si" || "Si" || "SI" || "sI")
                   {
                     cout << "\n\n\t\tGracias por su compra!";
                     setbuf(stdin, NULL);
                     cin.get();
                     exit(0);
                   }
                   else 
                   cout << "\n\n\tTecle una tecla para volver.";
                   setbuf(stdin, NULL);
                   cin.get();
                   ClearScreen();
                   break;
                   
                }
        }
        break;
   }
}
return 0;
}

      
    
    
