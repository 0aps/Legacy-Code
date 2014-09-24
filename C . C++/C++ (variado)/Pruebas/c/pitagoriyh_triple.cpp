#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int aux;
    vector<int> nums;
    
    while(cin >> aux)
              {       
                         nums.push_back(aux);
                         if( nums.size() == 1 && !aux ) 
                                       break;   
                         if(aux<0)
                                  aux *=-1;
                                  
                         if(nums.size() == 3)
                         {
                              sort(nums.begin(), nums.begin()+3);                
                              if( (nums[0]+nums[1]) < nums[2] || 
                                    (nums[0]*nums[0]) + (nums[1]*nums[1]) != (nums[2]*nums[2]) )
                                                 cout << "wrong" << endl;
                              else
                                                 cout << "right" << endl;
                              nums.clear();
                         }
              }
    
    return 0;
}                                 
