#include <list>
#include <iostream>

const std::list<int> crear_lista(){
  std::list<int> l;
  l.push_back(3);
  l.push_back(4);
  return l;
}

int main(){
  const std::list<int> mi_lista(crear_lista());
  // no compila ya que es const
  // std::list<int>::iterator
  //  lit1 (l.begin()),
  //  lend(l.end());
  //for(;lit1!=lend1;++lit1) std::cout << *lit1 << ' ';
  //std::cout << std::endl;
  std::list<int>::const_iterator
    lit2 (mi_lista.begin()),
    lend2(mi_lista.end());
  for(;lit2!=lend2;++lit2) std::cout << *lit2 << ' ';
  std::cout << std::endl; std::cin.get();
  return 0;
}

