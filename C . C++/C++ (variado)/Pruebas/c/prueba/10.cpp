#include <iostream> // biblioteca para uso de cout 
#include <vector>
using namespace std;

int main()
{
   unsigned long long numero,numero2;
   unsigned long long factor,i,cont;
   vector<unsigned long long> c;
   char resp[12];
   
   do {
      cout << "Introduce un número entero: ";
      cin >> numero;
      factor = 2;
      numero2 = numero;
      i = 0, cont = 1,c.push_back(0);
      while(numero >= factor*factor) {
         if(!(numero % factor)) {        
            cout << numero << "/" << factor << " = " << numero/factor <<  ">> " << c[i]+1 << endl;
            numero = numero / factor;
            c[i]++;
            //if( numero == factor) c[i]++;
            if( numero <  factor*factor && !(numero%factor)) c[i]++;
            continue;
         }
          
         if(factor == 2) factor++,i++,c.push_back(0);
         else factor += 2,i++,c.push_back(0);
      }
      if(numero != factor)c.push_back(0),c[i+1]++;
      
      for(unsigned long long j=0; j<c.size(); j++)
      {       
              if(c[j] == 0)
                           continue;
              cout << c[j] << endl;
              cont *= ++c[j];
      }
      
      c.clear();
      cout << "taotal de factores: " << cont;
      cout << endl;
      cout << "Descomponer otro número?: ";
      cin >> resp;
      
   } while(resp[0] == 's' || resp[0] == 'S');
   return 0;
}
