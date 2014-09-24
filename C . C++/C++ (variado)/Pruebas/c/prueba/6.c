#include <stdio.h>
#include <stdlib.h>

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
    
    sprintf(p,"%i",n);
    
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

int p_capicua(long long n)
{    
    long long n1 = n,
        cifra = cifras(n);
    if(cifra == 1 && n != 9)return n+1; //si es d una sola cifra
    
    
    long long FR = n/rpow(10, cifra - cifra/2), //frontal
        BR = n%rpow(10, cifra/2),       //last-back
        iFR = inverso(FR);               
     
    if( iFR == BR) //palindromo
    {
        n = n+rpow(10, cifras(FR));      //le sumo el 10, 100, o 1000
        FR = n/rpow(10, cifra - cifra/2); 
        iFR = inverso(FR);               //como cambio fr, hay q actualizarlo
        //
    }
     
     n = n-BR;                           //le resto la parte d atras
     n = n+iFR;                          //y la sustituyo por la de alante
     
     if(n1 > n)                          //si num viejo es mayor que el nuevo   
     {                                   //necesitamos el prox palindromo
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
    long long n,k;
    scanf("%i", &n);
    
    while(n--)
    {
              scanf("%d", &k);
              //printf("%i", k);
              if(k == 0) printf("1\n");
              else 
              printf("%d\n", p_capicua(k) );
    
    }
                           
    return 0;
}
 
