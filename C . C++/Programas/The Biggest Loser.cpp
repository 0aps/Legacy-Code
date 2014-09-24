#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


int main()
{
    unsigned short t;
    vector<float> por;
    vector<float> por2;
    vector<string> nums;
    
    string nombre;
    char sex;
    float a,b;
    
    while(cin >> t)
    {
       cin.ignore();
       cin.clear();
       if(!t) break;
       
       while(t--)
       { 
               if(cin >> nombre >> sex >> a >> b)
                    {
                           nums.push_back(nombre);
                           if(sex == 'M')
                                  por.push_back( ((a-b)/a)*100 ),
                                  por2.push_back(0);
                           else  por2.push_back( ((a-b)/a)*100 ),
                                   por.push_back(0);             
                    }   
        }
        
        for(float i=0,aux,aux2; i<2; i++)
        {
            aux  = *(max_element(por.begin(), por.end() )) ;
            aux2 = *(max_element(por2.begin(), por2.end() )) ;
     
            if(i == 0)
            {
              cout << nums[ (max_element(por.begin(), por.end() )) - por.begin()] << " " 
                   << setprecision(2) << fixed << aux << "% ";
            }
            else
              cout << nums[ (max_element(por2.begin(), por2.end() )) - por2.begin()] << " " 
                   << setprecision(2) << fixed << aux2 << "%" << endl;
        }
    nums.clear();
    por.clear();
    por2.clear();
    }
       
    cin.get();
    return 0;
}
