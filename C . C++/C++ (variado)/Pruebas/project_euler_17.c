#include <iostream>

using std::cout;
using std::string;

int main()
{
    string numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                        "seventeen", "eighteen", "nineteen"},
           decenas[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",
                        "ninety"},
           centenas("hundredand");



    int sum_1_9 = 0, sum_11_19(0), sum_20_99(0), sum_100_999(0);
    for(int i = 0; i < sizeof(numbers)/sizeof(string); i++)
    {
        if(i < 9) sum_1_9 += numbers[i].size();
        else
             sum_11_19 += numbers[i].size();
    }

    for(int i = 0; i < 8; i++) sum_20_99 += decenas[i].size()*10 + sum_1_9;

    for(int i = 0; i < 9; i++)
    {
        sum_100_999 +=  numbers[i].size() + (centenas.size()-3);
        sum_100_999 += (numbers[i].size()*99) + (centenas.size()*99) + sum_1_9 + sum_11_19 + sum_20_99;
    }

    cout << "Total: " << sum_1_9+sum_11_19+sum_20_99+sum_100_999+11;

    return 0;

}
