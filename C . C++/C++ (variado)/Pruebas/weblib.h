#ifndef _WEBLIB_H_
#define _WEBLIB_H_
 
#include <iostream>
#include <windows.h>
#include <conio.h>
 
using namespace std;
 
typedef struct Lista{
   int c1, p1, f1;
   char c2[15], p2[15], f2[15];
};
 
typedef struct String{
   char s[50];
};
 
int gen_web(Lista &P,String Fr[]){
 
   short i;
   FILE *Arch;
   char dir[50];
   cout << "Ingrese la direccion en la que desea guardar la pagina: " << endl;
   fflush(stdin);
   cin.getline(dir, 50);
   fflush(stdin);
   Arch = fopen(dir, "wt");
   if (Arch == NULL){
   
      cout << "ATENCION!............ Hubo un error al crear la pagina." << endl;
   
   }
   else{
       
    fprintf(Arch,"<html> \n");
    fprintf(Arch,"<head>\n");
    fprintf(Arch,"<title> CONTADOR DE PALABRAS, FRASES Y CARACTERES  </title>\n");
    fprintf(Arch,"</head>\n");
    fprintf(Arch,"<body bgcolor = ""00FFCC"">\n");
    fprintf(Arch,"<br> <br> <br>\n");
    fprintf(Arch,"<center>\n");
    fprintf(Arch,"AUTOR: JOSE ANTONIO CARTAGENA GUERRA <br>\n");
    fprintf(Arch,"CONTADOR DE PALABRAS, FRASES Y CARACTERES <br> <br>\n");
    fprintf(Arch,"<table border = 2>\n");
    fprintf(Arch,"<tr><td><b> %s </b></td><td> %d </td></tr> <tr><td><b> %s </b></td><td> %d</td></tr> <tr><td><b> %s </b></td><td> %d </td><tr>", P.c2, P.c1, P.p2, P.p1, P.f2, P.f1);
    fprintf(Arch,"</table>\n");
    fprintf(Arch,"</center>\n");
    fprintf(Arch,"<p>\n");
    for(i = 0; i < 10; i++){
   
       fprintf(Arch, "%s<br>", Fr[i]);
   
    }
    fprintf(Arch, "</p>\n");
    fprintf(Arch,"</body>\n");
    fprintf(Arch,"</html>\n");
  }
  fclose(Arch);
}
 
#endif
