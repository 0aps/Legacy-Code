/*#include <iostream>
#include <ctime>
#include <cmath>
#include <limits>

typedef long long Long;

long long is_primo(long long num)
{
    if( !(num%2)) return 0;

    long long raiz = sqrt(num);
    for(long long i = 3; i <= raiz; i+=2)
        if( !(num%i ) ) return 0;

    return 1;
}

long long is_primo2(long long num)
{
    long long div(0);
    for(long long i=1; i <= num; i++)
            if(!(num%i)) div++;

    return (div > 2)? 0 : 1;
}

void descomprimir_factores(Long num)
{
    int rep(0);
    for(long long fac = 2; fac <= sqrt(num);)
    {
        if( !(num%fac ) )
        {
            num = num / fac;
            rep++;
                if (!(num%fac))
                        continue;
                else
                {
                        std::cout << fac << "^" << rep << std::endl;
                        rep = 0;
                }
        }
        (fac == 2)? fac++ :
                    fac += 2;

    }
     std::cout << num << "^" << (rep+1)? rep : 1;
}

void factores_primos(Long num)
{
    int fac = 2;
    if( !(num%fac) )
    {
        std::cout << fac << std::endl;
        num /= fac;
        fac++;
    }

    while(fac <= sqrt(num))
    {
        if( !(num%fac) )
            {
                std::cout << fac << std::endl;
                num = num/fac;
            }
        fac+=2;
    }

}

void descomprimir_factores2(Long num)
{
    if( !(num%2) ) std::cout << 2 << std::endl;

    long long raiz = sqrt(num);
    long long i=3;
    for(; i <= raiz; i+=2)
            if( !(num%i) && is_primo(i) )
                std::cout << i << std::endl;

}

void iterar1(int num)
{

    for(int i = 0, j =1; i < num; j++)
        {
            cout << i << "\t" << j%num << endl;
            if( !(j%20) ) i++, j=0;
        }

}

void iterar2(int num)
{
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
                cout << i << "\t" << j << endl;
}


 int64_t meh = GetTimeMs64();
    iterar1(10000);
    int64_t fack = GetTimeMs64();
    cout << fack-meh << endl;

    meh = GetTimeMs64();
    iterar2(10000);
    fack = GetTimeMs64();
    cout << fack-meh;




void messure_code(void(*p_function)(Long), Long num)
{
    clock_t start = clock();
    p_function(num);
    std::cout << std::endl << (clock() - start)/(double)CLOCKS_PER_SEC << std::endl << std::endl;

}

void messure_code(long long(*p_function)(Long), Long num)
{
    clock_t start = clock();
    std::cout << p_function(num);
    std::cout << std::endl << (clock() - start)/(double)CLOCKS_PER_SEC << std::endl << std::endl;

}


int main()
{
    messure_code(descomprimir_factores,  std::numeric_limits<Long>::max() );
    //messure_code(descomprimir_factores2, std::numeric_limits<Long>::max() );
    messure_code(factores_primos, std::numeric_limits<Long>::max() );


    //messure_code(is_primo, std::numeric_limits<long long>::max() );
    //messure_code(is_primo2, std::numeric_limits<long long>::max() );

    return 0;
}
*/
