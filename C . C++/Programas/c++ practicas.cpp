#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>

using namespace std;
// while - se ejecuta mientras la condicion sea verdadera
// while - evaluacion de condicion - sentencia 

// do, while - se ejecuta mientras la condicion se a verdadera
// do, while - sentencia - evaluacion de condicion

// for - se ejecuta miestras la condicion sea verdadera.
// for - inicializacion - evaluacion de condicion -  sentencia - incremento.
// for - despues se evalua la condicion nuevamente - sentencia - incremento.  : )

// true - cualquier numero diferente a cero.
// false - cero

// Si en una comparacion o bucle no hay condicion explicita, esta es verdadera.

// char almacena el valor ansii asignado.
// si aun tipo char se le asigna un entero muestra el valor ansii del entero.
// si aun tipo char se le asigna un caracter muestra el caracter.

//strlen no cuenta el final de cadena.
// ej: 
// char * arrey = "Hola Angel"; (hay 10 caracteres) con el final de cadena serian (11);
// i = strlen(arrey); i = 10;
// arrey[0] = H
// arrey[9] = l
// arrey[10] = '\0'
// por lo tanto si i = 10 entonces arrey[10] estaria en el final de cadena. =)

//char hola[4];
// hola[0] = "h";
//[1] = o
//[2] = l
//[3] = a
//[4] = /0
//el indice indica el # de caracteres SIN sumarsele el final de cadena


// Son lo mismo:
// while(cad[l]) l++;
// while(cad[l]!=0) l++;

// los corchetes {} son opcinales con "case:"
// case: ejecuta mas de una sentencia sin corchetes

//un puntero a un tipo char (char *var) se imprime igual que un arrey. (char arrey[100])
// cout << var << endl << arrey; // se imprime la cadena completa y no es necesario poner *.
// si se pone cout << *var; imprimira el elemento apuntado.
// por defecto seria var[0];
// *var[0]; // ilegal.

// ej 2:
// char *var = "Hola Angel";
// char *aux = var;  // equivalente asignando luego. aux = var;
// var[1] = o;
// Para asignar individualmente tratando como si fuera un arrey, hay que usar el operador de referencia
// aux = &var[1];
//(*puntero)++;    // aumenta el VALOR que esta siendo apuntado.
// puntero++;      //aumenta la direccion apuntada. 
                   //osea si apunta a valor[0], apuntara a valor[1];
                   
//fstream fichero("hola.txt"); el archivo no se crea magiacamente si no existe.
//fstream fichero("hola.txt", ios::app); coloca el puntero al final pero no lo escribe por lo tanto es:
//fstream fichero("hola.txt", ios::out | ios:app); // ahora si :)
//fstream fichero("hola.txt", ios::out); ahora si se crea el archivo.
//un archivo debe de estar abierto antes de comprobar si existe.
// while(origen.get(c)) final.put(c); //mientras copio origen copio final.
  

//typedef struct se utiliza en C para obviar el tener que colocar  struct <identificador> <objeto nuevo>.

//char *argv[] = puntero hacia un arry char.
// equivalente a: char **argv; o char argv[][]; (en cierto modo la ultima) :)
//doble puntero = dos dimenciones.

//   A calling convention defines how parameters are passed on the stack and whether 
//  the caller or the function has to tidy up the stack after the call. //tydy up = ordenar

//  "cdecl" This is the default for C and C++. Parameters are pushed from right to left,
//  C then B then A. The called function gets the values of the parameters but doesn't alter 
//  the stack, so the compiler has to add an instruction after the call to increment the stack 
//  to make it all balance. There are variations between different platforms over register usage, 
//  and some languages e.g. Visual Basic cannot used cdecl. It does however support variadic 
//  functions such as printf().
    
//  "stdcall" This is probably the commonest, certainly if non C/C++ languages are involved. 
//  Like cdecl, the parameters are pushed from right to left ( c,b,a ) and the function itself
//  must clean up the stack before returning.
    
//  "winapi" This is the default on Windows if none is specified. It defaults to stdcall on 
//  Windows and cdecl on Windows CE. It isn't the same as stdcall though so if you try to 
//  call a dll function marked winapi when expecting stdcall, Windows doesn't find it.
    
//  "fastcall" This uses registers for sped but it is implemented differently
//  between different compilers so use it if you are sticking to compilers from one
//  source and not being called from languages like Visual Basic or C#.
    
