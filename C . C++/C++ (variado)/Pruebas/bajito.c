#include <windows.h>
 
void __main()
{
  HANDLE stdout = GetStdHandle(STD_OUTPUT_HANDLE);
  char holas[] = "hola mundo";
  DWORD written = 0;
  WriteFile(stdout, holas, strlen(holas), &written, 0);
}

size_t strlen(const char *cadena)
{
  const char *ptr = cadena;
  while(*ptr++);
  return ptr - cadena;
}
