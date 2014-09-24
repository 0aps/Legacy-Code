// alea.c: Ejemplo de ficheros de acceso aleatorio.
#include <stdio.h>
#include <stdlib.h>
 
struct stRegistro {
   char valido;  // Campo que indica si el registro es válido S->Válido, N->Inválido
   char nombre[34];
   int dato[4];
};

int Menu();
void Leer(struct stRegistro *reg);
void Mostrar(struct stRegistro *reg);
void Listar(long n, struct stRegistro *reg);
long LeeNumero();
void Empaquetar(FILE **fa);
 
int main()
{
   struct stRegistro reg;
   FILE *fa;
   int opcion;
   long numero;
   fa = fopen("alea.dat", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("alea.dat", "w+b");  // si el fichero no existe, lo crea.
   do {
      opcion = Menu();
      switch(opcion) 
      {
         case '1': // Añadir registro
            Leer(&reg);
            // Insertar al final:
            fseek(fa, 0, SEEK_END);
            fwrite(&reg, sizeof(struct stRegistro), 1, fa);
            break;
         case '2': // Mostrar registro
            system("cls");
            printf("Mostrar registro: ");
            numero = LeeNumero();
            fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
            fread(&reg, sizeof(struct stRegistro), 1, fa);
            Mostrar(&reg);
            break;
         case '3': // Eliminar registro
            system("cls");
            printf("Eliminar registro: ");
            numero = LeeNumero();
            fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
            fread(&reg, sizeof(struct stRegistro), 1, fa);
            reg.valido = 'N';
            fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
            fwrite(&reg, sizeof(struct stRegistro), 1, fa);
            break;
         case '4': // Mostrar todo
            rewind(fa);
            numero = 0;
            system("cls");
            printf("Nombre                             Datos\n");
            while(fread(&reg, sizeof(struct stRegistro), 1, fa))
               Listar(numero++, &reg);
            system("PAUSE");
            break;
         case '5': // Eliminar marcados
            Empaquetar(&fa);
            break;
      }
   } while(opcion != '0');
   fclose(fa);
   return 0;
}
 
// Muestra un menú con las opciones disponibles y captura una opción del usuario
int Menu()
{
   char resp[20];
   do {
      system("cls");
      printf("MENU PRINCIPAL\n");
      printf("--------------\n\n");
      printf("1- Insertar registro\n");
      printf("2- Mostrar registro\n");
      printf("3- Eliminar registro\n");
      printf("4- Mostrar todo\n");
      printf("5- Eliminar registros marcados\n");
      printf("0- Salir\n");
      fgets(resp, 20, stdin);
   } while(resp[0] != '0' && resp[0] > '5');
   return resp[0];
}
 
// Permite que el usuario introduzca un registro por pantalla
void Leer(struct stRegistro *reg)
{
   int i;
   char numero[6];
   system("cls");
   
   printf("Leer registro:\n\n");
   reg->valido = 'S';
   
   printf("Nombre: ");
   fgets(reg->nombre, 34, stdin);
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   
   i = strlen(reg->nombre)-1;
   
   if( reg->nombre[i] == '\n' )
      reg->nombre[i] = 0;
      
   for(i = 0; i < 4; i++) 
   {
      printf("Dato[%1d]: ", i);
      fgets(numero, 6, stdin);
      reg->dato[i] = atoi(numero);
   }
}
 
// Muestra un registro en pantalla, si no está marcado como borrado
void Mostrar(struct stRegistro *reg)
{
   int i;
   system("cls");
   if(reg->valido == 'S') 
   {
      printf("Nombre: %s\n", reg->nombre);
      for(i = 0; i < 4; i++) printf("Dato[%1d]: %d\n", i, reg->dato[i]);
   }
   system("PAUSE");
}
 
// Muestra un registro por pantalla en forma de listado,
// si no está marcado como borrado
void Listar(long n, struct stRegistro *reg)
{
   int i;
   if(reg->valido == 'S')
    {
      printf("[%d] %s", n, reg->nombre);
      for(i = 0; i < 4; i++) printf(", %4d", reg->dato[i]);
      printf("\n");
    }
}
 
// Lee un número suministrado por el usuario
long LeeNumero()
{
   char numero[6];
   fgets(numero, 6, stdin);
   return atoi(numero);
}
 
// Elimina los registros marcados como borrados
void Empaquetar(FILE **fa)
{
   FILE *ftemp;
   struct stRegistro reg;
   
   
   
   ftemp = fopen("alea.tmp", "wb");
   rewind(*fa);
   
   getchar();
   while(fread(&reg, sizeof(struct stRegistro), 1, *fa))
      
      if(reg.valido == 'S')   fwrite(&reg, sizeof(struct stRegistro), 1, ftemp);
      fclose(ftemp);
   
   fclose(*fa);
   remove("alea.bak");
   rename("alea.dat", "alea.bak");
   rename("alea.tmp", "alea.dat");
   *fa = fopen("alea.dat", "r+b");
}
