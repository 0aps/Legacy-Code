#include <windows.h>

size_t strlen(char *cadena)
{
  char *ptr = cadena;
  while(*ptr++);
  return ptr - cadena;
}

int main()
{
  HANDLE stdout = GetStdHandle(STD_OUTPUT_HANDLE);
  char holas[] = "hola mundo";
  DWORD written = 0;
  WriteFile(stdout, holas, strlen(holas), &written, 0);
}
