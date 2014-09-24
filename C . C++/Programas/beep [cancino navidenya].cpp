#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include<windows.h>

using namespace std;

void nota1(){
Beep(100,1000);
}                              //Beep(nota,largo nota);
void nota2(){          //Beep(nota = 100-10,000,largo nota = 1-10,000);
Beep(1000,1000);  //Beep(100 = nota aguda,largo nota)
                              //Beep(10000 = nota grave,largo nota)
}
void nota3(){
Beep(10000,1000);
}
void nota4(){
Beep(4000,1000);
}
void nota5(){
Beep(2000,1000);
}                 
void nota6(){    
Beep(3000,1000);  
                  
}
void nota7(){
Beep(4000,1000);
}
void nota8(){
Beep(5000,1000);
}
int main(int argc, char *argv[])
{   
    system("TITLE § Cancion Navideña §     by: .::BLaCKHoLE::.    CPH©");
    for (int i=0;i<=59;i++){
    cout <<"\n\t\t\t   DO ";
    nota1();
    cout <<"RE ";    
    nota2();
    cout <<"MI ";   
    nota3();
    cout <<"FA ";  
    nota4();
    cout <<"SO ";    
    nota5();
    cout <<"LA ";  
    nota6();
    cout <<"SI ";  
    nota7();
    cout <<"DO ";  
    nota8(); 
    system("CLS");          
}    
    return EXIT_SUCCESS;
}
