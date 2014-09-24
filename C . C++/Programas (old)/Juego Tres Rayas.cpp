#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
   
int Pausa(int e){
    
    long tmi = clock() + e;
    while(clock() < tmi);
}
   
string jsino;
string numero;
string jugador;
string a1=" ",a2=" ",a3=" ";
string b1=" ",b2=" ",b3=" ";
string c1=" ",c2=" ",c3=" ";
int comienzo = 1;



int raya();


//cierta inteligencia 8-)

int enemigo(){
      //ATAKE a traves :S
    if(a1 == "O" && b2 == "O" && c3 != "X" && c3 != "O"){c3 = "O";raya();}
    if(b2 == "O" && c3 == "O" && a1 != "X" && a1 != "O"){a1 = "O";raya();}
    if(a1 == "O" && c3 == "O" && b2 != "X" && b2 != "O"){b2 = "O";raya();}
    if(a3 == "O" && b2 == "O" && c1 != "X" && c1 != "O"){c1 = "O";raya();}
    if(b2 == "O" && c1 == "O" && a3 != "X" && a3 != "O"){a3 = "O";raya();}
    if(a3 == "O" && c1 == "O" && b2 != "X" && b2 != "O"){b2 = "O";raya();}
    
   //ATAKE EN HORIZONTAL
    if(a1 == "O" && a2 == "O" && a3 != "O" && a3 != "X"){a3 = "O";raya();}
    if(b1 == "O" && b2 == "O" && b3 != "O" && b3 != "X"){b3 = "O";raya();}
    if(c1 == "O" && c2 == "O" && c3 != "O" && c3 != "X"){c3 = "O";raya();}
    if(a2 == "O" && a3 == "O" && a1 != "O" && a1 != "X"){a1 = "O";raya();}
    if(b2 == "O" && b3 == "O" && b1 != "O" && b1 != "X"){b1 = "O";raya();}
    if(c2 == "O" && c3 == "O" && c1 != "O" && c1 != "X"){c1 = "O";raya();}
    if(a1 == "O" && a3 == "O" && a2 != "O" && a2 != "X"){a2 = "O";raya();}
    if(b1 == "O" && b3 == "O" && b2 != "O" && b2 != "X"){b2 = "O";raya();}
    if(c1 == "O" && c3 == "O" && c2 != "O" && c2 != "X"){c2 = "O";raya();}
    //ATAKE EN VERTICAL
    if(a1 == "O" && b1 == "O" && c1 != "O" && c1 != "X"){c1 = "O";raya();}
    if(a2 == "O" && b2 == "O" && c2 != "O" && c2 != "X"){c2 = "O";raya();}
    if(a3 == "O" && b3 == "O" && c3 != "O" && c3 != "X"){c3 = "O";raya();}
    if(b1 == "O" && c1 == "O" && a1 != "O" && a1 != "X"){a1 = "O";raya();}
    if(b2 == "O" && c2 == "O" && a2 != "O" && a2 != "X"){a2 = "O";raya();}
    if(b3 == "O" && c3 == "O" && a3 != "O" && a3 != "X"){a3 = "O";raya();}
    if(c1 == "O" && a1 == "O" && b1 != "O" && b1 != "X"){b1 = "O";raya();}
    if(c2 == "O" && a2 == "O" && b2 != "O" && b2 != "X"){b2 = "O";raya();}
    if(c3 == "O" && a3 == "O" && b3 != "O" && b3 != "X"){b3 = "O";raya();}
    //otra jugada de *****
    if(b1 == "X" && a3 == "X" && b2 == "O" && a1 != "X" && a1 != "O"){a1 ="O";raya();}
    if(b1 == "X" && a3 == "X" && b2 == "O" && a1 == "O" && c3 == "X" && b3 != "X" && b3 != "O"){b3 = "O";raya();}
    //bug
    if(a2 == "X" && c3 == "X" && b2 == "O" && a3 != "X" && a3 != "O"){a3 = "O";raya();}
    //jugada de ***** O_o a
    if(a2 == "X" && c1 == "X" && b2 == "O" && b1 != "X" && b1 != "O"){b1 = "O";raya();}
    if(a2 == "X" && b1 == "O" && b2 == "O" && b3 == "X" && c1 == "X" && a3 != "X" && a3 != "O"){a3 = "O";raya();}
    //jugada de ***** O_o b
    if(b1 == "X" && b2 == "O" && c3 == "X" && c2 != "X" && c2 != "O"){c2 = "O";raya();}
    if(a2 == "X" && b1 == "O" && b2 == "O" && b3 == "X" && c1 == "X" && a3 != "X" && a3 != "O"){a3 = "O";raya();}
    
    //jugada5
    if(a1 == "X" && c3 == "X" && a2 != "X" && a2 != "O"){a2 = "O";raya();}
    if(a3 == "X" && c1 == "X" && b1 != "X" && b1 != "O"){b1 = "O";raya();}  
    
    //verticales dobles
    if(a1 == "X" && b1 == "X" && c1 != "O" && c1 != "X"){c1 = "O";raya();}
    if(a2 == "X" && b2 == "X" && c2 != "O" && c2 != "X"){c2 = "O";raya();}
    if(a3 == "X" && b3 == "X" && c3 != "O" && c3 != "X"){c3 = "O";raya();}
    if(b1 == "X" && c1 == "X" && a1 != "O" && a1 != "X"){a1 = "O";raya();}
    if(b2 == "X" && c2 == "X" && a2 != "O" && a2 != "X"){a2 = "O";raya();}
    if(b3 == "X" && c3 == "X" && a3 != "O" && a3 != "X"){a3 = "O";raya();}
    if(c1 == "X" && a1 == "X" && b1 != "O" && b1 != "X"){b1 = "O";raya();}
    if(c2 == "X" && a2 == "X" && b2 != "O" && b2 != "X"){b2 = "O";raya();}
    if(c3 == "X" && a3 == "X" && b3 != "O" && b3 != "X"){b3 = "O";raya();} 
     //horizontales dobles
    if(a1 == "X" && a2 == "X" && a3 != "O" && a3 != "X"){a3 = "O";raya();}
    if(b1 == "X" && b2 == "X" && b3 != "O" && b3 != "X"){b3 = "O";raya();}
    if(c1 == "X" && c2 == "X" && c3 != "O" && c3 != "X"){c3 = "O";raya();}
    if(a2 == "X" && a3 == "X" && a1 != "O" && a1 != "X"){a1 = "O";raya();}
    if(b2 == "X" && b3 == "X" && b1 != "O" && b1 != "X"){b1 = "O";raya();}
    if(c2 == "X" && c3 == "X" && c1 != "O" && c1 != "X"){c1 = "O";raya();}
    if(a1 == "X" && a3 == "X" && a2 != "O" && a2 != "X"){a2 = "O";raya();}
    if(b1 == "X" && b3 == "X" && b2 != "O" && b2 != "X"){b2 = "O";raya();}
    if(c1 == "X" && c3 == "X" && c2 != "O" && c2 != "X"){c2 = "O";raya();}       
                
     //a traves :S
    if(a1 == "X" && b2 == "X" && c3 != "X" && c3 != "O"){c3 = "O";raya();}
    if(b2 == "X" && c3 == "X" && a1 != "X" && a1 != "O"){a1 = "O";raya();}
    if(a1 == "X" && c3 == "X" && b2 != "X" && b2 != "O"){b2 = "O";raya();}
    if(a3 == "X" && b2 == "X" && c1 != "X" && c1 != "O"){c1 = "O";raya();}
    if(b2 == "X" && c1 == "X" && a3 != "X" && a3 != "O"){a3 = "O";raya();}
    if(a3 == "X" && c1 == "X" && b2 != "X" && b2 != "O"){b2 = "O";raya();}
    //variadas jugadas y posibles fallos
    if(a1 == "O" && a2 == "X" && a3 == "X" && b1 == "X" && b2 == "O" && b3 == "O" && c3 == "X" && c2 != "X" && c2 != "O"){c2 = "O";raya();}
    
    if(a2 == "X" && b1 == "X" && a1 == "O" && b2 == "O" && c3 == "X" && b3 != "X" && b3 != "O"){b3 = "O";raya();}
    
    if(a1 == "O" && a2 == "X" && b1 == "X" && b2 == "X" && b3 == "O" && c2 == "O" && c3 == "X" && c1 != "O" && c1 != "X"){c1 == "O";raya();}
    
    //jugada
    if(a3 == "X" && b1 == "X"  && b3 != "X" && b3 != "O"){b3 = "O"; raya();}
    if(c3 == "X" && b1 == "X"  && b3 != "X" && b3 != "O"){b3 = "O"; raya();}
    if(a2 == "X" && c1 == "X"  && c2 != "X" && c2 != "O"){c2 = "O"; raya();}
    if(a2 == "X" && c3 == "X"  && c2 != "X" && c2 != "O"){c2 = "O"; raya();}
    //jugada2 
    if(c2 == "X" && a1 == "X" && a3 == "X" && c1 != "X" && c1 != "O"){ c1 = "O"; raya();}
    if(b3 == "X" && a1 == "X" && c1 == "X" && c3 != "X" && c3 != "O"){ c3 = "O"; raya();}
    if(a2 == "X" && c1 == "X" && c3 == "X" && a3 != "X" && a3 != "O"){ a3 = "O"; raya();}
    if(b1 == "X" && c3 == "X" && a3 == "X" && a1 != "X" && a1 != "O"){ a1 = "O"; raya();}
    //jugada3
    if(a2 == "X" && c2 == "X" && b1 != "X" && b1 != "O"){b1 = "O";raya();}
    if(b1 == "X" && b3 == "X" && a2 != "X" && a2 != "O"){a2 = "O";raya();}
    //jugada4
    if(b1 == "X" && c2 == "X" && b3 == "X" && c3 != "O" && c3 != "X"){c3 = "O";raya();}
    if(b3 == "X" && a2 == "X" && c2 == "X" && a3 != "O" && a3 != "X"){a3 = "O";raya();}
     
    //jugada6
    if(a2 == "X" && b1 == "X" && b2 == "O" && a1 != "O" && a1 != "X"){a1 = "O";raya();}
    if(a2 == "X" && b3 == "X" && b2 == "O" && a3 != "O" && a3 != "X"){a3 = "O";raya();}
    if(b3 == "X" && c2 == "X" && b2 == "O" && c3 != "O" && c3 != "X"){c3 = "O";raya();}
    if(b1 == "X" && c2 == "X" && b2 == "O" && c1 != "O" && c1 != "X"){c1 = "O";raya();}           
    
   
        
   
    
    
    if(comienzo == 1){
    //comienzo
   if(b2 == "X" && b2 != "X" && b2 != "O"){a1 = "O";comienzo = 0; raya();}
   if(a1 == "X" || a3 == "X" || c1 == "X" || c3 == "X" && b2 != "X" && b2 != "O"){b2 = "O";comienzo = 0; raya();} 
   if(a2 == "X" || b1 == "X" || b3 == "X" || c2 == "X" && b2 != "X" && b2 != "O"){b2 = "O";comienzo = 0; raya();}
}
    
    
   //restantes
   if(a1 != "X" && a1 != "O" && a1 != "X"){a1 = "O"; raya();}
   if(a2 != "X" && a2 != "O" && a2 != "O"){a2 = "O"; raya();} 
   if(a3 != "X" && a3 != "O" && a3 != "O"){a3 = "O"; raya();} 
   if(b1 != "X" && b1 != "O" && b1 != "O"){b1 = "O"; raya();}
   if(b2 != "X" && b2 != "O" && b2 != "O"){b2 = "O"; raya();}
   if(b3 != "X" && b3 != "O" && b3 != "O"){b3 = "O"; raya();}
   if(c1 != "X" && c1 != "O" && c1 != "O"){c1 = "O"; raya();}
   if(c2 != "X" && c2 != "O" && c2 != "O"){c2 = "O"; raya();}
   if(c3 != "X" && c3 != "O" && c3 != "O"){c3 = "O"; raya();}
    
}

