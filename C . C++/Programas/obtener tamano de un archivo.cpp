// obtaining file size
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  long begin,end(0);
  ifstream myfile ("libro.txt");
  begin = myfile.tellg();
  myfile.seekg (0, ios::end);
  end = myfile.tellg();
  myfile.close();
  cout << "size is: " << (end-begin) << " bytes.\n";
  cin.get();
  return 0;
}
