#include <iostream>

using namespace std;

class alumno{
      
      int nota, acc;
      
      public:
             alumno() : nota(0), acc(0) {};
             void tomar_n(int);
             int promedio() { return nota/acc; };
};

void alumno::tomar_n (int x)
{
    cin >> x;
    nota += x;
    acc++;
}


int main()
{
    alumno *alum;
    int a, n, aux;
    
    std::cout << "Cuantos alumnos hay? "; std::cin >> a;
    std::cout << "Cuantas notas son? "; std::cin >> n;
    
    alum = new alumno[a];
    
    for(int i(0); i < a; i++,alum++)
         {
           for(int x(0); x < n; x++)
                 alum->tomar_n(aux);             
          cout << "Promedio del alumno " << i+1
               << ": " << alum->promedio() << endl;
          }
    
    setbuf(stdin,  NULL);
    cin.get();
    
    return 0;
}      
