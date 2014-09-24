/* Write a program to take a person's forum name , age , forum user id 
(a postive integer equal to or between 1 and 999999). 
The program should ask for each datum individually, and not go to the next unless 
the previous was valid.  If there is an error, it must prompt again until it is write or 
the program is halted.The entry "quit" should exit the program at any question. */

/*
# User name can't begin with spaces, or have no characters in it. 
# It can truncate strings over 20, if needed.
# Age has to be positive and not 0. 
# It doesn't need a maximum, but you are free to make your program logical.
# User ID can't be negative or 0. The maximum I require is 999999.
# Typing "exit" should exit the program gracefully.
# The prompt should be logical.
# Most importantly, it must not crash, segfault, lockup, 
  or enter an infinite loop no matter what is entered 
*/


/*
  Name: Ejercicio #2
  Copyright: GPL 
  Author: @aps
  Date: 08/08/11 07:05
  Description: Realizando ejercicios que antes no pude. xP 
*/


#include <iostream> // << >>
#include <cstring>

using namespace std;


int caracteres(char[]);

int main(int argc, char *argv[])
{
    char nombre[20],aux[10];
    int edad, ID;
    
    
    
    cout << endl << "\t\t Bienvenido a Aps Gamming\n" << endl;
    cout << " \\\\ Escriba exit para salir en cualquier instancia // ";
    
while(true)
{
    cout << "\n\nIngrese su nombre: ";
    
    cin.getline(nombre, 20);
          
    if( !strcmp(nombre,"exit"))
    exit(1);
    
    else if(nombre[0] == ' ')
    cout << "Tu nombre no puede empezar con espacio.";
    
    else if(nombre[0] == '\0')
    cout << "Tu nombre no puede quedar en blanco.";
      
    else if( caracteres(nombre) == 0)
    break;
    
}
     
while(1)
{
    cout << "\nIngrese su edad: ";
    cin.getline(aux, 10);
    
    edad = atoi(aux);
    
    if (!strcmp(aux, "exit") )
    return 0;
    
    else if (edad <=0)
    cout << "Tu edad no puede ser ni neutral ni tampoco negativa.";
    
    else break;
}

while (true)
{
    cout << "\nIngrese su ID: ";
    cin.getline(aux, 10);
    
    ID = atoi(aux);

    if(!strcmp(aux, "exit") )
    return 0;

    else if(ID <= 0 || ID > 99999)
    cout << "Tu ID no puede ser negativa ni mayor de 99999";

    else break;    

}

    cout << "\n\nTu eres " << nombre 
         << "\nEdad "      << edad 
         << "el ano proximo tendras " 
         << edad + 1       << "\nTu ID de usuario es " 
         << ID 
         << ", el proximo usuario sera el " << ID + 1 << "." << endl;
         
    setbuf(stdin, NULL);
    cin.get();
    return 0;
    
}



/*
#include <string>
#include <cstring>

using namespace std;

bool no_character(string input)
{
    for (unsigned int i=0; i < input.size(); i++)
        {
            if(isalpha(input[i]))
                return false;
        }
    return true;
}

int main()
{
    string input;
    string name;
    int age;
    int usrid;

    cout << "Welcome to Shae's solution to Programming Challenge 2." << endl;
    cout << "Type exit and press enter to close this program." << endl;

    // While loop to take the input for the name
    while(1)
    {
        cout << "Please type your forum name and press enter: ";
        getline (cin, input, '\n');

        if (input == "exit")
            return 0;
        else if (input.size() == 0)
            cout << "Your forum name cannot be blank, please try again." << endl;
        else if (input[0] == ' ')
            cout << "Your forum name cannot start with a space, please try again." << endl;
        else if (no_character(input))
            cout << "Your forum name must contain a non-numerical character, please try again." << endl;
        else
        {
            name = input;
            break;
        }
    }

    // While loop to take the input for the age
    while(1)
    {
        cout << "Please type your age and press enter: ";
        getline (cin, input, '\n');
        age = atoi(input.c_str());

        if (input == "exit")
            return 0;
        else if (input.size() == 0)
            cout << "Your age cannot be blank, please try again." << endl;
        else if (input[0] == ' ')
            cout << "Your age cannot start with a space, please try again." << endl;
        else if (age < 1 || age > 120)
            cout << "Your age cannot be less than 1, greater than 120, and must be a number, please try again." << endl;
        else
            break;
    }

    // While loop to take the input for the user id
    while(1)
    {
        cout << "Please type your user id and press enter: ";
        getline (cin, input, '\n');
        usrid = atoi(input.c_str());

        if (input == "exit")
            return 0;
        else if (input.size() == 0)
            cout << "Your user id cannot be blank, please try again." << endl;
        else if (input[0] == ' ')
            cout << "Your user id cannot start with a space, please try again." << endl;
        else if (usrid < 1 || usrid > 999999)
            cout << "Your user id cannot be less than 1, greater than 999999, and must be a number, please try again." << endl;
        else
            break;
    }

    cout << "You are " << name << ", aged " << age << " next year you will be " << age + 1 << ", with user id " << usrid << ", the next user is " << usrid + 1 << "." << endl;
    return 0;
}
*/


int caracteres(char nombre[])
{
    for(int i(0); nombre[i]; i++) //hasta que no se llegue al final de cadena
    {
    
      if(nombre[i] < 'A' || nombre[i] > 'Z') // si algun caracter es menor que A
                                             // o es mayor que Z
         {
                                 
          if(nombre[i] >= 'a' && nombre[i] <= 'z') //si el caracter esta dentro de 
             {                                     // la 'a' a la 'z'. bien.
               continue;                           //de lo contrario salgo.
             }
        
               cout << "Tu nombre solo puede tener letras de la A-Z.";
               return 1;
                    
         }
    }
        
return 0;
}
