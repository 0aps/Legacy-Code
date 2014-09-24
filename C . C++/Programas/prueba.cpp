#include <iostream>
#include <iomanip>
using namespace std;

int main()
 {
                        
  int   matriz[6][6]={                            {0,1,2,3,4,7},
                                                  {8,8,9,2,3,4},
                                                  {4,5,6,7,8,9},
                                                  {9,8,2,1,3,4},
                                                  {8,8,9,2,3,4},
                                                  {8,8,9,2,3,4},
                                               };
  
  for(int x(0); x < 6; x++)
  {
          
          for(int i(0); i < 6; i++)
          {
                  cout << "matriz["<<x<<"]"<<i<<"]: " << matriz[x][i];
                  cout << endl;
          }
          cout << endl << endl;
  }
  

setbuf(stdin, NULL);
cin.get();
return 0;

}

