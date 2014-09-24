#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
    char Caracter[200],s;
    double W=1,H=0.5,Q=0.25,E=0.125,S=0.0625,T=0.03125,X=0.015625,TOTAL=0;
    int i = 0,LC,Conteo=0;
    s='j';
 while(s !='*'){
    cin>>Caracter;
    s = Caracter[0];
    LC = strlen(Caracter);
    while(i<LC){
        switch(Caracter[i]){
            case 'W':
            TOTAL+=W;
            break;
            case 'H':
            TOTAL+=H;
            break;
            case 'Q':
            TOTAL+=Q;
            break;
            case 'E':
            TOTAL+=E;
            break;
            case 'S':
            TOTAL+=S;
            break;
            case 'T':
            TOTAL+=T;
            break;
            case 'X':
            TOTAL+=X;
            break;
            case '/':
            if(TOTAL==1){
                Conteo++;
                }
            TOTAL=0;
            break;
            default:
            TOTAL+=2;
            break;
            }
            i++;
    }
    if (s!='*'){cout<<Conteo<<endl;
    Conteo=0;
    i=0;}
    }
    return 0;
}
