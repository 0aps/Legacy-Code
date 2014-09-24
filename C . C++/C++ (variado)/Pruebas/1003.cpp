#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm> 
#include <sstream>

using namespace std;      

int main()
{
    int t,n,m,aux;
    string str;
    vector<int> nums;
    vector<int>::iterator i;
    
    cin >> t;
    while(t--)
    {
              cin >> n >> m;
              
              while(m--)
              {
                        
                        setvbuf(stdin, NULL, _IONBF, 0); 
                        
                        getline(cin, str);
                        stringstream ss(str);
                        
                        i = nums.begin();
              
                        while(ss >> aux)
                                      if(nums.size() < n)
                                                      nums.push_back(aux);
                                                      
                                      else
                                          *i += aux,i++;                             
              }                  
              
              int x = ( max_element(nums.begin(), nums.end()) - nums.begin())+1;
              cout << x << endl;
              nums.clear(); 
}
 return 0;
}
/*for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
                                        cout << *i << endl;                                  
              */
