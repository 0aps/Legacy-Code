int a[4] = { 1, 2, 3, 4 };
int i = 3;

void f(int j)
{
    int k;
    k = j;  // k = 2
    printf("%i ",   k );
    i = 0;
    k = j;  // k = 1 (!?!)    
    printf("%i ",   k );
}


int main()
{
  f(a[i]);
  getchar();
  return 0;
}
