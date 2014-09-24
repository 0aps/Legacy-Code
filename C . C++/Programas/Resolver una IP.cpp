#include <iostream>

using namespace std;

/*
  Name: Ip Resolver
  Author: @aps
  Date: 29/04/12 18:19
  Description: Resuelve la ip introducida
*/

long potencia(long num, int exp, long ret = 1)
{
    for(;exp>0;exp--) ret*=num;
    return ret;
}

int main(int argc, char *argv[])
{    
   
    char aux[4][4] = {0};
    unsigned short auxt[8] = { 128, 64, 32, 16, 8, 4, 2, 1};
    unsigned short ip[4],base[4],broadcast[4],mask[4] = {0};
    
    for (int x = 0, i = 0, y = 0; argv[1][x]; x++, y++ )
         if(argv[1][x] != '.') aux[i][y] =  argv[1][x];
         else {i++; y=-1;}
      
    for(int x = 0; x < 4; x++ )
    {
         ip[x]  = atoi(aux[x]);
         if(ip[x] > 255){ cout << "Coloque una ip valida.\n"; return 1; }
    }    
    if ( atoi(argv[2]) > 32 ){ cout << "Coloque una mascara valida.\n"; return 1; }
    
       for(int x = 0; x < atoi(argv[2]); x++ ) 
           {
               
             if( x < 8 )
             mask[0] += auxt[x]; 
                  
             if( x == 8   )// x > 8
                 for(int x = 0; x < atoi(argv[2])-8 && x < 8 ; x++ ) 
                    mask[1] += auxt[x];
    
             if( x == 16 )// x > 16
                 for(int x = 0; x < atoi(argv[2])-16 && x < 8; x++ ) 
                    mask[2] += auxt[x]; 
            
             if( x == 24 )// x > 24 
                 for(int x = 0; x < atoi(argv[2])-24 && x < 8; x++ ) 
                    mask[3] += auxt[x];
           }   
                     
         
    cout << "\nIP: " << argv[1] << endl;
    cout << "Mascara: " << argv[2] << " (";
            for(int x = 0; x < 4; x++ )
            {  
             cout << mask[x] << ( x == 3 ? ")\n\n" : "." );
            } 
            
    //////////aca
    for(int x = 0; x < 4; x++ )  
      {
        base[x] = ip[x] & mask[x];
        broadcast[x] = (ip[x]| ~mask[x]);
      } 
   /////////////aca
 
       
    
    cout << "Base: "; 
    for(int x = 0; x < 4; x++ )
    cout << base[x] << ( x == 3 ? "\n" : "." );
     
    
    cout << "BroadCast: ";
    for(int x = 0; x < 4; x++ ) 
    cout << broadcast[x] << ( x == 3 ? "\n\n" : "." );
    
    cout << "Primer host: ";
    for(int x = 0; x < 4; x++ )
    {  
     if(x == 3) base[x]++;
     cout << base[x] << ( x == 3 ? "\n" : "." );
    }
    
    cout << "Ultimo host: ";
    for(int x = 0; x < 4; x++ )
    {
     if(x == 3) broadcast[x]--;  
     cout << broadcast[x] << ( x == 3 ? "\n" : "." );
    }
    
    
    setbuf(stdin, 0);
    return 0;
}
