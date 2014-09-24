#include <iostream>
#include <fstream>

/*
  Name: Codificar, decodificar.
  Copyright: GPL
  Author: @aps
  Date: 14/07/11 16:42
  Description: Codifico la cadena desplazandole 3 posiciones.
               La decodifico igual. Ambas las guardo en un archivo. 
*/

using namespace std;

int depurar(char, int=0);  //funcion para depurar y que no se salga del abecedario la encriptacion.
int encriptar();           
int desencriptar(); 

char caracteres[255];                        //variable a codificar y para el archivo a decodifcar
char aux[20];                               //variable para el menu.
fstream archivo;                           //archivo a codificar
fstream d_archivo;                        //archivo a decodifcar

int main()
{
    while(1)
    {
    system("cls"); 
    archivo.open("codificado.txt");
      
    cout << "Encriptador y Desencriptador."
         << endl << endl
         << "1)Encriptar"
         << endl << endl
         << "2)Desencriptar"
         << endl << endl
         << "3)Salir\n\n:";
     cin.getline(aux, 20);
     
     if( !strcmp(aux, "Encriptar") || !strcmp(aux, "encriptar") || aux[0] == 49 )
        if(encriptar() == 0)
        cout << endl << endl << "Cadena encriptada con exito.";
        else cout << endl << endl << "Error en la codificacion.";
       
        
     if( !strcmp(aux, "Desencriptar") || !strcmp(aux, "desencriptar") || aux[0] == 50 )
        if(desencriptar() == 0)
        cout << endl << endl << "Archivo desencriptado con exito.";
        else cout << endl << endl << "Error decodificando el archivo.";
        
     if( !strcmp(aux, "Salir") || !strcmp(aux, "salir") || aux[0] == 51 )
        break;
        
        cin.get();
     }
                  
     return 0;
}

int depurar(char caracter, int v)
{
    // CODIFICAR
    // Si se escribe Z,Y,X,z,y,x se escribira A,B,C,a,b,c.
    
    //DECODIFICAR
    // Si se escribe A,B,C,a,b,c se escribira Z,Y,X,z,y,x
    
    //decodifico
      if(v == 1)
     {
     if(caracter == 'A')// A = Z
     return 90+3;  // le sumo 3 para que cuando le reste 3 abajo me de Z(90).
     else if(caracter == 'a')//a = z
     return 122+3;
     else if(caracter == 'B')//B = X
     return 88+3;
     else if(caracter == 'b')// b = x
     return 120+3;
     else if(caracter == 'C')// C = Y
     return 89+3;
     else if(caracter == 'c')// c = y
     return 121+3;    
           
     else if(caracter == 0x35) // #  
     return 32;                //espacio
     else return caracter;
     }
     
     //codificar
     if(v == 0)
     {
     if(caracter == 'Z')// Z = A
     return 65-3;  // le quito 3 para que cuando le sume 3 arriba me de A(65).
     else if(caracter == 'z')//z = a
     return 97-3;
     else if(caracter == 'X')//X = B
     return 66-3;
     else if(caracter == 'x')// x = b
     return 98-3;
     else if(caracter == 'Y')// Y = C
     return 67-3;
     else if(caracter == 'y')// y = c
     return 99-3;
     else return caracter;
     }
     
     
}

int encriptar()
{
    if(!archivo.good()) // si el archivo no existe o esta abierto.
    {
    cout << "\nEl archivo \"codificado.txt\" no existe. Se creara uno.\n\n";
    archivo.open("codificado.txt", ios:: out);
    archivo.clear();
    archivo.close();
    archivo.open("codificado.txt");
    }else
    {
    archivo.clear();
    archivo.close();
    archivo.open("codificado.txt", ios::out | ios::app);
    }
    
    cout << "Ingrese los caracteres a codificar:\n\n: ";
    cin.getline(caracteres, 255);
    
    for(int i=0; caracteres[i]; i++)
    {
            caracteres[i] = depurar(caracteres[i]);
            caracteres[i]+=3;
            archivo << caracteres[i];        
    }
    archivo.clear();
    archivo.close();    
    return 0;
}

int desencriptar()
{
    char aux[255];  //variable auxiliar

    cout << "Ingrese la ruta del archivo a decodificar: " ;
    cin.getline(caracteres, 255);
    
    d_archivo.open("codificado.txt", ios::in); 
       
    if(!d_archivo.good())
    return 1;
    
    for(int i=0; d_archivo.get(aux[i]); i++);

    d_archivo.clear();
    d_archivo.close();
    
    d_archivo.open("decodificar.txt", ios::out);
    
    for(int i=0; aux[i]; i++)
    {
        //    cout << endl << endl << aux;
        //    cin.get();
            
             aux[i] = depurar(caracteres[i], 1);
             aux[i]-=3;
             d_archivo << aux[i];      
    }
    d_archivo.clear();
    d_archivo.close();
    return 0;
}
     
