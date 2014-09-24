#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//Colocar menu
// Redisenyar estructura del programa
// Reparar bugs con '\\' al momento de crearse el archivo.
//@aps - 9/7/11


void procedimiento(); 

    char archivo[100], ruta[100], nArchivo[100];
    char ruta2[100];
 
 
int main(int argc, char *argv[])
{
    
    cout << "Escribe el nombre del archivo: ";
    cin.getline(archivo, 100);
    
    cout << "Escribe la ruta."
         << "\nNota: si no se escribe la ruta el archivo se creara en [C:\\]"
         << "\nNota2: si se escribe mal la ruta el archivo se creara en el directorio actual."
         << "\n\nRuta: ";
    cin.getline(ruta, 100);

  if(strcmp (ruta, "" ) == 0)
  {
           cout << endl 
                << "No se espesifico la ruta, el archivo [" << archivo << "] se creara en [C:\\].";
           strcpy(ruta, "C:\\");
           strcat(ruta, archivo); 
           ofstream myfile(ruta);
 
    if(myfile.good())
    cout << endl << endl 
         << "Archivo creado con exito.";
    else 
    cout << endl 
         << "No se pudo crear el archivo.";
    
   }
                            
                            else 
                            {
                                  strcat(ruta, archivo);
                            
                                  ofstream myfile(ruta);

                               if(myfile) 
                                    cout << endl << endl 
                                         << "Archivo creado con exito";
                               
                               else cout <<  endl 
                                         << "No se pudo crear el archivo";
                            }
                            
char  opcion[10];
                 cout << endl << "Desea salir o renombrar el archivo: ";
                 cin.getline(opcion, 100);

       if(opcion[0] == ' ')
          exit(0);
       else if(opcion[0] == 's')
          exit(0);
       else if(opcion[0] == 'S')
          exit(0);
       
         else if(opcion[0] == 'r')
       {
          procedimiento();         
       }
       else if(opcion[0] == 'R')
       {
            procedimiento();
       }


    setbuf(stdin, NULL);
    cin.get();
    return 0;
}
 

void procedimiento()
{
     
          setbuf(stdin, NULL);
 
          cout << "Ruta: ";
          cin.getline(ruta, 100);
 
          cout << "Archivo: " ;
          cin.getline(archivo, 100);
  
          cout << "Nuevo nombre: ";
          cin.getline(nArchivo, 100);
 
 strcpy(ruta2, ruta);
 strcat(ruta, archivo);
 strcat(ruta2, nArchivo);
 
                  if (rename(ruta ,ruta2) == 0 )
    
                  {
                     cout << endl << "Se renombro el archivo"<<endl;
                  }
             else
                     cout << endl 
                          << "No se pudo renombrar archivo"
                          << endl;
}
