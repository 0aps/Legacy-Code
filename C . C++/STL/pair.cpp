//Dificultad: inserción y acceso en O(1)

#include <vector> // en la práctica este include es sobreentendido ya que implícitamente
//se hace cuando utilizamos <vector>, <set> ...
#include <iostream>
#include <string>

int main(){
  std::pair<int,std::string> p = std::make_pair(5,"pouet");
  std::cout << p.first << ' ' << p.second << std::endl;
  std::cin.get();
  return 0;
}