int resultado(){
    textcolor(WHITE);
    cout << "\n\n\n\n\n\n                                  1     2     3\n";
    textcolor(LIGHTGREEN);
    cout << "                               \xC9\xcD\xcd\xCD\xCD\xCD\xCB\xcd\xcd\xCD\xCD\xCD\xCB\xcd\xcd\xCD\xCD\xCD\xBB\n";
    textcolor(WHITE);cout <<
            "                             A ";textcolor(LIGHTGREEN);cout << "\xba  ";textcolor(LIGHTRED);if(a1 == "O"){
                                          textcolor(LIGHTBLUE);}cout << a1;
                                          ;textcolor(LIGHTGREEN);cout << "  \xba  ";textcolor(LIGHTRED);if(a2 == "O"){
                                          textcolor(LIGHTBLUE);}cout << a2;textcolor(LIGHTGREEN);cout << "  \xba  ";textcolor(LIGHTRED);if(a3 == "O"){
                                          textcolor(LIGHTBLUE);}cout << a3;textcolor(LIGHTGREEN);cout << "  \xba\n"
            "                               \xcc\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xb9\n";
    textcolor(WHITE);cout <<
            "                             B ";textcolor(LIGHTGREEN);cout <<"\xba  ";textcolor(LIGHTRED);if(b1 == "O"){
                                          textcolor(LIGHTBLUE);}cout << b1;textcolor(LIGHTGREEN);cout  << "  \xba  ";textcolor(LIGHTRED);if(b2 == "O"){
                                          textcolor(LIGHTBLUE);}cout << b2;textcolor(LIGHTGREEN);cout << "  \xba  ";textcolor(LIGHTRED);if(b3 == "O"){
                                          textcolor(LIGHTBLUE);}cout << b3;textcolor(LIGHTGREEN);cout << "  \xba\n"
            "                               \xcc\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xb9\n";
    textcolor(WHITE);cout <<
            "                             C ";textcolor(LIGHTGREEN);cout <<"\xba  ";textcolor(LIGHTRED);if(c1 == "O"){
                                          textcolor(LIGHTBLUE);}cout << c1;textcolor(LIGHTGREEN);cout  << "  \xba  ";textcolor(LIGHTRED);if(c2 == "O"){
                                          textcolor(LIGHTBLUE);}cout << c2;textcolor(LIGHTGREEN);cout << "  \xba  ";textcolor(LIGHTRED);if(c3 == "O"){
                                          textcolor(LIGHTBLUE);}cout << c3;textcolor(LIGHTGREEN);cout << "  \xba\n"
            "                               \xc8\xCD\xcd\xcd\xCD\xCD\xCa\xcd\xcd\xCD\xCD\xCD\xCa\xcd\xcd\xCD\xCD\xCD\xBc\n";
            textcolor(WHITE);
            cout << jugador << endl;
            Pausa(1);
            sino:
            textcolor(LIGHTCYAN);
            cout << "\n                              Otra Partida (si/no)";
            a1=" ",a2=" ",a3=" ";
            b1=" ",b2=" ",b3=" ";
            c1=" ",c2=" ",c3=" ";
            comienzo = 1;
            textcolor(YELLOW);
            cin >> jsino;
            if(jsino != "si" && jsino != "no"){
                     textcolor(LIGHTMAGENTA);
                     cout << "\n                                 Escoge Si o No...\n";
                     Pausa(50);
                     goto sino;
                     }
            if(jsino == "si"){
                     Pausa(20);                     
                     raya();
                     }
            if(jsino == "no"){
                     Pausa(20);
                     textcolor(LIGHTRED);
                     cout << "\n                                    Saliendo...";
                     Pausa(100);
                     clrscr();
                     cout << "\n\n";
                     abort();
                     
                     }
                     
            
            }
            
 
