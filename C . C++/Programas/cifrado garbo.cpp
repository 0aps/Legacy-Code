#include <iostream>

/*
  Name: Code Cifrado Garbo
  Copyright: GPL
  Author: @aps
  Date: 01/08/11 17:39
  Description: Cifrado Garbo -- googlear.  
*/



using namespace std;

//   se da la cadena
//   se considera como el indice la posicion de cada letra
//   le saco el modulo de 5 al indice
//   dependiendo del resultado cifro con el respectivo alfabeto.
//   si albabeto[i] == la letra de cadena
//   guardamos la posicion letra de alfabeto
//   buscamo esa posicion en el alf[posicion de alfabeto]
//   remplazamos         


int main()
{

char cadena[50];
char alfabeto[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; 
char alf1[]    ="GHIJKLMNOPQRSTUVWXYZABCDEFghijklmnopqrstuvwxyzabcdef";
char alf2[]    ="EFGHIJKLMABCDNOPQRSTZUVWXYefghijklmabcdnopqrstzuvwxy";
char alf3[]    ="AZYBXCWDVEFUTGHSRIJQKPLMONazybxcwdvefutghsrijqkplmon";
char alf4[]    ="QRSTUVWXYZBACEDFHGJILKMONPqrstuvwxyzbacedfhgjilkmonp";
char alf5[]    ="DEGFIHJABCKOLMNPRQTSVUZXYWdegfihjabckolmnprqtsvuzxyw";
int modulo[sizeof(cadena)],veces;


cout << "Introduce la cadena a cifrar: ";
cin.getline(cadena,50);

for(int i(0),x(1); cadena[i]; i++,x++)
{
         veces=1;  
                  
         modulo[i] = x%5; // el modulo es igual al indice modulo de 5
         
         if(modulo[i] == 0)  // si el modulo es igual a 0
         modulo[i] = x;    //el modulo pasa ser igual que el indice  
                      
         
         if(modulo[i] == 1) // primer alfabeto
         {
          while(veces <= 2) // se debe cifrar dos veces
          { 
                  
                for(int x = 0; alfabeto[x]; x++)  //busco la letra en el alfabeto  
              {
               
                  if(cadena[i] == alfabeto[x]) //si la encuentro
                 {
                    cadena[i] = alf1[x];   //remplazo
                    break; //salgo
                 }   
                   
              }
               veces++;
           }
         }
         
         if(modulo[i] == 2)
         {
         while(veces <= 2)
          {
          
              for(int x = 0; alfabeto[x]; x++)
               {
                  if(cadena[i] == alfabeto[x])
                  {
                  cadena[i] = alf2[x];
                  break;
                  }
                 
               }
           veces++;
          }
         
          }
         
         if(modulo[i] == 3)
         {
         
         while(veces <= 2)
          {
          
            for(int x = 0; alfabeto[x]; x++)
            {
                  if(cadena[i] == alfabeto[x])
                  {
                  cadena[i] = alf3[x];
                  break;
            
                  }
            }
          veces++;
          }
          
          }     
         if(modulo[i] == 4)
         {
         while(veces <= 2)
          {
          
            for(int x = 0; alfabeto[x]; x++)
            {
                  if(cadena[i] == alfabeto[x])
                  {
                  cadena[i] = alf4[x];
                  break;
            
                  }
            }
             veces++;
           }
         }
         
         if(modulo[i] == 5)
         {
         while(veces <= 2)
          {
          
            for(int x = 0; alfabeto[x]; x++)
            {
                  if(cadena[i] == alfabeto[x])
                  {
                  cadena[i] = alf5[x];
                  break;
            
                  }
            }
           veces++;
          }
          
         }

}

cout << endl << endl << cadena;         
    
    
    setbuf(stdin, NULL);
    cin.get();
    
    return 0;
}
