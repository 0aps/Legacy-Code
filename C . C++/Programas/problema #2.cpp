/*
* Copypaste (p) 2010 by b0ch0n XD
* 2- Hacer un programa que lea diez valores enteros en un array y
* los muestre en pantalla.
* Después que los ordene de menor a mayor y los vuelva a mostrar.
* Y finalmente que los ordene de mayor a menor y
* los muestre por tercera vez.
* Para ordenar la lista usar una función que implemente el método
* de la burbuja y que tenga como parámetro de entrada el tipo de
* ordenación, de mayor a menor o de menor a mayor.
* Para el array usar una variable global.
*/

#include <iostream>

using namespace std;

void ingresar(void);
void mostrar(void);
void ordenar(int);

int array[10];
int conteo;

int M=1;
int m=0;

int main()
{
 ingresar();
 mostrar();
 ordenar(M);
 ordenar(m);
}

void ingresar()
{
 //variable local de entrada
 int entrada;

 for(conteo=0; conteo<10; conteo++)
 {
  cout<<"Ingrese un numero entero("<<conteo<<" numeros ingresados de 10):"<<endl;
  cin>>entrada;
  array[conteo]=entrada;
 }
 system("cls");
 return;
}

void mostrar()
{
 cout<<endl<<"Los numeros del array son: "<<endl;
 for(conteo=0;conteo<10;conteo++)
  cout<<array[conteo]<<endl;
 system("pause");
 return;
}

void ordenar(int tipo)
{
 int TAM=10,i,j,aux,pasada=0;
 for(i=1; i<TAM; i++)
  {
   for(j=0; j<TAM-1-pasada; j++)
    {
     if(tipo)//si tipo=1 ordena de mayor a menor
      {
       if (array[j] < array[j+1])
        {
         aux = array[j];
         array[j] = array[j+1];
         array[j+1] = aux;
        }
      }
     else//tipo=0 ordena de menor a mayor
      {
       if (array[j] > array[j+1])
        {
         aux = array[j];
         array[j] = array[j+1];
         array[j+1] = aux;
        }
      }
    }
   pasada++;
  }
 system("cls");
 if(tipo)
  cout<<"Ordenados de mayor a menor:"<<endl;
 else
  cout<<"Ordenados de menor a mayor:"<<endl;
 mostrar();
 return;
}
