#include <stdio.h>
#include <string.h>

//Eratostenes good performance
char* cEratostenes(int n)
{
     char *lista = (char*)malloc(n);
     int i,p;
     memset(lista, 1, n);
                   for(i=2; i*i <= n; i++)
                   {
                           if( lista[i-1] == 0) continue;
                           
                           for(p=i*2; p <= n; p+=i)      
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
    int n,i,aux,pos,pos2,*primos,*paux,*p;
    char *lista;

    while( scanf("%d",&n) && n)
    {
              setbuf(stdin,NULL);
              lista = cEratostenes(n);       
              aux=0;
                    for(i=0; i<n; i++)
                             if((lista[i])) aux++;
                             
              primos = (int*)malloc( (aux+1)*sizeof(int) );
              memset(primos,0,(aux+1)*sizeof(int));
                             
                    for(i=0,paux=primos; i<n; i++)
                              if((lista[i])) *paux++ = (i+1);
              
                    if(n > 7)primos--;          
                    for(p=primos+(aux); aux; p--)
                          for(paux=p-1; aux && *paux != 1 ; paux--)
                                  if((*p + *paux) == n)
                                             aux = 0,
                                             pos  = paux-primos,
                                             pos2 = p-primos;
                                       
                    printf("%d = %d + %d\n", n,primos[pos],primos[pos2]);     
             //       free(primos);
    }
    return 0;
}
