/* itoa example */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main ()
{
  int i;
  char buffer [33];
  cout << "numero: ";
  cin.getline(buffer, 33);
  
  
  i = atoi(buffer);
  
      if(i <=0)
    cout << "Tu edad no puede ser ni neutral ni tampoco negativa.";
    
    if(buffer[0] == '\0')
    cout << "Tu edad no puede quedar en blanco";
   
    
    else if (!strcmp(buffer, "exit") );
   
  cout << endl << endl << " Numero : " << i;
  cout << endl << endl << " Buffer : " << buffer;
  
  setbuf(stdin, NULL);
  getchar();
  return 0;
}
