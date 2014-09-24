/*
#include <iostream>

using namespace std;

//el mcm d 2 numeros es un multiplo del mas grande (d ambos actually pero ta ma cerca del segundo)
//so vamo buscando el multiplo q sea divido por el ma bajito, y el primero entonce ese es!
long long mcm(long long a, long long b, int i = 1)
{
    return ( !((b*i)%a) )? b*i : mcm(a,b, i+1);
}


//el gcd x medio del algoritmo de euclides
//se sustenta en el hecho q el gcd(a,b) == gcd(b,r)
//para todo r | a = q*b + r (o sea q r se el cosciente de a/b)
//esto es que el residuo de a/b siempre es divisible por el mcd(a,b)
//ej: 60%48 = 12, 48%12 = 0, 12 es el mcd.

int gcd(int a, int b)
{
    return (!a)? b : gcd(b%a, a);
}


int main()
{
    int j, limit(20);
    int acc(0), clase;
/*
     for(i=1; j != 20+1; i++ )
        for(j=1; j <= 20; j++)
            if( i%j ) break;
*/

/*
      Caso en donde hay una bucle y j%limit (residuo 1, 2, 3, 4 ... limit) para j >= 1
      37.0 segs
      //2520 -> 10
     for(j = 1; acc != limit;)
         if( acc != limit-1 && !(j%((acc+1)%limit)) ) acc++;
         else if( acc == limit-1 && !(j%limit)) acc++;
         else
                    acc = 0,
                    j++;
*/
/*
    3 segs
    j = 1;
                  //es hasta -1 porque el ultimo caso no cuenta, o sea si cuenta
                  //pero es obvio que limit dividira a su propio multiplo!
    while( acc != limit-1) //mientras no hayan limit divisiones continuas bien hechas
    {
        if ( !( (j*limit)%(acc+1)  ) ) acc++; //vamos a dividir entre los multiplo de limit
                                              //si se divide entre 1...limit bien, entonces tamo good
        else                            //d lo contrario, si un caso falla, empezamo otra ve'
            acc = 0,                    //y con un multiplo (limit*j) distinto.
            j++;
    }

*/
/*
    //lo mismo pero con for -> 3 segs
    for(j=1; acc != limit-1; )
        if( ! ((j*limit)%(acc+1)) ) acc++;
        else
            j++, acc = 0;

    cout << j*limit;

    cout << mcm(62500,10503200);
    return 0;
}
*/
