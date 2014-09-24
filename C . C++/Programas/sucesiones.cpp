#include <iostream>
#include <cmath>

/*
  Name: E_l_sucesiones
  Copyright: GPL
  Author:@Aps 
  Date: 16/01/13 19:05
  Description: Evalua los primeros diez términos de una división de polinomios. 
  
  Bugs:        Sólo funciona bien con polinomios simples.
               Hay que mejorar el algoritmo que es una chapuza. 
*/


using namespace std;

void evaluar(char *n_bucle, int bucle, char *nombre, char *cadena, char *i_nombre, double entero);

int main(int argc, char **argv)
{
    //argv[1] = "[x^2+7] / [x^2-4]";
    char *buf, *buf2, *temp, *mtemp, **temp2;
    double p1(0),p2(0),total;
    
    buf = new char[250], buf2 = new char[250], temp2 = new char*[250];
    strncpy(buf, argv[1], 250),  strncpy(buf2, strstr(argv[1], "/ ["), 250);
    temp = buf, mtemp = buf2, buf-=1, buf2+=1;
      
    for(int x(48),y(0), z(0);
          y < 10; 
          y++, x++, p1=0, p2=0, buf = temp-1, buf2 = mtemp+1, temp2[z][0] = 'x')
    {
      while(*buf++ != ']')
      {
                  
                    if(*buf == '[')
                    {
                        if(*(buf+1) == 'x') 
                        {
                          temp2[z] = (buf+1); *(buf+1) = x;
                          p1 += atoi( buf+1 ); z++;
                        }   
                        
                        else 
                         p1 += atoi( buf+1 );
                    }           
                     
                    if(*buf == '^')   
                    {
                           
                        //Si x^2
                        if(*(buf-1) == 'x' && *(buf+1) != 'x') 
                        {
                                  
                          temp2[z] = (buf-1); *(buf-1) = x;
                          p1 = pow( atof(buf-1), atof(buf+1) ); z++;
                        }   
                        
                        //Si 2^2
                        else if(*(buf-1) != 'x' && *(buf+1) != 'x')
                           p1 = pow( atof(buf-1), atof(buf+1) );
                    
                        //Si 2^x   
                        if(*(buf+1) == 'x' && *(buf-1) != 'x') 
                        {
                                    
                          temp2[z] = (buf+1); *(buf+1) = x;
                          p1 = pow( atof(buf-1), atof(buf+1) ); z++;
                        }   
                    }      
                         
                    if( *buf == '/')
                    {
                        if(*(buf+1) == 'x') 
                        {
                          temp2[z] = (buf+1); *(buf+1) = x;
                          p1 /= atoi( buf+1 ); z++;
                        }   
                        
                        else 
                         p1 /= atoi( buf+1 );
                    }      
      
                    if( *buf == '*')
                    {
                        if(*(buf+1) == 'x') 
                        {
                          temp2[z] = (buf+1); *(buf+1) = x;
                          p1 *= atoi( buf+1 ); z++;
                        }   
                        
                        else 
                         p1 *= atoi( buf+1 );
                    }      
                    
                    if( *buf == '+')
                    {
                        if(*(buf+1) == 'x') 
                        {
                          temp2[z] = (buf+1); *(buf+1) = x;
                          p1 += atoi( buf+1 ); z++;
                        }   
                        
                        else 
                         p1 += atoi( buf+1 );
                    }              
                    
                    if( *buf == '-')
                    {
                        if(*(buf+1) == 'x') 
                        {
                          temp2[z] = (buf+1); *(buf+1) = x;
                          p1 -= atoi( buf+1 ); z++;
                        }   
                        
                        else 
                         p1 -= atoi( buf+1 );
                    }      
      
      }
      
     while(z-- != 0)
     {         
        temp2[z][0] = 'x';
     }z++;
      
      while(*buf2++ != ']')
      {     
                    if(*buf2 == '[')
                    {
                       if(*(buf2+1) == 'x') 
                        {
                          temp2[z] = (buf2+1); *(buf2+1) = x;
                          p2 += atoi( buf2+1 ); z++;
                        }   
                        else 
                         p2 += atoi( buf2+1 );
                    }
                    
                    if(*buf2 == '^')   
                         p2 = pow( atof(buf2-1), atof(buf2+1) );
                   
                   if( *buf2 == '/')
                         p2 /= atoi(buf2+1);
                    
                    if( *buf2 == '*')
                         p2 *= atoi(buf2+1);
                    
                    if( *buf2 == '+')
                         p2 += atoi(buf2+1);
                                  
                    if( *buf2 == '-')
                         p2 -= atoi(buf2+1);
      }
      
              total = p1/p2;  
              
      evaluar("y",y,0,0,"p1", p1);
      evaluar("y",y,0,0,"p2", p2);
      evaluar("y",y,0,0,"total", total);  
      cin.get();
      }

     delete[] buf,buf2;
    
     setbuf(stdin, NULL);
     return 0;
}

void evaluar(char *n_bucle, int bucle, char *nombre, char *cadena, char *i_nombre, double entero)
{
     if(nombre != 0 && n_bucle == 0 )
     {
               if(cadena == 0) cadena = "NULL";
               cout << nombre << ": " << cadena << endl; 
     }    

     if(i_nombre != 0 && n_bucle == 0)
     cout << i_nombre << ": " << entero << endl;

     if(n_bucle != 0 && nombre != 0 && cadena != 0) 
     cout << n_bucle << "(" << bucle << "): " << nombre << ": " << cadena << endl; 
 
     if(n_bucle != 0 && i_nombre != 0)
     cout << n_bucle << "(" << bucle << "): " << i_nombre << ": " << entero << endl; 
 
}


    //for(float n=300000000; n!=1000000000; n++)
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
    