//  "safecall" Used by Borland for COM/OLE calling.
//  "thiscall" This is used in C# for calling functions in classes exported from unmanaged code. 

// extern void funcion(); //esto indica que la definicion de la funcion esta en otra 
                         //archivo.
// el cheat engine DESCARTA direcciones de memoria.
// ej: ingreso 5. - descarta todas las que no tengan 5.
// ej: ingreso 2. - entre las que estaban. descarta todas las que no tienen 2.
// con readprocessemomory se LEE EL CONTENIDO que hay en una direccion de memoria.
// con writeprocessmemory se ESCRIBE en una direccion de memoria.

//srand(time(null));  //necesario para usar rand.
//rand()%RANGO;

//para tomar un valor entre un numero hasta el otro
//rand()%ultimo valor+primer valor

//scanmem = buscar direccinoes de memoria en linux
//ptrace = manejar memoria en linux

//comprobar si el primer bit de un char es 1 o 0 con: if(var&1)....
//Puedes hacer que el primer bit de un char valga 1 con: var|=1;
//Y puedes hacer que el primer bit valga 0 con: var&=254;

int vGlobal[10] = {10,9,8,7,6,5,4,3,2,1};

void goxy(int, int);
void matrices();
void caracteres();
void g();
void ej_1();
void ej_2();
void ej_3();
void ej_4();
void ej_5();
void ej_primos();
void ej_6();
void ej_7();
void ej_8();
void ej_9();
void ej_10();
void ej_11();
void ej_12();
void fichero_binario();
void Macro_names();
void punteros_arrey();
void colores();
void inlin_e();
void buscar_por_nombre();
void memoria_dinamica();
bool divisible_3(int);
bool Palindromo(char[40]);
int metodo_de_burbuja(int);
int mayor_arrey(int[], int[]);
int strlenn(char*);
int mayor(int,int);
int divisible(int);
void devolver_puntero();
char *invertir(char *);
void buscar_por_telefono();
void rellenar_arrey();
void prueba();


int main()
{
    srand(time(NULL));
    int funcion;
    while(funcion != 25)
{
cout << "Elige la funcion a ejecutar: \n\n"
     << "1. matrices().\n"
     << "2. caracteres().\n"
     << "3. g().\n"
     << "4. ej_1().\n"
     << "5. ej_2().\n"
     << "6. ej_3().\n"
     << "7. ej_4().\n"
     << "8. ej_5().\n"
     << "9. ej_6().\n"
     << "10. ej_7().\n"
     << "11. ej_8().\n"
     << "12. ej_9().\n"
     << "13. ej_10().\n"
     << "14. ej_11().\n"
     << "15. ej_12().\n"
     << "16. ej_primos().\n"
     << "17. punteros_arrey().\n"
     << "18. colores().\n"
     << "19. inlin_e().\n"
     << "20. memoria_dinamica().\n"
     << "21. devolver_puntero().\n"
     << "22. Macro_names().\n"
     << "23. fichero_binario().\n"
     << "24. Prueba().\n"
     << "25. Salir.";
     cout << "\n\n: ";
     cin >> funcion;
     
     switch(funcion)
     {
                    case 1: matrices(); break;
                    case 2: caracteres(); break;
                    case 3: g(); break;
                    case 4: ej_1(); break;
                    case 5: ej_2(); break;
                    case 6: ej_3(); break;
                    case 7: ej_4(); break;
                    case 8: ej_5(); break;
                    case 9: ej_6(); break;
                    case 10: ej_7(); break;
                    case 11: ej_8(); break;
                    case 12: ej_9(); break;
                    case 13: ej_10(); break;
                    case 14: ej_11(); break;
                    case 15: ej_12(); break;
                    case 16: ej_primos(); break;
                    case 17: punteros_arrey(); break;
                    case 18: colores(); break;
                    case 19: inlin_e(); 
                    case 20: memoria_dinamica(); break;
                    case 21: devolver_puntero(); break;
                    case 22: Macro_names(); break;
                    case 23: fichero_binario(); break;
                    case 24: prueba();break;
                    default: cout << "Elige una funcion valida.\n"; break;
     }
     
     setbuf(stdin, NULL);
     cin.get();
    
}     
                    
setbuf(stdin, NULL);
    cin.get();
    return 0;
}



