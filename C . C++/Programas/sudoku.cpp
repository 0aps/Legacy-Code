#include <iostream>
#include <vector>
using namespace std;
 
const int M=9;
 
//Lliurament 1
 
int primera_fila_grup (int x, int y){
 
  int k;
 
  if (0<=x and x<=2) k=0;
  if (3<=x and x<=5) k=3;
  if (6<=x and x<=8) k=6;
 
  return k;
}
 
int ultima_fila_grup (int x, int y){
 
  int k;
 
  if (0<=x and x<=2) k=2;
  if (3<=x and x<=5) k=5;
  if (6<=x and x<=8) k=8;
 
  return k;
}
 
int primera_columna_grup (int x, int y){
 
  int k;
 
  if (0<=y and y<=2) k=0;
  if (3<=y and y<=5) k=3;
  if (6<=y and y<=8) k=6;
 
  return k;
}
 
int ultima_columna_grup (int x, int y){
 
  int k;
 
  if (0<=y and y<=2) k=2;
  if (3<=y and y<=5) k=5;
  if (6<=y and y<=8) k=8;
   
  return k;
}
 
void omplir_possibles (vector<bool> &p){
   
  int i;
  i=0;
 
  while(i<M){
    p[i]=true;
    i++;
  }
}
 
void eliminar_possible (vector<bool> &p, int k){
 
  p[k-1]=false;
   
}
 
bool conte_possible (vector<bool> p, int k){
   
  bool e;
 
  if(p[k-1]==true) e=true;
  else e=false;
 
  return e;
       
}
 
int numero_possibles (vector<bool> p){
   
  int i, cont=0;
   
  for(i=0; i<M; i++){
    if(p[i]==true) cont++;
  }
   
  return cont;
   
}
 
int primer_possible (vector<bool> p){
   
  int i;
   
  i=0;
   
  while(p[i]!=true) i++;
   
  return i+1;
}
 
//Lliurament 2
 
void possibles (vector<vector<int> > t, int f, int c, vector<bool> &pos){
       
    omplir_possibles(pos);
     
    int i;
   
    //Recorrido-Possibles FILA
     
    for(i=0; i<M; i++){
      if(t[f][i]!=0) eliminar_possible(pos, t[f][i]);
    }
     
    //Recorrido-Possibles COLUMNA
     
    for(i=0; i<M; i++){
     if(t[i][c]!=0) eliminar_possible(pos, t[i][c]);
    }
     
    int w, z, x, y;
     
    w=primera_fila_grup(f, c);
    z=ultima_fila_grup(f, c);
    x=primera_columna_grup(f, c);
    y=ultima_columna_grup(f, c);
 
     
    //Recorrido-Possibles GRUP
     
    int j, k;
     
    for(j=0; j<3; j++){
      for(k=0; k<3; k++){
    if(t[w+j][x+k]!=0) eliminar_possible(pos, t[w+j][x+k]);
      }
  }
 
}
 
void omplir (vector<vector<int> > &t){
   
  int i, j;
   
  for(i=0; i<M; i++){
    for(j=0; j<M; j++){
      cin>>t[i][j];
    }
  }
   
}
 
void escriure (vector<vector<int> > t){
   
  int i, j;
   
  for(i=0; i<M; i++){
    for(j=0; j<M; j++){
      if(j==2 or j==5){
    if(t[i][j]==0) cout<<". | ";
    if(t[i][j]!=0) cout<<t[i][j]<<" | ";
      }
      else{
    if(t[i][j]==0) cout<<". ";
    if(t[i][j]!=0) cout<<t[i][j]<<" ";
      }
    }
    if(i==2 or i==5) cout<<endl<<"------+-------+-------"<<endl;
    else cout<<endl;
  }
   
}
 
bool queden_buides (vector<vector<int> > t){
   
  int i, j;
  i=0;
   
  bool k=false;
   
  /* for(i=0; i<M and !k; i++){
     for(j=0; j<M and !k; j++){
     k=t[i][j]==0;
     }
     }  */
  //També és pot fer amb for
   
  while(i<M and !k){
    j=0;
    while(j<M and!k){
      k=t[i][j]==0;
      j++;
    }
    i++;
  }
 
  return k;
}
 
//Lliurament 3
 
bool obligat_fila (vector<vector<int> > t, int f, int c, int n){
   
  vector<bool> pos(9, true);
  int i;
  bool k=true;
     
  for(i=0; i<M and k; i++){
    if(i!=c){
      if(t[f][i]==n) k=false;
      if(t[f][i]==0){
    possibles(t, f, i, pos);
    if(conte_possible(pos, n)) k=false;
      }
    }
  }
  return k;
}
 
bool obligat_col (vector<vector<int> > t, int f, int c, int n){
   
  vector<bool> pos(9, true);
  int i;
  bool k=true;
   
  for(i=0; i<M and k; i++){
    if(i!=f){
      if(t[i][c]==n) k=false;
      if(t[i][c]==0){
    possibles(t, i, c, pos);
    if(conte_possible(pos, n)) k=false;
      }
    }
  }
  return k;  
}
 
bool obligat_grup (vector<vector<int> > t, int f, int c, int n){
   
  vector<bool> pos(9, true);
  int i, j;
  bool k=true;
   
  int w, z, x, y;
     
  w=primera_fila_grup(f, c);
  z=ultima_fila_grup(f, c);
  x=primera_columna_grup(f, c);
  y=ultima_columna_grup(f, c);
   
  for(i=0; i<3 and k; i++){
    for(j=0; j<3 and k; j++){
      if(w+i!=f or x+j!=c){
    if(t[w+i][x+j]==n) k=false;
    if(t[w+i][x+j]==0) {
      possibles(t, w+i, x+j, pos);
      if(conte_possible(pos, n)) k=false;
    }
      }
    }
  }
  return k;
}
 
//Lliurament 4
 
bool algun_segur (vector<vector<int> > &t, int f, int c){
   
  int n;
  bool k=false;
   
  for(n=1; n<=M; n++){
    if(obligat_fila(t, f, c, n)){
      t[f][c]=n;
      k=true;
    }
    if(obligat_col(t, f, c, n)){
      t[f][c]=n;
      k=true;
    }
    if(obligat_grup(t, f, c, n)){
      t[f][c]=n;
      k=true;
    }
  }
  return k;
}
 
int main(){
  vector<int> col(M, 0);
  vector<vector<int> > taula (M, col);
  vector<bool> p (M);
     
  cout<<"Entreu sudoku, linies de 9 digits separats per blanc. Poseu zero a les caselles buides."<<endl<<endl;
  omplir(taula);
  cout<<endl;
   
  int i, j;
 
  bool hacanviat=true;
   
  while(queden_buides(taula) and hacanviat){
    hacanviat=false;
    cout<<"Resolent sudoku:"<<endl<<endl;
    escriure(taula);
    cout<<endl;
    for(i=0; i<M; i++){
      for(j=0; j<M; j++){
    if(taula[i][j]==0){
      algun_segur(taula, i, j);
      if(algun_segur(taula, i, j)){
        cout<<"A la casella ("<<i<<","<<j<<") hi ha d'anar un "<<taula[i][j]<<endl;
        hacanviat=true;
      }
    }
      }
    }
    cout<<endl;
  }
  if(!queden_buides(taula)){
    cout<<"Resolent sudoku:"<<endl<<endl;
    escriure(taula);
    cout<<endl<<"RESOLT !!"<<endl;
  }
  if(!hacanviat){
    cout<<"El sudoku és massa difícil"<<endl;
  }}
