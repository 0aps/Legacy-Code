#include <iostream>
#include <algorithm>
#include <sstream>

#include <math.h>

using namespace std;

/*
      a       (1)
      aa      (2)
      aba     (3)
      abba    (4)
      abcba   (5)
      abccba  (6)
      abcdcba (7)

      FR = BR^-1
*/


int sInverso(int n){
    stringstream ss;
    ss << n;
    string str(ss.str());
    string p = str;
    reverse(str.begin(), str.end());
    return (p == str);
}

//fr = cifras/2-1 //final
//if( cifras%1 ) br = cifras/2+1 else br = cifras/2 //principio
   

string n_capicua(string num)
{
//    int cifras = string.length();
//    if(cifras == 1 || string != "9" ) return atoi( num.c_str() )+1;
      
    string p = num;
    reverse(str.begin(), str.end());
    return (p == str);
}         
    

       


int main()
{
    int n,k,aux;
    string str;
    cin >> n;
    
    while(n--)
    {
              //cin >> k;                     
              getline(cin, str);
              //for(aux=k+1; !sInverso(aux); aux++);
              for(aux=k+1; !sInverso(aux); aux++);
              cout << n_capicua(str) << endl;
    }
                           
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
