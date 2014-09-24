#include <iostream>
#include <algorithm>
#include <vector>

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
    int n,aux,*primos;
    char *lista;
    vector<int> sum;
       
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
                             
                    for(int i=0,*paux=primos; i<n; i++)
                              if(bool(lista[i])) *paux++ = (i+1);

                    if(n > 7)primos++;          
                    for(int *p=primos; *p; p++)
                          for(int *paux=p+1; *paux; paux++)
                                  if((*p + *paux) == n)
                                            sum.push_back(*p),
                                            sum.push_back( (*paux - *p) ),
                                            sum.push_back(*paux);
              
                              cout <<  n << " = " <<
                      sum[ ((max_element(sum.begin(), sum.end() )) - sum.begin())-2 ]
                                   << " + " <<
                      sum[ ((max_element(sum.begin(), sum.end() )) - sum.begin()) ] << '\n'; 
              
                      sum.clear();
                      delete[] primos;
    }
        
    cin.get();
    return 0;
}


/*
vector<int> eratostenes(int n)
{
            vector<int> lista;
            for(int i=1; i<=n; i++) lista.push_back(i);
            for(int i=2; i*i <= n; i++)
            {
                    if( find(lista.begin(), lista.end(),i) == lista.end() )
                    continue;
                    for(int p=i*2; p <= n; p+=i)
                            lista.erase(remove(lista.begin(), lista.end(), p), lista.end());
            }
            
            return lista;
}
                     
int main()
{
    int n;
    vector<int>primos;
    
    while(cin >> n && n)
    {
              cin.ignore();
              cin.clear();
              
              primos = eratostenes(n); 
              for(int i=0; i < primos.size(); i++)
                              cout << " " << primos[i];
                              cout << endl;
              int i(-1);
               do {
                       while(i++<4)
                       std::cout <<  ' ' << primos[i];
                       cout << endl; i=-1; 
                  } while ( std::next_permutation(primos.begin(),primos.end()) );
                  
                  /*for(int i(0); 
                  next_permutation(primos.begin(),primos.end())
                                                               ;)
                  {
                              cout << " " << primos[i]; 
                              if(++i == primos.size())
                              i=0,cout << endl;
                  }
    }
    cin.get();
    return 0;
}
*/
