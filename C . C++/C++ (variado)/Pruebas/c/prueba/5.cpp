// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>

using namespace std;

int main () {
  int myints[] = {1,2,3,5,7};
  vector<int> myvector;

  myvector.push_back(1);
  myvector.push_back(2);
  myvector.push_back(3);
  myvector.push_back(5);
  myvector.push_back(7);
  
  //std::sort (myints,myints+5);  
  //std::sort (myvector.begin(),myvector.end());

/*  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' ' 
              << myints[3] << ' ' << myints[4] << '\n';
  } while ( std::next_permutation(myints,myints+5) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' '
            << myints[3] << ' ' << myints[4] << '\n';
*/
  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myvector[0] << ' ' << myvector[1] << ' ' << myvector[2] << ' ' 
              << myvector[3] << ' ' << myvector[4] << '\n';
  } while ( std::next_permutation(myvector.begin(),myvector.end()) );

  std::cout << "After loop: " << myvector[0] << ' ' << myvector[1] << ' ' << myvector[2] << ' '
            << myvector[3] << ' ' << myvector[4] << '\n';


  std::cin.get();
  return 0;
}
