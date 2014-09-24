#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
        
    int x, y,m,aux;
    string str;
    int arrey[] = {1,2,0,4,5,6};
    vector<int> numss(arrey,arrey+6);
    vector<int>::iterator i;
    
    //cout << min_element(numss.begin(), numss.end()) - numss.begin(); //posicion del elemento menor
            //*min_element(numss.begin(), numss.end()) // elemento menor
    cin.get();
    //return 0;
    
    
    std::string tmp;
   std::getline(std::cin, tmp);
   
        std::vector<int> nums;
        std::stringstream ss(tmp);
 
        int ti(0);
        while( ss >> ti) //por alguna razon no cogo el primer caracter, asi que vuelatelo 
            nums.push_back(ti);
        
        cout << "size: " << nums.size() << endl;
 
        for(std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i) {
           std::cout << *i << std::endl; // this will print all the contents of *features*
      //     *i += *i;
}
    std::cin.get();
    return 0;
}
