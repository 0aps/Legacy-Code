#include <iostream>
#include <cstdio>

using namespace std;


int cifras( int n)
{
    int x;
    for(x=0; n != 0; n=n/10,x++); //mientras no llegue a cero, contamos  
                             //ese sera el numero de cifras
    return x;
}

int inverso (int n)
{
    int cf = cifras(n),i=0;
    char p[cf],aux[cf];
    
    itoa(n,p,10);
   
    while(cf--)
    {
             aux[i] = p[cf];
             i++;
    }
     
    aux[i] = 0;
    i = atoi(aux);
    
    return i;

}

int rpow(int b, int e)
{
    return (e == 0)? 1 : b*rpow(b,e-1);
}

int p_capicua(int n)
{    
    int n1 = n; 
    int cifra = cifras(n);
    if(cifra == 1)return n;
    
    int FR = n/rpow(10, cifra - cifra/2); //frontal
    int FRc = n/rpow(10, (cifra - cifra/2)-1 );
    int BR = n%rpow(10, cifra/2);         //last-back
    int iFR = inverso(FR);
     
    if( iFR == BR) //palindromo
    {
        n = n+rpow(10, cifras(FR));
        FR = n/rpow(10, cifra - cifra/2);
        iFR = inverso(FR);
        //
    }
     
     n = n-BR;
     n = n+iFR;
     
     if(n1 > n)
     {
           n = n+rpow(10, cifras(FR));
           FR = n/rpow(10, cifra - cifra/2);
           iFR = inverso(FR);
           
           BR = n%rpow(10, cifra/2); 
           n = n-BR;
           n = n+iFR;
     }    
     return n;
}



int main()
{
    int n,k,aux;
    cin >> n;
    
    while(n--)
    {
              cin >> k;                     
              cout << p_capicua(k) << endl;
    
    }
                           
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
