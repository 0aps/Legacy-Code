#include <list>
#include <iostream>

int main(){
  std::list<int> ma_lista;
  ma_lista.push_back(4);
  ma_lista.push_back(5);
  ma_lista.push_back(4);
  ma_lista.push_back(1);
  std::list<int>::const_iterator
    lit (ma_lista.begin()),
    lend(ma_lista.end());
  for(;lit!=lend;++lit) std::cout << *lit << ' ';
  std::cout << std::endl; std::cin.get();
  return 0;
}