void prueba()
{ 
  float y = 25.4;
char a[20] = { 'a', 'b', 'c'} ;
sprintf (a, "%i", y); //pasa el int a char
int x = -1;
while (x++ < 10)
cout << a[x] << endl; 

cout << a;
}     








void g()
    {
        int x(8);
        cout << x <<endl;
                            {
                                int x(0); x++;
                                cout << x << endl;
          
                          {
                                 int x(9); x--;
                                 cout << x << endl;
                     {
//                        :: vGlobal =10;
                        cout << vGlobal;
                     }
                          }
                             } 
}

int strlenn(char *p)
{
    int i(0);
    while(*p++) i++;
    //*(p++) primero se aumenta la posicion de memoria apuntada, luego se muestra.
    return i;
}

void caracteres()
{
     char v[] = "ABDCDEFGHIJKLMNOPQRSTUVXWYZabcdefghijklmnopqrstuvxwyz";
     int i=-1;
     while(v[++i])
     {
             cout << "ANSI " << v[i] << ":  " << int(v[i]) <<endl;
     }
                  cin.get();
}



int mayor(int a, int b)
{
if(a>b) return a; else return b;
}

int divisible(int x)
{
    if(x%3 == 0)return 0; else return 1;
}

/* Enum = enumeracion
enum {lunes, martes, meiercoles, jueves, viernes}dias;  [si] se utiliza el identificador "dias"
enum dias{lunes, martes, miercoles, jueves, viernes); [no] se utiliza el identifcador "dias".

###  dias x; [ahora si se usa] x]  ###


# Ojo: con "cin" no funciona, con scanf si. >:l
*/

void matrices()
{
// Las arreys son variables (?) con diferentes valores en una sola.
// Hay dos tipos de arreys: vectores(unidimencioneles) y matrizes(bidimencionales).
// Los vectores tienen una sola dimecion [] - filas.
// Las matrices tienen dos dimenciones [][] - filas y columnas.
// Filas/horizontal - Columnas/vertical.     
  
     
int nota[5][3];   // matriz de 5 * 3
for(int a=1; a<=5; a++)    //Primer for para los alumnos [filas].
{
   for(int i=1; i<=3; i++)   // Segundo for para las notas [columnas] [En 'i' es donde se guarda el valor de la nota.]
    {
        
   //     cout << "notas # " << i << " del alumno " << a << ":";
     //   cin >> nota[a][i];
        
    }
 cout << endl; // Espacio entre cada alumno.
}
       cout << endl << endl;
       
for(int a=1; a<=5; a++)
{
  for(int i=1; i <= 3; i++)
   { 
        cout << "notas #" << i << "del alumno" << a << ": " << nota[a][i] << endl; 
    
   }
cout << endl;
}

}


// Siempre que se inicialize un arrey de caracter o de enteros,
// sin indice y declarandolo uno x uno,
// se debe de colocar el final de cadena. 
// int b[] = {39,32,100,31,65,38,99, '\0'};

int mayor_arrey(int a[], int b[])
{
    
    int mayor = 0;

for(int i=0; a[i] && b[i]; i++)
{
        if(a[i] > mayor)
        mayor = a[i];
        
        if(b[i] > mayor)
        mayor = b[i];
}

return mayor;

}

void ej_1()
{
  for (int i(1); i<=20; i++)
  {
      cout << i;
      if(!(i%3)) cout << "\t Divisible\n"; else cout << "\t No divisible\n";  
      // Otra opcion: i%3 == 0;
      // i%3 == true entonces lo vuelvo falso. (h)
  }
}

void ej_2()
{
     int i=0;
     while(++i<=20)
     {
                 cout << "Numero: " << i;
                 if(divisible_3(i)) // If siempre evalua verdadero si no hay condicion.
                 cout << "\tDivisible\n"; else cout << "\tNo divisible\n";
     }
     
}

bool divisible_3(int n)
{
     if(!(n%3))
     return true; return false;
}

void ej_3()
{

int a, b;
     
     for( a=1; a<=20; a++)
     {
           for ( b=1; b<=a; b++)
           
           cout << b << " ";
           cout << endl; 
           
     }
     
     
}

void ej_4()
{
     int x(1),i(1),z(1);
     
     while(i<=23)
     {
        cout << i;
        if(x) i+=4; else i-=2;

        if(i<=23)
       cout << ","; else cout << ".";   
       
       x = !x;// cin.get(); goxy(z+=3,0); 
     }     
     
}

