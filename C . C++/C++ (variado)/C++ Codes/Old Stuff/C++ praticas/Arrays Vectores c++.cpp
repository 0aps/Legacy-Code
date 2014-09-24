#include <iostream> //<>
using namespace std;
//Arrays y Vectores + For

int main(){
int notas[4];
int b, p;
cout << "Escribe tus 4 notas: \n\n";
for (b=0; b<4; b++)
{
cout << "Nota " << b+1 << ": ";
cin >> notas[b];
}
cout << "\n\nLas notas ingresadas son: ";
for (b=0; b<4; b++)
{
cout << notas[b]; (b==3) ? cout << "." : cout << ","; 

} 
int a=notas[0];
int c=notas[1];
int d=notas[2];
int e=notas[3];
p=a+c+d+e;
cout << " Y tu promedio es: " << p/4;
system("pause>nul");

return 0;
}

/*
#include <iostream> // <>
using namespace std;

int main(){
    int notas[4], i;
cout << "Ingresa tus cuatro notas: " << endl ;
for(i=0; i<4; i++){
cout << "\nNota: ";
cin >> notas[i];}

cout << "Las notas ingresadas son: " << endl;
for (i=0; i<4; i++){
    cout << notas[i] << "\n\n" ;
}
cout << "\n\n Y el promedio de estas es: " << notas[i]/4;
system("pause>nul");
}*/
