#include "weblib.h"
 /* Taller **: 06.20.12.11.
*/
 
using namespace std;
 
//Parametrización de funciones
 
void Contador(char , short &, short &, short &),  Leer_Archivo_String(String []);
Lista Contar_Archivo_Char(Lista );
 
//Función principal
int main(){
   Lista Pal;
   String Frases[10] = {'\0'};
   short i;
   Pal = Contar_Archivo_Char(Pal);
   getch();
   getchar();
   Leer_Archivo_String(Frases);
   getch();
   gen_web(Pal, Frases);
   return EXIT_SUCCESS;
}
 
Lista Contar_Archivo_Char(Lista P){
   short con_c = 0, con_p = 1, con_f = 1;
   FILE *file;
   char dir[50], c;
   cout << "Ingrese ruta y nombre del archivo con su extencion:" << endl;
   fflush(stdin);
   cin.getline(dir, 50);
   fflush(stdin);
   file = fopen(dir, "rt");
   if(file == NULL){
      cout << "ATENCION............. Fallo al abrir archivo. " << endl;
      con_c = 0;
      con_f = 0;
      con_p = 0;
      getch();
      return P;
   }
   while(!feof(file)){
      c = fgetc(file);
      Contador(c, con_c, con_p, con_f);  
   }
   fclose(file);
   P.c1 = con_c;
   P.p1 = con_p;
   P.f1 = con_f;
   fflush(stdin);
   strcpy(P.c2, "Caracteres:");
   fflush(stdin);
   strcpy(P.p2, "Palabras:");
   fflush(stdin);
   strcpy(P.f2, "Frases:");
   fflush(stdin);
   return P;
}
 
void Contador(char c, short &con_c, short &con_p, short &con_f){
   if(c == '\n'){
      ++con_f;
      ++con_p;
   }
   else if(c == ' '){
      ++con_p;
   }
   else if(c == -1){
      //No hagas nada :D
   }
   else{
      ++con_c;
   }
}
 
void Leer_Archivo_String(String Fra[]){
   FILE *file;
   short i = 0;
   char dir[50];
   cout << "Ingrese nuevamente la direccion y el nombre del archivo con su extencion: " << endl;
   fflush(stdin);
   cin.getline(dir, 50);
   fflush(stdin);
   file = fopen(dir, "rt");
   if(file == NULL){
      cout << "ATENCION............. Fallo al abrir archivo. " << endl;
      return;  
   }
   else{
      while(!feof(file)){
         fgets(Fra[i].s, 50, file);
         ++i;
      }
      fclose(file);
   }
}