void goxy(int x, int y) 
{ 
COORD coord; 
coord.X = x; coord.Y = y; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
}

void ej_5()
{
 
     int n;
     char opcion[100];
     
     for(;;)
     {
     cout << "Ingrese un numero: ";
     cin >> n;
     
     if(!(n % n && n % 1))
     {
            if(n != 2 && (!(n % 2)) )
            //if(n != 3 && (!(n % 3)) )
            cout << "\t\tNo primo.\n\n";
            else  cout << "\t\tPrimo.\n\n";
     }
     cout << "Desea salir o continuar? ";
     setbuf(stdin, NULL);
     cin.getline(opcion, 100);
     
     if(opcion[0] == 's' || opcion[0] == 'S')
     {cout << " \t\t\tbye\t :)"; break;}
     
     else { cout << "\n\n";  continue; }
    }
 }
     
void ej_primos()
{
     // Un numero primo es aquel que solo es divisible por el mismo y la unidad (osea uno).
     // Ej: 1,2,3,5,7,11,etc.
     // El unico numero par primo es el 2.
     // Un numero compuesto son los numeros que no son primos.
     // Un factor es un divisor de un numero cuyo resto es cero.
     //  10|__5___
     //      2  < - -- - Divisor
     
     
     
   int numero;
   int factor;
   char resp[12];
   int aco;
   int x;
   
   do {
      cout << "Introduce un numero entero: ";
      cin >> numero;
      factor = 2;     
      aco=0;
                  
      while(numero >= factor*factor) {  
         if(!(numero % factor)) {          
            cout << factor << " * "; 
            x=factor;
            if(x == factor)
            aco +=1;
            
            numero = numero / factor;
          
            continue;
         }
         if(factor == 2) factor++;          
         else factor += 2;
      }
      cout << numero << endl; aco += 1;
      cout << "# de repeticiones: " << aco;
      cout << "\nDescomponer otro numero?: ";
      cin >> resp;
   } while(resp[0] == 's' || resp[0] == 'S');

}
int regresar(char caracter)
{
    if(caracter == 65)
    {
    return 67;
    }
}

void ej_6()
{
//may 65-90
//m 97-122
// char tiene prevalencia sobre los enteros. 
// si a un tipo char se le asigna un entero muestra su valor ansii.
        cout << "Mayuscula: ";
for(char i(65); i<=90; i++)
      {
                if(i == 'A')
                {i=regresar(i);}
                cout << i;
       if(i==90)
       {
                cout << "\nMinuscula: ";
                for(char i(97); i<=122; i++)
                {
                         cout << i;
                } 

        }
}
}

void ej_7()
{

for(char x('A'); x<='Z'; x+=2)
{
      
      char z = tolower(x)+1;
      cout << x << z;
        
         if( x== 'Y')
      {
          cout << endl;
          
          for(char x('a'); x<='z'; x+=2)
        {
                 char z = toupper(x)+1;
                 cout <<  x << z;
                        
        }
      }   
}
                      
     
}

