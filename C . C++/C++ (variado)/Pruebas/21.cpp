#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string sTorn;
    int n,average(0);
    
    cin >> sTorn >> n;
    
    {
       string players[n];
       int ra[n],k[n];
       double w[n],we[n];
    
       int i(0);
       
       for(; n--; i++)
               cin >> players[i] >> ra[i] >> w[i] >> we[i] >> k[i], average+=ra[i];
       
       cout << endl << "Tournament: " << sTorn << endl
            << "Numer of Players: " << i << endl
            << "New ratings: " << endl;
       
       average/=i;
       for(n=0; i--; n++)
               cout << players[n] << " " << (ra[n]+k[n]*(w[n]-we[n])) << endl;
    }
       cout << "Media Elo: " << average << endl;       
    
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
