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

int p_capicua(int n)
{    
    int n1 = n; 
    int cifra = cifras(n);
    if(cifra == 1 && n != 9)return n+1; //si es d una sola cifra
    
    
    int FR = n/rpow(10, cifra - cifra/2); //frontal
    int BR = n%rpow(10, cifra/2);         //last-back
    int iFR = inverso(FR);               
     
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
    int n,k;
    scanf("%i", &n);
    int arrey[n],aux=n;
    
    while(n--)
    {
              scanf("%i", &k);
              if(k == 0) arrey[n] = 1;
              else if(k <= 9999999)
                   arrey[n] = p_capicua(k);
    
    }
    while(aux--)printf("%i\n", arrey[aux]);
      
    setbuf(stdin, NULL);
    return 0;
}
