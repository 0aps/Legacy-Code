//    Read bhaarat.text and read the language names beginning with an "S" or "H", and write them 
//    only the language names!) to a file named out.text
//    otput can be flexible, however, it cannot include the original numbers and some sort of 
//    whitespace should separate the words (newlines if you are going for extra credit). 
//    Extra credit for correctly numbered lines.
//    The language "English" and its number and period is then added to the original file in 
//    continuation of the list.

#include <fstream>
#include <iostream>
#include <string>

                       //lang solo guarda hasta el espacio
                       //por ejemplo:
                       // primera linea:
                       //1. hola
                       //guarda '1.'
                       //luego en la prox interaccion
                       //guarda 'hola'
  

using namespace std;

int main() {

    ifstream inputFile("libro.txt"); //the input file
    string lang; //holds the languages as they are gotten from the file
    
    ofstream outFile("out.text"); //the output file
    int lineNum = 1; //keeps track of which line in the output we are up to
    
    //me coloco en la ultima posicion del archivo
    //devuelvo todos los bytes que ocupa el archivo a pos.    
    inputFile.seekg(0, ios::end); 
    int pos = inputFile.tellg(); 
    //como no necesito esto ya que 'harcodee' el num de palabras
    pos = 23051;  
    
    
    //creo un puntero a un puntero que apunta a un char
    //creo un puntero que apunta a un arrey de chars de 500 bytes
        char **cadena = new char* [pos];
    
    //creo un arrey de 100 chars para cada elemento del puntero a arrey
        for(int i = 0; i < pos; i++) 
        cadena[i] = new char[100];
 
 
    
    // me coloco en la primera parte de archivo.
       inputFile.seekg(0, ios::beg); 

    
    /* parts of the file are read one at a time, deliminated by whitespace */
    while (!inputFile.eof()) 
    {
          
           for(int i=0; i < pos; i++)
           {
              inputFile >> cadena[i]; 
              cout << cadena[i];
              if(!strcmp(cadena[i],"BERGANZA.-") );
              lineNum++; 
           }
}
    
    cout << "El numero de veces que aparece Berganza es: " << lineNum << endl;
 
    inputFile.close();
    outFile.close();

    /* appends "23. " to the file" */
   // ofstream appendFile("bhaarat.txt", ios::app);
   // appendFile << endl << "23. English" << endl;
   // appendFile.close();

    for(int i = 0; i < pos; i++) delete[] cadena[i];
    delete[] cadena;

    cout << "done" << endl;
    cin.get();
}  
