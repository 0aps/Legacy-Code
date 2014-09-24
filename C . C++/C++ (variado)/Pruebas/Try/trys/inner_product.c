/*
// inner_product example
#include <iostream>     // std::cout
#include <functional>   // std::minus, std::divides
#include <numeric>      // std::inner_product

int myaccumulator (int x, int y) {return x-y;}
int myproduct (int x, int y) {return x+y;}

int main () {
  int init = 0;
  int series1[] = {10,20,30};
  int series2[] = {1,2,3};

    //(10*1)+(20*2)+(30*3)
  std::cout << "using default inner_product: ";
  std::cout << std::inner_product(series1,series1+3,series2,init);
  std::cout << '\n';

  //(10/1)-(20/2)-(30/3)
  std::cout << "using functional operations: ";
  std::cout << std::inner_product(series1,series1+3,series2,init,
                                  std::minus<int>(),std::divides<int>());
  std::cout << '\n';

  //0-(10+1)-(20+2)-(30+3)
  std::cout << "using custom functions: ";
  std::cout << std::inner_product(series1,series1+3,series2,init,
                                  myaccumulator,myproduct);
  std::cout << '\n';

  return 0;
}
*/
