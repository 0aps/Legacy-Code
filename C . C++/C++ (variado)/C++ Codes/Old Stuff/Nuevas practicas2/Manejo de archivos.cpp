#include <iostream> //<< >>
using namespace std;

int main(int argc, char *argv)
{
    FILE *archivo;
    archivo=fopen("Hola.txt", "a");
    fprintf(archivo, "Hola mundo\n");
    fclose(archivo);
    return 0;
}
