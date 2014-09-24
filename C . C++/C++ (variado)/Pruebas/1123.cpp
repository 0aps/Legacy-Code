#include <iostream>
#include <set>

using namespace std;
                     
int main()
{
    int n;
    set<unsigned long long> st,st2;
    set<unsigned long long>::iterator ist;
    
    st.insert(1);
    for(ist = st.begin(); st2.size() <= 1500; ist = st.begin() )
    {
            st.insert( (*ist)*2);
            st.insert( (*ist)*3);
            st.insert( (*ist)*5);
            st2.insert(*ist);
            st.erase(*ist);
    }
    
    
    while(cin >> n && n)
    {             
         ist = st2.begin();
         while(--n)
         ist++;
         cout << *ist << endl;   
    }
    
    cin.get();
    return 0;
}


int is_primo(int n)
{
    int lim(0);
    for(int i=1; i<=n; i++)
            {
                 if( !(n%i) ) lim++;
                 if(lim > 2) break;
            }
    return (lim == 2)? 1 : 0;
}

/*
  llenar la lista hasta n
  buscar los primos desde 7 hasta n
  buscar los multiplos de 7 hasta n
  e ir quitandolos de la lista
  
  lo impractivo aquí posiblemente sea la forma de encontrar lso numeros primos
}
*/

void impractico()
{
    int n;
    list<int> t;
    list<int> pr;
    list<int>::iterator it;
    
     for(int i=1; i <= 1500; i++)
    {
            t.push_back(i);
            if(i>=7)
                    if( is_primo(i) ) pr.push_back(i);
    }
    
    for(it = pr.begin(); it != pr.end(); it++)
            for(int j=7; j < 1500; j++)
                    if( !(j%(*it)) ) t.remove(j);
    
       for (it=t.begin(); it!=t.end(); ++it)
               std::cout << ' ' << *it;
               
       cout << endl << t.size();

       while(cin >> n && n)
    {
         it = t.begin();
         while(--n)
         it++;
         cout << *it << endl;
         
    }
    cin.get();
    
}

/*
    list<int> lista = criba();
    
    for(list<int>::iterator it = lista.begin(); it != lista.end(); it++)
                             cout << " " << *it;
    */
list<int> criba(int n)
{
          list<int> lista;
          list<int>::iterator it;
          
          for(int i = 1; i<= n; i++)
                  lista.push_back(i);
          
          for(int i = 2; i <= n; i++)
          {
                  it = find(lista.begin(), lista.end(), i);
                  if(i != *it) continue;
                  else
                      for(int p = 2*i; p <= n; p+=i)
                              lista.remove(p);
          }

          return lista;
}
                        
    

