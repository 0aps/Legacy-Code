/* assert example */
#include <stdio.h>
#include <assert.h>

void print_number(int* myInt) {
  assert (myInt!=NULL);
  printf ("%d\n",*myInt);
}

int main ()
{
  int a=10;
  int * b = NULL;
  int * c = NULL;

  b=&a;

  print_number (b);
  print_number (c);
  
  setbuf(stdin ,NULL);
  getchar();
  return 0;
}
