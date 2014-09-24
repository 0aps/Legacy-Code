#include <iostream>
#include <list>
#include <algorithm>

#include <stack>
#include <queue>
#include <sstream>

using namespace std;

int main()
{
    int t,aux;
    stack<int> st;
    queue<int> qe;
//    priority_queue<int, vector<int>, greater<int> pque;
    
    list<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    
    list<int>::iterator it = find(lista.begin(), lista.end(), 1);
    if( 2 != *it) cout << "no esta " << *it <<  endl;
    else 
    cout << "esta " << *it << endl;
    
    while(cin >> t && t);
    cout << "fuera";
    cin.ignore();
    cin.clear();
    /*
    while(t--)
    {
              string linea;
              istringstream iss;
              getline(cin, linea);
              iss << linea;
              
              while(iss >> aux)
              {
                         
    */          
    cin.get();
    return 0;
}
