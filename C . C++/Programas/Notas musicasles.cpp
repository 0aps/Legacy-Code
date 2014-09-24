#include <stdio.h>
#define getchar() fgetc(stdin)
#define DESPL     69
#define INIT_ARRAY(x) x['W'-DESPL]=0x40;x['H'-DESPL]=0x20;x['Q'-DESPL]=0x10;x['E'-DESPL]=0x8;x['S'-DESPL]=0x4;x['T'-DESPL]=0x2;x['X'-DESPL]=0x1;
int main(){
    unsigned int caracter, duracion=0;
    unsigned int  compasesValidos=0;
    unsigned char array[20]; /*si, es una brutalidad... pero es brutalmente rapido :-P*/
    char outputBuffer[BUFSIZ];
    char inputBuffer[BUFSIZ];
    int llenoBuff=0;
    int i=0;
    setbuf(stdout, outputBuffer); /*esto para mostrar*/
 
    INIT_ARRAY(array);
    fread(inputBuffer, sizeof(unsigned char), BUFSIZ, stdin);
    caracter=inputBuffer[i++];
 
    do{
        switch (caracter){
            case '/':
                if(duracion==0x40){
                    compasesValidos++;
                }
                duracion=0;
                break;
            case '\n':
                llenoBuff+=3;  
                if(llenoBuff>=BUFSIZ){
                    llenoBuff=3;
                    fflush( stdout );
                }
                printf("%d\n", compasesValidos);
                compasesValidos=0;
                duracion=0;break;
                i=0;
            default:
                duracion+=array[caracter-DESPL];
                break;
        }
        if(i>=BUFSIZ){
            fread(inputBuffer, sizeof(unsigned char), BUFSIZ, stdin);
            i=0;
 
        }
        caracter=inputBuffer[i++];
    }while (caracter!='*');
 
 
return 0;
}
