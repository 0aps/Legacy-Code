#include <iostream>
#include <vector>

using namespace std;

unsigned long long factores(unsigned long long tri, unsigned long long i)
{
         unsigned long long fact = 0;
         cout << i << "-> " << tri << endl;
         for(int i=1; i <= tri; i++)
                 if( !(tri%i) ) 
                 {
                     cout << "  " << i << "(" << ++fact << ") ";
                 }
         return  fact;
}

unsigned long long factores2(unsigned long long tri, unsigned long long x)
{
      unsigned long long cont=1,factor=2,i=0,tri2=tri;  
      vector<unsigned long long> c;      
      c.push_back(0);
      for( ; tri >= factor*factor; )
              {
                       if(!(tri % factor)) 
                       {        
                                tri = tri / factor;
                                c[i]++;
                                if( tri < factor*factor && !(tri%factor)) c[i]++;
                                
                                continue;
                       }
                       
                       if(factor == 2) factor++,i++,c.push_back(0);
                       else factor += 2,i++,c.push_back(0);
               }
               
      if(tri != factor)c.push_back(0),c[i+1]++;
      
      for(int j=0; j<c.size(); j++)
      {       
              if(c[j] == 0)
                           continue;
              cont *= ++c[j];
      }
      cout << x << "-> " << tri2 << "-> " << cont << endl;
      return cont;
}

int main()
{
    unsigned long long tri;
    for( unsigned long long i = 10000,tri = i*(i+1)/2;
         factores2(tri,i) != 200; 
         i++, tri = i*(i+1)/2
         );
    
    cin.get();
    return 0;
}
    