int raya(){
    clrscr();
    if(a1 == "O" && a2 == "O" && a3 == "O" ||
               b1 == "O" && b2 == "O" && b3 == "O" ||
               c1 == "O" && c2 == "O" && c3 == "O" ||
               a1 == "O" && b1 == "O" && c1 == "O" ||
               a2 == "O" && b2 == "O" && c2 == "O" ||
               a3 == "O" && b3 == "O" && c3 == "O" ||
               a1 == "O" && b2 == "O" && c3 == "O" ||
               c1 == "O" && b2 == "O" && a3 == "O"){
                     jugador = "\n                                   Has Perdido\n";
                     clrscr();
                     resultado();
                     }
    textcolor(WHITE);
    cout << "\n\n\n\n\n\n                                  1     2     3\n";
    textcolor(LIGHTGREEN);
    cout << "                               \xC9\xcD\xcd\xCD\xCD\xCD\xCB\xcd\xcd\xCD\xCD\xCD\xCB\xcd\xcd\xCD\xCD\xCD\xBB\n";
    textcolor(WHITE);cout <<
            "                             A ";textcolor(LIGHTGREEN);cout << "\xba  ";textcolor(LIGHTRED);if(a1 == "O"){
                                          textcolor(LIGHTBLUE);}cout << a1;
                                          ;textcolor(LIGHTGREEN);cout << "  \xba  ";textcolor(LIGHTRED);if(a2 == "O"){
                                          textcolor(LIGHTBLUE);}cout << a2;textcolor(LIGHTGREEN);cout << "  \xba  ";textcolor(LIGHTRED);if(a3 == "O"){
                                          textcolor(LIGHTBLUE);}cout << a3;textcolor(LIGHTGREEN);cout << "  \xba\n"
            "                               \xcc\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xb9\n";
    textcolor(WHITE);cout <<
            "                             B ";textcolor(LIGHTGREEN);cout <<"\xba  ";textcolor(LIGHTRED);if(b1 == "O"){
                                          textcolor(LIGHTBLUE);}cout << b1;textcolor(LIGHTGREEN);cout  << "  \xba  ";textcolor(LIGHTRED);if(b2 == "O"){
                                          textcolor(LIGHTBLUE);}cout << b2;textcolor(LIGHTGREEN);cout << "  \xba  ";textcolor(LIGHTRED);if(b3 == "O"){
                                          textcolor(LIGHTBLUE);}cout << b3;textcolor(LIGHTGREEN);cout << "  \xba\n"
            "                               \xcc\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xb9\n";
    textcolor(WHITE);cout <<
            "                             C ";textcolor(LIGHTGREEN);cout <<"\xba  ";textcolor(LIGHTRED);if(c1 == "O"){
                                          textcolor(LIGHTBLUE);}cout << c1;textcolor(LIGHTGREEN);cout  << "  \xba  ";textcolor(LIGHTRED);if(c2 == "O"){
                                          textcolor(LIGHTBLUE);}cout << c2;textcolor(LIGHTGREEN);cout << "  \xba  ";textcolor(LIGHTRED);if(c3 == "O"){
                                          textcolor(LIGHTBLUE);}cout << c3;textcolor(LIGHTGREEN);cout << "  \xba\n"
            "                               \xc8\xCD\xcd\xcd\xCD\xCD\xCa\xcd\xcd\xCD\xCD\xCD\xCa\xcd\xcd\xCD\xCD\xCD\xBc\n";
            textcolor(WHITE);             
            cout << "\n                            Seleccion : ";
            textcolor(YELLOW);
            cin >> numero;
            
         if(numero == "a1" &&( a1 == "X" || a1 == "O")||
            numero == "a2" &&( a2 == "X" || a2 == "O")||
            numero == "a3" &&( a3 == "X" || a3 == "O")||
            numero == "b1" &&( b1 == "X" || b1 == "O")||
            numero == "b2" &&( b2 == "X" || b2 == "O")||
            numero == "b3" &&( b3 == "X" || b3 == "O")||
            numero == "c1" &&( c1 == "X" || c1 == "O")||
            numero == "c2" &&( c2 == "X" || c2 == "O")||
            numero == "c3" &&( c3 == "X" || c3 == "O")){
                   textcolor(LIGHTMAGENTA);
                   cout << "\a\n                                 Ya Selecionado.";
                   Pausa(100);
                   raya();
                   }
        
         if(numero != "a1" &&
            numero != "a2" &&
            numero != "a3" &&
            numero != "b1" &&
            numero != "b2" &&
            numero != "b3" &&
            numero != "c1" &&
            numero != "c2" &&
            numero != "c3"){
                      textcolor(LIGHTMAGENTA);
                      cout << "\a\n                              Seleccion Incorrecta.";
                      Pausa(100);
                      raya();
                      }
                      
                      
                      
                      
            if(numero == "quit" || numero == "exit"){
                      cout << "Saliendo del 3 en raya..\n";
                      Pausa(100);
                      clrscr();                      
                      cout << "Pulse 'help' para ayuda.\n\n";
                      abort();
                      
                      
                      }
                      
            if(numero == "a1" && a1 != "X" && a1 != "O")a1 = "X";
            if(numero == "a2" && a2 != "X" && a2 != "O")a2 = "X";
            if(numero == "a3" && a3 != "X" && a3 != "O")a3 = "X";
            if(numero == "b1" && b1 != "X" && b1 != "O")b1 = "X";
            if(numero == "b2" && b2 != "X" && b2 != "O")b2 = "X";
            if(numero == "b3" && b3 != "X" && b3 != "O")b3 = "X";
            if(numero == "c1" && c1 != "X" && c1 != "O")c1 = "X";
            if(numero == "c2" && c2 != "X" && c2 != "O")c2 = "X";
            if(numero == "c3" && c3 != "X" && c3 != "O")c3 = "X";
            
            if(a1 == "X" && a2 == "X" && a3 == "X" ||
               b1 == "X" && b2 == "X" && b3 == "X" ||
               c1 == "X" && c2 == "X" && c3 == "X" ||
               a1 == "X" && b1 == "X" && c1 == "X" ||
               a2 == "X" && b2 == "X" && c2 == "X" ||
               a3 == "X" && b3 == "X" && c3 == "X" ||
               a1 == "X" && b2 == "X" && c3 == "X" ||
               c1 == "X" && b2 == "X" && a3 == "X"){
                     jugador = "\n                                    Has Ganado\n";
                     clrscr();
                     resultado();
                     }
            
                     if(a1 != " " && 
               b1 != " " && 
               c1 != " " && 
               a2 != " " && 
               b2 != " " && 
               c2 != " " && 
               a3 != " " &&
               b3 != " " && 
               c3 != " " ){
                     jugador = "\n                                      Empate\n";
                     clrscr();
                     resultado();
                     }                           
                                      
            enemigo();
                       
            }            

int main(){
    raya();
}
