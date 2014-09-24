#include <iostream>
#include <sstream>

int dividir(double *num)
{
        std::stringstream ss;
        int entero = *num, count;

        *num -= entero;
        ss << *num;
        count = ss.str().size()-2;

        for(int i = 0; i < count; i++)
                *num *= 10;

        return entero;
}

void meh(int *numero, int val)
{
    std::cout << "Papeletas de " << val << ": " << (int)(*numero)/val << std::endl;
    *numero %= val;

}

int main()
{
    int entero;
    double numero;
    std::cout << "> "; std::cin >> numero;

    entero = dividir(&numero);

    meh(&entero, 1000);
    meh(&entero, 500);
    meh(&entero, 20);
    meh(&entero, 5);
    meh(&entero, 1);
    entero = (int)numero;
    meh(&entero, 25);
    meh(&entero, 10);
    meh(&entero, 5);
    meh(&entero, 1);

    return 0;

}


