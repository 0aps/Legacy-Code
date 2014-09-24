#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using std::ifstream;
using std::vector;
using std::cout;
using std::endl;

struct nodo
{
    nodo(): izd(NULL), der(NULL) {};
    int val;
    struct nodo* izd;
    struct nodo* der;
};

void inserta(struct nodo** raiz, int num)
{

    if( !(*raiz) )
    {
        *raiz = new struct nodo;
        (*raiz)->val = num;
    }
    else
    {

        std::deque<struct nodo*>  cola;
        cola.push_back(  *raiz  );

        while(true)
        {
            struct nodo *n = cola.front();
            cola.pop_front();

            if( !n->izd ) {
                n->izd = new struct nodo;
                n->izd->val = num;
                break;
            } else {
                cola.push_back(n->izd);
            }

            if( !n->der ) {
                n->der = new struct nodo;
                n->der->val = num;
                break;
            } else {
                cola.push_back(n->der);
            }
        }
    }
}

vector<int> create_input(vector<int> input, vector<int> *a_pasada, vector<int> a_feo_pasado)
{
    int tam = a_pasada->size(), i(0), j(0);
    if(!tam || tam == 1) return *a_pasada = a_feo_pasado = input;


    vector<int> nuevo;
    std::map<int, std::pair<int, int> > pares;
    std::queue<int> nums;

    while( j < tam)
    {
        nums.push(input[i]);

        if(i >= 1)
        {
            pares[ a_pasada->at(j) ] = std::make_pair( nums.front(), nums.back() );
            nums.pop();
            j++;
        }
        i++;

    }

    *a_pasada = input;
    for(int i = 0, tam = a_feo_pasado.size(); i < tam; i++ )
    {
       nuevo.push_back( (pares[a_feo_pasado.at(i) ] ).first );
       nuevo.push_back( (pares[a_feo_pasado.at(i) ] ).second );
    }

    return nuevo;
}


void cargar(struct nodo ** raiz)
{
    int num, i(0), nivel(1);
    vector<int> input, pasado, feo_pasado;

    ifstream file("triang.txt");

    while( file >> num )
    {
        input.push_back(num);
        if (++i == nivel)
        {
            feo_pasado = create_input(input, &pasado, feo_pasado);
            for(int i = 0; i < feo_pasado.size(); i++)
            {
                inserta(raiz, feo_pasado[i]);
            }

            input.clear();
            nivel++;
            i=0;
        }
    }

}


void preorden(struct nodo* raiz, int *suma, int tmp=0)
{
    if(raiz)
    {
        //cout << raiz->val << '\t';
        tmp += raiz->val;

        preorden(raiz->izd, suma, tmp);
        preorden(raiz->der, suma, tmp);

        if(*suma < tmp) *suma = tmp;
        tmp -= raiz->val;
    }
}




int main()
{
    int suma(0);
    struct nodo* raiz = NULL;

    cargar(&raiz);
    preorden(raiz, &suma);

    cout << suma << endl;

    return 0;
}



//funciona igual que el metodo de preorden, pero iterativo :P
/*
void DFS(struct nodo *start)
{
    int sum = 0;
    std::stack<struct nodo *> q;
    q.push(start);

    while (q.size() != 0)
    {
        struct nodo *next = q.top();

        cout << next->val;
        q.pop();
        if (next->der)
            q.push(next->der);
        if (next->izd)
            q.push(next->izd);

    }
}
*/



/*

void BFS(struct nodo *start)
{
    std::deque<struct nodo *> q;
    q.push_back(start);
    while (q.size() != 0)
    {
        struct nodo *next = q.front();
        cout << next->val;

        q.pop_front();
        if (next->izd)
            q.push_back(next->izd);
        if (next->der)
            q.push_back(next->der);
    }
}*/



