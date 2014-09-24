#include <map>
#include <string>
#include <iostream>

int main(){
  std::map<std::string,unsigned> map_mis_idx;
  map_mis_idx["enero"] = 1;
  map_mis_idx["febrero"] = 2;
  //...
  std::map<std::string,unsigned>::const_iterator
    mit (map_mis_idx.begin()),
    mend(map_mis_idx.end());
  for(;mit!=mend;++mit) std::cout << mit->first << '\t' << mit->second << std::endl; 
  std::cin.get();
  return 0;
}
