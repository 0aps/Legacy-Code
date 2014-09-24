/*
#include <stdio.h>
#include <inttypes.h>
#include <iostream>
#include <stdexcept>
#include <limits>

    unsigned nChoosek( unsigned n, unsigned k )
    {
    if (k > n) return 0;
    if (k * 2 > n) return k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
    result *= (n-i+1);
    result /= i;
    }
    return result;
    }

//this is essencially the same thing as
// C600,3 where 600!/3!(600-3)! = 600!/3!(597)!
// Where 597! cancels out. And you just multiplies by 600*599*598
//and divide by 3*2*1
    uint64_t Combinations(unsigned int n, unsigned int k)
{
     if (k > n)
         return 0;
     uint64_t r = 1;
     for (unsigned int d = 1; d <= k; ++d)
     {
         r *= n--;
         r /= d;
     }
     return r;
}


    #include <stdio.h>

    int main(void)
    {
    std::cout << nChoosek(40,20) << std::endl;
    printf("600 choose 3 is: %I64u \n", choose(40, 20));
    return 0;
    }
*/