void ej_8()
{
//Se trata de leer caracteres desde el teclado y contar cuántos hay de cada tipo. 
//Los tipos que deberemos contar serán: consonantes, vocales, dígitos, signos de puntuación,
//mayúsculas, minúsculas y espacios. Cada carácter puede pertenecer a uno o varios grupos. 
//Los espacios son utilizados frecuentemente para contar palabras.    

char cadena[100];
char signos[] = {'.', ',', ':', ';', '"', '\'', '\\', '/', '(', ')', '[', ']', '{', '}', '¿', '?', '\0'};
int consonantes(0), vocales(0), digitos(0), signos_i(0), mayusculas(0), minusculas(0), espacios(0);
int i;

cout << "Ingrese una cadena: ";
cin.getline(cadena, 100);


for(i=0; cadena[i]; i++)
{
   //espacio   
   if(cadena[i] == ' ')
   {
                espacios+=1;
   }            
   
   //mayuscula      
   for(char b= 'A'; b<= 'Z'; b++) // Leo el abecedario en mayus
   {
            if(cadena[i] == b) //si hay alguna letra mayus se almacena
            {
                         mayusculas+=1;
       
           //vocales mayusculas
              if(cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
                {         
                  vocales += 1;  // cout << "wtf? \t" << vocales; cin.get();
                } else consonantes+=1;         
           }
   }      
         
   //consonantes
   for(char a = 'a'; a<='z'; a++)
  {   
      //minuscula   
      if(cadena[i] == a)
      {
         minusculas+=1;
      
      //vocales minusculas
         if(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u')
          {         
           vocales += 1;  // cout << "wtf? \t" << vocales; cin.get();
          } else consonantes+=1;
      }
      
  }
  //digitos
  for(char x=49; x <= 57; x++)
  { // 1 = 49 en anssi
    // 9 = 57 en anssi
     if(x == cadena[i])
       {        
                  digitos+=1;
       }
  }
  //signos
  for(int x=0; x<15; x++)
  {
    if(cadena[i] == signos[x])
   {
               signos_i+=1;
    }
   }
  
}
      
  cout << "Consonantes: " << consonantes << endl;
  cout << "Vocales: " << vocales << endl;
  cout << "Digitos: " << digitos << endl;
  cout << "Signos: " << signos_i << endl;
  cout << "Mayuscula: " << mayusculas << endl;
  cout << "Minuscula: " << minusculas << endl;
  cout << "Espacio: " << espacios;   
  

}     

void ej_9()
{
//Hacer un programa que lea diez valores enteros en un array y los muestre en
//pantalla. Después que los ordene de menor a mayor y los vuelva a mostrar. Y
//finalmente que los ordene de mayor a menor y los muestre por tercera vez. Para
//ordenar la lista usar una función que implemente el método de la burbuja y que
//tenga como parámetro de entrada el tipo de ordenación, de mayor a menor o de
//menor a mayor. Para el array usar una variable global.

/*
  Name: Ejercicio #2 c.conclase.net
  Copyright: GPL
  Author: @Aps
  Date: 30/06/11 22:48
  Description: Por fin logre hacer el maldito ejercisio sin ayuda. x-] 
  PD. Me costo MUCHO hacer esto. . .
*/



int opcion;                         //parametro de entrada de la funcion

for(int i=0; i<10; i++)    //bucle para la toma y muetra del arrey
{               
       //pido
       cout << "Numero " << i+1 << ": ";   //aumento en uno a "i" para que no empieze desde 0.
       cin >> vGlobal[i];
           
            //muestro
            if(i == 9)    //si "i" es igual a  9 muestro el arrey
         {
           
           cout << endl << endl << "Normal"
                 << "\n-------------------------------\n"; 
           
               for(int i=0; i<10; i++)
            {
               cout << vGlobal[i];
               if(i==9)                        // Si "i" es igual a 9 pongo . sino ,
               cout << "."; else cout << ",";
            }
         }
}
     cout << "\n-------------------------------"
          << "\n\nOrdenar de:\n\n0-Menor a mayor.\n1-Mayor a menor.\n\n:";
     cin  >> opcion;

     if(opcion == 0)
     {
        cout << "\n\nDe menor a mayor.";
        cout << "\n-------------------------------\n";
        metodo_de_burbuja(0);    
     }
     else if(opcion == 1) 
      {
        cout << "\n\nDe mayor a menor.";
        cout << "\n-------------------------------\n";  
        metodo_de_burbuja(1); 
      }
for(int i=0; i<10; i++)   //muestro el arrey ya ordenado
{  
     cout << vGlobal[i];
     if(i==9)
     cout << "."; else cout << ",";
}   
cout << "\n-------------------------------"; 

}

int metodo_de_burbuja(int a)
{

int arrey[10];                      //variable de ayuda para el ordenamiento
int pasadas(0);                      //numero de pasadas para terminar el ciclo de ordenacion

  
    if(a == 0) 
    {
              //ordenar de menor a mayor        
              for(int i=0; pasadas != 10; i++) //mientras # de pasadas sea diferente a 10
          {                                    //se hace el for
               if(vGlobal[i] == '\0')  //Si vGlobal[i] es igual al final de cadena
               continue;               //vuelvo a la evaluacion del for.
                                       //Esto es para que no se llegue hasta el final de cadena
                                       // y este quede atrapado en el ordenamiento provocando
                                       // un mal funcionamiento de la ordenacion.
               
               if(i==9)           //Cada vez que se llegue al final del arrey 
             {                    //es una pasada.
                 i=0;
                 pasadas+=1; 
             }
                 
                  if(vGlobal[i] < vGlobal[i+1]) // Si el primer # es < que el segundo
                {                               // todo bien.
                  continue;
                } else {                        
                        // Si el segundo es menor que el primero.
                        arrey[i] = vGlobal[i];  //guardo el primer # en otro arrey.
                        vGlobal[i] =  vGlobal[i+1]; //Ordeno.
                        vGlobal[i+1] = arrey[i];    //Ordeno.
                       }
          } 
    }
   
   
   if(a == 1)
  {
            //De mayor a menor
            
            for(int i=0;pasadas != 10; i++)
        {       
                 if(vGlobal[i] == '\0')
                 continue;
        
            if(i==9)
          {
            i=0;
            pasadas+=1; 
          }    
      //  1,2,3,4,5,6,7,8,9,10
              if(vGlobal[i] >  vGlobal[i+1])
           {     
              continue;
           }  else {
                      //if(segundo > primero)
                      arrey[i] = vGlobal[i];
                      vGlobal[i] =  vGlobal[i+1];
                      vGlobal[i+1] = arrey[i];  
                   }
        }
  }
  
}


void ej_10()
{

//Hacer un programa que lea 25 valores enteros en una tabla de 5 por 5, 
//y que después muestre la tabla y las sumas de cada fila y de cada columna. 
//Procura que la salida sea clara, no te limites a los números obtenidos.    

int tabla[5][5];
int s_fila[5][1];
int s_columna(0);

  for(int x=0; x<5; x++)
        {
                for(int z=0; z<1; z++)
                {
                        s_fila[x][z] = 0;
                }
        }
        
        for(int x=0; x<5; x++)
        {
                for(int z=0; z<5; z++)
                {
                        tabla[x][z] = 0;
                }
        }


for(int i=0; i<5; i++)
{
      
        for(int j=0; j<5; j++)
        {         
                
          cout << "Fila # " << i+1 << ", valor " << j+1 << ": ";
          cin >> tabla[i][j];
          
          s_fila[i][0] = s_fila[i][0] + tabla[i][j];  //s_fila es una matriz de 5x1
          s_columna += tabla[i][j];
        }
        if(i == 4)
        {
             
         for(int i=0; i<5; i++)
         {
                 cout << endl;
             for(int j=0; j<5; j++)
        {
             
          cout << "\nFila # " << i+1 << ", valor " << j+1 << ": " << tabla[i][j];
         
               if(j==4)
               cout << "\nTotal de fila # " << i+1 <<  ": " << s_fila[i][0];
                  
        }
         if(i == 4)
         cout << endl << "Total: " << s_columna;
         }
}
} 
}


void ej_11()
{
/*
  Name: Ultimo ej de cadena - c.conclase.net
  Copyright: GPL
  Author: @Aps
  Date: 01/07/11 16:20
  Description: Palindromos
  Cosas a reparar por si algun dia veo esto: Los espacios entre las palabras.
*/

//Una palabra es palindromo [con acento en la 'i'] si es capicua, osea que se lee igual
//al derecho y alrevez.

 char cadena[40];  //argumento para la funcion.
 setbuf(stdin, NULL);    
 cout << "Ingrese una palabra: ";
 cin.getline(cadena, 40);
 
 if(Palindromo(cadena) == false)
 cout << "\nLa palabra no es un palindromo."; 
 else
 cout << "\nLa palabra es un palindromo.";
  
}

bool Palindromo(char palabra[40])
{

    
char arrey[40];   //auxiliar para la comparacion
int x(0),z(0);    //necesario para el fin y inicio del ordenamiento
x = strlen(palabra)-1;  //me ubico en el ultimo caracter de la cadena

while(palabra[x])  //mientras no llegue al final de cadena.
{
   arrey[z] = palabra[x];  //le asigno al primer caracter de arrey el ultimo de palabra
   z++; x--; 
   
   if(x == -1) //si llego aqui es por que ya llegue al final de cadena de palabra
   {
        arrey[z] = '\0'; // marco final de cadena para evitar basura
        break;
   }
}

z=0; //para no declarar otra variable mas . . .
while(arrey[z] && palabra[z])
{
   if(palabra[z] != arrey[z])  //si el primer caracter de palabra no es igual al de arrey
   return false;               //la palabra no es palindromo.
   z++;                               
}                      

return true;
}

struct estructura_P
{
       char nombres[10];
       char telefono[10];
}personas[10];

void ej_12()
{
         //Escribir un programa que almacene en un array los nombres y números de teléfono de 10 
         //personas. El programa debe leer los datos introducidos por el usuario y guardarlos en 
         //memoria (en el array). Después debe ser capaz de buscar el nombre correspondiente a un 
         //número de teléfono y el teléfono correspondiente a una persona. Ambas opciones deben se 
         //accesibles a través de un menú, así como la opción de salir del programa. El menú debe 
         //tener esta forma, más o menos:

        //a) Buscar por nombre
        //b) Buscar por número de teléfono
        //c) Salir

char opcion;

fflush(stdin);

for (int i=0; i<10; i++)
{
    cout << "Persona " << i+1 << ": ";
    cin.getline(personas[i].nombres, 10);
    cout << "Telefono " << i+1 << ": ";
    cin.getline(personas[i].telefono, 10);
}
while(1)
{
cout << "\n\na)Buscar por nombre. " 
     << "\nb)Buscar por numero de telefono. "
     << "\nc)Salir.\n\n:";
     cin >> opcion;
     
     if(opcion == 'a' || opcion == 'A')
     {
               buscar_por_nombre();
               //ingreso nombre y me da telefono
     }
     else if(opcion == 'b' || opcion == 'B')
     {
          buscar_por_telefono();
          //ingrso telefono y me da nombre
     }
     else if(opcion == 'c' || opcion == 'C')
     {
          cout << endl << "\t\tSaliendo. . .";
          break;
     }
}
    
}

void buscar_por_nombre()
{
     fflush(stdin);    //limpio buffer
     char v_nombre[10]; 

     cout << "\n\nIngrese el nombre a buscar: ";
     cin.getline(v_nombre,10);
     
   for(int z=0; z<10; z++)  //bucle para el arrey de la estructura persona
  {        
     if( strcmp(v_nombre,personas[z].nombres) )  continue;     //si el nombre es != al de la
     else                                                      //estructura vuelvo al bucle
       {
          cout << "\n\nTelefono = " << personas[z].telefono;  // de lo contrario
          break;                                              //coloco el nombre actual 
       }

  }
         
}

void buscar_por_telefono()
{
     fflush(stdin);
     char v_telefono[10];
     
     cout << "\n\nIngrese el telefono a buscar: ";
     cin.getline(v_telefono,10);
     
   for(int z=0; z<10; z++)
  {        
           
           
     if( strcmp(v_telefono,personas[z].telefono) )  continue;     
     else 
       {
          cout << "\n\nNombre = " << personas[z].nombres;
          break;        
       } 
       
        
  }
                 
}

void punteros_arrey()
{
     char cadena1[] = "Cadena 1";
   char *cadena2 = "Cadena 2";
 
   cout << cadena1 << endl;
   cout << cadena2 << endl; 

   //cadena1++; // Ilegal, cadena1 es constante 
   cadena2++; // Legal, cadena2 es un puntero 

   cout << cadena1 << endl; 
   cout << cadena2 << endl;
 
   cout << cadena1[1] << endl;
   cout << cadena2[0] << endl;
 
   cout << cadena1 + 2 << endl; 
   cout << cadena2 + 1 << endl;
 
   cout << *(cadena1 + 2) << endl; 
   cout << *(cadena2 + 1) << endl; 
}

void memoria_dinamica()
{
   char *c; 
   int *i = NULL; 
   float **f; 
   int n;
 
   // Cadena de 122 más el nulo:
   c = new char[123];
   // Array de 10 punteros a float:
   f = new float *[10]; //(1)
   // Cada elemento del array es un array de 10 float 
   for(n = 0; n < 10; n++) f[n] = new float[10]; //(2)
   // f es un array de 10*10 
   f[0][0] = 10.32; 
   f[9][9] = 21.39; 
   c[0] = 'a'; 
   c[1] = 0; 
   // liberar memoria dinámica
   for(n = 0; n < 10; n++) delete[] f[n]; 
   delete[] f; 
   delete[] c; 
   delete i; 
}


void colores()
{
 
union color {
    unsigned int c;
    struct {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
    };
};
  color c1 = { 0x80fedc12 };

    cout << "Color: " << dec << c1.c << " - " << hex << c1.c << endl;
    cout << "Rojo:  " << dec << (int)c1.red << " - " << hex << (int)c1.red << endl;
    cout << "Verde: " << dec << (int)c1.green << " - " << hex << (int)c1.green << endl;
    cout << "Azul:  " << dec << (int)c1.blue << " - " << hex << (int)c1.blue << endl;
    cout << "Alfa:  " << dec << (int)c1.alpha << " - " << hex << (int)c1.alpha << endl;

    c1.red = 0x42;
    c1.green = 0xde;
    cout << "Color: " << dec << c1.c << " - " << hex << c1.c << endl;
    cout << "Rojo:  " << dec << (int)c1.red << " - " << hex << (int)c1.red << endl;
    cout << "Verde: " << dec << (int)c1.green << " - " << hex << (int)c1.green << endl;
    cout << "Azul:  " << dec << (int)c1.blue << " - " << hex << (int)c1.blue << endl;
    cout << "Alfa:  " << dec << (int)c1.alpha << " - " << hex << (int)c1.alpha << endl;

}
  inline int mayor2(int a, int b) {
   if(a > b) return a; 
   return b; 
}
void inlin_e()
{
   
 
 
   cout << "El mayor de 12,32 es " << mayor2(12,32) << endl; 
   cout << "El mayor de 6,21 es " << mayor2(6,21) << endl; 
   cout << "El mayor de 14,34 es " << mayor2(14,34) << endl; 
} 

void devolver_puntero()
{
     
     
     setbuf(stdin, NULL);
     char vector[200]; //fijate que paso un arrey como parametro.
                       //Da igual si paso un puntero por que los arrey se tratan como
                       //punteros estatico.
     cout << "Ingrese la cadena: ";
     cin.getline(vector,200);
     
     cout << endl << endl
          << "Cadena normal: " << vector;
     cout << endl 
          << "Cadena invertida: " << invertir(vector);
}


char *invertir(char *string)
{
     int x,i = strlen(string); //caracter final.
     char *auxiliar;   
     string += i-1; //string apunta a string[0], lo ubico en el caracter final.
                    //le resto uno para que no este en el final de cadena.
                    //i no lo resto arriba porque tengo que preservar el valor del caracter final. 
     
     for(x=0; x<i; x++) //mientra x sea menor que i.
     {
     *auxiliar=*string; //el valor de auxiliar[0] = string[39]
     auxiliar++;        //auxiliar[1]
     string--;          //string[38]
     }
     
     *auxiliar = 0; //coloco fin de cadena/
     
               return auxiliar-i; //devuelvo el puntero y apunto a auxiliar al principio
                                  //de la cadena. (h)
}

void Macro_names()
{
     // standard macro names

  cout << "This is the line number " << __LINE__;
  cout << " of file " << __FILE__ << ".\n";
  cout << "Its compilation began " << __DATE__;
  cout << " at " << __TIME__ << ".\n";
  cout << "The compiler gives a __cplusplus value of " << __cplusplus;
  
  //__LINE__ = linea ejecutada.
  //__FILE__ = ruta completa con nombre del archivo.
  //__DATE__ = Fecha
  //__TIME__ = tiempo
  //__cplusplus = si el compilador compila con el standar de c++ devuelve 1.

}
struct tipoRegistro {
   char nombre[32];
   int edad;
   float altura;
};
void fichero_binario()
{

   tipoRegistro pepe;
   tipoRegistro pepe2;
   ofstream fsalida("prueba.dat", 
      ios::app | ios::binary);
   
   strcpy(pepe.nombre, "Angel ");
   pepe.edad = 15;
   pepe.altura = 223;
   
   fsalida.write(reinterpret_cast<char *>(&pepe), 
   sizeof(tipoRegistro));
   fsalida.close();

   ifstream fentrada("prueba.dat", 
      ios::in | ios::binary);
   
   fentrada.read(reinterpret_cast<char *>(&pepe2), 
      sizeof(tipoRegistro));
   cout << pepe2.nombre << endl;
   cout << pepe2.edad << endl;
   cout << pepe2.altura << endl;
   fentrada.close();

}

void rellenar_arrey()
{
     char arrey[10][11];
     char aux[10];
     
     for(int x=0; x<sizeof(aux);x++)
     {
     
     for(int i=0; i < sizeof(aux); i++)
     {
     aux[i] = rand()%57+65;
     }
        
     aux[10] = '\0';
     
     strcpy(arrey[x],aux);
           
        cout << "Aux[]:\t"<<aux <<endl;
        cout << "Arrey["<<x<<"]:\t"<<arrey[x] <<endl;
        cin.get ();
     }
}
     
     
