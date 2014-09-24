/* Caribbean Online Judge
* Problema: 1003 - General Election
* Categoria: Ad hoc
*
* Israel Leiva - 10-11-2011
*/
#include <iostream>
using namespace std;

/* Cada candidato se representa como una casilla en un arreglo. En el
* se van guardando los datos para luego encontrar el mayor */
int main(){
int tc, i, j, k, N, M, votes, max_votes, winner, cand[5] = {0};

cin >> tc;

for(i=0;i<tc;i++){
                  cin >> N >> M;
                  for(j=0;j<M;j++){
                        for(k=0;k<N;k++){
                                         cin >> votes;
                                         cand[k] += votes;
                                         cout << cand[k] << endl;
                                         }
                                  }

}
return 0;
}
