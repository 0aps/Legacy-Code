#include <iostream>

using namespace std;


   struct empaquetado {
   unsigned short broadcast[4];
   unsigned short mmask[4];
   unsigned char mask:8;
} paquete;


int contbit(unsigned char x)
{
	int count;
	for (count=0; x!=0; x>>=1)
		if ( x & 1)
			count++;
	return count;
}

int main(int argc, char *argv[])
{    
    paquete.mask = 254;
      
    
    for(int x = 0; x < 4; x++ )  
        paquete.mmask[x] = 255;
    
    for(int x = 0; x < 4; x++ )  
        paquete.broadcast[x] =  ~paquete.mmask[x];
        
    cout << "BroadCast: ";
    for(int x = 0; x < 4; x++ )
    {  
     cout << (~paquete.mmask[x]) << ( x == 3 ? "\n" : "." );
    }
    
    
    cout << endl<< endl << contbit(paquete.mask)<< endl;
    cout << contbit(233 | ~paquete.mask)<< endl;
    cout << paquete.mask << endl;
    cout << (192 | ~paquete.mask)<< endl;
     
    cin.get();
    return 0;
    
}
