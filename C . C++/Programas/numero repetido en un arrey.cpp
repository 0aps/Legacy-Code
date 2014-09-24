#include <iostream>

using namespace std;

//numero mas grande de un arrey

int main()
{
    //siete tres
    //cinco cuatros
    //seis seis
    int arrey[30] = { 3,3,3,3,4,4,4,4,6,6,6,6,3,3,3,6,6,4  };
    int *ptn = arrey;
    int veces(0);
        
    for(int x(0); *ptn; x++)
    {
   
            for(int i(0); arrey[i]; i++)
            {
                    if(arrey[x] == arrey[i+1])
                    veces++;
            }
            
    if(arrey[x] != *(ptn-1) )
    cout << "El numero " << arrey[x] << " se repite " << veces  << " veces." << endl;   
    
    *ptn++;
    veces = 0;
    
    }
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
    
                     
           
