#include <iostream>

using namespace std;

int main()
{
    char cadena[100], cadena_n[100], *aux = cadena-1;
    int veces(0); 
    
    //int i(0);
    
    cout << "Cadena: ";
    cin.getline(cadena,100);
    
    cout << "\n\nCadena_n: ";
    
    while( *aux++ )
    {
           if(*aux == *(aux+1) )
           {
              veces++;
                
           if( *(aux+1) !=  *(aux+2) )
           {
               cout << veces;              
               //cadena_n[i] = veces;            
               //i++;
               veces = 0; 
           }
             
              continue;
                               
           }
                   
    //cadena_n[i] = *aux;
    //i++;
    cout << *aux;
    
    }
    
    //cadena_n[i] = '\0';             
    
    //cout << "\n\nCadena_n: " << cadena_n;
    cout << "\n\nCadena: " << cadena;

    setbuf(stdin, NULL);
    cin.get();
    return 0;
    
    
}
