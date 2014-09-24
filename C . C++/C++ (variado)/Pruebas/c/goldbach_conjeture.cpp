#include <iostream>

using namespace std;

//Eratostenes good performance
char* cEratostenes(int n)
{
     char *lista = new char[n];
     memset(lista, 1, n);
                   for(int i=2; i*i <= n; i++)
                   {
                           if( lista[i-1] == 0) continue;
                           
                           for(int p=i*2; p <= n; p+=i)      
                                   lista[p-1] = 0;
                   }
     return lista;
}
/*
     crear primos desde 1 hasta n usando eratostenes boleano
     pasar esos 1/0 a un puntero
     permutar por cada elemento que se cumpla la condicion
     buscar la diferencia mayor e imprimi
*/
     
int main()
{
    int n,aux,pos,pos2,*primos;
    char *lista;

    while(cin >> n && n)
    {
              cin.ignore();
              cin.clear();
              lista = cEratostenes(n);       
              aux=0;
                    for(int i=0; i<n; i++)
                             if(bool(lista[i])) aux++;
                             
              primos = new int[aux+1];
              memset(primos,0,(aux+1)*sizeof(int));
                             
              //obtengos los numeros per se en primos y no por la posicion
                    for(int i=0,*paux=primos; i<n; i++)
                              if(bool(lista[i])) *paux++ = (i+1);
              
              //hay mas posibilidades de que se cumpla por el final
                    if(n > 7)primos--;          
                    for(int *p=primos+(aux); aux; p--)
                          for(int *paux=p-1; aux && *paux != 1 ; paux--)
                                  if((*p + *paux) == n)
                                             aux = 0,
                                             pos  = paux-primos,
                                             pos2 = p-primos;
                                           
                              cout <<  n << " = " <<
                      primos[pos]
                                   << " + " <<
                      primos[pos2] << '\n'; 
              
                      delete[] primos;
    }
        
    cin.get();
    return 0;
}
