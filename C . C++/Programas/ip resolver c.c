#include <stdio.h>

/*
  Name: Ip Resolver
  Author: @aps
  Date: 29/04/12 18:19
  Description: Resuelve la ip introducida
*/

long potencia(long num, int exp)
{
    for(long ret=1;exp>0;exp--) ret*=num;
    return ret;
}

int main(int argc, char *argv[])
{    
   
    char aux[4][4] = {0};
    unsigned short auxt[8] = { 128, 64, 32, 16, 8, 4, 2, 1};
    unsigned short ip[4],base[4],broadcast[4],mask[4] = {0};
    short x,i,y;
    
    for (x = 0, i = 0, y = 0; argv[1][x]; x++, y++ )
         if(argv[1][x] != '.') aux[i][y] =  argv[1][x];
         else {i++; y=-1;}
      
    for(x = 0; x < 4; x++ )
    {
         ip[x]  = atoi(aux[x]);
         if(ip[x] > 255){ printf("Coloque una ip valida.\n"); return 1; }
    }    
    if ( atoi(argv[2]) > 32 ){ printf("Coloque una mascara valida.\n"); return 1; }
    
       for( x = 0; x < atoi(argv[2]); x++ ) 
           {
               
             if( x < 8 )
             mask[0] += auxt[x]; 
                  
             if( x == 8   )// x > 8
                 for(y = 0; y < atoi(argv[2])-8 && y < 8 ; y++ ) 
                    mask[1] += auxt[y];
    
             if( x == 16 )// x > 16
                 for(y = 0; y < atoi(argv[2])-16 && y < 8; y++ ) 
                    mask[2] += auxt[y]; 
            
             if( x == 24 )// x > 24 
                 for( y = 0; y < atoi(argv[2])-24 && y < 8; y++ ) 
                    mask[3] += auxt[y];
           }   
                     
         
    printf("\nIP: %s\n", argv[1]);
    printf("Mascara: %s ( ", argv[2]);
            for( x = 0; x < 4; x++ )
            { 
             printf("%d", mask[x]); 
             if(x == 3)printf(" )\n\n"); else printf("."); 
            } 
            
    
    for( x = 0; x < 4; x++ )  
      {
        base[x] = ip[x] & mask[x];
        broadcast[x] = (ip[x]|~ mask[x]);
      } 
    
    printf("Base: "); 
      for( x = 0; x < 4; x++ )
            { 
             printf("%d", base[x]); 
             if(x == 3)printf("\n"); else printf("."); 
            }    
    
    printf("Broadcast: ");
      for(x = 0; x < 4; x++ )
            { 
             printf("%#x", broadcast[x]); 
             if(x == 3)printf("\n\n"); else printf("."); 
            } 
    
   printf("Primer host: ");
      for(x = 0; x < 4; x++ )
            {
             if(x == 3)base[x]++;     
             printf("%d", base[x]); 
             if(x == 3) printf("\n"); else printf("."); 
            } 
    
    printf("Ultimo host: ");
     for(x = 0; x < 4; x++ )
            { 
             if(x == 3) broadcast[x]--; 
             printf("%d", broadcast[x]); 
             if(x == 3) printf("\n\n"); else printf("."); 
            }    
            
      printf("Numero de host disponibles: %d ", potencia(2,7)- );
    
    setbuf(stdin, 0);

    return 0;
}
