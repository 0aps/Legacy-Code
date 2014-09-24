// DisplayString - output a character array to 
// standard output, the MS-DOS window 
#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
#include <string> 
using namespace std; 
// prototype declarations 
void displayString(char stringArray[]); 
int main(int nNumberofArgs, char* pszArgs[]) 
{ 
char charMyName[] = {"Angel Piña"};
displayString(charMyName); 
// wait until user is ready before terminating program 
// to allow the user to see the program results 
system("PAUSE"); 
return 0; 
} 
// displayString - display a character string 
// one character at a time 
void displayString(char stringArray[]) 
{ 
for(int i = 0; stringArray[i]; i++) 
{ 
cout << stringArray[i]; 
} 
}
