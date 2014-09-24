#include <iostream>

using namespace std;

void concatenar(char ** cadena_uno, char * cadena_dos){
   int lon_uno =0, lon_dos =0;
   int cont =0;
   char *tmp;
   
   while( (*cadena_uno)[lon_uno]!='\0')
      lon_uno++;
   
   while(cadena_dos[lon_dos]!='\0')
      lon_dos++;
   
   
   tmp = new char[lon_uno+lon_dos+1];
   
   for(int i=0; (*cadena_uno)[i]!='\0'; i++){
      tmp[cont] = (*cadena_uno)[i];
      cont++;
   }
   for(int i=0; cadena_dos[i]!='\0'; i++){
      tmp[cont] = cadena_dos[i];
      cont++;
   }
   tmp[cont]='\0';
   printf("%#x\n", &cadena_uno);
   printf("%#x\n", cadena_uno);
   printf("%s\n", *cadena_uno);
   
   cadena_uno = tmp;
   *cadena_uno = tmp;
   
   printf("%#x\n", &cadena_uno);
   printf("%#x\n", cadena_uno);
   printf("%s\n", *cadena_uno);
   cout<<"modificada "<<*cadena_uno<<endl;
}

int main(){
   char *cadena = "hola";
   char *cadenados = "como";
   concatenar(&cadena, cadenados);
   cout<<cadena<<endl;     
   cin.get();
}
