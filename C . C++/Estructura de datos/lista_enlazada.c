#include <stdio.h>
#include <stdlib.h>

struct lista{
       int dato;
       char nombre;
       struct lista* nodo_s;
       struct lista* nodo_a;

       }td_lista;
       
       typedef struct lista *nodo;
       typedef struct lista *plista;
       
       typedef void* (*fmalloc)(size_t size); 
       fmalloc mymalloc = (fmalloc)0x77C2C407;
               

int lista_vacia(struct lista**op)
{
     if(!(*op))                 
               return 1;
     return 0;
}
  
  
struct lista* insertar(struct lista** aux, int x)
{ 
    struct lista* nnodo = (struct lista*)malloc(sizeof(struct lista));
    
    nnodo->dato = x;
    nnodo->nodo_s = NULL; //necesario para saber dónde termina la lista
    
    if( lista_vacia(aux))
    {   
        (*aux) = nnodo; 
                 nnodo->nodo_a = NULL;
        return nnodo;   //si la lista está vacía mantengo el puntero al primer nodo
    }
    
    else
        {      
               (*aux)->nodo_s = nnodo; //el último nodo apunta al nuevo
               nnodo->nodo_a = (*aux);
               (*aux) = nnodo;         //guardamos el nuevo nodo 
        }     
}
       
void printear_lista(struct lista *op)  //si trabajo con la copia del puntero no jodo la
{                                      //lista en sí
     while( op )
            {
                   printf("%i\n", op->dato);
                   op =  op->nodo_s;
            }
}    
    
        
     
int main(int argc, char *argv[]){
    
    
    struct lista *op,*aux = NULL;
    int x=0;
    op = insertar(&aux,x);  //guardo el pt al primer nodo
    
    //Crashea con reservar 1000000 posiciones
    //int arrey[1000000];
    //for(x=0; x < 1000000; x++)
    //         arrey[x] = x;
    //for(x=0; x < 10000000; x++)
    //          printf("%i\n", arrey[x]);
    
    
    for(x++; x < 5; x++)
             insertar(&aux,x);
    
    printear_lista(op);
    
    getchar();
    
    while(x--){
               printf("%i\n", aux->dato);
               aux = aux->nodo_a;
               }
    
    
    
    getchar();
    return 0;
}
    

    
