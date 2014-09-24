#include <iostream>

using namespace std;

int main()
{
    int aux(0), D, N, nE, *E;
    
    cout << "Distancia a Pedernales: "; cin >> D;
    cout << "Kilometros que dura el tanque: "; cin >> N;
    cout << char(168) << "Cuantas estaciones hay? "; cin >> nE; 
    
    E   = new int[nE];
    aux = N;  
    
         for(int i=0; i < nE; i++)
                 {cout << "Estacion numero " << i+1 << ": "; cin >> E[i];}
    
    cout << "Partimos a pedernales. Buen viaje.\n";
    
         for(int i=0; i < nE; i++)
         {
                 aux = aux - E[i];
                 D   = D - E[i];
                         
                 //existe la proxima estacion
                 if(aux < E[i+1]) //llego con lo que tengo?
                          {
                                    cout << "\nNos paramos a llenar en la estacion "
                                         << i+1
                                         << ", teniamos "
                                         << aux
                                         << " kilometros, proxima estacion "
                                         << E[i+1]
                                         << " faltan " << D
                                         << " kilometros";
                                    aux = N;
                          }
                  else    cout << "\nEstacion " << i+1 
                               << " tanque: " << aux
                               << " proxima estacion: " << E[i+1]
                               << " faltan " << D
                               << " kilometros. ";
         }
         
         cout << "\n\nLlegamos!";
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
