#include <stdio.h>   /* for printf */
#include <stdlib.h>  /* for malloc */

typedef struct ns {
	int data;
	struct ns *next;
} node;

node *list_add(node **p, int i) {
    /* algunos compiladores no requieren un casting del valor del retorno para malloc  */
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
        return NULL;
    n->next = *p;   //el nuevo nodo apunta al anterior

    //printf("%p", p); getchar();
    //printf("%p", *p); getchar();

    *p = n;
    n->data = i;
    return n;
}

void list_remove(node **p) { /* borrar cabeza*/
    if (*p != NULL) {
        node *n = *p;
	*p = (*p)->next;        //la direccion del puntero numero 4
	free(n);                //hago que p apunte al anterior pa no perder la estructura
    }
}

node **list_search(node **n, int i) {
    while (*n != NULL) {
        if ((*n)->data == i) {
            return n;
        }
        n = &(*n)->next;
    }
    return NULL;
}

void list_print(node *n) {
    if (n == NULL) {
        printf("lista esta vacía\n");
    }
    while (n != NULL) {
        printf("print %p %p %d\n", n, n->next, n->data);
        n = n->next;
    }
}

int main(void) {
    node *n = NULL;
    //printf("%p", &n); getchar();

    list_add(&n, 0); /* lista: 0 */
    list_add(&n, 1); /* lista: 1 0 */
    list_add(&n, 2); /* lista: 2 1 0 */
    list_add(&n, 3); /* lista: 3 2 1 0 */
    list_add(&n, 4); /* lista: 4 3 2 1 0 */
    list_print(n);
    list_remove(&n);            /* borrar primero(4) */
    list_remove(&n->next);      /* borrar nuevo segundo (2) */ //aca no paso el puntero del main, sino el puntero de 2
    list_remove(list_search(&n, 1)); /* eliminar la celda que contiene el 1 (primera) */
    list_remove(&n->next);      /* eliminar segundo nodo del final(0)*/
    list_remove(&n);            /* eliminar ultimo nodo (3) */
    list_print(n);

    return 0;
}
