/*
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef std::map<long long, long long> mapita;

long long collatz(long long num, long long i=0)
{
    return (num == 1)? i : (!(num&1))? collatz(num/2, ++i) : collatz((3*num)+1, ++i);

}

bool value_comparer(mapita::value_type
                    &i1, mapita::value_type &i2)
{
return i1.second<i2.second;
}


int main()
{
    mapita chain_len;

    for(int i=1; i < 1e6; i++)
     {
        chain_len[i] = collatz(i);
     }

    mapita::iterator it = max_element(chain_len.begin(), chain_len.end(), value_comparer);

    cout << it->first << "-> " << it->second << endl;
    return 0;
}



*/
