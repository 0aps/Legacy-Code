#include <stdio.h>
#include <string.h>

int great(int *arrey, int x)
{
    int mayor = 1,pos,i=0;
    while(x--)
    {
              if (mayor < arrey[i])
                        {
                                   mayor = arrey[i];
                                   pos = i;
                        }
    }
    return pos;
}

int main()
{
    int t,n,m;
    char str[100];
    char *paux;
    
    scanf("%d", &t);
    
    while(t--)
    {
              scanf("%d %d", &n, &m);
              
              int g[n],a[n],aux;
              memset(g,0, n);
              
              while(m--)
              {
                       //    scanf("%s", str);
                       //    printf("%s\n", str);
                       //    paux = strtok (str," ");
                           aux = 0;
                           while(n--){
                                      scanf("%d", a[aux]);
                                      g[aux] += a[aux];  
                       //               g[aux] += atoi(paux);
                       //               paux = strtok(NULL, " ");
                                      aux++;
                                      }              
              }
              printf("%d", great(g, aux-1));  
    }                                  
    setbuf(stdin, NULL);
    getchar();
    return 0;
}             
