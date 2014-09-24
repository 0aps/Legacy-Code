


/*#include <iostream>

//el gcd x medio del algoritmo de euclides
//se sustenta en el hecho q el gcd(a,b) == gcd(b,r)
//para todo r | a = q*b + r (o sea q r se el cosciente de a/b)
//esto es que el residuo de a/b siempre es divisible por el mcd(a,b)
//ej: 60%48 = 12, 48%12 = 0, 12 es el mcd.
int gcd(int a, int b)
{
    return (!a)? b : gcd(b%a, a);
}


//el mcm d 2 numeros es un multiplo del mas grande (d ambos actually pero ta ma cerca del segundo)
//so vamo buscando el multiplo q sea divido por el ma bajito, y el primero entonce ese es!
int lcm(int a, int b, int i=1)
{
    return ( !((b*i)%a) )? b*i : lcm(a, b, ++i);
}


int main()
{
    std::cout << "GCD: " << gcd(42,56);
    std:: cout << std::endl << "LCM: " << lcm(2,3);

    std::cout << std::endl << "GCD by lcm: " << (42*56)/lcm(42,56);
    std::cout << std::endl << "LCM by gcd: " << (2*3)/gcd(2,3);

    return 0;


}
*/
