#include <iostream>

bool leep_year(int year)
{
    if( !(year%100) && !(year%400) )
    {
        return true;
    }else if( !(year%4) )
    {
        return true;
    }

    return false;

}

int sundays_day_until_year(int *month, int year)
{
    int sunday_january_1990 = 7;


    for(int i = 0; i < (year-1990); i++ )
    {
        for(int j = 0; j < 12;)
        {
           sunday_january_1990 += 7;
           if( sunday_january_1990 > month[j])
            {
               sunday_january_1990 -= month[j];
               j++;
            }

       }
    }

    return sunday_january_1990;
}

int sundays_in_month(int month, int year, int *day_count )
{
    if ( month == 28 && leep_year(year) )
            month = 29;

    while( *day_count < month )
            *day_count += 7;

    *day_count -= month;

    return (*day_count == 1)? 1 : 0;

}



int main()
{
    int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int suma_de_sundays(0), actual_day_count = sundays_day_until_year(months, 1901);

    if( actual_day_count == 1) suma_de_sundays++;
    for(int i=0; i < (2000-1901); i++)
    {
        for(int j=0; j < sizeof(months)/sizeof(int); j++)
                suma_de_sundays += sundays_in_month(months[j], 1991+i, &actual_day_count);
    }

    std::cout << suma_de_sundays << std::endl;

    return 0;
}
