#include <cstdio> 
#include <cstdlib> 
#include <iostream>

int main()
{
    int celsius, factor, fahrenheit;
    printf("Enter the temperature in celcius: ");
    scanf("%i", &celsius);
factor = 212 - 32;
fahrenheit = factor * celsius/100 + 32;

printf("\nFahrenheit value is: %i\n\n", fahrenheit);
system("pause");
return 0;
}
