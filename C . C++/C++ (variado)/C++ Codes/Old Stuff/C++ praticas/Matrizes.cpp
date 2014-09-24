#include <iostream> // << >>
using namespace std;

int main(){
  float matriz[5][3];
  int i;

for(i=1; i<=3; i++){
    cout << "Ingrese la " << i << " nota del alumno 1: ";
    cin >> matriz[1][i];
}
cout << "\n";
for (i=1; i<=3; i++){
    cout << "Ingrese la " << i << " nota del alumno 2: ";
    cin >> matriz[2][i];
    }
cout << "\n";

for(i=1; i<=3; i++){
    cout << "Ingrese la " << i << " nota del alumno 3: ";
    cin >> matriz[3][i];
}
cout << "\n";

for (i=1; i<=3; i++){
    cout << "Ingrese la " << i << " nota del alumno 4: ";
    cin >> matriz[4][i];
    }
    
cout << "\n";

for (i=1; i<=3; i++){
    cout << "Ingrese la " << i << " nota del alumno 5: ";
    cin >> matriz[5][i];
    }
    cout << "\n";
    
cout << "                  Nota 1\t    Nota 2\t    Nota 3    \n";

cout << "Alumno 1 |\t |   " << matriz[1][1] << "  |\t   |   " << matriz[1][2]  << "  |\t   |   "  << matriz[1][3] << "  | \n";
cout << "Alumno 2 |\t |   " << matriz[2][1] << "  |\t   |   " << matriz[2][2]  << "  |\t   |   "  << matriz[2][3] << "  | \n";
cout << "Alumno 3 |\t |   " << matriz[3][1] << "  |\t   |   " << matriz[3][2]  << "  |\t   |   "  << matriz[3][3] << "  | \n";
cout << "Alumno 4 |\t |   " << matriz[4][1] << "  |\t   |   " << matriz[4][2]  << "  |\t   |   "  << matriz[4][3] << "  | \n";
cout << "Alumno 5 |\t |   " << matriz[5][1] << "  |\t   |   " << matriz[5][2]  << "  |\t   |   "  << matriz[5][3] << "  | \n";

setbuf(stdin, NULL);
cin.get();
return 0;
}
    
