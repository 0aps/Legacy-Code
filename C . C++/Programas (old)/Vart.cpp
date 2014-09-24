#include <iostream.h>
#include <stdio.h>
#include <ctype.h>

 struct datos
 {
  char nombre[30];
  int matricula;
  char carrera[30];
  char semestre[30];
  int calificacion;
  int calprom;       
       };
       
  main()
  {
  struct datos alumnos[10];
  int total=0;
  int cont=0;
    while (cont < 2) {
    cont++;
     cout << "Ingrese los datos de cada alumno\n ";
     cout << "ingrese el nombre del alumno numero: " << (cont) << "\n";
     cin >> alumnos[cont].nombre;
     }
  return 0;
        }
