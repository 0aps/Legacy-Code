#include <iostream>
#include <cmath>
//#define e 2.71828

/*
  Name: E_l_sucesiones
  Copyright: GPL
  Author: 
  Date: 16/01/13 19:05
  Description: Evalua los primeros diez términos de una división de polinomios. 
  
  Bugs:        Sólo funciona bien con polinomios simples.
               Hay que mejorar el algoritmo que es una chapuza. 
*/


using namespace std;

void evaluar(char *n_bucle, int bucle, char *nombre, char *cadena, char *i_nombre, double entero);

double promedio(double arrey[], int x);
double e_absoluto(double arrey[], double promedio);
double e_relativo(double ea, double promedio); 
double e_porcentual(double er);
double exceso_y_defecto(double promedio, double ea, int e_d);
double forma_cientifica(double e, double d);


int main(int argc, char **argv)
{   
  
         double arrey[10] = {0}; int x;
         cout << "Cuantos valores imprimiras: "; cin >> x;
         cout << "Introduce los valores: " << endl;
         for( int z(0); z < x; z++)
              cin >> arrey[z];
         
         cout << "El promedio es: " << promedio(arrey, x) << endl;
         cout << "El error absoluto es: " << e_absoluto(arrey, promedio(arrey, x) ) << endl;
         cout << "El error relativo es: " << e_relativo( e_absoluto(arrey, promedio(arrey, x) ), promedio(arrey, x) ) << endl; 
         cout << "El error porcentual es: " << e_porcentual( e_relativo( e_absoluto(arrey, promedio(arrey, x) ), promedio(arrey, x) ) ) << endl; 
         cout << "El error por exceso es: " <<  exceso_y_defecto( promedio(arrey,x), e_absoluto(arrey, promedio(arrey, x)), 1 ) << endl;
         cout << "El error por defecto es: " << exceso_y_defecto( promedio(arrey,x), e_absoluto(arrey, promedio(arrey, x)), 0 ) << endl;
         cout << "La forma cientifica es: " << forma_cientifica( exceso_y_defecto(promedio(arrey,x), e_absoluto(arrey, promedio(arrey, x)), 1 ),
                                                                 exceso_y_defecto(promedio(arrey,x), e_absoluto(arrey, promedio(arrey, x)), 0 ) );
         
         setbuf(stdin, NULL);
         cin.get();
         return 0;
}


double promedio(double arrey[], int x)
{
      double acc(0);
      for(int z(0); z < x; z++)acc+=arrey[z];     
      return acc/x;
}

double e_absoluto(double arrey[], double promedio)
{
      double ea(0); int num(0);
      for(int z(0); arrey[z]; z++)num++;
    
      for(int z(0); z < num; z++)
      {
              if( (arrey[z] - promedio) < 0 ) 
               ea += (arrey[z] - promedio)*-1; else
               ea += (arrey[z] - promedio); 
      }
      
    return ea/num;
}

double e_relativo(double ea, double promedio)    
{
      return (ea/promedio);
}

double e_porcentual(double er)
{
      return (er*100);
}

double exceso_y_defecto(double promedio, double ea, int e_d)
{
       if(e_d)//exceso
       return (promedio+ea); else
       return (promedio-ea);
}

double forma_cientifica(double e,double d)
{
       return (e+d)/2;
}
       
         
         
    
    //for(float n=1,x; n!=1000000000; n++)
   
    //if(n==10 || n == 100 || n==500 || n== 1000 ||n == 10000 || n == 50000 || n == 100000 || n == 300000 || n == 1000000)
    // if(n==1 || n == 2 || n == 3 || n == 10 || n == 50 || n==200||n==100000 || n == 50000 || n == 1000000)
    
    //cout << "n(" << n << "): " 
    //     <<  (pow(n,2) + 7) / (pow(n,2) - 4)  << endl;
 
    //cout << "n(" << n << "): " 
    //    <<  (pow(n,2)-3*n+5)/(4*pow(n,2)+n+10) << endl;
   
    //cout << "n(" << n << "): " 
    //     <<  (pow(n,2)-4*n+6)/(pow(n,3)+12)  << endl;
 
    //cout << "n(" << n << "): " 
    //     <<  pow( (pow(n,3)-pow(n,2)+1)/(4*pow(n,3)+pow(n,2)-n), (n+1)/(2*n+4) ) << endl;
       
    //cout << "n(" << n << "): " 
    //     << ( -4*pow(n,2) + 7*pow(n,2) -8*n + 5 ) / (2*pow(n,3) + pow(n,2) + n + 10) << endl;
    
    //cout << "n(" << n << "): " 
    //     << pow( ( (2*n-2)/(n+6) ), (n-1)/1/(2*n+3) )  << endl;
    //cout << "n(" << n << "): " 
    //     << pow( pow( ( (2*n-2)/(n+6) ), n-1 ) , 1/(2*n+3)  )  << endl;
    //cout << "n(" << n << "): " 
    //     << pow(2,(n-1)/1/(2*n+3) ) << endl;
    
