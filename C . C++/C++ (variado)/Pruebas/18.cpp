#include <iostream>

using namespace std;

void a_lo_que_apunta_el_puntero(char *cad, int * num)
{
     cout << "la direcion de cad es: " << &cad
          << " (observa que ahora tenemos otro puntero)" << endl
          << "cad apunta a: " << (void*)cad << endl
          << "la cual es la direccion que pasamos para que otro puntero le apunte. :P" << endl;


     cout << "la direcion de num es: " << &num
          << " (observa que ahora tenemos otro puntero)" << endl
          << "num apunta a: " << (void*)num << endl
          << "la cual es la direccion que pasamos para que otro puntero le apunte. :P" << endl;

     int a = 5;
     num = &a;

     char *tmp = new char[10];
     cad = tmp;

     cout << "tmp apunta a: " << (void*)tmp << endl
          << "cad apunta a la misma direccion: " << (void*)cad << endl << endl;

     cout << "a apunta a: " << &a << endl
          << "num apunta a la misma direccion: " << (void*)num << endl << endl;

}

// &cad    = direccion del doble puntero
//  cad    = direccion del puntero al que apunta el doble puntero
//  *cad   = direccion a la que apunta el puntero que apunta el doble puntero
// *(*cad) = valor de la direccion apuntata por el puntero al que apunta el doble puntero

// *cad = tmp  hacer que cambie la direccion a la que apunta el puntero apuntado por el doble puntero
// cad = &tmp cambiar la direccion a la que apunta el doble puntero
void direccion_del_puntero(char **cad, int **num)
{
     cout << "la dir del doble puntero es " << &cad << endl
          << "la dir del d.puntero es: " << cad << " (nuestro puntero original)" << endl
          << "y apunta a: " << (void*)*cad << endl
          << "y vale: " << *cad << endl;

     cout << "la dir del doble puntero es " << &num << endl
          << "la dir del puntero es: " << num << " (nuestro puntero original)" << endl
          << "y apunta a: " << (void*)*num << endl
          << "y vale: " << *(*num);

     char *tmp = new char[10];
     *cad = tmp;
     //strncpy((*cad), "feo", strlen("feo"));

     //int a = 15; // CASO CURIOSO ESTA VARIABLE SE LIBERA CUANDO TERMINA LA
                 //   FUNCION Y QUEDA UN VALOR ARBITRARIO EN ELLA
     int *a = new int(15);
     *num = a;
     *(*num) = 30;


     cout << "\ntmp apunta a: " << (void*)tmp << endl
          << "cad apunta a la misma direccion: " << (void*)*cad << endl;

     //cout << "\na apunta a: " << &a << endl
     //     << "y vale: " << a << endl
     //     << "num apunta a la misma direccion: " << (void*)*num << endl;

     cout << "\na apunta a: " << a << endl
          << "y vale: " << *a << endl
          << "num apunta a la misma direccion: " << (void*)*num << endl;

}

int main()
{
    char *cad = "hola";
    int *num = new int(10);

    cout << "La direccion del puntero es: " << &cad << endl
         << "esta apuntando a: " << (void*)cad << endl
         << "y tiene el valor: " << cad << endl;


    cout << "La direccion del puntero es: " << &num << endl
         << "esta apuntando a: " << num << endl
         << "y tiene el valor: " << *num << endl;

    cin.get();

    a_lo_que_apunta_el_puntero(cad, num);

    cout << "\nLa direccion del puntero es: "<< &cad << endl
         << "esta apuntando a: " << (void*)cad << endl
         << "y tiene el valor: " << cad << endl;

    cout << "La direccion del puntero es: " << &num << endl
         << "esta apuntando a: " << (void*)num << endl
         << "y tiene el valor: " << *num << endl;

    cin.get();

    direccion_del_puntero(&cad, &num);

    cout << "\nLa direccion del puntero es: "<< &cad << endl
         << "esta apuntando a: " << (void*)cad << endl
         << "y tiene el valor: " << cad << endl;

    cout << "La direccion del puntero es: " << &num << endl
         << "esta apuntando a: " << num << endl
         << "y tiene el valor: " << *num << endl;
    cin.get();

    return 0;
}

