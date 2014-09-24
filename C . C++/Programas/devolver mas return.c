#include <windows.h>
 
void SayLong(int number)
{
  char Data[5];
  ltoa(number,Data,10);
  MessageBox(0,Data,"El Numero",0);
}
 
void return1(DWORD Valor) { __asm mov eax,Valor }
 
DWORD Trozear(char *str)
{
  DWORD Max = strlen(str);
  DWORD Palabras = 0;
  
  char **str_array = (char**)malloc(1*4); //un solo puntero a string
  str_array[0] = (char*)malloc(1024);
  ZeroMemory(str_array[0],1024);
 
  for (int x = 0;x < Max;x++)
  {
    DWORD Pos = strlen(str_array[Palabras]);
    if (str[x] == 32)
    {
      Palabras++;
      str_array = (char**)realloc(str_array,(Palabras+1)*4);
      str_array[Palabras] = (char*)malloc(1024);
      ZeroMemory(str_array[Palabras],1024);
    }
    str_array[Palabras][Pos] = str[x];
    str_array[Palabras][Pos+1] = 0;
  }
  __asm
  {
    mov ecx,[str_array]
  }
  return Palabras+1;
}
 
void main()
{
  DWORD Palabras = 0;
  char *texto = (char*)malloc(1024);
  strcpy(texto,"Esta es una prueba para que separe por espacios");
  Trozear(texto);
  char **str_ptr;
  __asm mov Palabras,eax
  __asm mov [str_ptr],ecx
  SayLong(Palabras);
  for (int y = 0;y < Palabras;y++)
  {
    MessageBox(0,str_ptr[y],"Palabra",0);
    free(str_ptr[y]);
  }
  free(str_ptr);
  free(texto);
}
