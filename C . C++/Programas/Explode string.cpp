#include <iostream>

using namespace std;

char **explode_string(char *, char);
int x(-1);
 

int main()
{
  char *string = "hola_angel_como_te_va______________";
  char **output = NULL;
  
  output = explode_string(string, '_');
  
  cout << "String original = " << string << endl;
  
  cout << "Por partes: " << endl;
  
  for(int i(0); i<= x; i++)
  cout << output[i] << endl;
      
  setbuf(stdin, NULL);
  cin.get();
}

char **explode_string(char * string, char var)
{
     char *aux = string;
         
      do
      {
         if(*aux == var)
              x++;
      }
      while(*aux++);
     
     char **output = new char *[x];
     
     for(int i(0); i <= x; i++) 
        output[i] = new char[100];
     
     for(int i(0); i <= x;  i++) 
     for(int z(0); z < 100; z++) 
        output[i][z] = '\0';
     

        for(int i(0);  *string; string++)
        { 
        
           for(int z(0); z < 100 || *string  ; z++, string++ )
              {         
           
                 if(*string == var)
                   {
                               i++;
                               break;
                   }
                     
                    output[i][z] = *string;
              }
                        
        }    
                        
  return output;
}
  
  
