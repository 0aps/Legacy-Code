#include <set>
#include <iostream>

int main(){
  std::set<int> s; // equivale a std::set<int,std::less<int> >
  s.insert(2); // s contiene 2
  s.insert(5); // s contiene 2 5
  s.insert(2); // el repetido no es insertado
  s.insert(1); // s contiene 1 2 5
  std::set<int>::const_iterator
    sit (s.begin()),
    send(s.end());
  for(;sit!=send;++sit) std::cout << *sit << ' ';
  std::cout << std::endl;  std::cin.get();
  return 0;
}
