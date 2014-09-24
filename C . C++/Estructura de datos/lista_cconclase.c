#include <stdlib.h>
#include <stdio.h>
 
typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;
 

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
 
/* Funciones con listas: */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
 
int ListaVacia(Lista l);
 
void BorrarLista(Lista *);
void MostrarLista(Lista l);
 
int main() {
   Lista lista = NULL;
   pNodo p;
 
   Insertar(&lista, 20);
   
   printf("%p,%d", lista->siguiente, lista->valor);
   getchar();
   
   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);

   MostrarLista(lista);
   getchar();
   Borrar(&lista, 10);
   Borrar(&lista, 15);
   Borrar(&lista, 45);
   Borrar(&lista, 30);
   Borrar(&lista, 40);

   MostrarLista(lista);
   
   BorrarLista(&lista);

   return 0;
}

void Insertar(Lista *lista, int v) {
   pNodo nuevo, anterior;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   
   /* Si la lista está vacía */ 
   if(ListaVacia(*lista) || (*lista)->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = *lista; 
      /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
      *lista = nuevo;
   } else {
      /* Buscar el nodo de valor menor a v */
      anterior = *lista;
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un valor mayor que v */
         printf("%p, %d", anterior->siguiente, anterior->valor);
         getchar();
      while(anterior->siguiente && anterior->siguiente->valor <= v) 
      {
         anterior = anterior->siguiente;
         printf("por qu'e co;os me ejecuto?");
         
      }
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = anterior->siguiente;
      
   printf("1 %p", nuevo->siguiente);
   getchar();
      anterior->siguiente = nuevo;
   }
}

void Borrar(Lista *lista, int v) {
   pNodo anterior, nodo;
   
   nodo = *lista;
   anterior = NULL;
   while(nodo && nodo->valor < v) {
      anterior = nodo; 
      nodo = nodo->siguiente;
   }
   if(!nodo || nodo->valor != v) return;
   else { /* Borrar el nodo */
      if(!anterior) /* Primer elemento */
         *lista = nodo->siguiente;
      else  /* un elemento cualquiera */
         anterior->siguiente = nodo->siguiente;
      free(nodo);
   }   
}

int ListaVacia(Lista lista) {
   return (lista == NULL);
}

void BorrarLista(Lista *lista) {
   pNodo nodo;

   while(*lista) {
      nodo = *lista;
      *lista = nodo->siguiente;
      free(nodo);
   }
}

void MostrarLista(Lista lista) {
   pNodo nodo = lista;

   if(ListaVacia(lista)) printf("Lista vacía\n");
   else {
      while(nodo) {
         printf("%d -> ", nodo->valor);
         nodo = nodo->siguiente;
     }
     printf("\n");
   }
}
