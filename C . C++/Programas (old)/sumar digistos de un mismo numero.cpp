#include <stdio.h>
 
int procesar( int num );
 
int main()
{
    int num;
 
    printf( "ingrese un numero: " );
    scanf( "%d", &num );
 
    printf( "\nsuma = %d\n", procesar( num ) );
    getchar();getchar();
    return 0;
}
 
 
int procesar( int num )
{
    static int acumulador = 0;
 
    if( num > 0  )
    {            
        acumulador += num%10;
        procesar( num /= 10 );
    }
    return acumulador;
}
