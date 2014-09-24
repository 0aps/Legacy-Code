// Ingresar diez (10) números enteros. Informar cuántos de ellos son negativos. 
//De esos números negativos debe informarse cuantos son pares. 
//Además debe mostrar cual es la suma de los números positivos 
//y cuál es la suma de los números negativos.
#include <iostream>
using namespace std;

int main()
{
    int n[15],i;
for(i=1;i<11; i++)
{
    cout << "Ingrese el " << i << " numero: ";
    cin >> n[i];
}
cout << "\n";
for(i=1; i<=10; i++)
{
    cout << "Estos son los numeros ingresados: "
    << n[i] << "\n";
}z
if(n[i]<0)
{
    for(i=1; i<10; i++)
    {
        cout << "\nEstos numeros son negativos:" 
             << n[i] << "\n";
    }
}
cin.get();
cin.get();
return 0;
}
/*
#include <stdio.h>
#include <conio.h>
#include <iostream>

int x,cont1=0,cont2=0,negativos=0,positivos=0;// variables no declaradas en el for

int main()

{
   for(int cont=1;cont<=10;cont++)
   {
      
      printf("\nIngrese un n%cmero: ",163);
      scanf("%d",&x);
      
      if(x<0)
      {
         cont1++;

         negativos= negativos+x;// suma de los negativos

         if(x%2==0) //para saber si son pares
   
         {
         cont2++;//cunatos pares
         }
      
         else;
      }
      
      else
      {
         positivos= positivos+x;//suma de los positivos
      }
      
   }
   printf("\nN%cmeros negativos: %d\n",163,cont1);
   
   printf("\nN%cmeros pares negativos: %d\n",163,cont2);

   printf("\nSuma n%cmeros postivos: %d\n",163,positivos);

   printf("\nSuma negativos: %d\n\n",negativos);

   getch();
}
*/
